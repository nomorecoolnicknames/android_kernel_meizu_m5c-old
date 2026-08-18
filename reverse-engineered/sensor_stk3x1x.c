/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: stk3x1x_show_send at 0xffffffc00043da8c
// ============================================================================

undefined8 stk3x1x_show_send(void)

{
  return 0;
}



// ============================================================================
// Function: stk3x1x_release at 0xffffffc00043da94
// ============================================================================

undefined8 stk3x1x_release(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd0) = 0;
  return 0;
}



// ============================================================================
// Function: stk3x1x_local_uninit at 0xffffffc00043dac0
// ============================================================================

undefined8 stk3x1x_local_uninit(void)

{
  if ((uRamffffffc0010b5502 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b54e0,0xffffffc000d9a400,&__func___28089);
  }
  i2c_del_driver(0xffffffc00100c238);
  uRamffffffc001185e60 = 0;
  return 0;
}



// ============================================================================
// Function: stk3x1x_i2c_detect at 0xffffffc00043db1c
// ============================================================================

undefined8 stk3x1x_i2c_detect(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = uRamffffffc000d9a488;
  return 0;
}



// ============================================================================
// Function: stk3x1x_i2c_remove at 0xffffffc00043db34
// ============================================================================

undefined8 stk3x1x_i2c_remove(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  destroy_workqueue(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x1e0));
  lVar1 = lRamffffffc00100c230 + 0x28;
  if (lVar1 == 0) {
    printk(0xffffffc000d9a4c0,&__func___28084,0x15fc,0xffffffea);
  }
  else {
    puVar3 = (undefined8 *)&stk3x1x_attr_list;
    do {
      puVar4 = puVar3 + 1;
      driver_remove_file(lVar1,*puVar3);
      puVar3 = puVar4;
    } while (puVar4 != (undefined8 *)&__func___28084);
  }
  iVar2 = misc_deregister(0xffffffc00100c320);
  if (iVar2 != 0) {
    printk(0xffffffc000d9a490,&__func___28084,0x1601,iVar2);
  }
  uRamffffffc001185e60 = 0;
  i2c_unregister_device(param_1);
  kfree(*(undefined8 *)(param_1 + 0xc0));
  return 0;
}



// ============================================================================
// Function: stk3x1x_show_pthreshold_calibration at 0xffffffc00043dc10
// ============================================================================

