// Decompiled component driver: touch_ft5x46.c
// source: stock m5c kernel via Ghidra (reference)


undefined8 fts_rw_iic_drv_open(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd0) = DAT_ffffffc00156bd10;
  return 0;
}



undefined8 fts_rw_iic_drv_release(void)

{
  return 0;
}



long fts_rw_iic_drv_ioctl(long param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  undefined8 *__s;
  void *__s_00;
  ulong uVar3;
  int iVar4;
  long lVar5;
  size_t __n;
  undefined8 *puVar6;
  int iVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  ulong local_10;
  ulong local_8;
  
  lVar5 = *(long *)(param_1 + 0xd0);
  esd_switch(0);
  DAT_ffffffc00156bd80 = 1;
  mutex_lock(DAT_ffffffc00156bd10 + 0x68);
  if (param_2 == 0xc) {
    lVar5 = *(long *)(lVar5 + 0x90);
    uVar1 = *(ulong *)(((ulong)&stack0xffffffffffffff70 & 0xffffffffffffc000) + 8);
    if (param_3 < 0xfffffffffffffff0 && param_3 + 0x10 <= uVar1) {
      if (param_3 < 0xfffffffffffffff0 && param_3 + 0x10 <= uVar1) {
        lVar2 = __copy_from_user(&local_10,param_3,0x10);
        if (lVar2 == 0) {
          if ((int)(uint)local_8 < 0x25) {
            __s = (undefined8 *)
                  __kmalloc(-(ulong)((uint)local_8 >> 0x1f) & 0xfffffff000000000 |
                            (local_8 & 0xffffffff) << 4,0xd0);
            if (__s == (undefined8 *)0x0) {
              lVar5 = -0xc;
            }
            else {
              __n = (long)(int)(uint)local_8 * 0x10;
              if (CARRY8(local_10,__n) ||
                  *(ulong *)(((ulong)&stack0xffffffffffffff70 & 0xffffffffffffc000) + 8) <
                  local_10 + __n) {
                memset(__s,0,__n);
              }
              else {
                __n = __copy_from_user(__s,local_10,__n);
              }
              if (__n == 0) {
                lVar2 = __kmalloc((long)(int)(uint)local_8 << 3,0xd0);
                if (lVar2 == 0) {
                  lVar5 = -0xc;
                  kfree(__s);
                }
                else if ((int)(uint)local_8 < 1) {
LAB_ffffffc0008422c4:
                  lVar5 = 0;
                }
                else {
                  if (*(ushort *)((long)__s + 10) < 0x2001) {
                    lVar8 = 0;
                    iVar7 = 0;
                    puVar6 = __s;
                    do {
                      *(undefined8 *)(lVar2 + lVar8 * 8) = *puVar6;
                      __s_00 = (void *)__kmalloc(*(undefined2 *)((long)puVar6 + 10),0xd0);
                      *puVar6 = __s_00;
                      if (__s_00 == (void *)0x0) {
                        lVar5 = -0xc;
                        goto LAB_ffffffc00084212c;
                      }
                      uVar1 = (ulong)*(ushort *)((long)puVar6 + 10);
                      uVar3 = *(ulong *)(lVar2 + lVar8 * 8);
                      if (CARRY8(uVar3,uVar1) ||
                          *(ulong *)(((ulong)&stack0xffffffffffffff70 & 0xffffffffffffc000) + 8) <
                          uVar3 + uVar1) {
                        memset(__s_00,0,uVar1);
                      }
                      else {
                        uVar1 = __copy_from_user(__s_00,uVar3,uVar1);
                      }
                      if (uVar1 != 0) {
                        iVar7 = iVar7 + 1;
                        lVar5 = -0xe;
                        goto LAB_ffffffc00084212c;
                      }
                      iVar7 = iVar7 + 1;
                      lVar8 = (long)iVar7;
                      puVar6 = __s + lVar8 * 2;
                      if ((int)(uint)local_8 <= iVar7) {
                        iVar7 = 0;
                        if ((int)(uint)local_8 < 1) goto LAB_ffffffc0008422c4;
                        goto LAB_ffffffc00084221c;
                      }
                    } while (*(ushort *)((long)puVar6 + 10) < 0x2001);
                    lVar5 = -0x16;
LAB_ffffffc00084212c:
                    if (0 < iVar7) {
                      puVar6 = __s;
                      do {
                        puVar9 = puVar6 + 2;
                        kfree(*puVar6);
                        puVar6 = puVar9;
                      } while (puVar9 != __s + ((ulong)(iVar7 - 1) + 1) * 2);
                    }
                  }
                  else {
                    lVar5 = -0x16;
                  }
                  kfree(lVar2);
                  kfree(__s);
                }
              }
              else {
                lVar5 = -0xe;
                kfree(__s);
              }
            }
          }
          else {
            lVar5 = -0x16;
          }
          goto LAB_ffffffc000841f8c;
        }
      }
      else {
        local_10 = 0;
        local_8 = 0;
      }
    }
    lVar5 = -0xe;
  }
  else {
    lVar5 = -0x19;
  }
  goto LAB_ffffffc000841f8c;
LAB_ffffffc00084221c:
  do {
    lVar8 = (long)iVar7;
    lVar10 = lVar8 * 0x10;
    if (*(char *)(__s + lVar8 * 2 + 1) == '\0') {
      uVar1 = fts_i2c_write(lVar5,__s[lVar8 * 2],*(undefined2 *)((long)__s + lVar10 + 10));
      uVar3 = uVar1 & 0xffffffff;
      iVar4 = (int)uVar1;
      if (iVar4 < 0) {
        iVar7 = iVar7 + 1;
        dev_err(lVar5 + 0x20,s__s_IIC_Write_failed_ffffffc000f951c0,&__func___42546);
        if ((int)(uint)local_8 <= iVar7) break;
        goto LAB_ffffffc00084221c;
      }
    }
    else {
      uVar1 = fts_i2c_read(lVar5,0,0,__s[lVar8 * 2],*(undefined2 *)((long)__s + lVar10 + 10));
      uVar3 = uVar1 & 0xffffffff;
      if ((int)uVar1 < 0) {
        dev_err(lVar5 + 0x20,s__s_IIC_Read_failed_ffffffc000f951a8,__func___42539);
      }
      else {
        uVar1 = *(ulong *)(lVar2 + lVar8 * 8);
        uVar3 = (ulong)*(ushort *)((long)__s + lVar10 + 10);
        if (!CARRY8(uVar1,uVar3) &&
            uVar1 + uVar3 <= *(ulong *)(((ulong)&stack0xffffffffffffff70 & 0xffffffffffffc000) + 8))
        {
          uVar3 = __copy_to_user(uVar1,__s[lVar8 * 2],uVar3);
        }
      }
    }
    iVar4 = (int)uVar3;
    iVar7 = iVar7 + 1;
  } while (iVar7 < (int)(uint)local_8);
  lVar5 = (long)iVar4;
LAB_ffffffc000841f8c:
  mutex_unlock(DAT_ffffffc00156bd10 + 0x68);
  esd_switch(1);
  DAT_ffffffc00156bd80 = 0;
  return lVar5;
}



int fts_rw_iic_drv_init(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_4;
  
  if ((DAT_ffffffc0012abf0a >> 2 & 1) != 0) {
    __dynamic_dev_dbg(&PTR_s_focaltech_ctl_ffffffc0012abee8,param_1 + 0x20,
                      s__FTS_____ft_rw_iic_drv_init_____ffffffc000f951d8);
  }
  local_4 = DAT_ffffffc00115d8e0 << 0x14;
  if (DAT_ffffffc00115d8e0 == 0) {
    iVar2 = alloc_chrdev_region(&local_4,0,1,s_ft_rw_iic_drv_ffffffc000f95200);
    DAT_ffffffc00115d8e0 = local_4 >> 0x14;
  }
  else {
    iVar2 = register_chrdev_region(local_4,1,s_ft_rw_iic_drv_ffffffc000f95200);
  }
  if (-1 < iVar2) {
    DAT_ffffffc00156bd10 = kmem_cache_alloc_trace(DAT_ffffffc001355a58,0xd0,0x98);
    if (DAT_ffffffc00156bd10 == 0) {
      unregister_chrdev_region(local_4,1);
      dev_err(param_1 + 0x20,s__s_ft_rw_iic_drv_failed_ffffffc000f95240,__func___42599);
      iVar2 = -0xc;
    }
    else {
      lVar1 = DAT_ffffffc00156bd10 + 0x68;
      *(long *)(DAT_ffffffc00156bd10 + 0x90) = param_1;
      __mutex_init(lVar1,s__fts_rw_i2c_dev_tt_>fts_rw_i2c_m_ffffffc000f95260,&DAT_ffffffc00156bd18);
      lVar1 = DAT_ffffffc00156bd10;
      iVar2 = DAT_ffffffc00115d8e0 << 0x14;
      cdev_init(DAT_ffffffc00156bd10,&fts_rw_iic_drv_fops);
      *(undefined8 *)(lVar1 + 0x40) = 0;
      *(undefined **)(lVar1 + 0x48) = &fts_rw_iic_drv_fops;
      iVar2 = cdev_add(lVar1,iVar2,1);
      if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
        printk(&DAT_ffffffc000f95288,iVar2,0);
      }
      DAT_ffffffc00156bd18 = __class_create(0,s_fts_class_ffffffc000f952a0,&DAT_ffffffc00156bd18);
      if (DAT_ffffffc00156bd18 < 0xfffffffffffff001) {
        device_create(DAT_ffffffc00156bd18,0,DAT_ffffffc00115d8e0 << 0x14,0,
                      s_ft_rw_iic_drv_ffffffc000f95200);
        iVar2 = 0;
      }
      else {
        dev_err(param_1 + 0x20,s__s_failed_in_creating_class__ffffffc000f952b0,__func___42599);
        iVar2 = -1;
      }
    }
    return iVar2;
  }
  dev_err(param_1 + 0x20,s__s_ft_rw_iic_drv_failed_error_co_ffffffc000f95210,__func___42599,iVar2);
  return iVar2;
}



void fts_rw_iic_drv_exit(void)

{
  device_destroy(DAT_ffffffc00156bd18,DAT_ffffffc00115d8e0 << 0x14);
  class_destroy(DAT_ffffffc00156bd18);
  cdev_del(DAT_ffffffc00156bd10);
  kfree(DAT_ffffffc00156bd10);
  unregister_chrdev_region(DAT_ffffffc00115d8e0 << 0x14,1);
  return;
}



undefined8 fts_tpfwver_store(void)

{
  return 0xffffffffffffffff;
}



undefined8 fts_tprwreg_show(void)

{
  return 0xffffffffffffffff;
}



undefined8 fts_fwupgradeapp_show(void)

{
  return 0xffffffffffffffff;
}



undefined8 fts_getprojectcode_show(void)

{
  return 0xffffffffffffffff;
}



undefined8 fts_getprojectcode_store(void)

{
  return 0xffffffffffffffff;
}



undefined8 ft5x46_ctptest_store(void)

{
  return 0xffffffffffffffff;
}



void fts_test_i2c_write(undefined8 param_1,undefined4 param_2)

{
  fts_i2c_write(DAT_ffffffc00156bdb8,param_1,param_2);
  return;
}



long fts_debug_write(undefined8 param_1,ulong param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  ulong __n;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  undefined8 local_448;
  undefined8 uStack_440;
  undefined8 local_438;
  undefined8 uStack_430;
  undefined8 local_428;
  undefined8 uStack_420;
  undefined8 local_418;
  undefined8 uStack_410;
  undefined8 local_408;
  undefined8 uStack_400;
  undefined1 local_3f8;
  byte local_3f7 [1015];
  
  esd_switch(0);
  DAT_ffffffc00156bd80 = 1;
  iVar2 = (int)param_3;
  __n = (ulong)iVar2;
  if (CARRY8(param_2,__n) ||
      *(ulong *)(((ulong)&stack0xfffffffffffffb30 & 0xffffffffffffc000) + 8) < param_2 + __n) {
    memset(&local_3f8,0,__n);
  }
  else {
    __n = __copy_from_user(&local_3f8,param_2,__n);
  }
  if (__n != 0) {
    dev_err(DAT_ffffffc00156bda0 + 0x20,s__s_copy_from_user_error_ffffffc000f95358,__func___42561);
    esd_switch(1);
    DAT_ffffffc00156bd80 = 0;
    return -0xe;
  }
  DAT_ffffffc00156bd20 = local_3f8;
  switch(local_3f8) {
  case 0:
    local_478 = 0;
    uStack_470 = 0;
    local_468 = 0;
    uStack_460 = 0;
    local_458 = 0;
    uStack_450 = 0;
    local_448 = 0;
    uStack_440 = 0;
    local_438 = 0;
    uStack_430 = 0;
    local_428 = 0;
    uStack_420 = 0;
    local_418 = 0;
    uStack_410 = 0;
    local_408 = 0;
    uStack_400 = 0;
    strcpy((char *)&local_478,(char *)local_3f7);
    uVar1 = *(undefined4 *)(DAT_ffffffc00156bda0 + 0x1f0);
    *(char *)((long)&local_478 + (long)(iVar2 + -1)) = '\0';
    disable_irq(uVar1);
    iVar2 = fts_ctpm_fw_upgrade_with_app_file(DAT_ffffffc00156bda0,&local_478);
    enable_irq(*(undefined4 *)(DAT_ffffffc00156bda0 + 0x1f0));
    if (-1 < iVar2) goto switchD_ffffffc000842694_caseD_3;
    esd_switch(1);
    pcVar3 = s__s_upgrade_failed__ffffffc000f95378;
    goto LAB_ffffffc0008426fc;
  case 1:
    iVar2 = fts_i2c_write(DAT_ffffffc00156bda0,local_3f7,1);
    break;
  case 2:
    iVar2 = fts_i2c_write(DAT_ffffffc00156bda0,local_3f7,2);
    break;
  default:
    goto switchD_ffffffc000842694_caseD_3;
  case 4:
    fts_ctpm_auto_clb(DAT_ffffffc00156bda0);
    goto switchD_ffffffc000842694_caseD_3;
  case 6:
  case 7:
    if (iVar2 + -1 < 1) goto switchD_ffffffc000842694_caseD_3;
    iVar2 = fts_i2c_write(DAT_ffffffc00156bda0,local_3f7);
    break;
  case 8:
    DAT_ffffffc00156bd80 = (uint)local_3f7[0];
    if (DAT_ffffffc00156bd80 == 1) {
      esd_switch(0);
    }
    else if (local_3f7[0] == 0) {
      esd_switch(1);
    }
                    /* WARNING: Subroutine does not return */
    printk(s_zax_flag__d_ffffffc000f95390,DAT_ffffffc00156bd80);
  }
  if (iVar2 < 0) {
    esd_switch(1);
    pcVar3 = s__s_write_iic_error_ffffffc000f953a0;
LAB_ffffffc0008426fc:
    DAT_ffffffc00156bd80 = 0;
    dev_err(DAT_ffffffc00156bda0 + 0x20,pcVar3,__func___42561);
    return (long)iVar2;
  }
switchD_ffffffc000842694_caseD_3:
  esd_switch(1);
  DAT_ffffffc00156bd80 = 0;
  return param_3;
}



void fts_test_i2c_read(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  fts_i2c_read(DAT_ffffffc00156bdb8,param_1,param_2,param_3,param_4);
  return;
}



