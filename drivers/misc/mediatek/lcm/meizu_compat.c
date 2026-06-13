#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/string.h>
#include <linux/slab.h>

// Global variables for Meizu HW configuration
static char mz_sn[64] = "0123456789ABCDEF";
static char mz_psn[64] = "0123456789ABCDEF";
static char mz_colortype[64] = "white";
static unsigned int mz_sw_version_val = 0;
static unsigned int mz_hw_id = 0x20002020;
static unsigned int mz_rtx_val = 0;
static unsigned int mz_tptype_val = 0x74797065;
static unsigned int mz_lcd_id_val = 0;

static int mz_usb_temp = 32;
static int mz_usb_temp_prev = 32;
static int mz_usb_temp_raw = 0;

// Exported ADC functions from MTK core
extern int IMM_GetOneChannelValue(int dwChannel, int *data, int *raw);
extern int IMM_IsAdcInitReady(void);
extern int sec_schip_enabled(void);

// Setup function implementations to parse parameters from kernel command line
int __init mz_private_get_sn_setup(char *str)
{
    if (str) strlcpy(mz_sn, str, sizeof(mz_sn));
    return 1;
}
EXPORT_SYMBOL(mz_private_get_sn_setup);
__setup("androidboot.serialno=", mz_private_get_sn_setup);

int __init mz_private_get_psn_setup(char *str)
{
    if (str) strlcpy(mz_psn, str, sizeof(mz_psn));
    return 1;
}
EXPORT_SYMBOL(mz_private_get_psn_setup);
__setup("psn=", mz_private_get_psn_setup);

int __init mz_private_get_colortype_setup(char *str)
{
    if (str) strlcpy(mz_colortype, str, sizeof(mz_colortype));
    return 1;
}
EXPORT_SYMBOL(mz_private_get_colortype_setup);
__setup("cus_color=", mz_private_get_colortype_setup);

int __init mz_private_get_sw_version_setup(char *str)
{
    if (str) {
        if (sscanf(str, "0x%x", &mz_sw_version_val) != 1) {
            mz_sw_version_val = 0;
        }
    }
    return 1;
}
EXPORT_SYMBOL(mz_private_get_sw_version_setup);
__setup("androidboot.cus_param=", mz_private_get_sw_version_setup);

// HW Identification APIs called by proprietary kernel modules
unsigned int mz_get_hw_id(void)
{
    return mz_hw_id % 10;
}
EXPORT_SYMBOL(mz_get_hw_id);

int mz_has_muic(void)
{
    return (mz_hw_id % 10) == 1;
}
EXPORT_SYMBOL(mz_has_muic);

// Meizu proinfo partition read interface
int meizu_do_private_slot_read_flag(int slot, char *val1, char *val2)
{
    if (val1) *val1 = '0';
    if (val2) *val2 = '0';

    if (slot == 0x204400) {
        if (mz_rtx_val == 1) {
            if (val1) *val1 = '1';
        } else if (mz_rtx_val == 2) {
            if (val1) *val1 = '2';
        }
    }
    return 0;
}
EXPORT_SYMBOL(meizu_do_private_slot_read_flag);

// Torch interface for camera/flash drivers
int SY7806_set_torch_for_meizu_mode(int mode, int level)
{
    pr_info("SY7806_set_torch_for_meizu_mode: mode %d, level %d\n", mode, level);
    return 0;
}
EXPORT_SYMBOL(SY7806_set_torch_for_meizu_mode);

// USB NTC Thermistor calculations
int meizu_usb_temp_volt_to_temp(int volt)
{
    int temp = 30; // default 30C
    if (volt > 0) {
        // Linear approximation: 1000mV -> 25C, 500mV -> 50C
        temp = 75 - (volt / 20);
    }
    if (temp < -20) temp = -20;
    if (temp > 80) temp = 80;
    return temp;
}
EXPORT_SYMBOL(meizu_usb_temp_volt_to_temp);

int meizu_get_usb_temp(void)
{
    int data[4];
    int raw_val = 0;
    int scaled_val = 0;

    if (!IMM_IsAdcInitReady()) {
        return 0;
    }

    if (IMM_GetOneChannelValue(12, data, &raw_val) == -1) {
        mz_usb_temp = mz_usb_temp_prev;
    } else {
        mz_usb_temp_raw = raw_val;
        scaled_val = (raw_val * 1500) >> 12; // 12-bit ADC scaling with 1.5V ref
        mz_usb_temp_prev = mz_usb_temp;
        mz_usb_temp = meizu_usb_temp_volt_to_temp(scaled_val);
    }

    return mz_usb_temp;
}
EXPORT_SYMBOL(meizu_get_usb_temp);

// Dummy thermal and temp show variables/stubs to prevent crashes
ssize_t meizu_cup_temp_show(struct class *class, struct class_attribute *attr, char *buf)
{
    return sprintf(buf, "42000\n"); // 42C
}
EXPORT_SYMBOL(meizu_cup_temp_show);

ssize_t meizu_pcb_temp_show(struct class *class, struct class_attribute *attr, char *buf)
{
    return sprintf(buf, "36000\n"); // 36C
}
EXPORT_SYMBOL(meizu_pcb_temp_show);

ssize_t meizu_cam_thermal_status_show(struct class *class, struct class_attribute *attr, char *buf)
{
    return sprintf(buf, "0\n");
}
EXPORT_SYMBOL(meizu_cam_thermal_status_show);