long stk3x1x_show_pthreshold_calibration(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = snprintf(param_2,0x1000,0xffffffc000d9a4f8,*(undefined2 *)(lRamffffffc001185e68 + 0x196),
                   *(undefined2 *)(lRamffffffc001185e68 + 0x194));
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_store_firlen at 0xffffffc00043dc48
// ============================================================================

undefined8 stk3x1x_store_firlen(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  int iStack_4;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27422,0xd89);
    param_3 = 0;
  }
  else {
    iVar3 = sscanf(param_2,0xffffffc000e5d090,&iStack_4);
    lVar2 = lRamffffffc001185e68;
    if (iVar3 == 1) {
      if (iStack_4 < 0x21) {
        if (iStack_4 < 1) {
          puVar1 = (undefined8 *)(lRamffffffc001185e68 + 0x224);
          *(undefined4 *)(lRamffffffc001185e68 + 0x270) = 1;
          *puVar1 = 0;
          *(undefined8 *)(lVar2 + 0x22c) = 0;
          *(undefined8 *)(lVar2 + 0x234) = 0;
          *(undefined8 *)(lVar2 + 0x23c) = 0;
          *(undefined8 *)(lVar2 + 0x244) = 0;
          *(undefined8 *)(lVar2 + 0x24c) = 0;
          *(undefined8 *)(lVar2 + 0x254) = 0;
          *(undefined8 *)(lVar2 + 0x25c) = 0;
          *(undefined8 *)(lVar2 + 0x264) = 0;
          *(undefined4 *)(lVar2 + 0x26c) = 0;
        }
        else {
          puVar1 = (undefined8 *)(lRamffffffc001185e68 + 0x224);
          *(int *)(lRamffffffc001185e68 + 0x270) = iStack_4;
          *puVar1 = 0;
          *(undefined8 *)(lVar2 + 0x22c) = 0;
          *(undefined8 *)(lVar2 + 0x234) = 0;
          *(undefined8 *)(lVar2 + 0x23c) = 0;
          *(undefined8 *)(lVar2 + 0x244) = 0;
          *(undefined8 *)(lVar2 + 0x24c) = 0;
          *(undefined8 *)(lVar2 + 0x254) = 0;
          *(undefined8 *)(lVar2 + 0x25c) = 0;
          *(undefined8 *)(lVar2 + 0x264) = 0;
          *(undefined4 *)(lVar2 + 0x26c) = 0;
        }
      }
      else {
        printk(0xffffffc000d9a588,&__func___27422,0xd94,&__func___27422);
      }
    }
    else {
      printk(0xffffffc000d9a558,&__func___27422,0xd8e,param_2);
      param_3 = 0;
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_show_firlen at 0xffffffc00043dd70
// ============================================================================

long stk3x1x_show_firlen(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = *(int *)(lRamffffffc001185e68 + 0x270);
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27415,0xd78);
    lVar3 = 0;
  }
  else {
    printk(0xffffffc000d9a5c8,&__func___27415,iVar2,*(undefined4 *)(lRamffffffc001185e68 + 0x26c));
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = *(int *)(lRamffffffc001185e68 + 0x264) / iVar2;
    }
    printk(0xffffffc000d9a5f0,&__func___27415,*(int *)(lRamffffffc001185e68 + 0x264),iVar1);
    iVar2 = scnprintf(param_2,0x1000,0xffffffc000e8cd68,iVar2);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



// ============================================================================
// Function: stk3x1x_ps_maxdiff_store at 0xffffffc00043de28
// ============================================================================

long stk3x1x_ps_maxdiff_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uStack_8;
  
  uStack_8 = 0;
  iVar1 = kstrtoull(param_2,10,&uStack_8);
  if (-1 < iVar1) {
    *(short *)(lRamffffffc001185e68 + 0x18c) = (short)uStack_8;
    return param_3;
  }
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_ps_ltnct_store at 0xffffffc00043de84
// ============================================================================

long stk3x1x_ps_ltnct_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uStack_8;
  
  uStack_8 = 0;
  iVar1 = kstrtoull(param_2,10,&uStack_8);
  if (-1 < iVar1) {
    *(short *)(lRamffffffc001185e68 + 0x18e) = (short)uStack_8;
    return param_3;
  }
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_ps_htnct_store at 0xffffffc00043dee0
// ============================================================================

long stk3x1x_ps_htnct_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uStack_8;
  
  uStack_8 = 0;
  iVar1 = kstrtoull(param_2,10,&uStack_8);
  if (-1 < iVar1) {
    *(short *)(lRamffffffc001185e68 + 400) = (short)uStack_8;
    return param_3;
  }
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_store_ps_offset at 0xffffffc00043df90
// ============================================================================

undefined8
stk3x1x_store_ps_offset(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  uint uStack_4;
  
  lVar5 = lRamffffffc001185e68;
  uStack_4 = 0;
  sscanf(param_3,0xffffffc000e5d090,&uStack_4);
  bVar1 = 399 < ((uStack_4 & 0xffff) - 1 & 0xffff);
  if (bVar1) {
    *(undefined2 *)(lVar5 + 0x192) = 400;
  }
  else {
    *(undefined2 *)(lVar5 + 0x192) = (undefined2)uStack_4;
  }
  uRamffffffc001185e70 = (uint)!bVar1;
  mutex_lock(0xffffffc00100c368);
  sVar4 = *(short *)(lVar5 + 0x192);
  sVar2 = sVar4 + *(short *)(lVar5 + 400);
  sVar3 = sVar4 + *(short *)(lVar5 + 0x18e);
  *(short *)(lVar5 + 0x194) = sVar2;
  *(short *)(lVar5 + 0x196) = sVar3;
  printk(0xffffffc000d9a618,&__func___27832,sVar4,sVar2,sVar3);
  mutex_unlock(0xffffffc00100c368);
  return param_4;
}



// ============================================================================
// Function: stk3x1x_i2c_resume at 0xffffffc00043e074
// ============================================================================

undefined8 stk3x1x_i2c_resume(void)

{
  if ((uRamffffffc0010b5552 >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010b5530,0xffffffc000d9a400,&__func___28020);
  return 0;
}



// ============================================================================
// Function: stk3x1x_i2c_suspend at 0xffffffc00043e0c0
// ============================================================================

undefined8 stk3x1x_i2c_suspend(void)

{
  if ((uRamffffffc0010b557a >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010b5558,0xffffffc000d9a400,&__func___28015);
  return 0;
}



// ============================================================================
// Function: stk3x1x_open at 0xffffffc00043e10c
// ============================================================================

undefined8 stk3x1x_open(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = lRamffffffc001185e60;
  *(long *)(param_2 + 0xd0) = lRamffffffc001185e60;
  if (lVar1 == 0) {
    printk(0xffffffc000d9a648,&__func___27972,0x110a);
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = nonseekable_open();
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_show_flag at 0xffffffc00043e154
// ============================================================================

long stk3x1x_show_flag(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  if (iRamffffffc001185e70 != 1) {
    iVar1 = snprintf(param_2,0x1000,0xffffffc000e8cd68,1);
    return (long)iVar1;
  }
  iVar1 = snprintf(param_2,0x1000,0xffffffc000e8cd68,0);
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_store_trace at 0xffffffc00043e2c8
// ============================================================================

ulong stk3x1x_store_trace(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  undefined4 uStack_4;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27239,0xb28);
    param_3 = 0;
  }
  else {
    iVar1 = sscanf(param_2,0xffffffc000d8a790,&uStack_4);
    if (iVar1 == 1) {
      *(undefined4 *)(lRamffffffc001185e68 + 0x90) = uStack_4;
    }
    else {
      printk(0xffffffc000d9a670,&__func___27239,0xb32,param_2,param_3 & 0xffffffff);
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_ps_htnct_show at 0xffffffc00043e378
// ============================================================================

long stk3x1x_ps_htnct_show(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27409,0xd68);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000e8cd68,*(undefined2 *)(lRamffffffc001185e68 + 400))
    ;
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_ps_ltnct_show at 0xffffffc00043e3dc
// ============================================================================

long stk3x1x_ps_ltnct_show(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27397,0xd50);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000e8cd68,
                      *(undefined2 *)(lRamffffffc001185e68 + 0x18e));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_ps_maxdiff_show at 0xffffffc00043e440
// ============================================================================

long stk3x1x_ps_maxdiff_show(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27385,0xd37);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000e8cd68,
                      *(undefined2 *)(lRamffffffc001185e68 + 0x18c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_recv at 0xffffffc00043e4a4
// ============================================================================

long stk3x1x_show_recv(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27286,0xbb0);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9b228,
                      *(undefined4 *)(lRamffffffc001185e68 + 0x180));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_alsval at 0xffffffc00043e508
// ============================================================================

long stk3x1x_show_alsval(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (plRamffffffc001185e68 == (long *)0x0) {
    printk(0xffffffc000d9a528,&__func___27356,0xcdf);
    lVar4 = 0;
  }
  else {
    if (*(short *)((long)plRamffffffc001185e68 + 0xd4) == 0) {
      lVar4 = 0;
      lVar3 = 0x1000;
    }
    else {
      iVar2 = 0;
      lVar4 = 0;
      do {
        lVar3 = (long)iVar2;
        iVar2 = iVar2 + 1;
        iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000ebd470,
                          *(undefined4 *)(*plRamffffffc001185e68 + lVar3 * 4 + 0x58));
        lVar4 = lVar4 + iVar1;
      } while (iVar2 < (int)(uint)*(ushort *)((long)plRamffffffc001185e68 + 0xd4));
      lVar3 = 0x1000 - lVar4;
    }
    iVar2 = scnprintf(param_2 + lVar4,lVar3,0xffffffc000dfa978);
    lVar4 = lVar4 + iVar2;
  }
  return lVar4;
}



// ============================================================================
// Function: stk3x1x_show_alslv at 0xffffffc00043e5f4
// ============================================================================

long stk3x1x_show_alslv(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (plRamffffffc001185e68 == (long *)0x0) {
    printk(0xffffffc000d9a528,&__func___27340,0xcba);
    lVar4 = 0;
  }
  else {
    if (*(short *)((long)plRamffffffc001185e68 + 0xd2) == 0) {
      lVar4 = 0;
      lVar3 = 0x1000;
    }
    else {
      iVar2 = 0;
      lVar4 = 0;
      do {
        lVar3 = (long)iVar2;
        iVar2 = iVar2 + 1;
        iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000ebd470,
                          *(undefined4 *)(*plRamffffffc001185e68 + lVar3 * 4 + 0x1c));
        lVar4 = lVar4 + iVar1;
      } while (iVar2 < (int)(uint)*(ushort *)((long)plRamffffffc001185e68 + 0xd2));
      lVar3 = 0x1000 - lVar4;
    }
    iVar2 = scnprintf(param_2 + lVar4,lVar3,0xffffffc000dfa978);
    lVar4 = lVar4 + iVar2;
  }
  return lVar4;
}



// ============================================================================
// Function: stk3x1x_show_config at 0xffffffc00043e6e0
// ============================================================================

long stk3x1x_show_config(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27212,0xae5);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9a6a8,*(undefined4 *)(lRamffffffc001185e68 + 0x94)
                      ,*(undefined4 *)(lRamffffffc001185e68 + 0x9c),
                      *(undefined4 *)(lRamffffffc001185e68 + 0xa8),
                      *(undefined4 *)(lRamffffffc001185e68 + 0x164),
                      *(undefined4 *)(lRamffffffc001185e68 + 0x168),
                      *(undefined4 *)(lRamffffffc001185e68 + 0xac));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_trace at 0xffffffc00043e768
// ============================================================================

long stk3x1x_show_trace(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27232,0xb1b);
    lVar2 = 0;
  }
  else {
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9b228,*(undefined4 *)(lRamffffffc001185e68 + 0x90)
                     );
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_store_alsval at 0xffffffc00043e7cc
// ============================================================================

undefined8 stk3x1x_store_alsval(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  ushort uVar2;
  long *plVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  
  plVar3 = plRamffffffc001185e68;
  if (plRamffffffc001185e68 == (long *)0x0) {
    printk(0xffffffc000d9a528,&__func___27365,0xcef);
    param_3 = 0;
  }
  else {
    iVar4 = strcmp(param_2,0xffffffc000d9a6c0);
    if (iVar4 == 0) {
      lVar6 = *plVar3;
      uVar1 = *(undefined8 *)(lVar6 + 0x60);
      *(undefined8 *)((long)plVar3 + 0x114) = *(undefined8 *)(lVar6 + 0x58);
      *(undefined8 *)((long)plVar3 + 0x11c) = uVar1;
      uVar1 = *(undefined8 *)(lVar6 + 0x70);
      *(undefined8 *)((long)plVar3 + 0x124) = *(undefined8 *)(lVar6 + 0x68);
      *(undefined8 *)((long)plVar3 + 300) = uVar1;
      uVar1 = *(undefined8 *)(lVar6 + 0x80);
      *(undefined8 *)((long)plVar3 + 0x134) = *(undefined8 *)(lVar6 + 0x78);
      *(undefined8 *)((long)plVar3 + 0x13c) = uVar1;
      uVar1 = *(undefined8 *)(lVar6 + 0x90);
      *(undefined8 *)((long)plVar3 + 0x144) = *(undefined8 *)(lVar6 + 0x88);
      *(undefined8 *)((long)plVar3 + 0x14c) = uVar1;
    }
    else {
      uVar2 = *(ushort *)((long)plVar3 + 0xd4);
      uVar5 = read_int_from_buf_isra_11(param_2,param_3,*plVar3 + 0x58,uVar2);
      if (uVar2 != uVar5) {
        printk(0xffffffc000d9a558,&__func___27365,0xcf9,param_2);
      }
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_store_alslv at 0xffffffc00043e8b0
// ============================================================================

undefined8 stk3x1x_store_alslv(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ushort uVar2;
  long *plVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  
  plVar3 = plRamffffffc001185e68;
  if (plRamffffffc001185e68 == (long *)0x0) {
    printk(0xffffffc000d9a528,&__func___27349,0xcca);
    param_3 = 0;
  }
  else {
    iVar4 = strcmp(param_2,0xffffffc000d9a6c0);
    if (iVar4 == 0) {
      lVar6 = *plVar3;
      lVar1 = *(long *)(lVar6 + 0x24);
      plVar3[0x1b] = *(long *)(lVar6 + 0x1c);
      plVar3[0x1c] = lVar1;
      lVar1 = *(long *)(lVar6 + 0x34);
      plVar3[0x1d] = *(long *)(lVar6 + 0x2c);
      plVar3[0x1e] = lVar1;
      lVar1 = *(long *)(lVar6 + 0x44);
      plVar3[0x1f] = *(long *)(lVar6 + 0x3c);
      plVar3[0x20] = lVar1;
      plVar3[0x21] = *(long *)(lVar6 + 0x4c);
      *(undefined4 *)(plVar3 + 0x22) = *(undefined4 *)(lVar6 + 0x54);
    }
    else {
      uVar2 = *(ushort *)((long)plVar3 + 0xd2);
      uVar5 = read_int_from_buf_isra_11(param_2,param_3,*plVar3 + 0x1c,uVar2);
      if (uVar2 != uVar5) {
        printk(0xffffffc000d9a558,&__func___27349,0xcd4,param_2);
      }
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_show_chipinfo at 0xffffffc00043e99c
// ============================================================================

long stk3x1x_show_chipinfo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27250,0xb4e);
    lVar2 = 0;
  }
  else {
    iVar1 = sprintf(param_2,0xffffffc000eac888,0xffffffc000d9a488);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_ps_calibbias at 0xffffffc00043ea00
// ============================================================================

long stk3x1x_show_ps_calibbias(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStack_8 [4];
  int iStack_4;
  
  printk(0xffffffc000d9a6c8,0);
  iVar1 = iRamffffffc001185e74;
  if (iRamffffffc001185e70 == 1) {
    emmc_read(0xffffffc000d11e28,0x300014,4,auStack_8);
    sscanf(auStack_8,0xffffffc000e5d090,&iStack_4);
    printk(0xffffffc000d9a6f8,iStack_4);
    iVar1 = iStack_4;
    if (iStack_4 < 0) {
      iVar1 = sprintf(param_3,0xffffffc000e8cd68,0xffffffff);
      goto code_r0xffffffc00043ea4c;
    }
  }
  iVar1 = sprintf(param_3,0xffffffc000e8cd68,iVar1);
code_r0xffffffc00043ea4c:
  return (long)iVar1;
}



// ============================================================================
// Function: stk3x1x_show_ps_offset at 0xffffffc00043eabc
// ============================================================================

long stk3x1x_show_ps_offset(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_8 [4];
  undefined4 uStack_4;
  
  if (lRamffffffc001185e68 != 0) {
    emmc_read(0xffffffc000d11e28,0x300014,4,auStack_8);
    sscanf(auStack_8,0xffffffc000e5d090,&uStack_4);
    printk(0xffffffc000d9a6f8,uStack_4);
    printk(0xffffffc000d9a720,&__func___27428,*(undefined2 *)(lRamffffffc001185e68 + 0x192));
    iVar1 = snprintf(param_2,0x1000,0xffffffc000e8cd68,uStack_4);
    return (long)iVar1;
  }
  printk(0xffffffc000d9a528,&__func___27428,0xda9);
  return 0;
}



// ============================================================================
// Function: stk3x1x_get_addr at 0xffffffc00043ebb4
// ============================================================================

undefined8 stk3x1x_get_addr(long param_1,undefined1 *param_2)

{
  if (param_1 != 0) {
    if (param_2 != (undefined1 *)0x0) {
      param_2[1] = 1;
      param_2[2] = 2;
      param_2[3] = 3;
      param_2[4] = 4;
      param_2[5] = 5;
      param_2[6] = 6;
      param_2[7] = 7;
      param_2[8] = 8;
      param_2[9] = 9;
      param_2[10] = 10;
      param_2[0xb] = 0xb;
      param_2[0xc] = 0xc;
      param_2[0xd] = 0xd;
      param_2[0xe] = 0x10;
      param_2[0xf] = 0x11;
      param_2[0x10] = 0x12;
      param_2[0x11] = 0x13;
      param_2[0x12] = 0x14;
      param_2[0x13] = 0x15;
      param_2[0x14] = 0x16;
      param_2[0x15] = 0x17;
      *param_2 = 0;
      param_2[0x16] = 0x18;
      param_2[0x17] = 0x80;
      return 0;
    }
  }
  return 0xfffffff2;
}



// ============================================================================
// Function: stk3x1x_local_init at 0xffffffc00043ec8c
// ============================================================================

undefined8 stk3x1x_local_init(void)

{
  undefined8 uVar1;
  undefined1 auStack_18 [24];
  
  if ((uRamffffffc0010b55a2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b5580,0xffffffc000d9a400,&__func___28095);
  }
  stk3x1x_get_addr(uRamffffffc00100c210,auStack_18);
  uVar1 = i2c_register_driver(0,0xffffffc00100c238);
  if ((int)uVar1 == 0) {
    if (iRamffffffc00100c390 == -1) {
      printk(0xffffffc000d9a760,&__func___28095,0x162b,0xffffffff);
      uVar1 = 0xffffffff;
    }
  }
  else {
    printk(0xffffffc000d9a738,&__func___28095,0x1625);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ============================================================================
// Function: stk3x1x_hwmsen_read_block at 0xffffffc00043ed50
// ============================================================================

undefined8
stk3x1x_hwmsen_read_block(long param_1,undefined1 param_2,undefined8 param_3,ushort param_4)

{
  uint6 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 uStack_31;
  undefined8 uStack_30;
  undefined1 *puStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  uStack_20 = 0;
  uStack_8 = 0;
  puStack_28 = &uStack_31;
  uStack_30 = (ulong)CONCAT24(1,(uint)*(ushort *)(param_1 + 2));
  uStack_18._0_4_ = CONCAT22(1,*(ushort *)(param_1 + 2));
  uVar1 = CONCAT24(param_4,(undefined4)uStack_18);
  uStack_18 = (ulong)(uVar1 & 0xffffffffff);
  if (param_1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uStack_31 = param_2;
    uStack_10 = param_3;
    if ((param_4 & 0xff) < 9) {
      iVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&uStack_30,2);
      uVar3 = 0;
      if (iVar2 != 2) {
        printk(0xffffffc000d9a7d0,param_2,param_3,param_4 & 0xff,iVar2);
        uVar3 = 0xfffffffb;
      }
    }
    else {
      printk(0xffffffc000d9a7a8,param_4 & 0xff,8);
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}



// ============================================================================
// Function: stk3x1x_get_timing at 0xffffffc00043ee24
// ============================================================================

undefined8 stk3x1x_get_timing(void)

{
  return 200;
}



// ============================================================================
// Function: stk3x1x_master_recv at 0xffffffc00043ee2c
// ============================================================================

int stk3x1x_master_recv(long param_1,undefined1 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xc0) + 0x90);
  iVar2 = *(int *)(*(long *)(param_1 + 0xc0) + 0x94);
  if (0 < iVar2) {
    iVar5 = 1;
    do {
      iVar4 = iVar5;
      iVar5 = iVar4 + -1;
      iVar3 = stk3x1x_hwmsen_read_block(param_1,param_2,param_3,(char)param_4);
      if (iVar3 == 0) {
        if (uVar1 == 0) {
          return param_4;
        }
        if (iVar4 == 1) {
          return param_4;
        }
        if ((uVar1 >> 0xf & 1) == 0) {
          return param_4;
        }
        goto code_r0xffffffc00043ef34;
      }
      __const_udelay(0x68dbc);
      iVar5 = iVar4 + 1;
    } while (iVar4 + 1 != iVar2 + 1);
    if ((uVar1 == 0) || (iVar5 = iVar4, (uVar1 >> 0xf & 1) == 0)) {
      return iVar3;
    }
code_r0xffffffc00043ef34:
    printk(0xffffffc000d9a800,iVar5,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  return param_4;
}



// ============================================================================
// Function: stk3x1x_read_ps at 0xffffffc00043ef54
// ============================================================================

uint stk3x1x_read_ps(long param_1,undefined2 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  lVar4 = *(long *)(param_1 + 0xc0);
  if (param_1 == 0) {
    printk(0xffffffc000d9a820,&__func___26984,0x44f);
    uVar3 = 0xffffffea;
  }
  else {
    iVar2 = stk3x1x_master_recv(param_1,*(undefined1 *)(lVar4 + 0x87),&uStack_8,2);
    if (iVar2 < 0) {
      printk(0xffffffc000d9a848,iVar2);
      uVar3 = 0xfffffff2;
    }
    else {
      *param_2 = CONCAT11(uStack_8,uStack_7);
      uVar1 = *(uint *)(lVar4 + 0x90);
      uVar3 = uVar1 & 1;
      if ((uVar1 & 1) != 0) {
        printk(0xffffffc000d9a860,CONCAT11(uStack_8,uStack_7));
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



// ============================================================================
// Function: stk3x1x_show_ps at 0xffffffc00043effc
// ============================================================================

long stk3x1x_show_ps(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27262,0xb6c);
    lVar2 = 0;
  }
  else {
    iVar1 = stk3x1x_read_ps(*(undefined8 *)(lRamffffffc001185e68 + 8),lRamffffffc001185e68 + 0xce);
    if (iVar1 != 0) {
      iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9a878,iVar1);
      return (long)iVar1;
    }
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9b228,*(undefined2 *)(lRamffffffc001185e68 + 0xce)
                     );
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_cali at 0xffffffc00043f0b0
// ============================================================================

long stk3x1x_show_cali(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27373,0xd07);
    lVar4 = 0;
  }
  else {
    iVar3 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x20,&uStack_8,2);
    uVar2 = uStack_7;
    uVar1 = uStack_8;
    if (iVar3 < 0) {
      uVar5 = 0xd0e;
    }
    else {
      iVar3 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x22,&uStack_8,2);
      if (-1 < iVar3) {
        printk(0xffffffc000d9a8b0,&__func___27373,*(undefined2 *)(lRamffffffc001185e68 + 0x18a),
               *(undefined2 *)(lRamffffffc001185e68 + 0x186),
               *(undefined2 *)(lRamffffffc001185e68 + 0x188),
               (uint)CONCAT11(uStack_8,uStack_7) + (uint)CONCAT11(uVar1,uVar2));
        printk(0xffffffc000d9a8e8,&__func___27373,*(undefined2 *)(lRamffffffc001185e68 + 0x194),
               *(undefined2 *)(lRamffffffc001185e68 + 0x196));
        iVar3 = scnprintf(param_2,0x1000,0xffffffc000f15e00,
                          *(undefined2 *)(lRamffffffc001185e68 + 0x18a));
        return (long)iVar3;
      }
      uVar5 = 0xd16;
    }
    printk(0xffffffc000d9a888,&__func___27373,uVar5,&__func___27373,iVar3);
    lVar4 = (long)iVar3;
  }
  return lVar4;
}



// ============================================================================
// Function: stk3x1x_show_allreg at 0xffffffc00043f20c
// ============================================================================

long stk3x1x_show_allreg(undefined8 param_1,long param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined2 uStack_8;
  
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  uStack_8 = 0;
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27303,0xc13);
    lVar4 = 0;
  }
  else {
    iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0,&uStack_28,7);
    if ((((iVar2 < 0) ||
         (iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),7,
                                      (long)&uStack_28 + 7,7), iVar2 < 0)) ||
        (iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0xe,
                                     (long)&uStack_20 + 6,7), iVar2 < 0)) ||
       (((iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x15,
                                      (long)&uStack_18 + 5,7), iVar2 < 0 ||
         (iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x1c,
                                      (long)&uStack_10 + 4,4), iVar2 < 0)) ||
        (iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x3e,&uStack_8,2),
        iVar2 < 0)))) {
      printk(0xffffffc000d9a848,iVar2);
      lVar4 = -0xe;
    }
    else {
      uVar6 = 0;
      iVar2 = 0;
      do {
        printk(0xffffffc000d9a910,uVar6 & 0xffffffff,*(undefined1 *)((long)&uStack_28 + uVar6));
        puVar1 = (undefined1 *)((long)&uStack_28 + uVar6);
        uVar5 = uVar6 & 0xffffffff;
        uVar6 = uVar6 + 1;
        iVar3 = scnprintf(param_2 + iVar2,0x1000 - (long)iVar2,0xffffffc000d9a930,uVar5,*puVar1);
        iVar2 = iVar2 + iVar3;
      } while (uVar6 != 0x20);
      printk(0xffffffc000d9a940,(undefined1)uStack_8);
      printk(0xffffffc000d9a960,(undefined1)uStack_8);
      iVar3 = scnprintf(param_2 + iVar2,0x1000 - (long)iVar2,0xffffffc000d9a980,(undefined1)uStack_8
                        ,uStack_8._1_1_);
      lVar4 = (long)(iVar3 + iVar2);
    }
  }
  return lVar4;
}