long fts_debug_read(undefined8 param_1,ulong param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  byte local_3f9;
  char local_3f8 [8];
  char acStack_3f0 [8];
  char local_3e8 [1000];
  
  local_3f9 = 0;
  esd_switch(0);
  DAT_ffffffc00156bd80 = 1;
  if (DAT_ffffffc00156bd20 == '\x01') {
    iVar1 = fts_i2c_read(DAT_ffffffc00156bda0,0,0,local_3f8,1);
    uVar2 = 1;
    param_3 = 1;
    if (iVar1 < 0) {
      esd_switch(1);
LAB_ffffffc000842a94:
      DAT_ffffffc00156bd80 = 0;
      dev_err(DAT_ffffffc00156bda0 + 0x20,s__s_read_iic_error_ffffffc000f953f0,__func___42587);
      return (long)iVar1;
    }
LAB_ffffffc0008429f0:
    if (CARRY8(param_2,uVar2) ||
        *(ulong *)(((ulong)&stack0xfffffffffffffbc0 & 0xffffffffffffc000) + 8) < param_2 + uVar2)
    goto LAB_ffffffc000842a10;
LAB_ffffffc000842974:
    uVar2 = __copy_to_user(param_2,local_3f8,uVar2);
  }
  else {
    if (DAT_ffffffc00156bd20 == '\0') {
      iVar1 = fts_read_reg(DAT_ffffffc00156bda0,0xffffffa6,&local_3f9);
      if (iVar1 < 0) {
        uVar2 = 0x17;
        param_3 = 0x17;
        local_3f8[0] = s_get_fw_version_failed__ffffffc000f953b8[0];
        local_3f8[1] = s_get_fw_version_failed__ffffffc000f953b8[1];
        local_3f8[2] = s_get_fw_version_failed__ffffffc000f953b8[2];
        local_3f8[3] = s_get_fw_version_failed__ffffffc000f953b8[3];
        local_3f8[4] = s_get_fw_version_failed__ffffffc000f953b8[4];
        local_3f8[5] = s_get_fw_version_failed__ffffffc000f953b8[5];
        local_3f8[6] = s_get_fw_version_failed__ffffffc000f953b8[6];
        local_3f8[7] = s_get_fw_version_failed__ffffffc000f953b8[7];
        acStack_3f0[0] = s_get_fw_version_failed__ffffffc000f953b8[8];
        acStack_3f0[1] = s_get_fw_version_failed__ffffffc000f953b8[9];
        acStack_3f0[2] = s_get_fw_version_failed__ffffffc000f953b8[10];
        acStack_3f0[3] = s_get_fw_version_failed__ffffffc000f953b8[0xb];
        acStack_3f0[4] = s_get_fw_version_failed__ffffffc000f953b8[0xc];
        acStack_3f0[5] = s_get_fw_version_failed__ffffffc000f953b8[0xd];
        acStack_3f0[6] = s_get_fw_version_failed__ffffffc000f953b8[0xe];
        acStack_3f0[7] = s_get_fw_version_failed__ffffffc000f953b8[0xf];
        local_3e8[0] = s_get_fw_version_failed__ffffffc000f953b8[0x10];
        local_3e8[1] = s_get_fw_version_failed__ffffffc000f953b8[0x11];
        local_3e8[2] = s_get_fw_version_failed__ffffffc000f953b8[0x12];
        local_3e8[3] = s_get_fw_version_failed__ffffffc000f953b8[0x13];
        local_3e8[4] = s_get_fw_version_failed__ffffffc000f953b8[0x14];
        local_3e8[5] = s_get_fw_version_failed__ffffffc000f953b8[0x15];
        local_3e8[6] = s_get_fw_version_failed__ffffffc000f953b8[0x16];
        local_3e8[7] = s_get_fw_version_failed__ffffffc000f953b8[0x17];
        goto LAB_ffffffc0008429f0;
      }
      param_3 = sprintf(local_3f8,s_current_fw_version_0x_02x_ffffffc000f953d0,(ulong)local_3f9);
    }
    else {
      if (DAT_ffffffc00156bd20 != '\a') {
        if (*(ulong *)(((ulong)&stack0xfffffffffffffbc0 & 0xffffffffffffc000) + 8) < param_2) {
          lVar3 = 0;
          goto LAB_ffffffc000842918;
        }
        uVar2 = 0;
        param_3 = 0;
        goto LAB_ffffffc000842974;
      }
      iVar1 = fts_i2c_read(DAT_ffffffc00156bda0,0,0,local_3f8,param_3);
      if (iVar1 < 0) {
        esd_switch(1);
        goto LAB_ffffffc000842a94;
      }
    }
    uVar2 = (ulong)param_3;
    if (!CARRY8(param_2,uVar2) &&
        param_2 + uVar2 <= *(ulong *)(((ulong)&stack0xfffffffffffffbc0 & 0xffffffffffffc000) + 8))
    goto LAB_ffffffc000842974;
  }
  lVar3 = (long)param_3;
  if (uVar2 == 0) {
LAB_ffffffc000842918:
    esd_switch(1);
    DAT_ffffffc00156bd80 = 0;
    return lVar3;
  }
LAB_ffffffc000842a10:
  dev_err(DAT_ffffffc00156bda0 + 0x20,s__s_copy_to_user_error_ffffffc000f95408,__func___42587);
  esd_switch(1);
  DAT_ffffffc00156bd80 = 0;
  return -0xe;
}



long fts_fwupgradeapp_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  char cStack_81;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  strcpy((char *)&local_80,param_3);
  (&cStack_81)[param_4] = '\0';
  esd_switch(0);
  DAT_ffffffc00156bd80 = 1;
  mutex_lock(DAT_ffffffc00156bdb0 + 0x200);
  disable_irq(*(undefined4 *)(param_1 + 0x1d0));
  fts_ctpm_fw_upgrade_with_app_file(param_1 + -0x20,&local_80);
  enable_irq(*(undefined4 *)(param_1 + 0x1d0));
  mutex_unlock(DAT_ffffffc00156bdb0 + 0x200);
  esd_switch(1);
  DAT_ffffffc00156bd80 = 0;
  return param_4;
}



long fts_tpfwver_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  char local_1;
  
  local_1 = '\0';
  mutex_lock(DAT_ffffffc00156bdb0 + 0x200);
  iVar6 = fts_read_reg(DAT_ffffffc00156bda0,0xffffffa6,&local_1);
  cVar2 = s_get_tp_fw_version_fail__ffffffc000f95450[0x18];
  uVar3 = s_get_tp_fw_version_fail__ffffffc000f95450._16_8_;
  uVar1 = s_get_tp_fw_version_fail__ffffffc000f95450._8_8_;
  if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f95420);
  }
  if (local_1 == -1) {
    lVar9 = 0x18;
    *(undefined8 *)param_3 = s_get_tp_fw_version_fail__ffffffc000f95450._0_8_;
    *(undefined8 *)(param_3 + 8) = uVar1;
    *(undefined8 *)(param_3 + 0x10) = uVar3;
    param_3[0x18] = cVar2;
  }
  else {
    iVar6 = sprintf(param_3,s_firmware_version_0x_02X_ffffffc000f95470);
    lVar9 = (long)iVar6;
  }
  msleep(5);
  iVar6 = fts_read_reg(DAT_ffffffc00156bda0,0xffffffa8,&local_1);
  uVar4 = s_each_tp_vendor_ffffffc000f954f0._8_8_;
  uVar3 = s_get_tp_vendor_id_fail__ffffffc000f954c0._16_8_;
  uVar1 = s_get_tp_vendor_id_fail__ffffffc000f954c0._8_8_;
  if (iVar6 < 0) {
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f95490);
  }
  if (local_1 == -1) {
    pcVar7 = param_3 + lVar9;
    lVar9 = lVar9 + 0x17;
    *(undefined8 *)pcVar7 = s_get_tp_vendor_id_fail__ffffffc000f954c0._0_8_;
    *(undefined8 *)(pcVar7 + 8) = uVar1;
    *(undefined8 *)(pcVar7 + 0x10) = uVar3;
    goto LAB_ffffffc000842c38;
  }
  if (local_1 == 'Q') {
    pcVar7 = s_ofilm_tp_vendor_ffffffc000f954d8;
  }
  else {
    if (local_1 == -0x80) {
      pcVar7 = param_3 + lVar9;
      lVar9 = lVar9 + 0xf;
      *(undefined8 *)pcVar7 = s_each_tp_vendor_ffffffc000f954f0._0_8_;
      *(undefined8 *)(pcVar7 + 8) = uVar4;
      goto LAB_ffffffc000842c38;
    }
    if (local_1 != -0x7b) goto LAB_ffffffc000842c38;
    pcVar7 = s_junda_tp_vendor_ffffffc000f95500;
  }
  pcVar8 = param_3 + lVar9;
  uVar1 = *(undefined8 *)(pcVar7 + 8);
  cVar2 = pcVar7[0x10];
  lVar9 = lVar9 + 0x10;
  *(undefined8 *)pcVar8 = *(undefined8 *)pcVar7;
  *(undefined8 *)(pcVar8 + 8) = uVar1;
  pcVar8[0x10] = cVar2;
LAB_ffffffc000842c38:
  msleep(5);
  iVar6 = fts_read_reg(DAT_ffffffc00156bda0,0xffffffab,&local_1);
  uVar5 = s_get_tp_color_fail__ffffffc000f95540._16_4_;
  uVar1 = s_get_tp_color_fail__ffffffc000f95540._8_8_;
  if (-1 < iVar6) {
    if (local_1 == -1) {
      param_3 = param_3 + lVar9;
      lVar9 = lVar9 + 0x13;
      *(undefined8 *)param_3 = s_get_tp_color_fail__ffffffc000f95540._0_8_;
      *(undefined8 *)(param_3 + 8) = uVar1;
      *(undefined4 *)(param_3 + 0x10) = uVar5;
    }
    else if (local_1 == '1') {
      *(char (*) [8])(param_3 + lVar9) = s_black_ffffffc000f95558;
      lVar9 = lVar9 + 7;
    }
    else if (local_1 == '2') {
      *(char (*) [8])(param_3 + lVar9) = s_white_ffffffc000f95560;
      lVar9 = lVar9 + 7;
    }
    mutex_unlock(DAT_ffffffc00156bdb0 + 0x200);
    return lVar9;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f95518);
}



undefined8 fts_fwupdate_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  esd_switch(0);
  DAT_ffffffc00156bd80 = 1;
  mutex_lock(DAT_ffffffc00156bdb0 + 0x200);
  disable_irq(*(undefined4 *)(param_1 + 0x1d0));
  iVar2 = fts_ctpm_fw_upgrade_with_i_file(param_1 + -0x20);
  if (iVar2 == 0) {
    msleep(300);
    uVar1 = fts_ctpm_get_i_file_ver();
    if ((DAT_ffffffc0012abf32 >> 2 & 1) != 0) {
      __dynamic_dev_dbg(&PTR_s_focaltech_ex_fun_ffffffc0012abf10,param_1,
                        s__s__FTS__upgrade_to_new_version_0_ffffffc000f95568,&__func___42686,uVar1);
    }
  }
  else {
    dev_err(param_1,s__s_ERROR__FTS__upgrade_failed_re_ffffffc000f95590,&__func___42686,iVar2);
  }
  enable_irq(*(undefined4 *)(param_1 + 0x1d0));
  mutex_unlock(DAT_ffffffc00156bdb0 + 0x200);
  esd_switch(1);
  DAT_ffffffc00156bd80 = 0;
  return param_4;
}



undefined8 fts_fwupdate_show(undefined8 param_1,undefined8 param_2,undefined2 *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  cVar1 = get_tp_upgrade_status();
  if (cVar1 == '\x01') {
    pcVar4 = s__name_battery_common_fg_20___cha_ffffffc000fa5510 + 0x60;
    pcVar2 = s__FTS___d_fts_ctp_firmware_upgrad_ffffffc000f955b8;
    uVar3 = 0x32d;
  }
  else {
    cVar1 = get_tp_upgrade_status();
    if (cVar1 == '\x02') {
      pcVar4 = s_3_U3D__s__fake_to_type_2_ffffffc000e5e229 + 0x17;
      pcVar2 = s__FTS___d_fts_ctp_firmware_upgrad_ffffffc000f955e8;
      uVar3 = 0x330;
    }
    else {
      cVar1 = get_tp_upgrade_status();
      if (cVar1 != '\0') {
        return 2;
      }
      pcVar4 = s_Config_options__0_ffffffc000fd2250 + 0x10;
      pcVar2 = s__FTS___d_fts_ctp_firmware_no_upg_ffffffc000f95610;
      uVar3 = 0x333;
    }
  }
  cVar1 = pcVar4[2];
  *param_3 = *(undefined2 *)pcVar4;
  *(char *)(param_3 + 1) = cVar1;
                    /* WARNING: Subroutine does not return */
  printk(pcVar2,uVar3);
}



void ft5x46_ctptest_show(void)

{
  char cVar1;
  undefined1 uVar2;
  long lVar3;
  byte local_109 [9];
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  
  local_109[0] = 0;
  mutex_lock(&DAT_ffffffc00115d8e8);
  psensor_irq_control(0);
  cVar1 = get_tp_upgrade_status();
  if (cVar1 == '\x01') {
    while (cVar1 = get_tp_upgrade_status(), cVar1 == '\x01') {
      if ((local_109[0] & 3) == 0) {
        uVar2 = get_tp_upgrade_status();
                    /* WARNING: Subroutine does not return */
        printk(s__FTS___d_tp_firmware_upgrading_s_ffffffc000f95680,0x44e,uVar2);
      }
      msleep(200);
      local_109[0] = local_109[0] + 1;
      if (0x1e < local_109[0]) {
        uVar2 = get_tp_upgrade_status();
                    /* WARNING: Subroutine does not return */
        printk(s__FTS___d_takes_6s_tp_still_upgra_ffffffc000f956b0,0x453,uVar2);
      }
    }
  }
  lVar3 = kmalloc_order_trace(0x14000,0x8020,5);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    printk(s__FTS___d_kmalloc_failed_in_funct_ffffffc000f956e0,0x45e,__func___42773);
  }
  local_100 = 0;
  uStack_f8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  fts_read_reg(DAT_ffffffc00156bdb8,0xffffffa8,local_109);
                    /* WARNING: Subroutine does not return */
  printk(s__FTS___d_ft5x46_ctptest_show_vid_ffffffc000f95708,0x465,local_109[0]);
}



undefined8 fts_create_apk_debug_channel(long param_1)

{
  undefined8 uVar1;
  
  DAT_ffffffc00156bd28 = proc_create_data(s_ftxxxx_debug_ffffffc000f95898,0x1ff,0,&fts_proc_fops,0);
  if (DAT_ffffffc00156bd28 == 0) {
    dev_err(param_1 + 0x20,s_<<_GTP_ERROR_>>_Couldn_t_create_p_ffffffc000f99780 + 0x10);
    uVar1 = 0xfffffff4;
  }
  else {
    _dev_info(param_1 + 0x20,s_Create_proc_entry_success__ffffffc000f958a8);
    uVar1 = 0;
  }
  return uVar1;
}



void fts_release_apk_debug_channel(void)

{
  if (DAT_ffffffc00156bd28 != 0) {
    proc_remove();
  }
  return;
}



/* WARNING: Type propagation algorithm not settling */

long fts_tprwreg_store(long param_1,undefined8 param_2,void *param_3,long param_4)

{
  int iVar1;
  ulong __n;
  int local_c [2];
  undefined1 local_4;
  
  local_c[1] = 0;
  local_4 = 0;
  mutex_lock(DAT_ffffffc00156bdb0 + 0x200);
  if ((param_4 - 3U & 0xfffffffffffffffd) == 0) {
    __n = param_4 - 1;
    memcpy(local_c + 1,param_3,__n);
    strToBytes(param_3,__n & 0xffffffff,local_c + 1,local_c);
    if ((local_c[0] == 1) || (local_c[0] == 2)) {
      local_c[0] = 0;
      if (__n == 2) {
                    /* WARNING: Subroutine does not return */
        printk(s__focal__0x_02x__ffffffc000f95990,0);
      }
      iVar1 = fts_write_reg(param_1 + -0x20,0,0);
      if (iVar1 < 0) {
        dev_err(param_1,s__Focal___s___Could_not_write_the_ffffffc000f95a10,__func___42667,0);
      }
      else if ((DAT_ffffffc0012abf5a >> 2 & 1) != 0) {
        __dynamic_dev_dbg(&PTR_s_focaltech_ex_fun_ffffffc0012abf38,param_1,
                          s__Focal___s___Write_0x_02x_into_r_ffffffc000f95a48,__func___42667,0,0);
      }
    }
    else {
      local_c[0] = -1;
      dev_err(param_1,s__s_____ERROR__Could_not_convert_t_ffffffc000f95938,__func___42667,param_3);
    }
  }
  else {
    dev_err(param_1,s_please_input_2_or_4_character_ffffffc000f95918);
  }
  mutex_unlock(DAT_ffffffc00156bdb0 + 0x200);
  return param_4;
}