ssize_t meizu_cup_sync_temp_show(struct class *class, struct class_attribute *attr, char *buf)
{
    return sprintf(buf, "42000\n");
}
EXPORT_SYMBOL(meizu_cup_sync_temp_show);

ssize_t meizu_usb_temp_show(struct class *class, struct class_attribute *attr, char *buf)
{
    meizu_get_usb_temp();
    return sprintf(buf, "%d\n", mz_usb_temp * 1000);
}
EXPORT_SYMBOL(meizu_usb_temp_show);

ssize_t meizu_usb_temp_store(struct class *class, struct class_attribute *attr, const char *buf, size_t count)
{
    return count;
}
EXPORT_SYMBOL(meizu_usb_temp_store);

// /proc/lk_info reader helpers
#define DEFINE_LK_INFO_SHOW(name, expr) \
static int name##_proc_show(struct seq_file *m, void *v) \
{ \
    expr; \
    return 0; \
} \
static int name##_proc_open(struct inode *inode, struct file *file) \
{ \
    return single_open(file, name##_proc_show, NULL); \
} \
static const struct file_operations name##_proc_fops = { \
    .owner = THIS_MODULE, \
    .open = name##_proc_open, \
    .read = seq_read, \
    .llseek = seq_lseek, \
    .release = single_release, \
};

DEFINE_LK_INFO_SHOW(hw_version, seq_printf(m, "%d\n", mz_hw_id))
DEFINE_LK_INFO_SHOW(sw_version, seq_printf(m, "0x%x\n", mz_sw_version_val))
DEFINE_LK_INFO_SHOW(sn, seq_printf(m, "%s\n", mz_sn))
DEFINE_LK_INFO_SHOW(colortype, seq_printf(m, "%s\n", mz_colortype))
DEFINE_LK_INFO_SHOW(psn, seq_printf(m, "%s\n", mz_psn))

static int rtx_proc_show(struct seq_file *m, void *v)
{
    char buf[2];
    buf[0] = '0';
    buf[1] = '0';
    int ret = meizu_do_private_slot_read_flag(0x204400, &buf[0], &buf[1]);
    int val = 0;
    if (ret == 0) {
        if (buf[0] == '1') {
            val = 1;
        } else if (buf[0] == '2') {
            val = 2;
        }
    } else {
        val = mz_rtx_val;
    }
    mz_rtx_val = val;
    seq_printf(m, "%d\n", val);
    return 0;
}
static int rtx_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, rtx_proc_show, NULL);
}
static const struct file_operations rtx_proc_fops = {
    .owner = THIS_MODULE,
    .open = rtx_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int sec_proc_show(struct seq_file *m, void *v)
{
    if (sec_schip_enabled() == 0) {
        seq_printf(m, "Non-Secure Chip\n");
    } else {
        seq_printf(m, "Secure Chip\n");
    }
    return 0;
}
static int sec_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, sec_proc_show, NULL);
}
static const struct file_operations sec_proc_fops = {
    .owner = THIS_MODULE,
    .open = sec_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

DEFINE_LK_INFO_SHOW(tptype, seq_printf(m, "%d\n", mz_tptype_val))
DEFINE_LK_INFO_SHOW(lcd_id, seq_printf(m, "%d\n", mz_lcd_id_val))

// Sysfs class `/sys/class/meizu`
static struct class *meizu_class;

static struct class_attribute meizu_class_attrs[] = {
    __ATTR(hw_version, 0444, NULL, NULL), // dummy placeholder
    __ATTR_RO(meizu_cup_temp),
    __ATTR_RO(meizu_pcb_temp),
    __ATTR_RO(meizu_cam_thermal_status),
    __ATTR_RO(meizu_cup_sync_temp),
    __ATTR_RW(meizu_usb_temp),
    __ATTR_NULL,
};

// Early flat DT scan helper called during setup_arch
int __init mz_private_init_dt_get(unsigned long node, const char *uname, int depth, void *data)
{
    if (depth != 1) return 0;
    if (strcmp(uname, "chosen") == 0 || strcmp(uname, "chosen@0") == 0) {
        *((unsigned long *)data) = node;
        return 1;
    }
    return 0;
}

// Meizu Class and Proc initialization
int __init meizu_init(void)
{
    struct proc_dir_entry *proc_entry;

    // Create /sys/class/meizu
    meizu_class = class_create(THIS_MODULE, "meizu");
    if (IS_ERR(meizu_class)) {
        printk(KERN_ERR "unable to register meizu class\n");
        return PTR_ERR(meizu_class);
    }

    // Register class attributes
    meizu_class->class_attrs = meizu_class_attrs;

    // Create /proc/lk_info/ directory and files
    proc_entry = proc_mkdir("lk_info", NULL);
    if (proc_entry) {
        proc_create("hw_version", 0444, proc_entry, &hw_version_proc_fops);
        proc_create("sw_version", 0444, proc_entry, &sw_version_proc_fops);
        proc_create("sn", 0444, proc_entry, &sn_proc_fops);
        proc_create("colortype", 0444, proc_entry, &colortype_proc_fops);
        proc_create("psn", 0444, proc_entry, &psn_proc_fops);
        proc_create("rtx", 0444, proc_entry, &rtx_proc_fops);
        proc_create("sec", 0444, proc_entry, &sec_proc_fops);
        proc_create("tptype", 0444, proc_entry, &tptype_proc_fops);
        proc_create("lcd_id", 0444, proc_entry, &lcd_id_proc_fops);
    }

    return 0;
}
late_initcall(meizu_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("nomorecoolnicknames");
MODULE_DESCRIPTION("Meizu M5c Compatibility Driver");