// ============================================================================
// Function: stk3x1x_store_recv at 0xffffffc00043f3e4
// ============================================================================

undefined8 stk3x1x_store_recv(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bStack_5;
  undefined4 uStack_4;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27294,0xbbc);
  }
  else {
    iVar1 = sscanf(param_2,0xffffffc000d4f720,&uStack_4);
    if (iVar1 == 1) {
      uVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),uStack_4,&bStack_5,1);
      printk(0xffffffc000d9a998,uStack_4,uVar2,bStack_5);
      *(uint *)(lRamffffffc001185e68 + 0x180) = (uint)bStack_5;
      return param_3;
    }
    printk(0xffffffc000d9a558,&__func___27294,0xbc1,param_2);
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_show_status at 0xffffffc00043f4d4
// ============================================================================

long stk3x1x_show_status(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined1 uStack_8;
  
  if (puRamffffffc001185e68 == (undefined8 *)0x0) {
    printk(0xffffffc000d9a528,&__func___27314,0xc55);
    lVar4 = 0;
  }
  else {
    puVar2 = (undefined4 *)*puRamffffffc001185e68;
    if (puVar2 == (undefined4 *)0x0) {
      iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9aa08);
    }
    else {
      iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9a9c0,*puVar2,puVar2[1],puVar2[2],
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x86),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x7a),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x89),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x8a),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x79),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x87),
                        *(undefined1 *)(puRamffffffc001185e68 + 0x11),
                        *(undefined1 *)((long)puRamffffffc001185e68 + 0x7e));
    }
    lVar4 = (long)iVar1;
    uVar3 = puRamffffffc001185e68[0x2e];
    iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000d9aa18,
                      *(undefined4 *)((long)puRamffffffc001185e68 + 0x154),
                      *(undefined4 *)(puRamffffffc001185e68 + 0x2b),
                      *(undefined4 *)((long)puRamffffffc001185e68 + 0x15c),
                      *(undefined1 *)((long)puRamffffffc001185e68 + 0x161),
                      *(undefined1 *)((long)puRamffffffc001185e68 + 0x162),
                      *(undefined1 *)(puRamffffffc001185e68 + 0x2c),
                      *(undefined4 *)((long)puRamffffffc001185e68 + 0x164),
                      *(undefined4 *)(puRamffffffc001185e68 + 0x2d),uVar3,
                      puRamffffffc001185e68[0x2f]);
    uVar5 = (undefined4)((ulong)uVar3 >> 0x20);
    lVar4 = lVar4 + iVar1;
    iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000d9aa58,
                      *(undefined4 *)(puRamffffffc001185e68 + 0x13),
                      *(undefined4 *)(puRamffffffc001185e68 + 0x17));
    lVar4 = lVar4 + iVar1;
    iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000d9aa68,0xffffffc000d9aa78);
    uStack_10 = 0;
    lVar4 = lVar4 + iVar1;
    uStack_20 = 0;
    uStack_18 = 0;
    uStack_8 = 0;
    iVar1 = stk3x1x_master_recv(puRamffffffc001185e68[1],0,&uStack_20,7);
    if (((iVar1 < 0) ||
        (iVar1 = stk3x1x_master_recv(puRamffffffc001185e68[1],7,(long)&uStack_20 + 7,7), iVar1 < 0))
       || (iVar1 = stk3x1x_master_recv(puRamffffffc001185e68[1],0xe,(long)&uStack_18 + 6,7),
          iVar1 < 0)) {
      printk(0xffffffc000d9a848,iVar1);
      lVar4 = -0xe;
    }
    else {
      iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,0xffffffc000d9aa88,(byte)uStack_20 & 1,
                        (byte)uStack_20 >> 1 & 1,
                        ((byte)uStack_20 >> 2 & 1) * (uint)uStack_20._5_1_ * 6,
                        (byte)uStack_20 >> 5 & 1,(byte)uStack_20 >> 6 & 1,(byte)uStack_10 & 1,
                        (byte)uStack_10 >> 2 & 1,(byte)uStack_10 >> 4 & 1,
                        CONCAT44(uVar5,(uint)((byte)uStack_10 >> 5)) & 0xffffffff00000001);
      lVar4 = lVar4 + iVar1;
    }
  }
  return lVar4;
}



// ============================================================================
// Function: stk3x1x_ps_val at 0xffffffc00043f738
// ============================================================================

int stk3x1x_ps_val(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  iVar2 = stk3x1x_master_recv(*(undefined8 *)(lRamffffffc001185e68 + 8),0x20,&uStack_8,4);
  if (iVar2 < 0) {
    printk(0xffffffc000d9a888,&__func___27125,0x873,&__func___27125,iVar2);
  }
  else {
    uVar1 = *(uint *)(lRamffffffc001185e68 + 0x158) & 0x3f;
    if (uVar1 == 0x30) {
      uVar3 = 100;
    }
    else if (uVar1 == 0x31) {
      uVar3 = 200;
    }
    else if (uVar1 == 0x32) {
      uVar3 = 400;
    }
    else {
      uVar3 = 800;
      if (uVar1 != 0x33) {
        printk(0xffffffc000d9ab08,&__func___27125,0x88c,&__func___27125);
        return -1;
      }
    }
    iVar2 = 0;
    if (uVar3 < (uint)CONCAT11(uStack_6,uStack_5) + (uint)CONCAT11(uStack_8,uStack_7)) {
      printk(0xffffffc000d9ab38,&__func___27125);
      iVar2 = 0xffff;
    }
  }
  return iVar2;
}



// ============================================================================
// Function: stk3x1x_master_send at 0xffffffc00043f85c
// ============================================================================

int stk3x1x_master_send(long param_1,undefined1 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xc0) + 0x90);
  iVar2 = *(int *)(*(long *)(param_1 + 0xc0) + 0x94);
  if (0 < iVar2) {
    iVar5 = 1;
    do {
      iVar4 = iVar5;
      iVar5 = iVar4 + -1;
      iVar3 = hwmsen_write_block(param_1,param_2,param_3,(char)param_4);
      if (iVar3 == 0) {
        if (uVar1 == 0) {
          return param_4;
        }
        if (iVar4 == 1) {
          return param_4;
        }
        if ((uVar1 >> 0xf & 1) == 0) {
          return param_4;
        }
        goto code_r0xffffffc00043f964;
      }
      __const_udelay(0x68dbc);
      iVar5 = iVar4 + 1;
    } while (iVar4 + 1 != iVar2 + 1);
    if ((uVar1 == 0) || (iVar5 = iVar4, (uVar1 >> 0xf & 1) == 0)) {
      return iVar3;
    }
code_r0xffffffc00043f964:
    printk(0xffffffc000d9ab60,iVar5,iVar2);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  return param_4;
}



// ============================================================================
// Function: stk3x1x_store_send at 0xffffffc00043f984
// ============================================================================

undefined8 stk3x1x_store_send(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_9;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27281,0xb9c);
  }
  else {
    iVar1 = sscanf(param_2,0xffffffc000d9ab80,&uStack_8,&uStack_4);
    if (iVar1 == 2) {
      uStack_9 = (undefined1)uStack_4;
      uVar2 = stk3x1x_master_send(*(undefined8 *)(lRamffffffc001185e68 + 8),uStack_8,&uStack_9,1);
      printk(0xffffffc000d9ab88,uStack_8,uStack_4,uVar2);
      return param_3;
    }
    printk(0xffffffc000d9a558,&__func___27281,0xba1,param_2);
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_write_led at 0xffffffc00043fa74
// ============================================================================

undefined8 stk3x1x_write_led(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x7b),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9abb0,&__func___26911,0x2aa);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_als at 0xffffffc00043fb64
// ============================================================================

undefined8 stk3x1x_write_als(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x7a),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9abd8,&__func___26944,0x368);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_read_state at 0xffffffc00043fbbc
// ============================================================================