void fts_ctpm_hw_reset(void)

{
  tpd_gpio_output(DAT_ffffffc00156bd88,1);
  msleep(0x14);
  tpd_gpio_output(DAT_ffffffc00156bd88,0);
  msleep(0x14);
  tpd_gpio_output(DAT_ffffffc00156bd88,1);
  msleep(400);
  return;
}



undefined8 fts_create_sysfs(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(param_1 + 0x30,&DAT_ffffffc00115d910);
  if (iVar1 != 0) {
    dev_err(param_1 + 0x20,s__s_____ERROR__sysfs_create_group_ffffffc000f95a88,__func___42882);
    sysfs_remove_group(param_1 + 0x30,&DAT_ffffffc00115d910);
    return 0xfffffffb;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f95ab8,__func___42882);
}



undefined8 fts_remove_sysfs(long param_1)

{
  sysfs_remove_group(param_1 + 0x30,&DAT_ffffffc00115d910);
  return 0;
}



ulong fts_GetFirmwareSize(undefined8 param_1)

{
  ulong uVar1;
  ulong uVar2;
  char local_80 [128];
  
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x32] = '\0';
  local_80[0x33] = '\0';
  local_80[0x34] = '\0';
  local_80[0x35] = '\0';
  local_80[0x36] = '\0';
  local_80[0x37] = '\0';
  local_80[0x38] = '\0';
  local_80[0x39] = '\0';
  local_80[0x3a] = '\0';
  local_80[0x3b] = '\0';
  local_80[0x3c] = '\0';
  local_80[0x3d] = '\0';
  local_80[0x3e] = '\0';
  local_80[0x3f] = '\0';
  local_80[0x40] = '\0';
  local_80[0x41] = '\0';
  local_80[0x42] = '\0';
  local_80[0x43] = '\0';
  local_80[0x44] = '\0';
  local_80[0x45] = '\0';
  local_80[0x46] = '\0';
  local_80[0x47] = '\0';
  local_80[0x48] = '\0';
  local_80[0x49] = '\0';
  local_80[0x4a] = '\0';
  local_80[0x4b] = '\0';
  local_80[0x4c] = '\0';
  local_80[0x4d] = '\0';
  local_80[0x4e] = '\0';
  local_80[0x4f] = '\0';
  local_80[0x50] = '\0';
  local_80[0x51] = '\0';
  local_80[0x52] = '\0';
  local_80[0x53] = '\0';
  local_80[0x54] = '\0';
  local_80[0x55] = '\0';
  local_80[0x56] = '\0';
  local_80[0x57] = '\0';
  local_80[0x58] = '\0';
  local_80[0x59] = '\0';
  local_80[0x5a] = '\0';
  local_80[0x5b] = '\0';
  local_80[0x5c] = '\0';
  local_80[0x5d] = '\0';
  local_80[0x5e] = '\0';
  local_80[0x5f] = '\0';
  local_80[0x60] = '\0';
  local_80[0x61] = '\0';
  local_80[0x62] = '\0';
  local_80[99] = '\0';
  local_80[100] = '\0';
  local_80[0x65] = '\0';
  local_80[0x66] = '\0';
  local_80[0x67] = '\0';
  local_80[0x68] = '\0';
  local_80[0x69] = '\0';
  local_80[0x6a] = '\0';
  local_80[0x6b] = '\0';
  local_80[0x6c] = '\0';
  local_80[0x6d] = '\0';
  local_80[0x6e] = '\0';
  local_80[0x6f] = '\0';
  local_80[0x70] = '\0';
  local_80[0x71] = '\0';
  local_80[0x72] = '\0';
  local_80[0x73] = '\0';
  local_80[0x74] = '\0';
  local_80[0x75] = '\0';
  local_80[0x76] = '\0';
  local_80[0x77] = '\0';
  local_80[0x78] = '\0';
  local_80[0x79] = '\0';
  local_80[0x7a] = '\0';
  local_80[0x7b] = '\0';
  local_80[0x7c] = '\0';
  local_80[0x7d] = '\0';
  local_80[0x7e] = '\0';
  local_80[0x7f] = '\0';
  sprintf(local_80,s_pin__d___s____s__s_s_ffffffc000e12240 + 0x10,
          s_<branch>Internal_Dev<_branch>_ffffffc000f0c9f8 + 0x20,param_1);
  uVar1 = filp_open(local_80,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = *(ulong *)(*(long *)(*(long *)(uVar1 + 0x18) + 0x30) + 0x40);
    filp_close(uVar1,0);
    return uVar2 & 0xffffffff;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f95658,local_80);
}



undefined8 fts_ReadFirmware(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char local_80 [128];
  
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x32] = '\0';
  local_80[0x33] = '\0';
  local_80[0x34] = '\0';
  local_80[0x35] = '\0';
  local_80[0x36] = '\0';
  local_80[0x37] = '\0';
  local_80[0x38] = '\0';
  local_80[0x39] = '\0';
  local_80[0x3a] = '\0';
  local_80[0x3b] = '\0';
  local_80[0x3c] = '\0';
  local_80[0x3d] = '\0';
  local_80[0x3e] = '\0';
  local_80[0x3f] = '\0';
  local_80[0x40] = '\0';
  local_80[0x41] = '\0';
  local_80[0x42] = '\0';
  local_80[0x43] = '\0';
  local_80[0x44] = '\0';
  local_80[0x45] = '\0';
  local_80[0x46] = '\0';
  local_80[0x47] = '\0';
  local_80[0x48] = '\0';
  local_80[0x49] = '\0';
  local_80[0x4a] = '\0';
  local_80[0x4b] = '\0';
  local_80[0x4c] = '\0';
  local_80[0x4d] = '\0';
  local_80[0x4e] = '\0';
  local_80[0x4f] = '\0';
  local_80[0x50] = '\0';
  local_80[0x51] = '\0';
  local_80[0x52] = '\0';
  local_80[0x53] = '\0';
  local_80[0x54] = '\0';
  local_80[0x55] = '\0';
  local_80[0x56] = '\0';
  local_80[0x57] = '\0';
  local_80[0x58] = '\0';
  local_80[0x59] = '\0';
  local_80[0x5a] = '\0';
  local_80[0x5b] = '\0';
  local_80[0x5c] = '\0';
  local_80[0x5d] = '\0';
  local_80[0x5e] = '\0';
  local_80[0x5f] = '\0';
  local_80[0x60] = '\0';
  local_80[0x61] = '\0';
  local_80[0x62] = '\0';
  local_80[99] = '\0';
  local_80[100] = '\0';
  local_80[0x65] = '\0';
  local_80[0x66] = '\0';
  local_80[0x67] = '\0';
  local_80[0x68] = '\0';
  local_80[0x69] = '\0';
  local_80[0x6a] = '\0';
  local_80[0x6b] = '\0';
  local_80[0x6c] = '\0';
  local_80[0x6d] = '\0';
  local_80[0x6e] = '\0';
  local_80[0x6f] = '\0';
  local_80[0x70] = '\0';
  local_80[0x71] = '\0';
  local_80[0x72] = '\0';
  local_80[0x73] = '\0';
  local_80[0x74] = '\0';
  local_80[0x75] = '\0';
  local_80[0x76] = '\0';
  local_80[0x77] = '\0';
  local_80[0x78] = '\0';
  local_80[0x79] = '\0';
  local_80[0x7a] = '\0';
  local_80[0x7b] = '\0';
  local_80[0x7c] = '\0';
  local_80[0x7d] = '\0';
  local_80[0x7e] = '\0';
  local_80[0x7f] = '\0';
  sprintf(local_80,s_pin__d___s____s__s_s_ffffffc000e12240 + 0x10,
          s_<branch>Internal_Dev<_branch>_ffffffc000f0c9f8 + 0x20,param_1);
  uVar1 = filp_open(local_80,0,0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar3 = *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8);
    uVar2 = *(undefined8 *)(*(long *)(*(long *)(uVar1 + 0x18) + 0x30) + 0x40);
    *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8) = 0xffffffffffffffff
    ;
    vfs_read(uVar1,param_2,uVar2);
    filp_close(uVar1,0);
    *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8) = uVar3;
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f95658,local_80);
}



void fts_update_fw_vendor_id(long *param_1)

{
  int iVar1;
  long lVar2;
  undefined1 local_1;
  
  lVar2 = *param_1;
  local_1 = 0xa8;
  iVar1 = fts_i2c_read(lVar2,&local_1,1,(long)param_1 + 0x11f,1);
  if (-1 < iVar1) {
    return;
  }
  dev_err(lVar2 + 0x20,s_fw_vendor_id_read_failed_ffffffc000f95ce8);
  return;
}



void fts_update_fw_ver(long *param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined1 local_1;
  
  lVar3 = *param_1;
  local_1 = 0xa6;
  lVar1 = lVar3 + 0x20;
  iVar2 = fts_i2c_read(lVar3,&local_1,1,(long)param_1 + 0x11c,1);
  if (iVar2 < 0) {
    dev_err(lVar1,s_fw_major_version_read_failed_ffffffc000f95d08);
  }
  local_1 = 0xb2;
  iVar2 = fts_i2c_read(lVar3,&local_1,1,(long)param_1 + 0x11d,1);
  if (iVar2 < 0) {
    dev_err(lVar1,s_fw_minor_version_read_failed_ffffffc000f95d28);
  }
  local_1 = 0xb3;
  iVar2 = fts_i2c_read(lVar3,&local_1,1,(long)param_1 + 0x11e,1);
  if (iVar2 < 0) {
    dev_err(lVar1,s_fw_sub_minor_version_read_failed_ffffffc000f95d48);
  }
  _dev_info(lVar1,s_Firmware_version____d__d__d_ffffffc000f95d70,
            *(undefined1 *)((long)param_1 + 0x11c),*(undefined1 *)((long)param_1 + 0x11d),
            *(undefined1 *)((long)param_1 + 0x11e));
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fts_ctpm_fw_upgrade_ReadChipID_Array(undefined8 param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  int iVar5;
  uint local_18 [2];
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  *param_2 = 0;
  iVar5 = 0x1e;
  local_18[0] = 0;
  hidi2c_to_stdi2c();
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    hidi2c_to_stdi2c(param_1);
    msleep(10);
    local_10 = 0x55;
    local_f = 0xaa;
    iVar1 = fts_i2c_write(param_1,&local_10,2);
    if (-1 < iVar1) {
      msleep(10);
      local_d = 0;
      local_10 = 0x90;
      local_e = 0;
      local_f = 0;
      local_18[0] = local_18[0] & 0xffff0000;
      fts_i2c_read(param_1,&local_10,4,local_18,2);
      if ((local_18[0] & 0xff) == (uint)(byte)DAT_ffffffc00115da28) {
        lVar3 = 0;
        bVar4 = (byte)DAT_ffffffc00115da28;
LAB_ffffffc00084414c:
        _DAT_ffffffc00156bd30 = *(undefined8 *)((long)&DAT_ffffffc00115da28 + lVar3 * 0xe);
        _DAT_ffffffc00156bd38 = *(undefined4 *)((long)&DAT_ffffffc00115da30 + lVar3 * 0xe);
        DAT_ffffffc00156bd3c = (&DAT_ffffffc00115da34)[lVar3 * 7];
        *param_2 = bVar4;
        msleep(10);
        local_10 = 7;
        fts_i2c_write(param_1,&local_10,1);
        msleep(200);
        hidi2c_to_stdi2c(param_1);
        msleep(10);
        return 0;
      }
      if ((local_18[0] & 0xff) == (uint)(byte)DAT_ffffffc00115da36) {
        lVar3 = 1;
        bVar4 = (byte)DAT_ffffffc00115da36;
        goto LAB_ffffffc00084414c;
      }
      uVar2 = local_18[0] & 0xff;
      if (uVar2 == (byte)DAT_ffffffc00115da44) {
        lVar3 = 2;
        bVar4 = (byte)DAT_ffffffc00115da44;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115da52) {
        lVar3 = 3;
        bVar4 = (byte)DAT_ffffffc00115da52;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115da60) {
        lVar3 = 4;
        bVar4 = (byte)DAT_ffffffc00115da60;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115da6e) {
        lVar3 = 5;
        bVar4 = (byte)DAT_ffffffc00115da6e;
        goto LAB_ffffffc00084414c;
      }
      uVar2 = local_18[0] & 0xff;
      if (uVar2 == (byte)DAT_ffffffc00115da7c) {
        lVar3 = 6;
        bVar4 = (byte)DAT_ffffffc00115da7c;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115da8a) {
        lVar3 = 7;
        bVar4 = (byte)DAT_ffffffc00115da8a;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115da98) {
        lVar3 = 8;
        bVar4 = (byte)DAT_ffffffc00115da98;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115daa6) {
        lVar3 = 9;
        bVar4 = (byte)DAT_ffffffc00115daa6;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115dab4) {
        lVar3 = 10;
        bVar4 = (byte)DAT_ffffffc00115dab4;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115dac2) {
        lVar3 = 0xb;
        bVar4 = (byte)DAT_ffffffc00115dac2;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115dad0) {
        lVar3 = 0xc;
        bVar4 = (byte)DAT_ffffffc00115dad0;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115dade) {
        lVar3 = 0xd;
        bVar4 = (byte)DAT_ffffffc00115dade;
        goto LAB_ffffffc00084414c;
      }
      uVar2 = local_18[0] & 0xff;
      if (uVar2 == (byte)DAT_ffffffc00115daec) {
        lVar3 = 0xe;
        bVar4 = (byte)DAT_ffffffc00115daec;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115dafa) {
        lVar3 = 0xf;
        bVar4 = (byte)DAT_ffffffc00115dafa;
        goto LAB_ffffffc00084414c;
      }
      if (uVar2 == (byte)DAT_ffffffc00115db08) {
        lVar3 = 0x10;
        bVar4 = (byte)DAT_ffffffc00115db08;
        goto LAB_ffffffc00084414c;
      }
    }
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 0xfffffffb;
    }
  } while( true );
}



undefined8 fts_ctpm_fw_upgrade_ReadVendorID(undefined8 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  iVar2 = 0x1e;
  *param_2 = '\0';
  local_18 = 0;
  hidi2c_to_stdi2c();
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    hidi2c_to_stdi2c(param_1);
    msleep(10);
    local_10 = 0x55;
    local_f = 0xaa;
    iVar1 = fts_i2c_write(param_1,&local_10,2);
    if (-1 < iVar1) {
      msleep(10);
      local_d = 0;
      local_10 = 0x90;
      local_e = 0;
      local_f = 0;
      local_18 = local_18 & 0xffff0000;
      fts_i2c_read(param_1,&local_10,4,&local_18,2);
      if (((char)local_18 == DAT_ffffffc00156bd38) && (local_18._1_1_ == DAT_ffffffc00156bd39)) {
        iVar2 = 0x1e;
        msleep(10);
        local_f = 0;
        local_10 = 3;
        local_e = 0xd7;
        local_d = 0x84;
        break;
      }
    }
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return 0xfffffffb;
    }
  } while( true );
  while (*param_2 = '\0', iVar2 != 0) {
    fts_i2c_write(param_1,&local_10,4);
    msleep(5);
    local_18 = local_18 & 0xffff0000;
    fts_i2c_read(param_1,&local_10,0,&local_18,2);
    iVar2 = iVar2 + -1;
    if ((char)local_18 != '\0') {
      *param_2 = (char)local_18;
      break;
    }
  }
  msleep(0x32);
  local_10 = 7;
  fts_i2c_write(param_1,&local_10,1);
  msleep(200);
  hidi2c_to_stdi2c(param_1);
  msleep(10);
  return 0;
}



