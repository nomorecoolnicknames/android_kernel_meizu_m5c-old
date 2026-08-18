/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: jd9365_lcm_compare_id at 0xffffffc0004e5330
// ============================================================================

undefined8 lcm_compare_id(void)

{
  char cVar1;
  undefined8 uVar2;
  char acStack_48 [8];
  undefined4 auStack_40 [16];
  
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(0x14);
  (*pcRamffffffc0011a0360)(0);
  (*pcRamffffffc0011a0380)(0x14);
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(0x78);
  auStack_40[0] = 0x13700;
  (*pcRamffffffc0011a03b8)(auStack_40,1,1);
  (*pcRamffffffc0011a0380)(10);
  (*pcRamffffffc0011a03e8)(0xffffffda,acStack_48,1);
  cVar1 = acStack_48[0];
  (*pcRamffffffc0011a03e8)(0xffffffdb,acStack_48,1);
  printk(0xffffffc000dd5718,&__func___18535,0x3b9,cVar1);
  printk(0xffffffc000dd5740,&__func___18535,0x3ba,acStack_48[0]);
  printk(0xffffffc000dd5768,&__func___18535,0x3bb,0);
  if ((cVar1 != -0x6d) || (uVar2 = 1, acStack_48[0] != 'e')) {
    printk(0xffffffc000dd5790);
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================================
// Function: jd9365_lcm_suspend_power at 0xffffffc0004e5474
// ============================================================================

void lcm_suspend_power(void)

{
  (*pcRamffffffc0011a0360)(0);
  (*pcRamffffffc0011a0380)(5);
  lcd_bais_enn_enable(0);
  (*pcRamffffffc0011a0380)(5);
  lcd_bais_enp_enable(0);
  return;
}



// ============================================================================
// Function: jd9365_lcm_init_power at 0xffffffc0004e54c8
// ============================================================================

void lcm_init_power(void)

{
  undefined4 uVar1;
  
  (*pcRamffffffc0011a0380)(5);
  lcd_bais_enp_enable(1);
  (*pcRamffffffc0011a0380)(5);
  uVar1 = lp3101_write_bytes(0,0xf);
  printk(0xffffffc000dd57b8,&__func___18509,0x2fa,uVar1);
  (*pcRamffffffc0011a0380)(2);
  lcd_bais_enn_enable(1);
  (*pcRamffffffc0011a0380)(5);
  uVar1 = lp3101_write_bytes(1,0xf);
  printk(0xffffffc000dd57e0,&__func___18509,0x30b,uVar1);
  (*pcRamffffffc0011a0380)(10);
  return;
}



// ============================================================================
// Function: jd9365_lcm_resume_power at 0xffffffc0004e5588
// ============================================================================

void lcm_resume_power(void)

{
  lcm_init_power();
  return;
}



// ============================================================================
// Function: jd9365_lcm_get_params at 0xffffffc0004e559c
// ============================================================================

void lcm_get_params(undefined4 *param_1)

{
  memset(param_1,0,0x380);
  *param_1 = 2;
  param_1[100] = 2;
  param_1[0x66] = 2;
  param_1[0xb7] = 2;
  param_1[7] = 0x500;
  param_1[0x6e] = 0x500;
  *(undefined1 *)((long)param_1 + 0x2e6) = 0x80;
  param_1[0x60] = 4;
  param_1[0x6a] = 4;
  param_1[0x6f] = 0x1e;
  *(undefined1 *)((long)param_1 + 0x2ea) = 0x31;
  param_1[6] = 0x2d0;
  param_1[0xdb] = 0x3e;
  param_1[0x5b] = 1;
  param_1[0xdc] = 0x6e;
  param_1[0x6b] = 0xc;
  param_1[0x70] = 0x3c;
  param_1[0x6c] = 0x18;
  param_1[0x71] = 0x42;
  param_1[0x73] = 0x2d0;
  param_1[0x8e] = 1;
  *(undefined1 *)(param_1 + 0x7d) = 6;
  param_1[0x8c] = 0xd4;
  param_1[0xb6] = 1;
  param_1[0xb1] = 1;
  param_1[0xb0] = 1;
  *(undefined1 *)(param_1 + 0xb9) = 9;
  *(undefined1 *)((long)param_1 + 0x2e5) = 3;
  *(undefined1 *)((long)param_1 + 0x2e7) = 3;
  *(undefined1 *)(param_1 + 0xba) = 6;
  *(undefined1 *)((long)param_1 + 0x2eb) = 1;
  *(undefined1 *)(param_1 + 0xbb) = 5;
  *(undefined1 *)(param_1 + 0xbc) = 0x33;
  *(undefined1 *)((long)param_1 + 0x2f1) = 1;
  *(undefined1 *)((long)param_1 + 0x2f2) = 9;
  return;
}



// ============================================================================
// Function: jd9365_lcm_set_util_funcs at 0xffffffc0004e56a0
// ============================================================================

void lcm_set_util_funcs(undefined8 param_1)

{
  memcpy(0xffffffc0011a0360,param_1,0xd8);
  return;
}



// ============================================================================
// Function: jd9365_lcm_init at 0xffffffc0004e576c
// ============================================================================

void lcm_init(void)

{
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(2);
  (*pcRamffffffc0011a0360)(0);
  (*pcRamffffffc0011a0380)(10);
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(0x78);
  push_table_constprop_0(0xffffffc00101fe40,0xe3);
  printk(0xffffffc000dd5808,&__func___18519,0x33e);
  return;
}



// ============================================================================
// Function: jd9365_lcm_suspend at 0xffffffc0004e5800
// ============================================================================

void lcm_suspend(void)

{
  push_table_constprop_0(0xffffffc001023e18,6);
  printk(0xffffffc000dd5808,&__func___18524,0x361);
  return;
}



// ============================================================================
// Function: jd9365_lcm_resume at 0xffffffc0004e5840
// ============================================================================

void lcm_resume(void)

{
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(2);
  (*pcRamffffffc0011a0360)(0);
  (*pcRamffffffc0011a0380)(10);
  (*pcRamffffffc0011a0360)(1);
  (*pcRamffffffc0011a0380)(0x14);
  push_table_constprop_0(0xffffffc00101fe40,0xe3);
  printk(0xffffffc000dd5808,&__func___18528,0x371);
  return;
}