undefined8 stk3x1x_read_state(long param_1,undefined1 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar1 = stk3x1x_master_recv(param_1,0,&uStack_1,1);
    if (iVar1 < 0) {
      printk(0xffffffc000d9a848,iVar1);
      uVar2 = 0xfffffff2;
    }
    else {
      uVar2 = 0;
      *param_2 = uStack_1;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_read_flag at 0xffffffc00043fc1c
// ============================================================================

uint stk3x1x_read_flag(long param_1,undefined1 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined1 uStack_1;
  
  lVar4 = *(long *)(param_1 + 0xc0);
  if (param_1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    iVar2 = stk3x1x_master_recv(param_1,*(undefined1 *)(lVar4 + 0x86),&uStack_1,1);
    if (iVar2 < 0) {
      printk(0xffffffc000d9a848,iVar2);
      uVar3 = 0xfffffff2;
    }
    else {
      *param_2 = uStack_1;
      uVar1 = *(uint *)(lVar4 + 0x90);
      uVar3 = uVar1 & 1;
      if ((uVar1 & 1) != 0) {
        printk(0xffffffc000d9ac00);
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



// ============================================================================
// Function: stk3x1x_get_ps_value at 0xffffffc00043fc9c
// ============================================================================

ulong stk3x1x_get_ps_value(long param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  byte bStack_1;
  
  iVar2 = *(int *)(param_1 + 0xa8);
  uVar3 = stk3x1x_read_flag(*(undefined8 *)(param_1 + 8),&bStack_1);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  uVar1 = bStack_1 & 1;
  printk(0xffffffc000d9ac20,&__func___27927,bStack_1,uVar1);
  if (*(int *)(param_1 + 0xb8) == 0) {
    if (*(int *)(param_1 + 0xb0) == 1) {
      if (*(int *)(param_1 + 0xb4) - lRamffffffc000fbc180 < 0) {
        *(undefined4 *)(param_1 + 0xb0) = 0;
      }
      if (*(int *)(param_1 + 0xb0) == 1) goto code_r0xffffffc00043fd4c;
    }
    if ((*(uint *)(param_1 + 0x90) >> 6 & 1) == 0) {
      uVar3 = (ulong)uVar1;
    }
    else if (iVar2 == 0) {
      printk(0xffffffc000d9ac78,param_2,uVar1);
      uVar3 = (ulong)uVar1;
    }
    else {
      printk(0xffffffc000d9ac50,param_2,uVar1);
      uVar3 = (ulong)uVar1;
    }
  }
  else {
code_r0xffffffc00043fd4c:
    printk(0xffffffc000d9acc0,&__func___27927,0x106c,param_2,uVar1);
    if ((*(uint *)(param_1 + 0x90) >> 6 & 1) == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      printk(0xffffffc000d9ac98,param_2,uVar1);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}



// ============================================================================
// Function: stk3x1x_check_intr at 0xffffffc00043fe64
// ============================================================================

uint stk3x1x_check_intr(long param_1,byte *param_2)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xc0);
  iVar3 = stk3x1x_read_flag();
  if (-1 < iVar3) {
    lVar1 = lVar5 + 0x178;
    printk(0xffffffc000d9ad38,&__func___27109,*param_2);
    if ((*param_2 >> 5 & 1) == 0) {
      clear_bit(1,lVar1);
      bVar2 = *param_2;
    }
    else {
      set_bit(1,lVar1);
      bVar2 = *param_2;
    }
    if ((bVar2 >> 4 & 1) == 0) {
      clear_bit(2,lVar1);
    }
    else {
      set_bit(2,lVar1);
    }
    uVar4 = *(uint *)(lVar5 + 0x90) & 0x8000;
    if ((*(uint *)(lVar5 + 0x90) >> 0xf & 1) != 0) {
      printk(0xffffffc000d9ad60,*param_2,*(undefined8 *)(lVar5 + 0x178));
      uVar4 = 0;
    }
    return uVar4;
  }
  printk(0xffffffc000d9ad00,&__func___27109,0x7ba);
  return 0xfffffff2;
}



// ============================================================================
// Function: stk3x1x_eint_work at 0xffffffc00043ff50
// ============================================================================

void stk3x1x_eint_work(void)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  byte bStack_1;
  
  lVar1 = lRamffffffc001185e68;
  printk(0xffffffc000d9ad90);
  iVar2 = stk3x1x_check_intr(*(undefined8 *)(lVar1 + 8),&bStack_1);
  if (iVar2 != 0) {
    printk(0xffffffc000d9ada8,&__func___27182,0x9ef,iVar2);
    msleep(0x1e);
    enable_irq(*(undefined4 *)(lVar1 + 200));
    return;
  }
  printk(0xffffffc000d9add8,*(undefined8 *)(lVar1 + 0x178));
  if (bRamffffffc00100c394 != (bStack_1 & 1)) {
    printk(0xffffffc000d9ae00);
    iVar2 = stk3x1x_read_ps(*(undefined8 *)(lVar1 + 8),lVar1 + 0xce);
    if (iVar2 != 0) {
      printk(0xffffffc000d9ae20,&__func___27182,0x9fb,iVar2);
      goto code_r0xffffffc00043ffc4;
    }
    uVar3 = (uint)bStack_1;
    printk(0xffffffc000d9ae50,&__func___27182,*(undefined2 *)(lVar1 + 0xce),uVar3 & 1);
    iVar2 = ps_report_interrupt_data((uVar3 & 1) << 2);
    if (iVar2 != 0) {
      printk(0xffffffc000d9ae80,&__func___27182,0xa06);
    }
    bRamffffffc00100c394 = bStack_1 & 1;
  }
  msleep(1);
  enable_irq(*(undefined4 *)(lVar1 + 200));
code_r0xffffffc00043ffc4:
  msleep(0x1e);
  enable_irq(*(undefined4 *)(lVar1 + 200));
  return;
}



// ============================================================================
// Function: stk3x1x_read_id at 0xffffffc0004400c4
// ============================================================================

undefined8 stk3x1x_read_id(long param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char cStack_9;
  byte bStack_8;
  char cStack_7;
  
  lVar4 = *(long *)(param_1 + 0xc0);
  if (param_1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    *(undefined2 *)(lVar4 + 0x282) = 0x400;
    *(undefined1 *)(lVar4 + 0x281) = 0;
    iVar2 = stk3x1x_master_recv(param_1,0x3e,&bStack_8,2);
    if (iVar2 < 0) {
      printk(0xffffffc000d9a848,iVar2);
      uVar3 = 0xfffffff2;
    }
    else {
      *(byte *)(lVar4 + 0x280) = bStack_8;
      printk(0xffffffc000d9aeb8,&__func___26972,bStack_8,cStack_7);
      if ((*(char *)(lVar4 + 0x280) == '\x1e') || (*(char *)(lVar4 + 0x280) == '\x17')) {
        *(byte *)(lVar4 + 0x161) = *(byte *)(lVar4 + 0x161) & 0x3f;
      }
      if (bStack_8 == 0x1d) {
        *(byte *)(lVar4 + 0x281) = *(byte *)(lVar4 + 0x281) | 4;
      }
      if (cStack_7 == -0x3d) {
        *(byte *)(lVar4 + 0x281) = *(byte *)(lVar4 + 0x281) | 2;
      }
      cStack_9 = '\x02';
      iVar2 = stk3x1x_master_send(param_1,0,&cStack_9,1);
      if (iVar2 < 0) {
        printk(0xffffffc000d9aee0,&__func___26964,0x3e2);
      }
      else {
        cStack_9 = '%';
        iVar2 = stk3x1x_master_send(param_1,0x90,&cStack_9,1);
        if (iVar2 < 0) {
          printk(0xffffffc000d9af08,&__func___26964,0x3ea);
        }
        else {
          cStack_9 = -0x7e;
          iVar2 = stk3x1x_master_send(param_1,0x92,&cStack_9,1);
          if (iVar2 < 0) {
            printk(0xffffffc000d9aee0,&__func___26964,0x3f2);
          }
          else {
            usleep_range(1000,5000);
            iVar2 = stk3x1x_master_recv(param_1,0x91,&cStack_9,1);
            cVar1 = cStack_9;
            if (iVar2 < 0) {
              printk(0xffffffc000d9a848,iVar2);
            }
            else {
              cStack_9 = '\0';
              iVar2 = stk3x1x_master_send(param_1,0,&cStack_9,1);
              if (iVar2 < 0) {
                printk(0xffffffc000d9aee0,&__func___26964,0x403);
              }
              else {
                printk(0xffffffc000d9af30,&__func___26964,cVar1);
                if (cVar1 < '\0') {
                  *(undefined2 *)(lVar4 + 0x282) = 0x400;
                  *(byte *)(lVar4 + 0x281) = *(byte *)(lVar4 + 0x281) | 1;
                }
              }
            }
          }
        }
      }
      printk(0xffffffc000d9af50,&__func___26972,*(undefined1 *)(lVar4 + 0x281));
      if (bStack_8 == 0) {
        printk(0xffffffc000d9af80,&__func___26972,0x435);
        uVar3 = 0xfffffffe;
      }
      else {
        bStack_8 = bStack_8 & 0xf0;
        if (((bStack_8 == 0x20) || (bStack_8 == 0x30)) || (bStack_8 == 0x10)) {
          uVar3 = 0;
        }
        else {
          printk(0xffffffc000d9afc8,&__func___26972,0x441);
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  return uVar3;
}



// ============================================================================
// Function: stk3x1x_write_ps at 0xffffffc00044038c
// ============================================================================

undefined8 stk3x1x_write_ps(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x79),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9aff0,&__func___26991,0x46d);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_wait at 0xffffffc0004403e4
// ============================================================================

undefined8 stk3x1x_write_wait(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x7d),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9b018,&__func___26998,0x47c);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_int at 0xffffffc00044043c
// ============================================================================

undefined8 stk3x1x_write_int(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x7c),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9b040,&__func___27005,0x48b);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_state at 0xffffffc000440494
// ============================================================================

undefined8 stk3x1x_write_state(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x78),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9b068,&__func___27012,0x4a9);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_flag at 0xffffffc0004404ec
// ============================================================================

undefined8 stk3x1x_write_flag(long param_1,undefined1 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_1;
  
  uStack_1 = param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(*(long *)(param_1 + 0xc0) + 0x86),&uStack_1,1)
  ;
  uVar2 = 0;
  if (iVar1 < 0) {
    printk(0xffffffc000d9aff0,&__func___27019,0x4b7);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_get_ir_value at 0xffffffc000440544
// ============================================================================

uint stk3x1x_get_ir_value(long param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  uint unaff_w21;
  undefined8 uVar3;
  byte bStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  *(undefined4 *)(param_1 + 0x290) = 1;
  uVar1 = (*(uint *)(param_1 + 0x15c) & 0xf) - param_2 & 0xff;
  switch(uVar1) {
  case 2:
    uVar3 = 1;
    break;
  case 3:
    uVar3 = 2;
    break;
  case 4:
    uVar3 = 3;
    break;
  case 5:
    uVar3 = 6;
    break;
  case 6:
    uVar3 = 0xc;
    break;
  case 7:
    uVar3 = 0x18;
    break;
  case 8:
    uVar3 = 0x30;
    break;
  case 9:
    uVar3 = 0x60;
    break;
  default:
    uVar1 = 0xffffffea;
    printk(0xffffffc000d9b090,&__func___27952,0x1098,&__func___27952);
    goto code_r0xffffffc0004405a4;
  }
  uVar1 = i2c_smbus_write_byte_data
                    (*(undefined8 *)(param_1 + 8),2,uVar1 | *(uint *)(param_1 + 0x15c) & 0xf0);
  if ((int)uVar1 < 0) {
    printk(0xffffffc000d9b0c0,&__func___27952,0x10a0,&__func___27952);
    goto code_r0xffffffc0004405a4;
  }
  uVar1 = i2c_smbus_write_byte_data
                    (*(undefined8 *)(param_1 + 8),0,*(uint *)(param_1 + 0x154) | 0xffffff80);
  if ((int)uVar1 < 0) {
    uVar3 = 0x10c5;
  }
  else {
    cVar2 = '\0';
    msleep(uVar3);
    do {
      msleep(3);
      uVar1 = stk3x1x_read_flag(*(undefined8 *)(param_1 + 8),&bStack_9);
      if ((int)uVar1 < 0) {
        printk(0xffffffc000d9ad00,&__func___27965,0x10d0,uVar1);
        goto code_r0xffffffc0004405a4;
      }
      cVar2 = cVar2 + '\x01';
      if (cVar2 == '\n') {
        printk(0xffffffc000d9b110,&__func___27965,0x10d8,&__func___27965);
        uVar1 = stk3x1x_write_flag(*(undefined8 *)(param_1 + 8),(bStack_9 | 0x36) & 0xfd);
        if ((uVar1 == 0) ||
           (printk(0xffffffc000d9b150,&__func___27116,0x7e2,uVar1), -1 < (int)uVar1))
        goto code_r0xffffffc000440698;
        goto code_r0xffffffc0004407ec;
      }
    } while ((bStack_9 >> 1 & 1) == 0);
    uVar1 = stk3x1x_write_flag(*(undefined8 *)(param_1 + 8),(bStack_9 | 0x36) & 0xfd);
    if ((uVar1 != 0) && (printk(0xffffffc000d9b150,&__func___27116,0x7e2,uVar1), (int)uVar1 < 0)) {
code_r0xffffffc0004407ec:
      printk(0xffffffc000d9b0c0,&__func___27965,0x10e1,&__func___27965);
      goto code_r0xffffffc0004405a4;
    }
    uVar1 = stk3x1x_master_recv(*(undefined8 *)(param_1 + 8),0x17,&uStack_8,2);
    if ((int)uVar1 < 0) {
      printk(0xffffffc000d9b0e8,&__func___27965,0x10e9,&__func___27965,uVar1);
      goto code_r0xffffffc0004405a4;
    }
    unaff_w21 = (uint)CONCAT11(uStack_8,uStack_7);
    *(ushort *)(param_1 + 0x276) = CONCAT11(uStack_8,uStack_7);
code_r0xffffffc000440698:
    uVar1 = i2c_smbus_write_byte_data
                      (*(undefined8 *)(param_1 + 8),2,*(undefined4 *)(param_1 + 0x15c));
    if (-1 < (int)uVar1) {
      *(undefined4 *)(param_1 + 0x290) = 0;
      return unaff_w21;
    }
    uVar3 = 0x10f2;
  }
  printk(0xffffffc000d9b0c0,&__func___27965,uVar3,&__func___27965);
code_r0xffffffc0004405a4:
  *(undefined4 *)(param_1 + 0x290) = 0;
  return uVar1;
}



// ============================================================================
// Function: stk3x1x_read_als at 0xffffffc00044085c
// ============================================================================

uint stk3x1x_read_als(long param_1,undefined2 *param_2)

{
  long lVar1;
  int iVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  lVar9 = *(long *)(param_1 + 0xc0);
  iVar7 = *(int *)(lVar9 + 0x270);
  if (param_1 == 0) {
    return 0xffffffea;
  }
  iVar6 = stk_als_ir_skip_als(lVar9);
  if (iVar6 == 1) {
    uRamffffffc001185f48 = 1;
    return 0;
  }
  iVar6 = stk3x1x_master_recv(param_1,*(undefined1 *)(lVar9 + 0x89),&uStack_8,2);
  if (iVar6 < 0) {
    printk(0xffffffc000d9a848,iVar6);
    return 0xfffffff2;
  }
  uVar10 = (uint)CONCAT11(uStack_8,uStack_7);
  if ((*(byte *)(lVar9 + 0x281) & 5) == 5) {
    iVar2 = uVar10 * *(ushort *)(lVar9 + 0x282);
    iVar6 = iVar2 + 0x3ff;
    if (-1 < iVar2) {
      iVar6 = iVar2;
    }
    if (0xffff < iVar6 >> 10) {
      uVar10 = 0xffff;
      goto code_r0xffffffc0004408fc;
    }
    uVar10 = iVar6 >> 10 & 0xffff;
  }
  if (((uVar10 < 0x1e) && ((*(byte *)(lVar9 + 0x281) >> 1 & 1) != 0)) &&
     (10000 < *(uint *)(lVar9 + 0x284))) {
    iVar6 = stk3x1x_get_ir_value(lVar9,5);
    if (iVar6 < 1) {
      printk(0xffffffc000d9b188,&__func___26937,uVar10,*(undefined4 *)(lVar9 + 0x284),iVar6);
    }
    else {
      *(short *)(lVar9 + 0x274) = (short)(iVar6 << 3);
      printk(0xffffffc000d9b188,&__func___26937,uVar10,*(undefined4 *)(lVar9 + 0x284),iVar6);
      if (1000 < iVar6) {
        uVar10 = *(uint *)(lVar9 + 0x284) & 0xffff;
      }
    }
  }
code_r0xffffffc0004408fc:
  iVar6 = *(int *)(lVar9 + 0x268);
  *(uint *)(lVar9 + 0x284) = uVar10;
  if (iVar6 < iVar7) {
    *(short *)(lVar9 + (long)iVar6 * 2 + 0x224) = (short)uVar10;
    *(int *)(lVar9 + 0x268) = iVar6 + 1;
    *(int *)(lVar9 + 0x26c) = *(int *)(lVar9 + 0x26c) + 1;
    *(uint *)(lVar9 + 0x264) = *(int *)(lVar9 + 0x264) + uVar10;
  }
  else {
    iVar6 = *(int *)(lVar9 + 0x26c);
    iVar2 = *(int *)(lVar9 + 0x264);
    iVar5 = 0;
    if (iVar7 != 0) {
      iVar5 = iVar6 / iVar7;
    }
    lVar1 = lVar9 + (long)(iVar6 - iVar5 * iVar7) * 2;
    uVar3 = *(ushort *)(lVar1 + 0x224);
    *(short *)(lVar1 + 0x224) = (short)uVar10;
    *(int *)(lVar9 + 0x26c) = iVar6 + 1;
    iVar6 = (iVar2 - (uint)uVar3) + uVar10;
    *(int *)(lVar9 + 0x264) = iVar6;
    uVar10 = 0;
    if (iVar7 != 0) {
      uVar10 = iVar6 / iVar7;
    }
    uVar10 = uVar10 & 0xffff;
  }
  uVar3 = *(ushort *)(lVar9 + 0x274);
  uRamffffffc001185f48 = 0;
  if (uVar3 == 0) {
    uVar8 = 1000;
    *(undefined2 *)(lVar9 + 0x278) = 1000;
  }
  else {
    if ((((uVar10 - 0x1a & 0xffff) < 0x4e06) && (0x32 < uVar3)) &&
       ((uVar10 * 0x29 < (uint)uVar3 || ((uint)uVar3 != uVar10 * 8 && uVar10 * 8 <= (uint)uVar3))))
    {
      *(undefined2 *)(lVar9 + 0x278) = 0x6ae;
    }
    else {
      *(undefined2 *)(lVar9 + 0x278) = 0x8ac;
    }
    printk(0xffffffc000d9b1c8,&__func___26937,uVar10,uVar3,*(undefined2 *)(lVar9 + 0x278));
    uVar8 = (uint)*(ushort *)(lVar9 + 0x278);
  }
  *param_2 = (short)((int)(uVar10 * uVar8) / 1000);
  if (((uint)*(ushort *)(lVar9 + 0x28c) + (*(ushort *)(lVar9 + 0x28c) / 10) * -10 & 0xffff) == 0) {
    iVar7 = stk3x1x_get_ir_value(lVar9,2);
    if (iVar7 < 1) {
      uVar4 = *(undefined2 *)(lVar9 + 0x274);
    }
    else {
      uVar4 = (undefined2)iVar7;
      *(undefined2 *)(lVar9 + 0x274) = uVar4;
    }
    uRamffffffc001185f48 = 1;
  }
  else {
    uVar4 = *(undefined2 *)(lVar9 + 0x274);
  }
  printk(0xffffffc000d9b200,&__func___26937,uVar4);
  uVar10 = *(uint *)(lVar9 + 0x90) & 1;
  if ((*(uint *)(lVar9 + 0x90) & 1) != 0) {
    printk(0xffffffc000d9b218,*param_2);
    uVar10 = 0;
  }
  return uVar10;
}



// ============================================================================
// Function: stk3x1x_show_als at 0xffffffc000440bc8
// ============================================================================

long stk3x1x_show_als(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (plRamffffffc001185e68 == (long *)0x0) {
    printk(0xffffffc000d9a528,&__func___27256,0xb59);
    lVar2 = 0;
  }
  else {
    if (*(int *)(*plRamffffffc001185e68 + 0x14) == 0) {
      iVar1 = stk3x1x_read_als(plRamffffffc001185e68[1],(long)plRamffffffc001185e68 + 0xcc);
      if (iVar1 != 0) {
        iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9a878,iVar1);
        return (long)iVar1;
      }
      iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9b228,
                        *(undefined2 *)((long)plRamffffffc001185e68 + 0xcc));
      return (long)iVar1;
    }
    iVar1 = scnprintf(param_2,0x1000,0xffffffc000d9b228,
                      *(undefined4 *)((long)plRamffffffc001185e68 + 0x284));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



// ============================================================================
// Function: stk3x1x_show_ir at 0xffffffc000440d80
// ============================================================================

long stk3x1x_show_ir(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27245,0xb3e);
    lVar3 = 0;
  }
  else {
    uVar1 = stk3x1x_get_ir_value(lRamffffffc001185e68,2);
    if ((int)uVar1 < 0) {
      iVar2 = scnprintf(param_2,0x1000,0xffffffc000d9a878,uVar1);
      return (long)iVar2;
    }
    *(short *)(lRamffffffc001185e68 + 0x274) = (short)uVar1;
    iVar2 = scnprintf(param_2,0x1000,0xffffffc000d9b228,uVar1 & 0xffff);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



// ============================================================================
// Function: stk3x1x_write_sw_reset at 0xffffffc000440e3c
// ============================================================================

undefined8 stk3x1x_write_sw_reset(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char cStack_2;
  char cStack_1;
  
  cStack_1 = '\0';
  lVar3 = *(long *)(param_1 + 0xc0);
  cStack_2 = '\x7f';
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x7d),&cStack_2,1);
  if (iVar1 < 0) {
    printk(0xffffffc000d9b230,&__func___27027,0x4d7);
    uVar2 = 0xfffffff2;
  }
  else {
    iVar1 = stk3x1x_master_recv(param_1,*(undefined1 *)(lVar3 + 0x7d),&cStack_1,1);
    if (iVar1 < 0) {
      printk(0xffffffc000d9b260,&__func___27027,0x4de);
      uVar2 = 0xfffffff2;
    }
    else if (cStack_2 == cStack_1) {
      cStack_2 = '\0';
      iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x8f),&cStack_2,1);
      if (iVar1 < 0) {
        printk(0xffffffc000d9b2f0,&__func___27027,0x4eb);
        uVar2 = 0xfffffff2;
      }
      else {
        msleep(0xd);
        uVar2 = 0;
      }
    }
    else {
      printk(0xffffffc000d9b290,&__func___27027,0x4e4);
      uVar2 = 0xfffffffb;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_ps_high_thd at 0xffffffc000440f74
// ============================================================================

undefined8 stk3x1x_write_ps_high_thd(long param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uStack_8;
  undefined1 auStack_7 [7];
  
  uStack_8 = (undefined1)((ushort)param_2 >> 8);
  lVar3 = *(long *)(param_1 + 0xc0);
  auStack_7[0] = (undefined1)param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x7e),&uStack_8,1);
  if (iVar1 < 0) {
    printk(0xffffffc000d9b328,&__func___27035,0x4ff);
    uVar2 = 0xfffffff2;
  }
  else {
    iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x7f),auStack_7,1);
    uVar2 = 0;
    if (iVar1 < 0) {
      printk(0xffffffc000d9b328,&__func___27035,0x506);
      uVar2 = 0xfffffff2;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_write_ps_low_thd at 0xffffffc000441024
// ============================================================================

undefined8 stk3x1x_write_ps_low_thd(long param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uStack_8;
  undefined1 auStack_7 [7];
  
  uStack_8 = (undefined1)((ushort)param_2 >> 8);
  lVar3 = *(long *)(param_1 + 0xc0);
  auStack_7[0] = (undefined1)param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x80),&uStack_8,1);
  if (iVar1 < 0) {
    uVar2 = 0x518;
  }
  else {
    iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x81),auStack_7,1);
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = 0x51f;
  }
  printk(0xffffffc000d9b348,&__func___27043,uVar2,&__func___27043);
  return 0xfffffff2;
}