undefined8 fts_ctpm_fw_upgrade_ReadLcmColor(undefined8 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  iVar2 = 0x1e;
  *param_2 = '\0';
  local_18 = 0;
  hidi2c_to_stdi2c();
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    hidi2c_to_stdi2c(param_1);
    msleep(10);
    local_10 = 0x55;
    local_f = 0xaa;
    iVar1 = fts_i2c_write(param_1,&local_10,2);
    if (-1 < iVar1) {
      msleep(10);
      local_d = 0;
      local_10 = 0x90;
      local_e = 0;
      local_f = 0;
      local_18 = local_18 & 0xffff0000;
      fts_i2c_read(param_1,&local_10,4,&local_18,2);
      if (((char)local_18 == DAT_ffffffc00156bd38) && (local_18._1_1_ == DAT_ffffffc00156bd39)) {
        iVar2 = 0x1e;
        msleep(10);
        local_f = 0;
        local_10 = 3;
        local_e = 0xd7;
        local_d = 0x86;
        break;
      }
    }
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return 0xfffffffb;
    }
  } while( true );
  while (*param_2 = '\0', iVar2 != 0) {
    fts_i2c_write(param_1,&local_10,4);
    msleep(5);
    local_18 = local_18 & 0xffff0000;
    fts_i2c_read(param_1,&local_10,0,&local_18,2);
    iVar2 = iVar2 + -1;
    if ((char)local_18 != '\0') {
      *param_2 = (char)local_18;
      break;
    }
  }
  msleep(0x32);
  local_10 = 7;
  fts_i2c_write(param_1,&local_10,1);
  msleep(200);
  hidi2c_to_stdi2c(param_1);
  msleep(10);
  return 0;
}



undefined8 fts_ctpm_fw_upgrade_ReadProjectCode(undefined8 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 local_18;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  char local_d;
  
  iVar3 = 0x1e;
  local_18 = 0;
  hidi2c_to_stdi2c();
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    hidi2c_to_stdi2c(param_1);
    msleep(10);
    local_10 = 0x55;
    local_f = 0xaa;
    iVar2 = fts_i2c_write(param_1,&local_10,2);
    if (-1 < iVar2) {
      msleep(10);
      local_d = 0;
      local_10 = 0x90;
      local_e = 0;
      local_f = 0;
      local_18 = local_18 & 0xffff0000;
      fts_i2c_read(param_1,&local_10,4,&local_18,2);
      if (((char)local_18 == DAT_ffffffc00156bd38) && (local_18._1_1_ == DAT_ffffffc00156bd39)) {
        msleep(10);
        local_f = 0;
        local_10 = 3;
        pcVar4 = param_2;
        cVar1 = -0x60;
        break;
      }
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0xfffffffb;
    }
  } while( true );
  while (pcVar4 = pcVar4 + 1, cVar1 != -0x3f) {
    local_d = cVar1;
    cVar1 = local_d + '\x01';
    local_e = 0xd7;
    fts_i2c_read(param_1,&local_10,4,pcVar4,1);
    if (*pcVar4 == '\0') break;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f95d90,param_2);
}



void fts_get_upgrade_array(void)

{
  int iVar1;
  undefined1 local_1;
  
  local_1 = 0;
  hidi2c_to_stdi2c(DAT_ffffffc00156bda0);
  iVar1 = fts_read_reg(DAT_ffffffc00156bda0,0xffffffa3,&local_1);
  if (-1 < iVar1) {
                    /* WARNING: Subroutine does not return */
    printk(s__s_chip_id____x_ffffffc000f95dc8,__func___42671,local_1);
  }
                    /* WARNING: Subroutine does not return */
  printk(s__Focal__Touch__read_value_fail_ffffffc000f95da8);
}



undefined8 fts_ctpm_auto_clb(undefined8 param_1)

{
  char cVar1;
  byte local_1;
  
  cVar1 = 'd';
  local_1 = 0;
  msleep(200);
  fts_write_reg(param_1,0,0x40);
  msleep(100);
  fts_write_reg(param_1,2,4);
  msleep(300);
  if ((byte)(DAT_ffffffc00156bd30 - 0x11U) < 4) {
    do {
      fts_read_reg(param_1,2,&local_1);
      if ((local_1 == 0xff) || (local_1 == 2)) break;
      cVar1 = cVar1 + -1;
      msleep(0x14);
    } while (cVar1 != '\0');
  }
  else {
    do {
      fts_read_reg(param_1,0,&local_1);
      if ((local_1 >> 4 & 7) == 0) break;
      cVar1 = cVar1 + -1;
      msleep(0x14);
    } while (cVar1 != '\0');
  }
  fts_write_reg(param_1,0,0x40);
  msleep(200);
  fts_write_reg(param_1,2,5);
  msleep(300);
  fts_write_reg(param_1,0,0);
  msleep(300);
  return 0;
}