// ============================================================================
// Function: stk3x1x_enable_ps.isra.36 at 0xffffffc0004410c4
// ============================================================================

int stk3x1x_enable_ps_isra_36(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long *plVar5;
  uint uVar6;
  
  plVar5 = *(long **)(param_1 + 0xc0);
  uVar1 = *(uint *)((long)plVar5 + 0x154);
  uVar2 = *(uint *)(plVar5 + 0x12);
  printk(0xffffffc000d9b370,&__func___27085,param_2);
  if ((param_2 == 0) && (*(short *)((long)plVar5 + 0x18a) == 0)) {
    printk(0xffffffc000d9b390,&__func___27085,0x621);
    hrtimer_cancel(plVar5 + 0x34);
    cancel_work_sync(plVar5 + 0x3d);
  }
  if (*(char *)((long)plVar5 + 0x184) != '\0') {
    *(undefined1 *)((long)plVar5 + 0x184) = 0;
  }
  uVar6 = uVar1 & 0xffffffba;
  if (param_2 == 0) {
    if (*(int *)(*plVar5 + 0x10) == 1) {
      __pm_relax(0xffffffc001185f50);
    }
  }
  else {
    if ((uVar1 >> 1 & 1) == 0) {
      uVar6 = uVar6 | 5;
    }
    else {
      uVar6 = uVar6 | 1;
    }
    if (*(int *)(*plVar5 + 0x10) == 1) {
      __pm_stay_awake(0xffffffc001185f50);
    }
  }
  if ((uVar2 >> 0xf & 1) != 0) {
    printk(0xffffffc000d9b3a8,&__func___27085,uVar6,uVar1,param_2);
  }
  if (uVar1 != uVar6) {
    printk(0xffffffc000d9b390,&__func___27085,0x64d);
    iVar4 = stk3x1x_write_state(param_1,uVar6);
    if (iVar4 < 0) {
      return iVar4;
    }
    *(uint *)((long)plVar5 + 0x154) = uVar6;
    if (param_2 != 0) {
      *(undefined2 *)((long)plVar5 + 0x18a) = 0;
      *(undefined2 *)((long)plVar5 + 0x186) = 0;
      *(undefined2 *)(plVar5 + 0x31) = 0xffff;
      if ((short)plVar5[0x33] == 1) {
        *(uint *)((long)plVar5 + 0x164) = (uint)*(ushort *)((long)plVar5 + 0x194);
        *(uint *)(plVar5 + 0x2d) = (uint)*(ushort *)((long)plVar5 + 0x196);
      }
      else {
        printk(0xffffffc000d9b390,&__func___27085,0x674);
      }
      iVar4 = stk3x1x_write_ps_high_thd(plVar5[1],*(undefined4 *)((long)plVar5 + 0x164));
      if (iVar4 != 0) {
        printk(0xffffffc000d9b390,&__func___27085,0x67a);
        printk(0xffffffc000d9b3c8,&__func___27085,0x67b,iVar4);
        return iVar4;
      }
      iVar4 = stk3x1x_write_ps_low_thd(plVar5[1],(int)plVar5[0x2d]);
      if (iVar4 != 0) {
        printk(0xffffffc000d9b390,&__func___27085,0x67f);
        printk(0xffffffc000d9b3f8,&__func___27085,0x680,iVar4);
        return iVar4;
      }
      printk(0xffffffc000d9b428,&__func___27085,*(undefined4 *)((long)plVar5 + 0x164),
             (int)plVar5[0x2d]);
      hrtimer_start(plVar5 + 0x34,plVar5[0x41],1);
      printk(0xffffffc000d9b450,&__func___27085,*(undefined4 *)((long)plVar5 + 0x164),
             (int)plVar5[0x2d]);
      if (*(int *)(*plVar5 + 0x10) == 0) {
        msleep(4);
        printk(0xffffffc000d9b390,&__func___27085,0x693);
        iVar4 = stk3x1x_read_ps(plVar5[1],(long)plVar5 + 0xce);
        if (iVar4 != 0) {
          printk(0xffffffc000d9ae20,&__func___27085,0x696);
          return iVar4;
        }
        printk(0xffffffc000d9b390,&__func___27085,0x699);
        iVar4 = stk3x1x_get_ps_value(plVar5,*(undefined2 *)((long)plVar5 + 0xce));
        if (iVar4 < 0) {
          printk(0xffffffc000d9b470,&__func___27085,0x69d,iVar4);
          return 0;
        }
        printk(0xffffffc000d9ae50,&__func___27085,*(undefined2 *)((long)plVar5 + 0xce),iVar4);
        if (iVar4 == 1) {
          iVar4 = 4;
        }
        iVar4 = ps_report_interrupt_data(iVar4);
        if (iVar4 != 0) {
          printk(0xffffffc000d9ae80,&__func___27085,0x6a6);
        }
      }
      else {
        printk(0xffffffc000d9b390,&__func___27085,0x68c);
        uVar3 = uRamffffffc000fbc180;
        *(undefined4 *)(plVar5 + 0x16) = 1;
        *(int *)((long)plVar5 + 0xb4) = (*(int *)((long)plVar5 + 0xac) * 100) / 1000 + (int)uVar3;
      }
    }
    if ((uVar2 & 0x8000) != 0) {
      printk(0xffffffc000d9b4a0,param_2);
      return 0;
    }
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_show_reg at 0xffffffc000441544
// ============================================================================

undefined8 stk3x1x_show_reg(void)

{
  undefined1 uStack_1;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27268,0xb7f);
  }
  else {
    stk3x1x_check_intr(*(undefined8 *)(lRamffffffc001185e68 + 8),&uStack_1);
    stk3x1x_read_ps(*(undefined8 *)(lRamffffffc001185e68 + 8),lRamffffffc001185e68 + 0xce);
    stk3x1x_read_als(*(undefined8 *)(lRamffffffc001185e68 + 8),lRamffffffc001185e68 + 0xcc);
    stk3x1x_write_als(*(undefined8 *)(lRamffffffc001185e68 + 8),
                      *(undefined4 *)(lRamffffffc001185e68 + 0x15c));
    stk3x1x_write_ps(*(undefined8 *)(lRamffffffc001185e68 + 8),
                     *(undefined4 *)(lRamffffffc001185e68 + 0x158));
    stk3x1x_write_ps_high_thd
              (*(undefined8 *)(lRamffffffc001185e68 + 8),
               *(undefined4 *)(lRamffffffc001185e68 + 0x164));
    stk3x1x_write_ps_low_thd
              (*(undefined8 *)(lRamffffffc001185e68 + 8),
               *(undefined4 *)(lRamffffffc001185e68 + 0x168));
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_store_config at 0xffffffc0004415fc
// ============================================================================

long stk3x1x_store_config(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = uRamffffffc001185e60;
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27226,0xaf6);
    param_3 = 0;
  }
  else {
    iVar3 = sscanf(param_2,0xffffffc000e7d720,&uStack_18,&uStack_14,&uStack_c,&uStack_8,&uStack_4,
                   &uStack_10);
    lVar2 = lRamffffffc001185e68;
    if (iVar3 == 6) {
      *(undefined4 *)(lRamffffffc001185e68 + 0x94) = uStack_18;
      *(undefined4 *)(lVar2 + 0x164) = uStack_8;
      *(undefined4 *)(lVar2 + 0x9c) = uStack_14;
      *(undefined4 *)(lVar2 + 0xa8) = uStack_c;
      *(undefined4 *)(lVar2 + 0x168) = uStack_4;
      *(undefined4 *)(lVar2 + 0xac) = uStack_10;
      iVar3 = stk3x1x_write_ps_high_thd(uVar1,*(undefined4 *)(lVar2 + 0x164));
      if (iVar3 == 0) {
        iVar3 = stk3x1x_write_ps_low_thd(uVar1,*(undefined4 *)(lRamffffffc001185e68 + 0x168));
        if (iVar3 != 0) {
          printk(0xffffffc000d9b3f8,&__func___27226,0xb0b,iVar3);
          param_3 = (long)iVar3;
        }
      }
      else {
        printk(0xffffffc000d9b3c8,&__func___27226,0xb05,iVar3);
        param_3 = (long)iVar3;
      }
    }
    else {
      printk(0xffffffc000d9b528,&__func___27226,0xb11,param_2);
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_write_als_high_thd at 0xffffffc000441cb8
// ============================================================================

undefined8 stk3x1x_write_als_high_thd(long param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uStack_8;
  undefined1 auStack_7 [7];
  
  uStack_8 = (undefined1)((ushort)param_2 >> 8);
  lVar3 = *(long *)(param_1 + 0xc0);
  auStack_7[0] = (undefined1)param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x82),&uStack_8,1);
  if (iVar1 < 0) {
    uVar2 = 0x531;
  }
  else {
    iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x83),auStack_7,1);
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = 0x538;
  }
  printk(0xffffffc000d9b348,&__func___27051,uVar2,&__func___27051);
  return 0xfffffff2;
}



// ============================================================================
// Function: stk3x1x_write_als_low_thd at 0xffffffc000441d58
// ============================================================================

undefined8 stk3x1x_write_als_low_thd(long param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uStack_8;
  undefined1 auStack_7 [7];
  
  uStack_8 = (undefined1)((ushort)param_2 >> 8);
  lVar3 = *(long *)(param_1 + 0xc0);
  auStack_7[0] = (undefined1)param_2;
  iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x84),&uStack_8,1);
  if (iVar1 < 0) {
    uVar2 = 0x54a;
  }
  else {
    iVar1 = stk3x1x_master_send(param_1,*(undefined1 *)(lVar3 + 0x85),auStack_7,1);
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = 0x551;
  }
  printk(0xffffffc000d9b348,&__func___27059,uVar2,&__func___27059);
  return 0xfffffff2;
}



// ============================================================================
// Function: stk3x1x_enable_als at 0xffffffc000441df8
// ============================================================================

int stk3x1x_enable_als(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  uint uVar5;
  
  plVar4 = *(long **)(param_1 + 0xc0);
  uVar1 = *(uint *)((long)plVar4 + 0x154);
  uVar2 = *(uint *)(plVar4 + 0x12);
  printk(0xffffffc000d9b370,&__func___27073,param_2);
  if (param_2 == 0) {
    uVar5 = uVar1 & 0xfffffff9 | (uVar1 & 1) << 2;
  }
  else {
    uVar5 = uVar1 & 0xfffffff9 | 2;
  }
  if ((uVar2 >> 0xf & 1) != 0) {
    printk(0xffffffc000d9b3a8,&__func___27073,uVar5,uVar1,param_2);
  }
  if (uVar5 != uVar1) {
    *(undefined4 *)(plVar4 + 0x52) = 0;
    if (param_2 == 0) {
      iVar3 = stk3x1x_write_state(param_1,uVar5);
      if (iVar3 < 0) {
        return iVar3;
      }
      *(uint *)((long)plVar4 + 0x154) = uVar5;
    }
    else {
      if (((uVar1 & 1) == 0) && (iVar3 = stk3x1x_get_ir_value(plVar4,2), 0 < iVar3)) {
        *(short *)((long)plVar4 + 0x274) = (short)iVar3;
        *(short *)((long)plVar4 + 0x276) = (short)iVar3;
      }
      if (*(int *)(*plVar4 + 0x14) == 0) {
        stk3x1x_write_als_high_thd(param_1);
        stk3x1x_write_als_low_thd(param_1,0xffffffff);
      }
      iVar3 = stk3x1x_write_state(param_1,uVar5);
      if (iVar3 < 0) {
        return iVar3;
      }
      *(uint *)((long)plVar4 + 0x154) = uVar5;
      *(undefined2 *)((long)plVar4 + 0x27a) = 0;
      *(undefined4 *)(plVar4 + 0x4d) = 0;
      *(undefined4 *)((long)plVar4 + 0x26c) = 0;
      *(undefined4 *)((long)plVar4 + 0x264) = 0;
      if (*(int *)(*plVar4 + 0x14) == 0) {
        queue_delayed_work_on(8,uRamffffffc00112e488,plVar4 + 2,0x16);
      }
      else {
        *(undefined4 *)(plVar4 + 0x14) = 1;
        *(int *)((long)plVar4 + 0xa4) =
             (*(int *)((long)plVar4 + 0x9c) * 100) / 1000 + (int)uRamffffffc000fbc180;
      }
    }
    *(undefined2 *)((long)plVar4 + 0x28c) = 0;
    if ((uVar2 & 0x8000) != 0) {
      printk(0xffffffc000d9b748,param_2);
    }
    return iVar3;
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_ps_calibration at 0xffffffc000441fe0
// ============================================================================

int stk3x1x_ps_calibration(long param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  short sVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  lVar5 = *(long *)(param_1 + 0xc0);
  uVar7 = *(uint *)(lVar5 + 0x154);
  bVar2 = (uVar7 & 1) != 0;
  if (bVar2) {
    printk(0xffffffc000d9b768,&__func___27098);
    stk3x1x_enable_ps_isra_36(*(undefined8 *)(lVar5 + 8),0);
  }
  uVar6 = uVar7 & 2;
  if ((uVar7 >> 1 & 1) == 0) {
    disable_irq(*(undefined4 *)(lVar5 + 200));
    iVar3 = stk3x1x_write_state(param_1,5);
    if (iVar3 < 0) {
      enable_irq(*(undefined4 *)(lVar5 + 200));
      goto code_r0xffffffc000442080;
    }
code_r0xffffffc000442038:
    iVar8 = 5;
    uVar7 = 0;
    do {
      msleep(0x3c);
      iVar3 = stk3x1x_read_ps(*(undefined8 *)(lVar5 + 8),lVar5 + 0xce);
      if (iVar3 != 0) goto code_r0xffffffc000442074;
      printk(0xffffffc000d9b7b8,&__func___27098,*(undefined2 *)(lVar5 + 0xce));
      iVar8 = iVar8 + -1;
      uVar7 = uVar7 + *(ushort *)(lVar5 + 0xce);
    } while (iVar8 != 0);
    uVar7 = uVar7 / 5;
    sVar4 = (short)uVar7;
    *(short *)(lVar5 + 0x27e) = sVar4;
    bVar1 = 399 < ((uVar7 & 0xffff) - 1 & 0xffff);
    if (bVar1) {
      uVar7 = 400;
      sVar4 = 400;
      *(undefined2 *)(lVar5 + 0x192) = 400;
    }
    else {
      *(short *)(lVar5 + 0x192) = sVar4;
      uVar7 = uVar7 & 0xffff;
    }
    uRamffffffc001185e70 = (uint)!bVar1;
    *(short *)(lVar5 + 0x194) = sVar4 + *(short *)(lVar5 + 400);
    *(short *)(lVar5 + 0x196) = sVar4 + *(short *)(lVar5 + 0x18e);
    printk(0xffffffc000d9a618,&__func___27098,uVar7);
code_r0xffffffc000442074:
    enable_irq(*(undefined4 *)(lVar5 + 200));
    if (uVar6 == 0) goto code_r0xffffffc000442080;
  }
  else {
    printk(0xffffffc000d9b790,&__func___27098);
    stk3x1x_enable_als(*(undefined8 *)(lVar5 + 8),0);
    disable_irq(*(undefined4 *)(lVar5 + 200));
    iVar3 = stk3x1x_write_state(param_1,5);
    if (-1 < iVar3) {
      uVar6 = 1;
      goto code_r0xffffffc000442038;
    }
    enable_irq(*(undefined4 *)(lVar5 + 200));
  }
  printk(0xffffffc000d9b7d0,&__func___27098);
  stk3x1x_enable_als(*(undefined8 *)(lVar5 + 8),1);
code_r0xffffffc000442080:
  if (bVar2) {
    printk(0xffffffc000d9b7f0,&__func___27098);
    stk3x1x_enable_ps_isra_36(*(undefined8 *)(lVar5 + 8),1);
  }
  return iVar3;
}



// ============================================================================
// Function: stk3x1x_set_ps_offset at 0xffffffc000442234
// ============================================================================

undefined8 stk3x1x_set_ps_offset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 auStack_8 [2];
  
  auStack_8[0] = 0;
  if (lRamffffffc001185e68 != 0) {
    stk3x1x_ps_calibration(*(undefined8 *)(lRamffffffc001185e68 + 8));
    printk(0xffffffc000d9a720,&__func___27436,*(undefined2 *)(lRamffffffc001185e68 + 0x192));
    snprintf(auStack_8,4,0xffffffc000e5d090,*(undefined2 *)(lRamffffffc001185e68 + 0x192));
    emmc_write(0xffffffc000d11e28,0x300014,4,auStack_8);
    return param_3;
  }
  printk(0xffffffc000d9a528,&__func___27436,0xdb6);
  return 0;
}



// ============================================================================
// Function: stk3x1x_store_ps_calibration at 0xffffffc000442300
// ============================================================================

undefined8
stk3x1x_store_ps_calibration
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  int iStack_4;
  
  iStack_4 = 0;
  uStack_8 = 0;
  iVar1 = sscanf(param_3,0xffffffc000e5d090,&iStack_4);
  if (iVar1 == 1) {
    if ((iStack_4 == 1) &&
       (stk3x1x_ps_calibration(*(undefined8 *)(lRamffffffc001185e68 + 8)), iRamffffffc001185e70 == 0
       )) {
      printk(0xffffffc000d9b810,&__func___27817,0xe3e);
      param_4 = 0xffffffffffffffff;
    }
    else {
      uRamffffffc001185e74 = (uint)*(ushort *)(lRamffffffc001185e68 + 0x192);
      printk(0xffffffc000d9a720,&__func___27817);
      snprintf(&uStack_8,4,0xffffffc000e5d090,*(undefined2 *)(lRamffffffc001185e68 + 0x192));
      emmc_write(0xffffffc000d11e28,0x300014,4,&uStack_8);
    }
  }
  return param_4;
}



// ============================================================================
// Function: stk3x1x_unlocked_ioctl at 0xffffffc0004423f8
// ============================================================================

/* WARNING: Type propagation algorithm not settling */