undefined8 fts_6x36_ctpm_fw_upgrade(long param_1,char *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  ulong uVar10;
  byte bVar11;
  int iVar12;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  if (((*param_2 != '\x02') || (param_3 < 0x120)) ||
     (uVar2 = (uint)(byte)param_2[0x101] + (uint)(byte)param_2[0x100] * 0x100, param_3 < uVar2)) {
    return 0xffffffff;
  }
  iVar9 = 0x1e;
  while( true ) {
    fts_write_reg(param_1,0xffffffbc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xffffffbc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    fts_i2c_write(param_1,&local_90,1);
    local_90 = 0xaa;
    fts_i2c_write(param_1,&local_90,1);
    msleep(DAT_ffffffc00156bd3a);
    local_90 = 0x90;
    local_8d = 0;
    local_8e = 0;
    local_8f = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) break;
    dev_err(param_1 + 0x20,s__FTS__Step_3__GET_CTPM_ID_FAIL_I_ffffffc000f95de0);
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) {
      return 0xfffffffb;
    }
  }
  local_90 = 0x90;
  local_8f = 0;
  iVar9 = 200;
  local_8e = 0;
  local_8d = 0;
  local_8c = 0;
  fts_i2c_write(param_1,&local_90,5);
  local_90 = 0x61;
  fts_i2c_write(param_1,&local_90,1);
  msleep(DAT_ffffffc00156bd3c);
  do {
    local_90 = 0x6a;
    local_8f = 0;
    local_8e = 0;
    local_8d = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if (((byte)local_98 == -0x50) && (local_98._1_1_ == '\x02')) break;
    msleep(0x32);
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_80 = 0xbf;
  local_7f = 0;
  bVar11 = 0;
  uVar6 = uVar2 / 0x78;
  uVar7 = 0;
  if (uVar6 != 0) {
    uVar10 = 0;
    bVar11 = 0;
    uVar8 = 0;
    do {
      local_7e = (undefined1)(uVar10 >> 8);
      iVar9 = (int)uVar10;
      local_7d = (undefined1)uVar10;
      local_7c = 0;
      local_7b = 0x78;
      pbVar4 = abStack_7a;
      do {
        bVar3 = param_2[uVar10];
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar5 = pbVar4 + 1;
        *pbVar4 = bVar3;
        bVar11 = bVar11 ^ bVar3;
        pbVar4 = pbVar5;
      } while (pbVar5 != abStack_2);
      iVar12 = 0x1e;
      fts_i2c_write(param_1,&local_80,0x7e);
      do {
        local_90 = 0x6a;
        local_8f = 0;
        local_8e = 0;
        local_8d = 0;
        local_98 = 0;
        fts_i2c_read(param_1,&local_90,4,&local_98,2);
        if ((((byte)local_98 & 0xf0) == 0xb0) &&
           ((int)uVar8 + (int)(uVar8 / 0xffd) * -0xffd + 3U ==
            (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
        msleep(1);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      uVar1 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar1;
      uVar10 = (ulong)(iVar9 + 0x78);
      uVar7 = uVar6;
    } while (uVar1 != uVar6);
  }
  uVar2 = uVar2 % 0x78;
  if (uVar2 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar2;
    uVar6 = uVar6 * 0x78;
    local_7d = (undefined1)uVar6;
    local_7e = (undefined1)(uVar6 >> 8);
    uVar1 = uVar6 + uVar2;
    pbVar4 = abStack_7a;
    do {
      bVar3 = param_2[uVar6];
      uVar6 = uVar6 + 1;
      *pbVar4 = bVar3;
      bVar11 = bVar11 ^ bVar3;
      pbVar4 = pbVar4 + 1;
    } while (uVar6 != uVar1);
    iVar9 = 0x1e;
    fts_i2c_write(param_1,&local_80,uVar2 + 6);
    do {
      local_90 = 0x6a;
      local_8f = 0;
      local_8e = 0;
      local_8d = 0;
      local_98 = 0;
      fts_i2c_read(param_1,&local_90,4,&local_98,2);
      if ((((byte)local_98 & 0xf0) == 0xb0) &&
         (uVar7 + 3 == (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
      msleep(1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 != bVar11) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar11
           );
    return 0xfffffffb;
  }
  local_90 = 7;
  fts_i2c_write(param_1,&local_90,1);
  msleep(300);
  return 0;
}



undefined8 fts_6336GU_ctpm_fw_upgrade(long param_1,char *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  ulong uVar10;
  byte bVar11;
  int iVar12;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  if (((*param_2 != '\x02') || (param_3 < 0x120)) ||
     (uVar2 = (uint)(byte)param_2[0x101] + (uint)(byte)param_2[0x100] * 0x100, param_3 < uVar2)) {
    return 0xffffffff;
  }
  iVar9 = 0x1e;
  while( true ) {
    fts_write_reg(param_1,0xffffffbc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xffffffbc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    fts_i2c_write(param_1,&local_90,1);
    local_90 = 0xaa;
    fts_i2c_write(param_1,&local_90,1);
    msleep(DAT_ffffffc00156bd3a);
    local_90 = 0x90;
    local_8d = 0;
    local_8e = 0;
    local_8f = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) break;
    dev_err(param_1 + 0x20,s__FTS__Step_3__GET_CTPM_ID_FAIL_I_ffffffc000f95de0);
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) {
      return 0xfffffffb;
    }
  }
  local_90 = 0x90;
  local_8f = 0;
  iVar9 = 200;
  local_8e = 0;
  local_8d = 0;
  local_8c = 0;
  fts_i2c_write(param_1,&local_90,5);
  local_90 = 0x61;
  fts_i2c_write(param_1,&local_90,1);
  msleep(DAT_ffffffc00156bd3c);
  do {
    local_90 = 0x6a;
    local_8f = 0;
    local_8e = 0;
    local_8d = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if (((byte)local_98 == -0x50) && (local_98._1_1_ == '\x02')) break;
    msleep(0x32);
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_80 = 0xbf;
  local_7f = 0;
  bVar11 = 0;
  uVar6 = uVar2 / 0x78;
  uVar7 = 0;
  if (uVar6 != 0) {
    uVar10 = 0;
    bVar11 = 0;
    uVar8 = 0;
    do {
      local_7e = (undefined1)(uVar10 >> 8);
      iVar9 = (int)uVar10;
      local_7d = (undefined1)uVar10;
      local_7c = 0;
      local_7b = 0x78;
      pbVar4 = abStack_7a;
      do {
        bVar3 = param_2[uVar10];
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar5 = pbVar4 + 1;
        *pbVar4 = bVar3;
        bVar11 = bVar11 ^ bVar3;
        pbVar4 = pbVar5;
      } while (pbVar5 != abStack_2);
      iVar12 = 0x1e;
      fts_i2c_write(param_1,&local_80,0x7e);
      do {
        local_90 = 0x6a;
        local_8f = 0;
        local_8e = 0;
        local_8d = 0;
        local_98 = 0;
        fts_i2c_read(param_1,&local_90,4,&local_98,2);
        if ((((byte)local_98 & 0xf0) == 0xb0) &&
           ((int)uVar8 + (int)(uVar8 / 0xffd) * -0xffd + 3U ==
            (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
        msleep(1);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      uVar1 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar1;
      uVar10 = (ulong)(iVar9 + 0x78);
      uVar7 = uVar6;
    } while (uVar1 != uVar6);
  }
  uVar2 = uVar2 % 0x78;
  if (uVar2 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar2;
    uVar6 = uVar6 * 0x78;
    local_7d = (undefined1)uVar6;
    local_7e = (undefined1)(uVar6 >> 8);
    uVar1 = uVar6 + uVar2;
    pbVar4 = abStack_7a;
    do {
      bVar3 = param_2[uVar6];
      uVar6 = uVar6 + 1;
      *pbVar4 = bVar3;
      bVar11 = bVar11 ^ bVar3;
      pbVar4 = pbVar4 + 1;
    } while (uVar6 != uVar1);
    iVar9 = 0x1e;
    fts_i2c_write(param_1,&local_80,uVar2 + 6);
    do {
      local_90 = 0x6a;
      local_8f = 0;
      local_8e = 0;
      local_8d = 0;
      local_98 = 0;
      fts_i2c_read(param_1,&local_90,4,&local_98,2);
      if ((((byte)local_98 & 0xf0) == 0xb0) &&
         (uVar7 + 3 == (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
      msleep(1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 != bVar11) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar11
           );
    return 0xfffffffb;
  }
  local_90 = 7;
  fts_i2c_write(param_1,&local_90,1);
  msleep(300);
  return 0;
}



undefined8 fts_6x06_ctpm_fw_upgrade(long param_1,long param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  char local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte local_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  uVar9 = 0;
  do {
    fts_write_reg(param_1,0xffffffbc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xffffffbc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    local_8f = 0xaa;
    do {
      uVar10 = uVar9;
      uVar9 = uVar10 + 1;
      iVar5 = fts_i2c_write(param_1,&local_90,2);
      msleep(5);
    } while (uVar9 < 5 && iVar5 < 1);
    msleep(DAT_ffffffc00156bd3a);
    local_8d = 0;
    local_90 = 0x90;
    local_8e = 0;
    local_8f = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) break;
    uVar9 = uVar10 + 2;
    dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_FAIL_ID1___ffffffc000f95e40);
  } while (uVar9 < 0x1e);
  if (0x1e < uVar9) {
    return 0xfffffffb;
  }
  local_90 = 0xcd;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  uVar10 = param_3 - 8;
  local_90 = 0x61;
  fts_i2c_write(param_1,&local_90,1);
  msleep(DAT_ffffffc00156bd3c);
  local_90 = 99;
  fts_i2c_write(param_1,&local_90,1);
  msleep(100);
  local_7f = 0;
  local_80 = 0xbf;
  uVar9 = uVar10 / 0x78;
  if (uVar9 == 0) {
    bVar8 = 0;
  }
  else {
    uVar11 = 0;
    bVar8 = 0;
    do {
      local_7e = (undefined1)(uVar11 >> 8);
      iVar5 = (int)uVar11;
      local_7d = (char)uVar11;
      local_7c = 0;
      local_7b = 0x78;
      pbVar7 = local_7a;
      do {
        bVar3 = *(byte *)(param_2 + uVar11);
        uVar11 = (ulong)((int)uVar11 + 1);
        pbVar6 = pbVar7 + 1;
        *pbVar7 = bVar3;
        bVar8 = bVar8 ^ bVar3;
        pbVar7 = pbVar6;
      } while (pbVar6 != abStack_2);
      uVar1 = iVar5 + 0x78;
      uVar11 = (ulong)uVar1;
      fts_i2c_write(param_1,&local_80,0x7e);
      msleep(0x15);
    } while (uVar1 != uVar9 * 0x78);
  }
  uVar1 = uVar10 % 0x78;
  if (uVar1 != 0) {
    local_7c = 0;
    uVar9 = uVar9 * 0x78;
    local_7b = (undefined1)uVar1;
    local_7d = (char)uVar9;
    local_7e = (undefined1)(uVar9 >> 8);
    uVar2 = uVar9 + uVar1;
    pbVar7 = local_7a;
    do {
      bVar3 = *(byte *)(param_2 + (ulong)uVar9);
      uVar9 = uVar9 + 1;
      *pbVar7 = bVar3;
      bVar8 = bVar8 ^ bVar3;
      pbVar7 = pbVar7 + 1;
    } while (uVar9 != uVar2);
    fts_i2c_write(param_1,&local_80,uVar1 + 6);
    msleep(0x14);
  }
  cVar4 = -6;
  do {
    local_7d = cVar4;
    local_7a[0] = *(byte *)(param_2 + (ulong)uVar10);
    cVar4 = local_7d + '\x01';
    bVar8 = bVar8 ^ local_7a[0];
    local_7e = 0x6f;
    local_7c = 0;
    uVar10 = uVar10 + 1;
    local_7b = 1;
    fts_i2c_write(param_1,&local_80,7);
    msleep(0x14);
  } while (cVar4 != '\0');
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 == bVar8) {
    local_90 = 7;
    fts_i2c_write(param_1,&local_90,1);
    msleep(300);
    return 0;
  }
  dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar8);
  return 0xfffffffb;
}



undefined8 fts_5x26_ctpm_fw_upgrade(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  ulong uVar9;
  undefined4 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  iVar8 = 0x1e;
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    local_8f = 0xaa;
    iVar3 = fts_i2c_write(param_1,&local_90,2);
    if (-1 < iVar3) {
      local_90 = 0x90;
      local_8d = 0;
      local_8e = 0;
      local_8f = 0;
      local_98 = local_98 & 0xffff0000;
      fts_i2c_read(param_1,&local_90,4,&local_98,2);
      if ((DAT_ffffffc00156bd38 == (char)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) {
        local_90 = 0x61;
        fts_i2c_write(param_1,&local_90,1);
        local_90 = 99;
        fts_i2c_write(param_1,&local_90,1);
        local_90 = 4;
        fts_i2c_write(param_1,&local_90,1);
        msleep(DAT_ffffffc00156bd3c);
        local_7f = 0;
        uVar6 = param_3 / 0x78;
        local_80 = 0xbf;
        if (uVar6 == 0) {
          bVar7 = 0;
        }
        else {
          uVar9 = 0;
          bVar7 = 0;
          do {
            local_7e = (undefined1)(uVar9 >> 8);
            iVar8 = (int)uVar9;
            local_7d = (undefined1)uVar9;
            local_7c = 0;
            local_7b = 0x78;
            pbVar5 = abStack_7a;
            do {
              bVar2 = *(byte *)(param_2 + uVar9);
              uVar9 = (ulong)((int)uVar9 + 1);
              pbVar4 = pbVar5 + 1;
              *pbVar5 = bVar2;
              bVar7 = bVar7 ^ bVar2;
              pbVar5 = pbVar4;
            } while (pbVar4 != abStack_2);
            uVar1 = iVar8 + 0x78;
            uVar9 = (ulong)uVar1;
            fts_i2c_write(param_1,&local_80,0x7e);
            msleep(0x15);
          } while (uVar1 != uVar6 * 0x78);
        }
        param_3 = param_3 % 0x78;
        if (param_3 != 0) {
          uVar6 = uVar6 * 0x78;
          local_7d = (undefined1)uVar6;
          local_7c = 0;
          local_7e = (undefined1)(uVar6 >> 8);
          local_7b = (undefined1)param_3;
          uVar1 = uVar6 + param_3;
          pbVar5 = abStack_7a;
          do {
            bVar2 = *(byte *)(param_2 + (ulong)uVar6);
            uVar6 = uVar6 + 1;
            *pbVar5 = bVar2;
            bVar7 = bVar7 ^ bVar2;
            pbVar5 = pbVar5 + 1;
          } while (uVar6 != uVar1);
          fts_i2c_write(param_1,&local_80,param_3 + 6);
          msleep(0x14);
        }
        local_90 = 0xcc;
        local_98 = local_98 & 0xffff0000;
        fts_i2c_read(param_1,&local_90,1,&local_98,1);
                    /* WARNING: Subroutine does not return */
        printk(&DAT_ffffffc000f95ea8,(char)local_98,bVar7);
      }
      dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78);
    }
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return 0xfffffffb;
    }
  } while( true );
}



undefined8 fts_5x36_ctpm_fw_upgrade(long param_1,long param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte local_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  iVar12 = 0x1e;
  bVar5 = *(char *)(DAT_ffffffc00156bd40 + DAT_ffffffc00115db18 + -0xc) == '\x1e';
  while( true ) {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    local_8f = 0xaa;
    fts_i2c_write(param_1,&local_90,2);
    msleep(DAT_ffffffc00156bd3a);
    local_8d = 0;
    local_90 = 0x90;
    local_8e = 0;
    local_8f = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (local_98._1_1_ == DAT_ffffffc00156bd39)) break;
    dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_FAILD_ID1___ffffffc000f95ef8,(byte)local_98,
            local_98._1_1_);
    iVar12 = iVar12 + -1;
    if (iVar12 == 0) {
      return 0xfffffffb;
    }
  }
  if ((DAT_ffffffc0012abf82 >> 2 & 1) != 0) {
    __dynamic_dev_dbg(&PTR_s_focaltech_flash_ffffffc0012abf60,param_1 + 0x20,
                      s__FTS__Step_3__CTPM_ID_OK_ID1___0_ffffffc000f95ec8);
  }
  local_90 = 0xcd;
  iVar12 = 0;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if (4 < (byte)local_98) {
    if ((byte)local_98 == 7) {
      iVar12 = 1;
    }
    else {
      iVar12 = 0;
      if (0xe < (byte)local_98) {
        iVar12 = 2;
      }
    }
  }
  if (bVar5) {
    local_90 = 0x61;
    fts_i2c_write(param_1,&local_90,1);
    msleep(DAT_ffffffc00156bd3c);
    local_90 = 99;
    fts_i2c_write(param_1,&local_90,1);
    msleep(0x32);
  }
  else {
    local_90 = 0x61;
    fts_i2c_write(param_1,&local_90,1);
    msleep(DAT_ffffffc00156bd3c);
  }
  if (iVar12 == 2) {
    uVar11 = param_3 - 0xe;
  }
  else {
    uVar11 = param_3 - 8;
  }
  local_80 = 0xbf;
  local_7f = 0;
  uVar9 = uVar11 / 0x78;
  if (uVar9 == 0) {
    bVar13 = 0;
  }
  else {
    uVar10 = 0;
    bVar13 = 0;
    do {
      local_7e = (undefined1)(uVar10 >> 8);
      iVar8 = (int)uVar10;
      local_7d = (undefined1)uVar10;
      local_7c = 0;
      local_7b = 0x78;
      pbVar6 = local_7a;
      do {
        bVar3 = *(byte *)(param_2 + uVar10);
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar7 = pbVar6 + 1;
        *pbVar6 = bVar3;
        bVar13 = bVar13 ^ bVar3;
        pbVar6 = pbVar7;
      } while (pbVar7 != abStack_2);
      uVar1 = iVar8 + 0x78;
      uVar10 = (ulong)uVar1;
      fts_i2c_write(param_1,&local_80,0x7e);
      msleep(0x15);
    } while (uVar1 != uVar9 * 0x78);
  }
  uVar1 = uVar11 % 0x78;
  if (uVar1 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar1;
    uVar9 = uVar9 * 0x78;
    local_7d = (undefined1)uVar9;
    local_7e = (undefined1)(uVar9 >> 8);
    uVar2 = uVar9 + uVar1;
    pbVar6 = local_7a;
    do {
      bVar3 = *(byte *)(param_2 + (ulong)uVar9);
      uVar9 = uVar9 + 1;
      *pbVar6 = bVar3;
      bVar13 = bVar13 ^ bVar3;
      pbVar6 = pbVar6 + 1;
    } while (uVar9 != uVar2);
    fts_i2c_write(param_1,&local_80,uVar1 + 6);
    msleep(0x14);
  }
  if (iVar12 == 2) {
    iVar12 = 0x7ff4;
    do {
      iVar8 = iVar12 + -0x400;
      if (bVar5) {
        iVar8 = iVar12;
      }
      local_7a[0] = *(byte *)(param_2 + (ulong)((uVar11 - 0x7ff4) + iVar12));
      local_7e = (undefined1)((uint)iVar8 >> 8);
      bVar13 = bVar13 ^ local_7a[0];
      iVar12 = iVar12 + 1;
      local_7d = (undefined1)iVar8;
      local_7c = 0;
      local_7b = 1;
      fts_i2c_write(param_1,&local_80,7);
      msleep(10);
    } while (iVar12 != 0x8000);
  }
  else {
    iVar8 = 0x7bfa;
    do {
      iVar4 = iVar8 + -0xc00;
      if (iVar12 == 1) {
        iVar4 = iVar8;
      }
      local_7e = (undefined1)((uint)iVar4 >> 8);
      local_7d = (undefined1)iVar4;
      local_7a[0] = *(byte *)(param_2 + (ulong)((uVar11 - 0x7bfa) + iVar8));
      iVar8 = iVar8 + 1;
      bVar13 = bVar13 ^ local_7a[0];
      local_7c = 0;
      local_7b = 1;
      fts_i2c_write(param_1,&local_80,7);
      msleep(10);
    } while (iVar8 != 0x7c00);
  }
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 == bVar13) {
    local_90 = 7;
    fts_i2c_write(param_1,&local_90,1);
    msleep(300);
    return 0;
  }
  dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar13);
  return 0xfffffffb;
}



undefined8 fts_5822_ctpm_fw_upgrade(long param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  
  local_98 = 0;
  iVar4 = 0x1e;
  hidi2c_to_stdi2c();
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    hidi2c_to_stdi2c(param_1);
    msleep(5);
    local_90 = 0x55;
    local_8f = 0xaa;
    iVar2 = fts_i2c_write(param_1,&local_90,2);
    if (-1 < iVar2) {
      msleep(1);
      local_8d = 0;
      local_90 = 0x90;
      local_8e = 0;
      local_8f = 0;
      local_98 = local_98 & 0xffff0000;
      fts_i2c_read(param_1,&local_90,4,&local_98,2);
      if ((DAT_ffffffc00156bd38 == (char)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) {
        local_90 = 0x61;
        iVar4 = 0xf;
        fts_i2c_write(param_1,&local_90,1);
        msleep(0x546);
        break;
      }
      dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78);
    }
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return 0xfffffffb;
    }
  } while( true );
LAB_ffffffc000846208:
  local_90 = 0x6a;
  local_98 = local_98 & 0xffff0000;
  fts_i2c_read(param_1,&local_90,1,&local_98,2);
  if (((char)local_98 == -0x10) && (local_98._1_1_ == -0x56)) {
    uVar3 = 0xf0;
    uVar1 = 0xaa;
    goto LAB_ffffffc000846250;
  }
  msleep(0x32);
  iVar4 = iVar4 + -1;
  if (iVar4 == 0) {
    uVar1 = local_98._1_1_;
    uVar3 = (char)local_98;
LAB_ffffffc000846250:
                    /* WARNING: Subroutine does not return */
    printk(s__FTS___s__erase_app_area_reg_val_ffffffc000f95f30,__func___42880,uVar3,uVar1);
  }
  goto LAB_ffffffc000846208;
}



undefined8 fts_5x06_ctpm_fw_upgrade(long param_1,long param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  char local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte local_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  uVar9 = 0;
  while( true ) {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    local_8f = 0xaa;
    do {
      uVar10 = uVar9;
      uVar9 = uVar10 + 1;
      iVar5 = fts_i2c_write(param_1,&local_90,2);
      msleep(5);
    } while (uVar9 < 5 && iVar5 < 1);
    msleep(DAT_ffffffc00156bd3a);
    local_8d = 0;
    local_90 = 0x90;
    local_8e = 0;
    local_8f = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) break;
    uVar9 = uVar10 + 2;
    dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_FAIL_ID1___ffffffc000f95e40);
    if (0x1d < uVar9) {
      return 0xfffffffb;
    }
  }
  if (0x1d < uVar9) {
    return 0xfffffffb;
  }
  local_90 = 0x61;
  uVar10 = param_3 - 8;
  fts_i2c_write(param_1,&local_90,1);
  msleep(DAT_ffffffc00156bd3c);
  local_90 = 99;
  fts_i2c_write(param_1,&local_90,1);
  msleep(100);
  local_7f = 0;
  local_80 = 0xbf;
  uVar9 = uVar10 / 0x78;
  if (uVar9 == 0) {
    bVar8 = 0;
  }
  else {
    uVar11 = 0;
    bVar8 = 0;
    do {
      local_7e = (undefined1)(uVar11 >> 8);
      iVar5 = (int)uVar11;
      local_7d = (char)uVar11;
      local_7c = 0;
      local_7b = 0x78;
      pbVar7 = local_7a;
      do {
        bVar3 = *(byte *)(param_2 + uVar11);
        uVar11 = (ulong)((int)uVar11 + 1);
        pbVar6 = pbVar7 + 1;
        *pbVar7 = bVar3;
        bVar8 = bVar8 ^ bVar3;
        pbVar7 = pbVar6;
      } while (pbVar6 != abStack_2);
      uVar1 = iVar5 + 0x78;
      uVar11 = (ulong)uVar1;
      fts_i2c_write(param_1,&local_80,0x7e);
      msleep(0x15);
    } while (uVar1 != uVar9 * 0x78);
  }
  uVar1 = uVar10 % 0x78;
  if (uVar1 != 0) {
    local_7c = 0;
    uVar9 = uVar9 * 0x78;
    local_7b = (undefined1)uVar1;
    local_7d = (char)uVar9;
    local_7e = (undefined1)(uVar9 >> 8);
    uVar2 = uVar9 + uVar1;
    pbVar7 = local_7a;
    do {
      bVar3 = *(byte *)(param_2 + (ulong)uVar9);
      uVar9 = uVar9 + 1;
      *pbVar7 = bVar3;
      bVar8 = bVar8 ^ bVar3;
      pbVar7 = pbVar7 + 1;
    } while (uVar9 != uVar2);
    fts_i2c_write(param_1,&local_80,uVar1 + 6);
    msleep(0x14);
  }
  cVar4 = -6;
  do {
    local_7d = cVar4;
    local_7a[0] = *(byte *)(param_2 + (ulong)uVar10);
    cVar4 = local_7d + '\x01';
    bVar8 = bVar8 ^ local_7a[0];
    local_7e = 0x6f;
    local_7c = 0;
    uVar10 = uVar10 + 1;
    local_7b = 1;
    fts_i2c_write(param_1,&local_80,7);
    msleep(0x14);
  } while (cVar4 != '\0');
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 != bVar8) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar8)
    ;
    return 0xfffffffb;
  }
  local_90 = 7;
  fts_i2c_write(param_1,&local_90,1);
  msleep(300);
  return 0;
}



undefined8 fts_5x46_ctpm_fw_upgrade(long param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  
  local_98 = 0;
  iVar1 = hidi2c_to_stdi2c();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f96030);
  }
  iVar1 = 0x1e;
  do {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xfffffffc,0x55);
    msleep(200);
    iVar2 = hidi2c_to_stdi2c(param_1);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      printk(&DAT_ffffffc000f96030);
    }
    msleep(10);
    local_90 = 0x55;
    local_8f = 0xaa;
    iVar2 = fts_i2c_write(param_1,&local_90,2);
    if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
      printk(&DAT_ffffffc000f96060);
    }
    msleep(1);
    local_8d = 0;
    local_90 = 0x90;
    local_8e = 0;
    local_8f = 0;
    local_98 = local_98 & 0xffff0000;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((uint)DAT_ffffffc00156bd38 == (local_98 & 0xff)) {
      if (local_98._1_1_ == DAT_ffffffc00156bd39) {
                    /* WARNING: Subroutine does not return */
        printk(&DAT_ffffffc000f96098,(uint)DAT_ffffffc00156bd38,local_98._1_1_);
      }
    }
    dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78,(undefined1)local_98)
    ;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0xfffffffb;
}



undefined8 fts_8606_writepram(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  undefined4 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  if (param_3 - 1 < 0x10000) {
    iVar9 = 0x14;
    do {
      fts_write_reg(param_1,0xfffffffc,0xffffffaa);
      msleep(DAT_ffffffc00156bd34);
      fts_write_reg(param_1,0xfffffffc,0x55);
      msleep(200);
      local_90 = 0x55;
      iVar3 = fts_i2c_write(param_1,&local_90,1);
      if (-1 < iVar3) {
        msleep(1);
        local_8d = 0;
        local_90 = 0x90;
        local_8e = 0;
        local_8f = 0;
        local_98 = local_98 & 0xffff0000;
        fts_i2c_read(param_1,&local_90,4,&local_98,2);
        if (((char)local_98 == -0x7a) && ((byte)(local_98._1_1_ - 6U) < 2)) {
          msleep(0x32,s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78);
          break;
        }
        dev_err(param_1 + 0x20);
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    local_80 = 0xae;
    local_7f = 0;
    uVar8 = param_3 / 0x78;
    if (uVar8 == 0) {
      uVar7 = 0;
    }
    else {
      uVar10 = 0;
      uVar7 = 0;
      do {
        local_7e = (undefined1)(uVar10 >> 8);
        iVar9 = (int)uVar10;
        local_7d = (undefined1)uVar10;
        local_7c = 0;
        local_7b = 0x78;
        pbVar5 = abStack_7a;
        do {
          bVar2 = *(byte *)(param_2 + uVar10);
          uVar10 = (ulong)((int)uVar10 + 1);
          pbVar6 = pbVar5 + 1;
          *pbVar5 = bVar2;
          uVar7 = uVar7 ^ bVar2;
          pbVar5 = pbVar6;
        } while (pbVar6 != abStack_2);
        uVar1 = iVar9 + 0x78;
        uVar10 = (ulong)uVar1;
        fts_i2c_write(param_1,&local_80,0x7e);
      } while (uVar1 != uVar8 * 0x78);
    }
    param_3 = param_3 % 0x78;
    if (param_3 != 0) {
      uVar8 = uVar8 * 0x78;
      local_7c = 0;
      local_7d = (undefined1)uVar8;
      local_7e = (undefined1)(uVar8 >> 8);
      local_7b = (undefined1)param_3;
      uVar1 = uVar8 + param_3;
      pbVar5 = abStack_7a;
      do {
        bVar2 = *(byte *)(param_2 + (ulong)uVar8);
        uVar8 = uVar8 + 1;
        *pbVar5 = bVar2;
        uVar7 = uVar7 ^ bVar2;
        pbVar5 = pbVar5 + 1;
      } while (uVar8 != uVar1);
      fts_i2c_write(param_1,&local_80,param_3 + 6);
    }
    local_90 = 0xcc;
    fts_i2c_read(param_1,&local_90,1,&local_98,1);
    if ((local_98 & 0xff) != uVar7) {
      dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(char)local_98,
              uVar7);
      return 0xfffffffb;
    }
    msleep(0x32);
    local_90 = 8;
    fts_i2c_write(param_1,&local_90,1);
    msleep(0x14);
    uVar4 = 0;
  }
  else {
    uVar4 = 0xfffffffb;
  }
  return uVar4;
}



undefined8 fts_8606_ctpm_fw_upgrade(long param_1,long param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_b8;
  uint local_b0 [2];
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_b8 = 0;
  local_b0[0] = 0;
  local_a8 = 5;
  fts_i2c_read(param_1,&local_a8,1,local_b0,1);
  if (param_3 == 0) {
    return 0xfffffffb;
  }
  if ((local_b0[0] & 0xff) == 0x81) {
    if (0xf000 < param_3) {
      return 0xfffffffb;
    }
  }
  else if ((0x10000 < param_3) && ((local_b0[0] & 0xff) == 0x80)) {
    return 0xfffffffb;
  }
  iVar6 = 0x1e;
  do {
    msleep(10);
    local_a8 = 0x55;
    local_a7 = 0xaa;
    iVar2 = fts_i2c_write(param_1,&local_a8,2);
    if (-1 < iVar2) {
      msleep(1);
      local_a5 = 0;
      local_a8 = 0x90;
      local_a6 = 0;
      local_a7 = 0;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,4,&local_b8,2);
      if (((DAT_ffffffc00156bd38 == (char)local_b8) && (DAT_ffffffc00156bd39 == local_b8._1_1_)) ||
         (((char)local_b8 == -0x7a && (local_b8._1_1_ == -0x5a)))) {
        local_97 = (undefined1)local_b0[0];
        local_96 = 0;
        iVar6 = 0xf;
        local_98 = 5;
        fts_i2c_write(param_1,&local_98,3);
        local_98 = 9;
        local_97 = 0xb;
        fts_i2c_write(param_1,&local_98,2);
        msleep(0x32);
        local_a8 = 0x61;
        fts_i2c_write(param_1,&local_a8,1);
        msleep(0x546);
        break;
      }
      dev_err(param_1 + 0x20,s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78,(char)local_b8,
              local_b8._1_1_);
    }
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return 0xfffffffb;
    }
  } while( true );
  while( true ) {
    msleep(0x32);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
    local_a8 = 0x6a;
    local_b8 = local_b8 & 0xffff0000;
    fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
    if (((char)local_b8 == -0x10) && (local_b8._1_1_ == -0x56)) break;
  }
  local_80 = 0xbf;
  uVar10 = 0;
  uVar5 = param_3 / 0x78;
  uVar8 = 0;
  if (uVar5 != 0) {
    uVar7 = 0x1000;
    uVar9 = 0;
    uVar10 = 0;
    do {
      local_7f = (undefined1)(uVar9 + 0x1000 >> 0x10);
      local_7e = (undefined1)(uVar9 + 0x1000 >> 8);
      local_7d = (undefined1)uVar9;
      local_7c = 0;
      local_7b = 0x78;
      pbVar3 = abStack_7a;
      uVar8 = uVar9;
      do {
        bVar1 = *(byte *)(param_2 + (ulong)uVar8);
        uVar8 = uVar8 + 1;
        pbVar4 = pbVar3 + 1;
        *pbVar3 = bVar1;
        uVar10 = uVar10 ^ bVar1;
        pbVar3 = pbVar4;
      } while (pbVar4 != abStack_2);
      iVar6 = 0x1e;
      fts_i2c_write(param_1,&local_80,0x7e);
      do {
        local_a8 = 0x6a;
        local_b8 = local_b8 & 0xffff0000;
        fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
        if (uVar7 == CONCAT11((char)local_b8,local_b8._1_1_)) break;
        msleep(1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      uVar7 = uVar7 + 1;
      uVar9 = uVar9 + 0x78;
      uVar8 = uVar5;
    } while (uVar7 != uVar5 + 0x1000);
  }
  uVar7 = param_3 % 0x78;
  if (uVar7 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar7;
    uVar5 = uVar5 * 0x78;
    iVar6 = uVar5 + 0x1000;
    local_7d = (undefined1)iVar6;
    local_7f = (undefined1)((uint)iVar6 >> 0x10);
    local_7e = (undefined1)((uint)iVar6 >> 8);
    uVar9 = uVar5 + uVar7;
    pbVar3 = abStack_7a;
    do {
      bVar1 = *(byte *)(param_2 + (ulong)uVar5);
      uVar5 = uVar5 + 1;
      *pbVar3 = bVar1;
      uVar10 = uVar10 ^ bVar1;
      pbVar3 = pbVar3 + 1;
    } while (uVar5 != uVar9);
    iVar6 = 0x1e;
    fts_i2c_write(param_1,&local_80,uVar7 + 6);
    do {
      local_a8 = 0x6a;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
      if ((uint)CONCAT11((char)local_b8,local_b8._1_1_) == uVar8 + 0x1000) break;
      msleep(1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = 100;
  msleep(0x32);
  local_a8 = 100;
  fts_i2c_write(param_1,&local_a8,1);
  msleep(300);
  local_a7 = 0;
  local_a8 = 0x65;
  uVar5 = param_3;
  if (0xfffe < param_3) {
    uVar5 = 0xfffe;
  }
  local_a4 = (undefined1)(uVar5 >> 8);
  local_a5 = 0;
  local_a6 = 0x10;
  local_a3 = (undefined1)uVar5;
  fts_i2c_write(param_1,&local_a8,6);
  msleep(param_3 >> 8);
  do {
    local_a8 = 0x6a;
    local_b8 = local_b8 & 0xffff0000;
    fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
    if (((char)local_b8 == -0x10) && (local_b8._1_1_ == 'U')) break;
    msleep(1);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (0xfffe < param_3) {
    local_a8 = 0x65;
    local_a6 = 0xff;
    local_a7 = 0;
    local_a5 = 0xfe;
    iVar6 = 100;
    local_a4 = (undefined1)(param_3 - 0xfffe >> 8);
    local_a3 = (undefined1)(param_3 - 0xfffe);
    fts_i2c_write(param_1,&local_a8,6);
    msleep(param_3 >> 8);
    do {
      local_a8 = 0x6a;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
      if (((char)local_b8 == -0x10) && (local_b8._1_1_ == 'U')) break;
      msleep(1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  local_a8 = 0x66;
  fts_i2c_read(param_1,&local_a8,1,&local_b8,1);
  if ((local_b8 & 0xff) != uVar10) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(char)local_b8,uVar10
           );
    return 0xfffffffb;
  }
  local_a8 = 7;
  fts_i2c_write(param_1,&local_a8,1);
  msleep(200);
  return 0;
}



void fts_8716_writepram(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f96218,__func___43061,0xa83,param_3);
}



undefined8 fts_8716_ctpm_fw_upgrade(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_b8;
  uint local_b0 [2];
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_b8 = 0;
  local_b0[0] = 0;
  hidi2c_to_stdi2c();
  local_b0[0] = local_b0[0] & 0xffffff00;
  local_a8 = 5;
  fts_i2c_read(param_1,&local_a8,1,local_b0,1);
  if (param_3 == 0) {
    return 0xfffffffb;
  }
  if ((local_b0[0] & 0xff) == 0x81) {
    if (0xf000 < param_3) {
      return 0xfffffffb;
    }
  }
  else if ((0x10000 < param_3) && ((local_b0[0] & 0xff) == 0x80)) {
    return 0xfffffffb;
  }
  iVar7 = 0x1e;
  do {
    msleep(10);
    local_a8 = 0x55;
    local_a7 = 0xaa;
    iVar3 = fts_i2c_write(param_1,&local_a8,2);
    if (-1 < iVar3) {
      msleep(1);
      local_a5 = 0;
      local_a8 = 0x90;
      local_a6 = 0;
      local_a7 = 0;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,4,&local_b8,2);
      if ((DAT_ffffffc00156bd38 == (char)local_b8) && (DAT_ffffffc00156bd39 == local_b8._1_1_)) {
        local_97 = (undefined1)local_b0[0];
        local_96 = 0;
        iVar7 = 0xf;
        local_98 = 5;
        fts_i2c_write(param_1,&local_98,3);
        local_98 = 9;
        local_97 = 0xb;
        fts_i2c_write(param_1,&local_98,2);
        msleep(0x32);
        local_a8 = 0x61;
        fts_i2c_write(param_1,&local_a8,1);
        msleep(0x546);
        break;
      }
      dev_err(param_1 + 0x20,s__FTS__Step_3__READ_FAIL_CTPM_ID__ffffffc000f96278);
    }
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      return 0xfffffffb;
    }
  } while( true );
  while( true ) {
    msleep(0x32);
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) break;
    local_a8 = 0x6a;
    local_b8 = local_b8 & 0xffff0000;
    fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
    if (((char)local_b8 == -0x10) && (local_b8._1_1_ == -0x56)) break;
  }
  local_80 = 0xbf;
  uVar9 = 0;
  iVar7 = (int)((ulong)param_3 / 0x78);
  iVar3 = 0;
  if ((ulong)param_3 / 0x78 != 0) {
    uVar6 = 0x1022;
    uVar8 = 0;
    uVar9 = 0;
    do {
      local_7f = (undefined1)(uVar8 + 0x1000 >> 0x10);
      local_7e = (undefined1)(uVar8 + 0x1000 >> 8);
      local_7d = (undefined1)uVar8;
      local_7c = 0;
      local_7b = 0x78;
      pbVar5 = abStack_7a;
      uVar1 = uVar8;
      do {
        bVar2 = *(byte *)(param_2 + (ulong)uVar1);
        uVar1 = uVar1 + 1;
        pbVar4 = pbVar5 + 1;
        *pbVar5 = bVar2;
        uVar9 = uVar9 ^ bVar2;
        pbVar5 = pbVar4;
      } while (pbVar4 != abStack_2);
      iVar3 = 0x1e;
      fts_i2c_write(param_1,&local_80,0x7e);
      do {
        local_a8 = 0x6a;
        local_b8 = local_b8 & 0xffff0000;
        fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
        if (CONCAT11((char)local_b8,local_b8._1_1_) == uVar6) break;
        msleep(1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      uVar6 = uVar6 + 1;
      uVar8 = uVar8 + 0x78;
      iVar3 = iVar7;
    } while (uVar6 != iVar7 + 0x1022U);
  }
  uVar6 = param_3 % 0x78;
  if (uVar6 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar6;
    uVar8 = iVar7 * 0x78;
    iVar7 = uVar8 + 0x1000;
    local_7d = (undefined1)iVar7;
    local_7f = (undefined1)((uint)iVar7 >> 0x10);
    local_7e = (undefined1)((uint)iVar7 >> 8);
    uVar1 = uVar8 + uVar6;
    pbVar5 = abStack_7a;
    do {
      bVar2 = *(byte *)(param_2 + (ulong)uVar8);
      uVar8 = uVar8 + 1;
      *pbVar5 = bVar2;
      uVar9 = uVar9 ^ bVar2;
      pbVar5 = pbVar5 + 1;
    } while (uVar8 != uVar1);
    iVar7 = 0x1e;
    fts_i2c_write(param_1,&local_80,uVar6 + 6);
    do {
      local_a8 = 0x6a;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
      if ((uint)CONCAT11((char)local_b8,local_b8._1_1_) == iVar3 + 0x1022U) break;
      msleep(1);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  iVar7 = 100;
  msleep(0x32);
  local_a8 = 100;
  fts_i2c_write(param_1,&local_a8,1);
  msleep(300);
  local_a7 = 0;
  local_a8 = 0x65;
  uVar6 = param_3;
  if (0xfffe < param_3) {
    uVar6 = 0xfffe;
  }
  local_a4 = (undefined1)(uVar6 >> 8);
  local_a5 = 0;
  local_a6 = 0x10;
  local_a3 = (undefined1)uVar6;
  fts_i2c_write(param_1,&local_a8,6);
  msleep(param_3 >> 8);
  do {
    local_a8 = 0x6a;
    local_b8 = local_b8 & 0xffff0000;
    fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
    if (((char)local_b8 == -0x10) && (local_b8._1_1_ == 'U')) break;
    msleep(1);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (0xfffe < param_3) {
    local_a8 = 0x65;
    local_a6 = 0xff;
    local_a7 = 0;
    local_a5 = 0xfe;
    iVar7 = 100;
    local_a4 = (undefined1)(param_3 - 0xfffe >> 8);
    local_a3 = (undefined1)(param_3 - 0xfffe);
    fts_i2c_write(param_1,&local_a8,6);
    msleep(param_3 >> 8);
    do {
      local_a8 = 0x6a;
      local_b8 = local_b8 & 0xffff0000;
      fts_i2c_read(param_1,&local_a8,1,&local_b8,2);
      if (((char)local_b8 == -0x10) && (local_b8._1_1_ == 'U')) break;
      msleep(1);
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  local_a8 = 0x66;
  fts_i2c_read(param_1,&local_a8,1,&local_b8,1);
  if ((local_b8 & 0xff) != uVar9) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(char)local_b8,uVar9)
    ;
    return 0xfffffffb;
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f96018,uVar9,uVar9);
}



undefined8 fts_3x07_ctpm_fw_upgrade(long param_1,char *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  ulong uVar10;
  byte bVar11;
  int iVar12;
  undefined2 local_98;
  undefined1 local_90;
  undefined1 local_8f;
  undefined1 local_8e;
  undefined1 local_8d;
  undefined1 local_8c;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte abStack_7a [120];
  byte abStack_2 [2];
  
  local_98 = 0;
  if (((*param_2 != '\x02') || (param_3 < 0x120)) ||
     (uVar2 = (uint)(byte)param_2[0x101] + (uint)(byte)param_2[0x100] * 0x100, param_3 < uVar2)) {
    return 0xffffffff;
  }
  iVar9 = 0x1e;
  while( true ) {
    fts_write_reg(param_1,0xffffffbc,0xffffffaa);
    msleep(DAT_ffffffc00156bd34);
    fts_write_reg(param_1,0xffffffbc,0x55);
    msleep(DAT_ffffffc00156bd36);
    local_90 = 0x55;
    fts_i2c_write(param_1,&local_90,1);
    local_90 = 0xaa;
    fts_i2c_write(param_1,&local_90,1);
    msleep(DAT_ffffffc00156bd3a);
    local_90 = 0x90;
    local_8d = 0;
    local_8e = 0;
    local_8f = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if ((DAT_ffffffc00156bd38 == (byte)local_98) && (DAT_ffffffc00156bd39 == local_98._1_1_)) break;
    dev_err(param_1 + 0x20,s__FTS__Step_3__GET_CTPM_ID_FAIL_I_ffffffc000f95de0);
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) {
      return 0xfffffffb;
    }
  }
  local_90 = 0x90;
  local_8f = 0;
  iVar9 = 200;
  local_8e = 0;
  local_8d = 0;
  local_8c = 0;
  fts_i2c_write(param_1,&local_90,5);
  local_90 = 0x61;
  fts_i2c_write(param_1,&local_90,1);
  msleep(DAT_ffffffc00156bd3c);
  do {
    local_90 = 0x6a;
    local_8f = 0;
    local_8e = 0;
    local_8d = 0;
    local_98 = 0;
    fts_i2c_read(param_1,&local_90,4,&local_98,2);
    if (((byte)local_98 == -0x50) && (local_98._1_1_ == '\x02')) break;
    msleep(0x32);
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_80 = 0xbf;
  local_7f = 0;
  bVar11 = 0;
  uVar6 = uVar2 / 0x78;
  uVar7 = 0;
  if (uVar6 != 0) {
    uVar10 = 0;
    bVar11 = 0;
    uVar8 = 0;
    do {
      local_7e = (undefined1)(uVar10 >> 8);
      iVar9 = (int)uVar10;
      local_7d = (undefined1)uVar10;
      local_7c = 0;
      local_7b = 0x78;
      pbVar4 = abStack_7a;
      do {
        bVar3 = param_2[uVar10];
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar5 = pbVar4 + 1;
        *pbVar4 = bVar3;
        bVar11 = bVar11 ^ bVar3;
        pbVar4 = pbVar5;
      } while (pbVar5 != abStack_2);
      iVar12 = 0x1e;
      fts_i2c_write(param_1,&local_80,0x7e);
      do {
        local_90 = 0x6a;
        local_8f = 0;
        local_8e = 0;
        local_8d = 0;
        local_98 = 0;
        fts_i2c_read(param_1,&local_90,4,&local_98,2);
        if ((((byte)local_98 & 0xf0) == 0xb0) &&
           ((int)uVar8 + (int)(uVar8 / 0xffd) * -0xffd + 3U ==
            (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
        msleep(1);
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
      uVar1 = (int)uVar8 + 1;
      uVar8 = (ulong)uVar1;
      uVar10 = (ulong)(iVar9 + 0x78);
      uVar7 = uVar6;
    } while (uVar1 != uVar6);
  }
  uVar2 = uVar2 % 0x78;
  if (uVar2 != 0) {
    local_7c = 0;
    local_7b = (undefined1)uVar2;
    uVar6 = uVar6 * 0x78;
    local_7d = (undefined1)uVar6;
    local_7e = (undefined1)(uVar6 >> 8);
    uVar1 = uVar6 + uVar2;
    pbVar4 = abStack_7a;
    do {
      bVar3 = param_2[uVar6];
      uVar6 = uVar6 + 1;
      *pbVar4 = bVar3;
      bVar11 = bVar11 ^ bVar3;
      pbVar4 = pbVar4 + 1;
    } while (uVar6 != uVar1);
    iVar9 = 0x1e;
    fts_i2c_write(param_1,&local_80,uVar2 + 6);
    do {
      local_90 = 0x6a;
      local_8f = 0;
      local_8e = 0;
      local_8d = 0;
      local_98 = 0;
      fts_i2c_read(param_1,&local_90,4,&local_98,2);
      if ((((byte)local_98 & 0xf0) == 0xb0) &&
         (uVar7 + 3 == (((byte)local_98 & 0xf) << 8 | (uint)local_98._1_1_))) break;
      msleep(1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_90 = 0xcc;
  fts_i2c_read(param_1,&local_90,1,&local_98,1);
  if ((byte)local_98 != bVar11) {
    dev_err(param_1 + 0x20,s__FTS___ecc_error__FW__02x_bt_ecc_ffffffc000f95e18,(byte)local_98,bVar11
           );
    return 0xfffffffb;
  }
  local_90 = 7;
  fts_i2c_write(param_1,&local_90,1);
  msleep(300);
  return 0;
}



void fts_ctpm_fw_upgrade_with_app_file(undefined8 param_1,undefined8 param_2)

{
  fts_GetFirmwareSize(param_2);
                    /* WARNING: Subroutine does not return */
  printk(s___________fts_ctpm_fw_upgrade_wi_ffffffc000f962b0);
}



undefined1 fts_ctpm_get_i_file_ver(void)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (2 < (ushort)DAT_ffffffc00115db18) {
    if ((DAT_ffffffc00156bd30 == -0x7a || DAT_ffffffc00156bd30 == '6') ||
       (DAT_ffffffc00156bd30 == 'd')) {
      return *(undefined1 *)(DAT_ffffffc00156bd40 + 0x10a);
    }
    if (DAT_ffffffc00156bd30 == 'X') {
      return *(undefined1 *)(DAT_ffffffc00156bd40 + 0x1d0a);
    }
    uVar1 = *(undefined1 *)(DAT_ffffffc00156bd40 + (ulong)(ushort)DAT_ffffffc00115db18 + -2);
  }
  return uVar1;
}



undefined8 fts_ctpm_update_project_setting(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  undefined2 local_110;
  long local_108;
  undefined2 local_100;
  byte local_f8 [120];
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  byte local_7a [122];
  
  local_100 = 0;
  local_110 = 0;
  local_108 = 0;
  bVar2 = *(byte *)(param_1 + 2);
  if ((DAT_ffffffc00156bd30 == '6') || (DAT_ffffffc00156bd30 == '\x06')) {
    fts_write_reg(param_1,0xffffffbc,0xffffffaa);
  }
  else {
    fts_write_reg(param_1,0xfffffffc,0xffffffaa);
  }
  msleep(0x32);
  if ((DAT_ffffffc00156bd30 == '6') || (DAT_ffffffc00156bd30 == '\x06')) {
    fts_write_reg(param_1,0xffffffbc,0x55);
  }
  else {
    fts_write_reg(param_1,0xfffffffc,0x55);
  }
  uVar5 = 0;
  msleep(0x1e);
  local_108 = CONCAT62(local_108._2_6_,0xaa55);
  do {
    uVar5 = uVar5 + 1;
    iVar3 = fts_i2c_write(param_1,&local_108,2);
    msleep(5);
    if (0 < iVar3) break;
  } while (uVar5 < 5);
  local_108._3_5_ = (uint5)((ulong)local_108 >> 0x18) & 0xffffffff00;
  local_108 = (ulong)local_108._3_5_ << 0x18;
  local_108 = CONCAT62(local_108._2_6_,0x90);
  fts_i2c_read(param_1,&local_108,4,&local_110,2);
  if ((DAT_ffffffc00156bd38 == (char)local_110) && (DAT_ffffffc00156bd39 == local_110._1_1_)) {
    if ((DAT_ffffffc0012abfaa >> 2 & 1) != 0) {
      __dynamic_dev_dbg(&PTR_s_focaltech_flash_ffffffc0012abf88,param_1 + 0x20,
                        s__FTS__Step_3__CTPM_ID_ID1___0x_x_ffffffc000f95e78);
    }
    local_108 = CONCAT71(local_108._1_7_,0xcd);
    fts_i2c_read(param_1,&local_108,1,&local_110,1);
    if ((DAT_ffffffc0012abfd2 >> 2 & 1) != 0) {
      __dynamic_dev_dbg(&PTR_s_focaltech_flash_ffffffc0012abfb0,param_1 + 0x20,
                        s_bootloader_version___0x_x_ffffffc000f963d8,(char)local_110);
    }
    local_f8[0] = 3;
    local_f8[1] = 0;
    local_f8[3] = 0;
    local_f8[2] = 0x78;
    fts_i2c_read(param_1,local_f8,4,local_f8,0x78);
    if ((DAT_ffffffc0012abffa >> 2 & 1) != 0) {
      __dynamic_dev_dbg(&PTR_s_focaltech_flash_ffffffc0012abfd8,param_1 + 0x20,
                        s__FTS__old_setting__uc_i2c_addr___ffffffc000f963f8,local_f8[0],local_f8[2],
                        local_f8[4]);
    }
    local_108._0_1_ = 99;
    fts_i2c_write(param_1,&local_108,1);
    msleep(100);
    local_f8[0] = bVar2;
    local_f8[3] = 0xff;
    local_f8[4] = 0x5a;
    local_f8[1] = ~bVar2;
    local_f8[5] = 0xa5;
    local_f8[2] = 0;
    local_80 = 0xbf;
    local_7f = 0;
    local_7e = 0x78;
    local_7d = 0;
    local_7c = 0;
    local_7b = 0x78;
    lVar4 = 0;
    do {
      lVar1 = lVar4 + 1;
      local_7a[lVar4] = local_f8[lVar4];
      lVar4 = lVar1;
    } while (lVar1 != 0x78);
    fts_i2c_write(param_1,&local_80,0x7e);
    msleep(100);
    local_108 = CONCAT71(local_108._1_7_,7);
    fts_i2c_write(param_1,&local_108,1);
    msleep(200);
    return 0;
  }
  return 0xfffffffb;
}



int fts_ctpm_fw_upgrade_with_i_file(long param_1)

{
  bool bVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  lVar2 = DAT_ffffffc00156bd40;
  bVar1 = (byte)(DAT_ffffffc00156bd30 - 0x11) < 4;
  bVar3 = (DAT_ffffffc00156bd30 & 0xfd) == 8;
  if ((bVar1 || (DAT_ffffffc00156bd30 == 6 || DAT_ffffffc00156bd30 == 0x55)) || (bVar3)) {
    if (0x7ff8 < DAT_ffffffc00115db18 - 8U) {
LAB_ffffffc000849028:
      pcVar6 = s__s_FW_length_error_ffffffc000f96458;
      goto LAB_ffffffc000849034;
    }
    lVar2 = DAT_ffffffc00156bd40 + DAT_ffffffc00115db18;
    if ((((*(byte *)(lVar2 + -6) ^ *(byte *)(lVar2 + -8)) != 0xff) ||
        ((*(byte *)(lVar2 + -5) ^ *(byte *)(lVar2 + -7)) != 0xff)) ||
       ((*(byte *)(lVar2 + -4) ^ *(byte *)(lVar2 + -3)) != 0xff)) {
      dev_err(param_1 + 0x20,s__s_FW_format_error_ffffffc000f96490,__func___43218);
      return -0x4d;
    }
    if ((bVar3) || (DAT_ffffffc00156bd30 == 0x55)) {
      iVar4 = fts_5x06_ctpm_fw_upgrade(param_1);
joined_r0xffffffc000848eb0:
      if (iVar4 != 0) {
        dev_err(param_1 + 0x20,s__s_upgrade_failed__err__ffffffc000f96470,__func___43218);
        return iVar4;
      }
    }
    else {
      if (bVar1) {
        iVar4 = fts_5x36_ctpm_fw_upgrade(param_1);
        goto joined_r0xffffffc000848eb0;
      }
      if (DAT_ffffffc00156bd30 == 6) {
        iVar4 = fts_6x06_ctpm_fw_upgrade(param_1);
        goto joined_r0xffffffc000848eb0;
      }
    }
    if (DAT_ffffffc00156bd32 == '\x01') {
      fts_ctpm_auto_clb(param_1);
    }
LAB_ffffffc000848e90:
    iVar5 = 0;
  }
  else {
    if (DAT_ffffffc00156bd30 == 0x36) {
      if (0x7ff8 < DAT_ffffffc00115db18 - 8U) goto LAB_ffffffc000849028;
      iVar4 = fts_6x36_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
    }
    else {
      if (DAT_ffffffc00156bd30 != 100) {
        if (DAT_ffffffc00156bd30 == 0x54) {
          if (0xd7f8 < DAT_ffffffc00115db18 - 8U) {
LAB_ffffffc0008490c8:
                    /* WARNING: Subroutine does not return */
            printk(&DAT_ffffffc000f964a8);
          }
          iVar4 = fts_5x46_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
joined_r0xffffffc000848ff8:
          if (iVar4 == 0) {
            return 0;
          }
          dev_err(param_1 + 0x20,s__FTS__upgrade_failed__err__d__ffffffc000f964c0,iVar4);
          return iVar4;
        }
        if (DAT_ffffffc00156bd30 == 0x58) {
          if (0xd7f8 < DAT_ffffffc00115db18 - 8U) goto LAB_ffffffc0008490c8;
          iVar4 = fts_5822_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
          goto joined_r0xffffffc000848ff8;
        }
        if (DAT_ffffffc00156bd30 == 0x59) {
          if (0xd7f8 < DAT_ffffffc00115db18 - 8U) goto LAB_ffffffc0008490c8;
          iVar4 = fts_5x26_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
          goto joined_r0xffffffc000848ff8;
        }
        if (DAT_ffffffc00156bd30 == 0x86) {
          iVar4 = fts_8606_writepram(param_1,&DAT_ffffffc00115db20,0xc60);
          if (iVar4 == 0) {
            iVar4 = fts_8606_ctpm_fw_upgrade(param_1,lVar2,DAT_ffffffc00115db18);
            goto joined_r0xffffffc000848ff8;
          }
LAB_ffffffc0008490b8:
          pcVar6 = s__s_upgrade_failed__err__ffffffc000f96470;
LAB_ffffffc000849034:
          dev_err(param_1 + 0x20,pcVar6,__func___43218);
          return -5;
        }
        if (DAT_ffffffc00156bd30 == 0x87) {
          iVar4 = fts_8716_writepram(param_1,&DAT_ffffffc00115db20,0xc60);
          if (iVar4 == 0) {
            iVar4 = fts_8716_ctpm_fw_upgrade(param_1,lVar2,DAT_ffffffc00115db18);
            goto joined_r0xffffffc000848ff8;
          }
          goto LAB_ffffffc0008490b8;
        }
        if (DAT_ffffffc00156bd30 == 0xe) {
          if (0x7ff8 < DAT_ffffffc00115db18 - 8U) goto LAB_ffffffc000849028;
          iVar4 = fts_3x07_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
          goto joined_r0xffffffc000848f10;
        }
        goto LAB_ffffffc000848e90;
      }
      if (0xbff8 < DAT_ffffffc00115db18 - 8U) goto LAB_ffffffc000849028;
      iVar4 = fts_6336GU_ctpm_fw_upgrade(param_1,DAT_ffffffc00156bd40);
    }
joined_r0xffffffc000848f10:
    iVar5 = 0;
    if (iVar4 != 0) {
      dev_err(param_1 + 0x20,s__s_upgrade_failed__err__ffffffc000f96470,__func___43218);
      iVar5 = iVar4;
    }
  }
  return iVar5;
}



void fts_set_ctp_fw(char param_1,char param_2)

{
  if (param_1 == -0x80) {
    if (param_2 == '1') {
      DAT_ffffffc00156bd40 = &DAT_ffffffc00115e780;
      DAT_ffffffc00115db18 = 54000;
    }
    else if (param_2 == '2') {
      DAT_ffffffc00115db18 = 54000;
      DAT_ffffffc00156bd40 = &DAT_ffffffc00116ba70;
    }
    else {
      if (param_2 != 'A') {
        if (param_2 == 'B') {
          DAT_ffffffc00115db18 = 0xcf0e;
          DAT_ffffffc00156bd40 = &DAT_ffffffc001185c70;
          return;
        }
                    /* WARNING: Subroutine does not return */
        printk(&DAT_ffffffc000f964e8);
      }
      DAT_ffffffc00115db18 = 0xcf0e;
      DAT_ffffffc00156bd40 = &DAT_ffffffc001178d60;
    }
  }
  else if (param_1 == 'Q') {
    if (param_2 != '1') {
      if (param_2 == '2') {
        DAT_ffffffc00115db18 = 54000;
        DAT_ffffffc00156bd40 = &DAT_ffffffc00119fe70;
        return;
      }
                    /* WARNING: Subroutine does not return */
      printk(&DAT_ffffffc000f964e8);
    }
    DAT_ffffffc00115db18 = 54000;
    DAT_ffffffc00156bd40 = &DAT_ffffffc001192b80;
  }
  else if (param_1 == -0x7b) {
    if (param_2 != '1') {
      if (param_2 == '2') {
        DAT_ffffffc00115db18 = 0xd18a;
        DAT_ffffffc00156bd40 = &DAT_ffffffc0011ba2f0;
        return;
      }
                    /* WARNING: Subroutine does not return */
      printk(&DAT_ffffffc000f964e8);
    }
    DAT_ffffffc00115db18 = 0xd18a;
    DAT_ffffffc00156bd40 = &DAT_ffffffc0011ad160;
  }
  return;
}



void fts_ctpm_auto_upgrade(void)

{
  undefined8 uVar1;
  undefined1 uVar2;
  char local_5;
  char local_4;
  char local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar1 = DAT_ffffffc00156bda0;
  local_4 = '\0';
  local_3 = '\0';
  local_2 = 0;
  local_1 = 0;
  fts_read_reg(DAT_ffffffc00156bda0,0xffffffa3,&local_4);
  if (DAT_ffffffc00156bd30 != local_4) {
    fts_ctpm_fw_upgrade_ReadChipID_Array(uVar1,&local_4);
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f96680,local_4);
  }
  fts_read_reg(uVar1,0xffffffa6,&local_5);
  msleep(3);
  fts_read_reg(uVar1,0xffffffab,&local_1);
  msleep(3);
  fts_read_reg(uVar1,0xffffffa8,&local_3);
  if ((local_3 == -0x80) && (local_5 == ')')) {
    fts_ctpm_fw_upgrade_ReadVendorID(uVar1,&local_2);
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f96508,local_2);
  }
  fts_set_ctp_fw(local_3,local_1);
  if (0 < DAT_ffffffc00115db18) {
    uVar2 = fts_ctpm_get_i_file_ver();
                    /* WARNING: Subroutine does not return */
    printk(&DAT_ffffffc000f96598,local_5,uVar2);
  }
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f96578);
}



void fts_check_gesture(undefined8 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0x20:
    if ((DAT_ffffffc00156bd5b >> 1 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xb0;
    break;
  case 0x21:
    if ((DAT_ffffffc00156bd5b & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xb1;
    break;
  case 0x22:
    if ((DAT_ffffffc00156bd5b >> 3 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xb2;
    break;
  case 0x23:
    if ((DAT_ffffffc00156bd5b >> 2 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xb3;
    break;
  case 0x24:
    if ((DAT_ffffffc00156bd59 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xa0;
    break;
  default:
    goto switchD_ffffffc0008496a0_caseD_25;
  case 0x30:
    if (-1 < (char)DAT_ffffffc00156bd5a) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc4;
    break;
  case 0x31:
    if ((DAT_ffffffc00156bd5a >> 3 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc2;
    break;
  case 0x32:
    if ((DAT_ffffffc00156bd5a >> 4 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc3;
    input_event(param_1,1,0xc3,1);
    input_event(param_1,0,0,0);
    goto LAB_ffffffc0008496ec;
  case 0x33:
    if ((DAT_ffffffc00156bd5a >> 2 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc0;
    break;
  case 0x34:
    if ((DAT_ffffffc00156bd5a >> 1 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc1;
    break;
  case 0x46:
    if ((DAT_ffffffc00156bd5a >> 5 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xc5;
    break;
  case 0x54:
    if ((DAT_ffffffc00156bd5a & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 199;
    break;
  case 0x65:
    if ((DAT_ffffffc00156bd5a >> 6 & 1) == 0) goto switchD_ffffffc0008496a0_caseD_25;
    DAT_ffffffc00156bd60 = 0xca;
  }
  input_event(param_1,1,0xc3,1);
  input_event(param_1,0,0,0);
LAB_ffffffc0008496ec:
  input_event(param_1,1,0xc3,0);
  input_event(param_1,0,0,0);
switchD_ffffffc0008496a0_caseD_25:
                    /* WARNING: Subroutine does not return */
  printk(&DAT_ffffffc000f96770,__func___42553,param_2,DAT_ffffffc00156bd60);
}



undefined8 fts_Gesture_init(long param_1)

{
  input_set_capability(param_1,1,0xc3);
  *(ulong *)(param_1 + 0x48) = *(ulong *)(param_1 + 0x48) | 8;
  return 0;
}



undefined8 fts_read_Gestruedata(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  char local_300;
  byte local_2ff;
  char acStack_201 [513];
  
  memset(&local_300,0,0x2fd);
  DAT_ffffffc00156bd50 = 0;
  local_300 = -0x2d;
  iVar5 = fts_i2c_read(DAT_ffffffc00156bda0,&local_300,1,&local_300,8);
  cVar4 = local_300;
  if (-1 < iVar5) {
    if (((byte)(DAT_ffffffc00156bd30 + 0x7aU) < 2 || DAT_ffffffc00156bd30 == 'd') ||
       ((DAT_ffffffc00156bd30 + 0xacU & 0xfb) == 0)) {
      pcVar6 = &local_300;
      DAT_ffffffc00156bd50 = (ushort)local_2ff;
      uVar2 = (uint)local_2ff * 4 + 2;
      local_300 = -0x2d;
      uVar3 = uVar2;
      if (0xfe < uVar2) {
        fts_i2c_read(DAT_ffffffc00156bda0,pcVar6,1,pcVar6,0xff);
        pcVar6 = acStack_201;
        uVar3 = (short)DAT_ffffffc00156bd50 * 4 - 0xfd;
      }
      iVar5 = fts_i2c_read(DAT_ffffffc00156bda0,&local_300,uVar2 < 0xff,pcVar6,uVar3);
      if (-1 < iVar5) {
        fts_check_gesture(DAT_ffffffc00156bdb0,cVar4);
        return 0xffffffff;
      }
    }
    else {
      if (local_300 == '$') {
        fts_check_gesture(DAT_ffffffc00156bdb0,0x24);
                    /* WARNING: Subroutine does not return */
        printk(s__d_check_gesture_gestrue_id__ffffffc000f967c8,0x24);
      }
      pcVar6 = &local_300;
      DAT_ffffffc00156bd50 = (ushort)local_2ff;
      local_300 = -0x2d;
      uVar2 = (local_2ff + 2) * 4;
      bVar1 = uVar2 < 0xff;
      if (!bVar1) {
        fts_i2c_read(DAT_ffffffc00156bda0,pcVar6,1,pcVar6,0xff);
        pcVar6 = acStack_201;
        uVar2 = (short)DAT_ffffffc00156bd50 * 4 - 0xf7;
      }
      iVar5 = fts_i2c_read(DAT_ffffffc00156bda0,&local_300,bVar1,pcVar6,uVar2);
      if (-1 < iVar5) {
        fts_check_gesture(DAT_ffffffc00156bdb0,0x24);
                    /* WARNING: Subroutine does not return */
        printk(s__d_read_gestrue_id__ffffffc000f967e8,0x24);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  printk(s__s_read_touchdata_failed__ffffffc000f967a8,__func___42560);
}



void fts_holster_enable(int param_1)

{
  long lVar1;
  uint uVar2;
  undefined2 local_8 [4];
  
  lVar1 = DAT_ffffffc00156bda0;
  if (param_1 == 0) {
    local_8[0] = 0x94;
    mutex_lock(&DAT_ffffffc0011c75b8);
    uVar2 = *(uint *)(lVar1 + 0x20c);
  }
  else {
    local_8[0] = 0x194;
    mutex_lock(&DAT_ffffffc0011c75b8);
    uVar2 = *(uint *)(lVar1 + 0x20c);
  }
  *(uint *)(lVar1 + 0x20c) = uVar2 & 0x2152dfff;
  i2c_master_send(lVar1,local_8,2);
  mutex_unlock(&DAT_ffffffc0011c75b8);
  return;
}



int fts_i2c_read(long param_1,void *param_2,int param_3,void *param_4,int param_5)

{
  int iVar1;
  
  mutex_lock(&DAT_ffffffc0011c75b8);
  if ((0x7f < param_3 - 1U) || (param_1 == 0)) {
    iVar1 = 0;
  }
  else {
    memcpy(DAT_ffffffc00156bd90,param_2,(long)param_3);
    *(ushort *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x2000;
    iVar1 = i2c_master_send(param_1,DAT_ffffffc00156bd98,param_3);
    if (iVar1 != param_3) {
                    /* WARNING: Subroutine does not return */
      printk(s_i2c_master_send_in__s_failed_ffffffc000f96b88,__func___43762);
    }
    *(ushort *)(param_1 + 2) = (ushort)*(byte *)(param_1 + 2);
  }
  if ((param_1 != 0) && (param_5 - 1U < 0x80)) {
    *(ushort *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x2000;
    iVar1 = i2c_master_recv(param_1,DAT_ffffffc00156bd98,param_5);
    if (iVar1 != param_5) {
                    /* WARNING: Subroutine does not return */
      printk(s_i2c_master_recv_in__s_failed_ffffffc000f96ba8,__func___43762);
    }
    memcpy(param_4,DAT_ffffffc00156bd90,(long)iVar1);
    *(ushort *)(param_1 + 2) = (ushort)*(byte *)(param_1 + 2);
  }
  mutex_unlock(&DAT_ffffffc0011c75b8);
  return iVar1;
}



undefined4 fts_i2c_write(long param_1,void *param_2,int param_3)

{
  undefined4 uVar1;
  
  mutex_lock(&DAT_ffffffc0011c75b8);
  if (param_3 < 9) {
    *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0x2152dfff;
    uVar1 = i2c_master_send(param_1,param_2,param_3);
    mutex_unlock(&DAT_ffffffc0011c75b8);
    return uVar1;
  }
  if (DAT_ffffffc00156bd90 != (void *)0x0) {
    memcpy(DAT_ffffffc00156bd90,param_2,(long)param_3);
    *(ushort *)(param_1 + 2) = *(byte *)(param_1 + 2) | 0x2000;
    uVar1 = i2c_master_send(param_1,DAT_ffffffc00156bd98,param_3);
    *(ushort *)(param_1 + 2) = (ushort)*(byte *)(param_1 + 2);
    mutex_unlock(&DAT_ffffffc0011c75b8);
    return uVar1;
  }
  mutex_unlock(&DAT_ffffffc0011c75b8);
  return 0;
}



undefined4 fts_write_reg(long param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  undefined1 local_8;
  undefined1 local_7;
  
  local_8 = param_2;
  local_7 = param_3;
  mutex_lock(&DAT_ffffffc0011c75b8);
  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & 0x2152dfff;
  uVar1 = i2c_master_send(param_1,&local_8,2);
  mutex_unlock(&DAT_ffffffc0011c75b8);
  return uVar1;
}



void fts_read_reg(undefined8 param_1,undefined1 param_2,undefined8 param_3)

{
  undefined1 local_1;
  
  local_1 = param_2;
  fts_i2c_read(param_1,&local_1,1,param_3,1);
  return;
}



void fts_esd_check_func(void)

{
  char local_c [2];
  undefined1 local_a;
  undefined1 local_9 [9];
  
  if ((DAT_ffffffc00156bd80 == 0) && (DAT_ffffffc00156bd84 == 0)) {
    local_9[0] = 0x95;
    fts_i2c_read(DAT_ffffffc00156bd70,local_9,1,local_c,1);
    if (local_c[0] != '\0') {
      DAT_ffffffc00156bd8c = local_c[0];
    }
    DAT_ffffffc00156be48 = 0;
    local_a = 0xa3;
    fts_i2c_read(DAT_ffffffc00156bd70,&local_a,1,local_c,1);
                    /* WARNING: Subroutine does not return */
    printk(s_focal__fts_esd_check_func_0xA3___ffffffc000f96f28,local_c[0]);
  }
  DAT_ffffffc00156bdd0 = 0;
  return;
}



void fts_set_esd_schedule(void)

{
  queue_delayed_work_on(8,DAT_ffffffc00156bdd8,&DAT_ffffffc00156bde0,300);
  return;
}



undefined4 fts_strncmp(byte *param_1,byte *param_2,long param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  
  if (param_3 == 0) {
    return 0;
  }
  bVar2 = *param_1 | 0x20;
  pbVar1 = param_2 + param_3;
  bVar3 = *param_2 | 0x20;
  if (bVar2 == bVar3) {
    do {
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      if (param_2 == pbVar1) {
        return 0;
      }
      bVar2 = *param_1 | 0x20;
      bVar3 = *param_2 | 0x20;
    } while (bVar2 == bVar3);
  }
  uVar4 = 0xffffffff;
  if (bVar3 <= bVar2) {
    uVar4 = 1;
  }
  return uVar4;
}



int FT5X46_get_test_data(void *param_1)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    iVar1 = DAT_ffffffc0015bd878 + DAT_ffffffc0015b9dd4;
    memcpy(param_1,&DAT_ffffffc0015bd880,(long)iVar1);
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  printk(s__FTS__focal___s_pTestData____NUL_ffffffc000f98910,__func___9070);
}



undefined1 FT5X46_TestItem_EnterFactoryMode(void)

{
  char cVar1;
  undefined1 uVar2;
  char local_1;
  
  local_1 = '\0';
  SysDelay(0x96);
  cVar1 = EnterFactory();
  if (cVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
    printk(s__FTS_Failed_to_Enter_factory_mod_ffffffc000f98938);
  }
  SysDelay(300);
  GetChannelNum();
  uVar2 = ReadReg(0x53,&local_1);
  if (local_1 != '\x01') {
    DAT_ffffffc0015d1880 = 0;
    return uVar2;
  }
  DAT_ffffffc0015d1880 = local_1;
  return uVar2;
}



void FT5X46_TestItem_RawDataTest(void)

{
                    /* WARNING: Subroutine does not return */
  printk(s__FTS_____________________________ffffffc000f98960);
}



void FT5X46_TestItem_SCapRawDataTest(void)

{
                    /* WARNING: Subroutine does not return */
  printk(s__FTS_____________________________ffffffc000f98d78);
}



void FT5X46_TestItem_SCapCbTest(void)

{
                    /* WARNING: Subroutine does not return */
  printk(s__FTS_____________________________ffffffc000f990f0);
}



void FT5X46_StartTest(void)

{
  int iVar1;
  
  DAT_ffffffc0015d1888 = (char *)0x0;
  DAT_ffffffc0015d1888 = (char *)kmalloc_order_trace(0x14000,0x20,5);
  DAT_ffffffc0015b9dc8 = 0;
  DAT_ffffffc0015b9dc8 = kmalloc_order_trace(0x14000,0x20,5);
  DAT_ffffffc0015b9dd8 = 0;
  DAT_ffffffc0015b9dd8 = kmalloc_order_trace(0x14000,0x20,5);
  DAT_ffffffc0015b9db0 = 0;
  DAT_ffffffc0015b9db0 = kmalloc_order_trace(0x4000,0x20,2);
  DAT_ffffffc0015bd878 = 0;
  iVar1 = sprintf(DAT_ffffffc0015d1888,s_ECC__85__170__IC_Name___s__IC_Co_ffffffc000f993e8,
                  &DAT_ffffffc00158e898,(ulong)DAT_ffffffc00158e878);
  DAT_ffffffc0015b9dc0 = 0;
  DAT_ffffffc0015b9dd4 = 0;
  DAT_ffffffc0015bd878 = iVar1 + DAT_ffffffc0015bd878;
  DAT_ffffffc0015b9dd0 = 0;
  DAT_ffffffc0015b9dbc = 0xb;
                    /* WARNING: Subroutine does not return */
  printk(s__FTS__focal___s_ffffffc000f984f0,s_Test_version__V1_1_0__2015_10_22_ffffffc000f99410);
}