long stk3x1x_unlocked_ioctl(long param_1,uint param_2,ulong param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_4;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0xd0) + 0xc0);
  if (param_2 == 0x80048404) {
    iVar4 = stk3x1x_read_ps(plVar7[1],(long)plVar7 + 0xce,param_3,0x80048404,0x80048404);
    if ((long)iVar4 != 0) {
      return (long)iVar4;
    }
    uStack_4 = (uint)*(ushort *)((long)plVar7 + 0xce);
    goto code_r0xffffffc000442a44;
  }
  if (param_2 < 0x80048405) {
    if (param_2 == 0x4004840f) {
      if (0xfffffffffffffffb < param_3 ||
          *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
        return -0xe;
      }
      lVar6 = __copy_from_user(&uStack_4,param_3,4);
      if (lVar6 != 0) {
        return -0xe;
      }
      *(undefined2 *)((long)plVar7 + 0x27e) = 0;
      *(undefined4 *)((long)plVar7 + 0x164) = *(undefined4 *)(*plVar7 + 0xa0);
      *(undefined4 *)(plVar7 + 0x2d) = *(undefined4 *)(*plVar7 + 0xa4);
      printk(0xffffffc000d9ba00,0,*(undefined4 *)((long)plVar7 + 0x164),(int)plVar7[0x2d]);
      return 0;
    }
    if (param_2 < 0x40048410) {
      if (param_2 == 0x40048401) {
        if (0xfffffffffffffffb < param_3 ||
            *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
          return -0xe;
        }
        lVar6 = __copy_from_user(&uStack_4,param_3,4);
        if (lVar6 != 0) {
          return -0xe;
        }
        if (uStack_4 == 0) {
          iVar4 = stk3x1x_enable_ps_isra_36(plVar7[1],0);
          lVar6 = (long)iVar4;
          if (lVar6 != 0) {
            printk(0xffffffc000d9b878,&__func___27992,0x1144,lVar6);
            return lVar6;
          }
          clear_bit(2,plVar7 + 0x2e);
          return 0;
        }
        iVar4 = stk3x1x_enable_ps_isra_36(plVar7[1],1);
        lVar6 = (long)iVar4;
        if (lVar6 != 0) {
          printk(0xffffffc000d9b850,&__func___27992,0x1136,lVar6);
          return lVar6;
        }
        set_bit(2,plVar7 + 0x2e);
        return 0;
      }
      if (param_2 == 0x40048405) {
        if (0xfffffffffffffffb < param_3 ||
            *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
          return -0xe;
        }
        lVar6 = __copy_from_user(&uStack_4,param_3,4);
        if (lVar6 != 0) {
          return -0xe;
        }
        if (uStack_4 == 0) {
          iVar4 = stk3x1x_enable_als(plVar7[1],0);
          lVar6 = (long)iVar4;
          if (lVar6 != 0) {
            printk(0xffffffc000d9b8d8,&__func___27992,0x1196,lVar6);
            return lVar6;
          }
          clear_bit(1,plVar7 + 0x2e);
          return 0;
        }
        iVar4 = stk3x1x_enable_als(plVar7[1],1);
        lVar6 = (long)iVar4;
        if (lVar6 != 0) {
          printk(0xffffffc000d9b8a8,&__func___27992,0x1188,lVar6);
          return lVar6;
        }
        set_bit(1,plVar7 + 0x2e);
        return 0;
      }
code_r0xffffffc0004425f8:
      printk(0xffffffc000d9baf8,&__func___27992,0x121a,&__func___27992);
      return -0x203;
    }
    if (param_2 == 0x80048402) {
      uStack_4 = (uint)((ulong)plVar7[0x2e] >> 2) & 1;
      if (0xfffffffffffffffb < param_3 ||
          *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
        return -0xe;
      }
      goto code_r0xffffffc0004427e8;
    }
    if (param_2 < 0x80048403) {
      if (param_2 == 0x40048411) {
        if (0xfffffffffffffffb < param_3 ||
            *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
          return -0xe;
        }
        lVar6 = __copy_from_user(&uStack_4,param_3,4);
        if (lVar6 != 0) {
          return -0xe;
        }
        *(uint *)((long)plVar7 + 0x164) = (uStack_4 & 0xffff) + (uint)*(ushort *)(plVar7 + 0x32);
        *(short *)((long)plVar7 + 0x27e) = (short)uStack_4;
        *(uint *)(plVar7 + 0x2d) = (uStack_4 & 0xffff) + (uint)*(ushort *)((long)plVar7 + 0x18e);
        iVar4 = stk3x1x_write_ps_high_thd(plVar7[1],*(undefined4 *)((long)plVar7 + 0x164));
        if ((long)iVar4 != 0) {
          return (long)iVar4;
        }
        iVar4 = stk3x1x_write_ps_low_thd(plVar7[1],(int)plVar7[0x2d]);
        if ((long)iVar4 == 0) {
          printk(0xffffffc000d9ba78,uStack_4);
          printk(0xffffffc000d9bab0,*(undefined2 *)((long)plVar7 + 0x27e),
                 *(undefined4 *)((long)plVar7 + 0x164),(int)plVar7[0x2d]);
          return 0;
        }
        return (long)iVar4;
      }
      goto code_r0xffffffc0004425f8;
    }
    iVar4 = stk3x1x_read_ps(plVar7[1],(long)plVar7 + 0xce,param_3,0x80048404,param_2);
    if ((long)iVar4 != 0) {
      return (long)iVar4;
    }
    uStack_4 = stk3x1x_get_ps_value(plVar7,*(undefined2 *)((long)plVar7 + 0xce));
    if ((int)uStack_4 < 0) {
      return (long)(int)uStack_4;
    }
  }
  else if (param_2 == 0x80048409) {
    iVar4 = stk3x1x_read_ps(plVar7[1],(long)plVar7 + 0xce,param_3,0x80048404,0x80048409);
    if ((long)iVar4 != 0) {
      return (long)iVar4;
    }
    uStack_4 = (uint)((int)(uint)*(ushort *)((long)plVar7 + 0xce) <= *(int *)((long)plVar7 + 0x164))
    ;
    printk(0xffffffc000d9b9c8);
  }
  else {
    if (param_2 < 0x8004840a) {
      if (param_2 == 0x80048407) {
        uVar3 = stk3x1x_read_als(plVar7[1],(long)plVar7 + 0xcc);
        if ((long)(int)uVar3 != 0) {
          return (long)(int)uVar3;
        }
        uVar1 = *(ushort *)((long)plVar7 + 0xd2);
        uVar2 = *(ushort *)((long)plVar7 + 0xcc);
        uVar8 = (uint)uVar2;
        if (((uVar1 != 0) && (lVar6 = *plVar7, *(uint *)(lVar6 + 0x1c) <= (uint)uVar2)) &&
           (uVar3 = (uint)uVar1, uVar1 != 1)) {
          if ((uint)uVar2 < *(uint *)(lVar6 + 0x20)) {
            uVar3 = 1;
          }
          else if (uVar1 != 2) {
            if ((uint)uVar2 < *(uint *)(lVar6 + 0x24)) {
              uVar3 = 2;
            }
            else if (uVar1 != 3) {
              uVar9 = (uint)uVar2;
              if (uVar9 < *(uint *)(lVar6 + 0x28)) {
                uVar3 = 3;
              }
              else if (uVar1 != 4) {
                if (uVar9 < *(uint *)(lVar6 + 0x2c)) {
                  uVar3 = 4;
                }
                else if (uVar1 != 5) {
                  if (uVar9 < *(uint *)(lVar6 + 0x30)) {
                    uVar3 = 5;
                  }
                  else if (uVar1 != 6) {
                    if (uVar9 < *(uint *)(lVar6 + 0x34)) {
                      uVar3 = 6;
                    }
                    else if (uVar1 != 7) {
                      if (uVar9 < *(uint *)(lVar6 + 0x38)) {
                        uVar3 = 7;
                      }
                      else if (uVar1 != 8) {
                        if (uVar9 < *(uint *)(lVar6 + 0x3c)) {
                          uVar3 = 8;
                        }
                        else if (uVar1 != 9) {
                          if (uVar8 < *(uint *)(lVar6 + 0x40)) {
                            uVar3 = 9;
                          }
                          else if (uVar1 != 10) {
                            if (uVar8 < *(uint *)(lVar6 + 0x44)) {
                              uVar3 = 10;
                            }
                            else if (uVar1 != 0xb) {
                              if (uVar8 < *(uint *)(lVar6 + 0x48)) {
                                uVar3 = 0xb;
                              }
                              else if (uVar1 != 0xc) {
                                if (uVar8 < *(uint *)(lVar6 + 0x4c)) {
                                  uVar3 = 0xc;
                                }
                                else if (uVar1 != 0xd) {
                                  if (uVar8 < *(uint *)(lVar6 + 0x50)) {
                                    uVar3 = 0xd;
                                  }
                                  else if ((uVar3 != 0xe) &&
                                          (uVar3 = 0xf, uVar8 < *(uint *)(lVar6 + 0x54))) {
                                    uVar3 = 0xe;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if ((int)(uint)*(ushort *)((long)plVar7 + 0xd4) <= (int)uVar3) {
          printk(0xffffffc000d9b908,&__func___27910,0xfd0);
          uVar3 = *(ushort *)((long)plVar7 + 0xd4) - 1;
        }
        if ((int)plVar7[0x14] == 1) {
          if (*(int *)((long)plVar7 + 0xa4) - lRamffffffc000fbc180 < 0) {
            *(undefined4 *)(plVar7 + 0x14) = 0;
          }
          if ((int)plVar7[0x14] == 1) {
            if ((*(uint *)(plVar7 + 0x12) >> 5 & 1) == 0) {
              uStack_4 = 0xffffffff;
            }
            else {
              printk(0xffffffc000d9b950,uVar2,*(undefined4 *)(*plVar7 + (long)(int)uVar3 * 4 + 0x58)
                    );
              uStack_4 = 0xffffffff;
            }
            goto code_r0xffffffc000442a44;
          }
        }
        if ((*(uint *)(plVar7 + 0x12) >> 5 & 1) != 0) {
          printk(0xffffffc000d9b930,uVar2,*(undefined4 *)(*plVar7 + (long)(int)uVar3 * 4 + 0x58));
        }
        uStack_4 = *(uint *)(*plVar7 + (long)(int)uVar3 * 4 + 0x58);
      }
      else {
        if (param_2 < 0x80048408) {
          if (param_2 == 0x80048406) {
            uStack_4 = (uint)((ulong)plVar7[0x2e] >> 1) & 1;
            if (0xfffffffffffffffb < param_3 ||
                *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4
               ) {
              return -0xe;
            }
            goto code_r0xffffffc0004427e8;
          }
          goto code_r0xffffffc0004425f8;
        }
        iVar4 = stk3x1x_read_als(plVar7[1],(long)plVar7 + 0xcc);
        if ((long)iVar4 != 0) {
          return (long)iVar4;
        }
        uStack_4 = (uint)*(ushort *)((long)plVar7 + 0xcc);
      }
code_r0xffffffc000442a44:
      if (0xfffffffffffffffb < param_3 ||
          *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
        return -0xe;
      }
      goto code_r0xffffffc0004427e8;
    }
    if (param_2 == 0x8004840c) {
      uStack_4 = *(uint *)(plVar7 + 0x2d);
      uVar5 = 0xffffffc000d9b9a0;
    }
    else {
      if (param_2 == 0x80048410) {
        stk3x1x_ps_calibration(plVar7[1]);
        uStack_4 = (uint)*(ushort *)((long)plVar7 + 0x27e);
        printk(0xffffffc000d9ba48);
        goto code_r0xffffffc0004427c8;
      }
      if (param_2 != 0x8004840b) goto code_r0xffffffc0004425f8;
      uStack_4 = *(uint *)((long)plVar7 + 0x164);
      uVar5 = 0xffffffc000d9b978;
    }
    printk(uVar5,&__func___27992,uStack_4);
  }
code_r0xffffffc0004427c8:
  if (0xfffffffffffffffb < param_3 ||
      *(ulong *)(((ulong)&stack0xffffffffffffffc0 & 0xffffffffffffc000) + 8) < param_3 + 4) {
    return -0xe;
  }
code_r0xffffffc0004427e8:
  lVar6 = __copy_to_user(param_3,&uStack_4,4);
  if (lVar6 != 0) {
    return -0xe;
  }
  return 0;
}



// ============================================================================
// Function: stk3x1x_eint_func at 0xffffffc000442d08
// ============================================================================

void stk3x1x_eint_func(void)

{
  long *plVar1;
  
  plVar1 = plRamffffffc001185e68;
  printk(0xffffffc000d9bb28);
  if (plVar1 != (long *)0x0) {
    if ((*(int *)(*plVar1 + 0x10) == 0) || (*(int *)(*plVar1 + 0x14) == 0)) {
      queue_delayed_work_on(8,uRamffffffc00112e488,plVar1 + 2,0);
    }
    if ((*(uint *)(plVar1 + 0x12) >> 2 & 1) != 0) {
      printk(0xffffffc000d9bb48);
    }
  }
  return;
}



// ============================================================================
// Function: stk3x1x_eint_handler at 0xffffffc000442d80
// ============================================================================

undefined8 stk3x1x_eint_handler(void)

{
  printk(0xffffffc000d9bb68);
  disable_irq_nosync(*(undefined4 *)(lRamffffffc001185e68 + 200));
  stk3x1x_eint_func();
  return 1;
}



// ============================================================================
// Function: stk3x1x_setup_eint at 0xffffffc000442db4
// ============================================================================

undefined4 stk3x1x_setup_eint(void)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = 0;
  uStack_4 = 0;
  lRamffffffc001186008 = get_alsps_platformdev();
  uVar4 = devm_pinctrl_get(lRamffffffc001186008 + 0x10);
  if (uVar4 < 0xfffffffffffff001) {
    uVar5 = pinctrl_lookup_state(uVar4,0xffffffc000d9bbd8);
  }
  else {
    printk(0xffffffc000d9bba8,&__func___27196,0xa34);
    uVar5 = pinctrl_lookup_state(uVar4,0xffffffc000d9bbd8);
  }
  if (uVar5 < 0xfffffffffffff001) {
    uVar5 = pinctrl_lookup_state(uVar4,0xffffffc000d9bc20);
  }
  else {
    printk(0xffffffc000d9bbe8,&__func___27196,0xa39);
    uVar5 = pinctrl_lookup_state(uVar4,0xffffffc000d9bc20);
  }
  if (0xfffffffffffff000 < uVar5) {
    printk(0xffffffc000d9bc28,&__func___27196,0xa40);
  }
  if (*(long *)(lRamffffffc001185e68 + 0xc0) == 0) {
    uVar2 = 0xffffffea;
    printk(0xffffffc000d9bd48,&__func___27196,0xa58);
  }
  else {
    of_property_read_u32_array
              (*(long *)(lRamffffffc001185e68 + 0xc0),0xffffffc000d9bc60,&uStack_8,2);
    gpio_request(uStack_8,0xffffffc000d9bc70);
    uVar2 = uStack_4;
    uVar6 = gpio_to_desc(uStack_8);
    gpiod_set_debounce(uVar6,uVar2);
    pinctrl_select_state(uVar4,uVar5);
    printk(0xffffffc000d9bc80,uStack_8,uStack_4);
    lVar1 = lRamffffffc001185e68;
    uVar2 = irq_of_parse_and_map(*(undefined8 *)(lRamffffffc001185e68 + 0xc0),0);
    *(undefined4 *)(lVar1 + 200) = uVar2;
    printk(0xffffffc000d9bcb0,*(undefined4 *)(lRamffffffc001185e68 + 200));
    if (*(int *)(lRamffffffc001185e68 + 200) == 0) {
      uVar2 = 0xffffffea;
      printk(0xffffffc000d9bcd8,&__func___27196,0xa4f);
    }
    else {
      iVar3 = request_threaded_irq
                        (*(int *)(lRamffffffc001185e68 + 200),stk3x1x_eint_handler,0,3,
                         0xffffffc000d9bd08,0);
      if (iVar3 == 0) {
        enable_irq(*(undefined4 *)(lRamffffffc001185e68 + 200));
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffea;
        printk(0xffffffc000d9bd18,&__func___27196,0xa53);
      }
    }
  }
  return uVar2;
}



// ============================================================================
// Function: stk3x1x_init_client at 0xffffffc000443008
// ============================================================================

int stk3x1x_init_client(long param_1)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0xc0);
  iVar2 = stk3x1x_write_sw_reset();
  if (iVar2 == 0) {
    iVar2 = stk3x1x_read_id(param_1);
    if (iVar2 == 0) {
      if (*(char *)((long)plVar3 + 0x184) != '\0') {
        if ((*(int *)(*plVar3 + 0x10) == 0) || (*(int *)(*plVar3 + 0x14) == 0)) {
          iVar2 = stk3x1x_setup_eint(param_1);
          if (iVar2 != 0) {
            printk(0xffffffc000d9bdd8,&__func___27206,0xa78,iVar2);
          }
        }
      }
      iVar2 = stk3x1x_write_state(param_1,*(undefined4 *)((long)plVar3 + 0x154));
      if (iVar2 == 0) {
        uVar1 = *(uint *)(plVar3 + 0x2b) & 0x3f;
        if (*(int *)(*plVar3 + 0x10) != 1) {
          uVar1 = *(uint *)(plVar3 + 0x2b);
        }
        iVar2 = stk3x1x_write_ps(param_1,uVar1);
        if (iVar2 == 0) {
          iVar2 = stk3x1x_write_als(param_1,*(undefined4 *)((long)plVar3 + 0x15c));
          if (iVar2 == 0) {
            iVar2 = stk3x1x_write_led(param_1,*(undefined1 *)((long)plVar3 + 0x161));
            if (iVar2 == 0) {
              iVar2 = stk3x1x_write_wait(param_1,(char)plVar3[0x2c]);
              if (iVar2 == 0) {
                iVar2 = stk3x1x_write_int(param_1,*(undefined1 *)((long)plVar3 + 0x162));
                if (iVar2 == 0) {
                  *(undefined4 *)((long)plVar3 + 0x26c) = 0;
                  *(undefined8 *)((long)plVar3 + 0x224) = 0;
                  *(undefined8 *)((long)plVar3 + 0x22c) = 0;
                  *(undefined8 *)((long)plVar3 + 0x234) = 0;
                  *(undefined8 *)((long)plVar3 + 0x23c) = 0;
                  *(undefined8 *)((long)plVar3 + 0x244) = 0;
                  *(undefined8 *)((long)plVar3 + 0x24c) = 0;
                  *(undefined8 *)((long)plVar3 + 0x254) = 0;
                  *(undefined8 *)((long)plVar3 + 0x25c) = 0;
                  *(undefined8 *)((long)plVar3 + 0x264) = 0;
                  if (*(char *)((long)plVar3 + 0x184) != '\0') {
                    *(undefined2 *)(plVar3 + 0x31) = 0xffff;
                    *(undefined1 *)(plVar3 + 0x42) = 1;
                    *(undefined2 *)((long)plVar3 + 0x186) = 0;
                    *(undefined2 *)((long)plVar3 + 0x18a) = 0;
                    *(undefined4 *)((long)plVar3 + 0x214) = 0;
                    *(undefined4 *)((long)plVar3 + 0x21c) = 9999;
                    *(undefined4 *)(plVar3 + 0x43) = 0;
                    *(undefined4 *)(plVar3 + 0x44) = 0;
                    *(undefined2 *)(plVar3 + 0x33) = 0;
                    iVar2 = stk3x1x_write_int(plVar3[1],0);
                    if (iVar2 == 0) {
                      iVar2 = stk3x1x_write_state(plVar3[1],5);
                      if (iVar2 == 0) {
                        hrtimer_start(plVar3 + 0x34,plVar3[0x41],1);
                      }
                      else {
                        printk(0xffffffc000d9b588,&__func___27146,0x94c,iVar2);
                      }
                    }
                    else {
                      printk(0xffffffc000d9b558,&__func___27146,0x945,iVar2);
                    }
                  }
                  *(undefined1 *)((long)plVar3 + 0x27c) = 0;
                  *(undefined1 *)((long)plVar3 + 0x27d) = 0;
                  iVar2 = 0;
                  *(undefined4 *)((long)plVar3 + 0x284) = 500;
                  *(undefined4 *)(plVar3 + 0x51) = 500;
                }
                else {
                  printk(0xffffffc000d9b558,&__func___27206,0xaba,iVar2);
                }
              }
              else {
                printk(0xffffffc000d9be80,&__func___27206,0xaa8,iVar2);
              }
            }
            else {
              printk(0xffffffc000d9be58,&__func___27206,0xaa2,iVar2);
            }
          }
          else {
            printk(0xffffffc000d9be30,&__func___27206,0xa9c,iVar2);
          }
        }
        else {
          printk(0xffffffc000d9be08,&__func___27206,0xa96,iVar2);
        }
      }
      else {
        printk(0xffffffc000d9b588,&__func___27206,0xa7f,iVar2);
      }
    }
    else {
      printk(0xffffffc000d9bda0,&__func___27206,0xa6e,iVar2);
    }
  }
  else {
    printk(0xffffffc000d9bd70,&__func___27206,0xa68,iVar2);
  }
  return iVar2;
}



// ============================================================================
// Function: stk3x1x_store_dev_init at 0xffffffc00044334c
// ============================================================================

undefined8 stk3x1x_store_dev_init(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  if (lRamffffffc001185e68 == 0) {
    printk(0xffffffc000d9a528,&__func___27443,0xdc4);
    param_3 = 0;
  }
  else {
    iVar1 = stk3x1x_init_client(*(undefined8 *)(lRamffffffc001185e68 + 8));
    if (iVar1 != 0) {
      printk(0xffffffc000d9beb0,&__func___27443,0xdc9);
    }
  }
  return param_3;
}



// ============================================================================
// Function: stk3x1x_i2c_probe at 0xffffffc0004433c8
// ============================================================================

int stk3x1x_i2c_probe(long param_1)

{
  byte bVar1;
  short sVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  long lVar9;
  code *pcStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  code *pcStack_60;
  code *pcStack_58;
  code *pcStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  code *pcStack_38;
  code *pcStack_30;
  code *pcStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  uStack_40 = 0;
  pcStack_60 = (code *)0x0;
  pcStack_58 = (code *)0x0;
  pcStack_50 = (code *)0x0;
  uStack_48 = 0;
  pcStack_90 = (code *)0x0;
  uStack_88 = 0;
  uStack_80 = 0;
  pcStack_38 = (code *)0x0;
  pcStack_30 = (code *)0x0;
  pcStack_28 = (code *)0x0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  uStack_8 = 0;
  pcStack_78 = (code *)0x0;
  uStack_70 = 0;
  uStack_68 = 0;
  printk(0xffffffc000d9bee8,&__func___28071,0xffffffc000d9aa78);
  plVar6 = (long *)kmem_cache_alloc_trace(uRamffffffc00115bd38,0x80d0,0x298);
  if (plVar6 == (long *)0x0) {
    iVar4 = -0xc;
  }
  else {
    memset(plVar6,0,0x298);
    lVar7 = lRamffffffc00100c210;
    *plVar6 = lRamffffffc00100c210;
    plRamffffffc001185e68 = plVar6;
    stk3x1x_get_addr(lVar7,plVar6 + 0xf);
    plVar6[3] = (long)(plVar6 + 3);
    plVar6[2] = 0xfffffffe0;
    plVar6[4] = (long)(plVar6 + 3);
    plVar6[5] = (long)stk3x1x_eint_work;
    init_timer_key(plVar6 + 6,2,0,0);
    plVar6[0xb] = (long)(plVar6 + 2);
    plVar6[10] = (long)delayed_work_timer_fn;
    printk(0xffffffc000d9bf10,*(undefined2 *)(param_1 + 2));
    *(undefined2 *)(param_1 + 2) = 0x48;
    printk(0xffffffc000d9bf10,0x48);
    plVar6[1] = param_1;
    *(long **)(param_1 + 0xc0) = plVar6;
    *(undefined4 *)((long)plVar6 + 0x9c) = 200;
    *(undefined4 *)(plVar6 + 0x14) = 0;
    *(undefined4 *)((long)plVar6 + 0xa4) = 0;
    *(undefined4 *)((long)plVar6 + 0xac) = 10;
    *(undefined4 *)(plVar6 + 0x16) = 0;
    *(undefined4 *)((long)plVar6 + 0xb4) = 0;
    *(undefined4 *)(plVar6 + 0x15) = 0;
    *(undefined4 *)(plVar6 + 0x12) = 0;
    *(undefined4 *)(plVar6 + 0x13) = 0;
    *(undefined4 *)((long)plVar6 + 0xbc) = 0;
    lVar7 = of_find_compatible_node(0,0,0xffffffc000d9bf28);
    plVar6[0x18] = lVar7;
    *(undefined4 *)(plVar6 + 0x2b) = 0x31;
    lVar7 = *plVar6;
    *(undefined4 *)((long)plVar6 + 0x15c) = 0x38;
    *(undefined1 *)((long)plVar6 + 0x184) = 1;
    *(undefined1 *)((long)plVar6 + 0x161) = 0xff;
    *(undefined4 *)((long)plVar6 + 0x154) = 0;
    *(undefined2 *)((long)plVar6 + 0x192) = 0;
    *(undefined1 *)(plVar6 + 0x2c) = 7;
    *(undefined1 *)((long)plVar6 + 0x162) = 0;
    *(undefined2 *)(plVar6 + 0x4f) = 1000;
    *(undefined4 *)((long)plVar6 + 0x164) = *(undefined4 *)(lVar7 + 0xa0);
    *(undefined4 *)(plVar6 + 0x2d) = *(undefined4 *)(lVar7 + 0xa4);
    *(undefined4 *)(plVar6 + 0x30) = 0;
    *(undefined4 *)(plVar6 + 0x4e) = 3;
    *(undefined2 *)((long)plVar6 + 0x18c) = 0x53;
    *(undefined2 *)((long)plVar6 + 0x18e) = 0x3f;
    *(undefined2 *)(plVar6 + 0x32) = 0x53;
    sVar2 = *(short *)(lVar7 + 0xa0);
    *(short *)((long)plVar6 + 0x194) = sVar2;
    *(short *)((long)plVar6 + 0x196) = (short)*(undefined4 *)(lVar7 + 0xa4);
    if (sVar2 == 0) {
      *(undefined2 *)((long)plVar6 + 0x194) = 0x4dd;
      *(undefined2 *)((long)plVar6 + 0x196) = 0x3b1;
    }
    if (*(int *)(lVar7 + 0x10) == 0) {
      printk(0xffffffc000d9bf40,&__func___28071);
      lVar7 = *plVar6;
    }
    bVar1 = *(byte *)((long)plVar6 + 0x162);
    *(byte *)((long)plVar6 + 0x162) = bVar1 | 3;
    if (*(int *)(lVar7 + 0x14) == 0) {
      *(byte *)((long)plVar6 + 0x162) = bVar1 | 0xb;
      printk(0xffffffc000d9bf68,&__func___28071);
    }
    printk(0xffffffc000d9bf90,&__func___28071,*(undefined4 *)((long)plVar6 + 0x154),
           (int)plVar6[0x2b],*(undefined4 *)((long)plVar6 + 0x15c),
           *(undefined1 *)((long)plVar6 + 0x161),(char)plVar6[0x2c],
           *(undefined1 *)((long)plVar6 + 0x162));
    printk(0xffffffc000d9c008);
    plVar6[0x2e] = 0;
    plVar6[0x2f] = 0;
    *(undefined2 *)((long)plVar6 + 0xd2) = 0xf;
    *(undefined2 *)((long)plVar6 + 0xd4) = 0x10;
    lVar7 = *plVar6;
    memcpy(plVar6 + 0x1b,lVar7 + 0x1c,0x3c);
    memcpy((long)plVar6 + 0x114,lVar7 + 0x58,0x40);
    *(undefined4 *)((long)plVar6 + 0x94) = 3;
    if ((*(uint *)((long)plVar6 + 0x154) >> 1 & 1) != 0) {
      set_bit(1,plVar6 + 0x2e);
    }
    if ((*(uint *)((long)plVar6 + 0x154) & 1) != 0) {
      set_bit(2,plVar6 + 0x2e);
    }
    lRamffffffc001185e60 = param_1;
    lVar7 = __alloc_workqueue_key(0xffffffc000e8de70,0x2000a,1,0,0,0xffffffc000d9c030);
    plVar6[0x3c] = lVar7;
    plVar6[0x3e] = (long)(plVar6 + 0x3e);
    plVar6[0x3d] = 0xfffffffe0;
    plVar6[0x3f] = (long)(plVar6 + 0x3e);
    plVar6[0x40] = (long)stk_ps_tune0_work_func;
    hrtimer_init(plVar6 + 0x34,1,1);
    plVar6[0x41] = 60000000;
    plVar6[0x39] = (long)stk_ps_tune0_timer_func;
    iVar4 = stk3x1x_init_client(param_1);
    if (iVar4 == 0) {
      iVar4 = misc_register(0xffffffc00100c320);
      if (iVar4 == 0) {
        lVar7 = lRamffffffc00100c230 + 0x28;
        if (lVar7 == 0) {
          iVar4 = -0x16;
code_r0xffffffc000443ad8:
          printk(0xffffffc000d9c268,&__func___28071,0x154f,iVar4);
        }
        else {
          lVar9 = 0;
          do {
            puVar8 = *(undefined8 **)(&stk3x1x_attr_list + lVar9);
            lVar9 = lVar9 + 8;
            iVar4 = driver_create_file(lVar7,puVar8);
            if (iVar4 != 0) {
              printk(0xffffffc000d9c078,&__func___27795,0xe1d,*puVar8,iVar4);
              goto code_r0xffffffc000443ad8;
            }
          } while (lVar9 != 0xa8);
          pcStack_60 = als_open_report_data;
          pcStack_58 = als_enable_nodata;
          uStack_40 = uStack_40 & 0xffffffffffff0000;
          pcStack_50 = als_set_delay;
          iVar4 = als_register_control_path(&pcStack_60);
          if (iVar4 == 0) {
            pcStack_90 = als_get_data;
            uStack_80 = CONCAT44(uStack_80._4_4_,100);
            iVar4 = als_register_data_path(&pcStack_90);
            uVar3 = uStack_8;
            if (iVar4 == 0) {
              uStack_8._0_2_ = (ushort)(byte)uStack_8;
              pcStack_38 = ps_open_report_data;
              pcStack_30 = ps_enable_nodata;
              pcStack_28 = ps_set_delay;
              if (*(int *)(*plVar6 + 0x10) == 1) {
                wakeup_source_prepare(0xffffffc001185f50,0xffffffc000d9c100);
                wakeup_source_add(0xffffffc001185f50);
                uStack_8._0_3_ = CONCAT12(1,(ushort)uStack_8);
                uStack_8 = uStack_8 & 0xffffffffffffff00;
              }
              else {
                uStack_8 = CONCAT71((uint7)(uVar3 >> 8) & 0xffffffffff0000,1);
              }
              iVar4 = ps_register_control_path(&pcStack_38);
              if (iVar4 == 0) {
                uStack_68 = CONCAT44(uStack_68._4_4_,100);
                pcStack_78 = ps_get_data;
                iVar4 = ps_register_data_path(&pcStack_78);
                if (iVar4 == 0) {
                  iVar4 = batch_register_support_info(4,uStack_40._1_1_,100,0);
                  if (iVar4 != 0) {
                    printk(0xffffffc000d9c110,&__func___28071,0x15bd,iVar4);
                  }
                  iVar4 = batch_register_support_info(7,uStack_8._1_1_,100,0);
                  if (iVar4 != 0) {
                    printk(0xffffffc000d9c150,&__func___28071,0x15c3,iVar4);
                  }
                  uRamffffffc00100c390 = 0;
                  lVar7 = kmem_cache_alloc_trace(uRamffffffc00115bd30,0x80d0,0x1d0);
                  lRamffffffc001186010 = lVar7;
                  if (lVar7 == 0) {
                    printk(0xffffffc000d9c190,&__func___27887,0xe7d);
                  }
                  else {
                    lVar9 = 0;
                    *(undefined8 *)(lVar7 + 0x50) = 0xffffffc000e6d1f0;
                    *(undefined8 *)(lVar7 + 0x1a8) = 0xffffffc001040d10;
                    iVar4 = device_register();
                    if (iVar4 == 0) {
                      do {
                        iVar4 = (int)lVar9;
                        lVar7 = lVar9 * 8;
                        lVar9 = lVar9 + 1;
                        iVar5 = device_create_file(lRamffffffc001186010,
                                                   *(undefined8 *)(&stk3x1x_devattr_list + lVar7));
                        if (iVar5 != 0) {
                          printk(0xffffffc000d9c1f0,&__func___27887,0xe8c);
                          for (lVar7 = 0; (int)lVar7 < iVar4; lVar7 = lVar7 + 1) {
                            device_remove_file(lRamffffffc001186010,
                                               *(undefined8 *)(&stk3x1x_devattr_list + lVar7 * 8));
                          }
                          device_unregister(lRamffffffc001186010);
                          kfree(lRamffffffc001186010);
                          goto code_r0xffffffc000443b74;
                        }
                      } while (lVar9 != 3);
                      goto code_r0xffffffc0004439dc;
                    }
                    printk(0xffffffc000d9c1c0,&__func___27887,0xe84);
                    kfree(lRamffffffc001186010);
                  }
code_r0xffffffc000443b74:
                  printk(0xffffffc000d9c298,&__func___28071,0x15cf);
code_r0xffffffc0004439dc:
                  printk(0xffffffc000d9c228,&__func___28071);
                  return 0;
                }
                printk(0xffffffc000d9c0d8,&__func___28071,0x15b6,iVar4);
              }
              else {
                printk(0xffffffc000d9c0b0,&__func___28071,0x15ad,iVar4);
              }
            }
            else {
              printk(0xffffffc000d9c0d8,&__func___28071,0x158f,iVar4);
            }
          }
          else {
            printk(0xffffffc000d9c0b0,&__func___28071,0x1586,iVar4);
          }
        }
        misc_deregister(0xffffffc00100c320);
      }
      else {
        printk(0xffffffc000d9c040,&__func___28071,0x1548);
      }
    }
    kfree(plVar6);
  }
  lRamffffffc001185e60 = 0;
  uRamffffffc00100c390 = 0xffffffff;
  printk(0xffffffc000d9c240,&__func___28071,0x15ea,&__func___28071,iVar4);
  return iVar4;
}



// [-] Could not find function stk3x1x_attr_list at 0xffffffc000b6c138

// [-] Could not find function stk3x1x_devattr_list at 0xffffffc000b6c900

// [-] Could not find function stk3x1x_i2c_id at 0xffffffc000b6caa8

// ============================================================================
// Function: stk3x1x_init at 0xffffffc000f5bc60
// ============================================================================

undefined8 stk3x1x_init(void)

{
  if ((uRamffffffc0010b54da >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b54b8,0xffffffc000d9a400,&__func___28101);
  }
  printk(0xffffffc000d9a420);
  lRamffffffc00100c210 = get_alsps_dts_func(0xffffffc000d9a430,lRamffffffc00100c210);
  if (lRamffffffc00100c210 == 0) {
    printk(0xffffffc000d9a448,&__func___28101,0x163b);
  }
  alsps_driver_add(0xffffffc00100c218);
  printk(0xffffffc000d9a470);
  return 0;
}



