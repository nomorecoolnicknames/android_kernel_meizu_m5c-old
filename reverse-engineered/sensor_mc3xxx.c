/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: mc3xxx_release at 0xffffffc000445370
// ============================================================================

undefined8 mc3xxx_release(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd0) = 0;
  return 0;
}



// ============================================================================
// Function: mc3xxx_open_report_data at 0xffffffc00044537c
// ============================================================================

undefined8 mc3xxx_open_report_data(void)

{
  return 0;
}



// ============================================================================
// Function: _MC3XXX_LowResFilter at 0xffffffc000445384
// ============================================================================

void _MC3XXX_LowResFilter(short param_1,long param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  
  lVar7 = (long)param_1;
  lVar4 = lVar7 * 0xe;
  sVar2 = *(short *)(param_2 + lVar7 * 2);
  iVar3 = (int)sVar2 - (int)*(short *)(lVar4 + -0x3ffee79fa6);
  iVar8 = (int)sVar2;
  if (iVar3 + 1U < 3) {
    iVar9 = (int)sVar2;
    if (*(short *)(lVar4 + -0x3ffee79fb0) == 0) {
      sVar1 = *(short *)(lVar4 + -0x3ffee79faa);
      if (iVar9 == sVar1 || (int)sVar2 < (int)sVar1) {
        iVar5 = (int)*(short *)(lVar4 + -0x3ffee79fa8);
        iVar9 = (int)sVar1;
        if ((int)sVar2 < (int)*(short *)(lVar4 + -0x3ffee79fa8)) {
          *(short *)(lVar4 + -0x3ffee79fa8) = sVar2;
          iVar5 = iVar8;
        }
      }
      else {
        *(short *)(lVar4 + -0x3ffee79faa) = sVar2;
        iVar5 = (int)*(short *)(lVar4 + -0x3ffee79fa8);
        iVar9 = (int)sVar2;
      }
      iVar6 = iVar9;
      if (iVar5 != iVar9) {
        lVar4 = lVar7 * 0xe;
        if (*(short *)(lVar4 + -0x3ffee79fac) == iVar8) {
          iVar9 = (int)*(short *)(lVar4 + -0x3ffee79fa8);
          *(short *)(lVar4 + -0x3ffee79fa4) = *(short *)(lVar4 + -0x3ffee79fa4) + 1;
          iVar6 = (int)*(short *)(lVar4 + -0x3ffee79faa);
        }
        else {
          *(undefined2 *)(lVar4 + -0x3ffee79fa4) = 0;
          iVar9 = (int)*(short *)(lVar4 + -0x3ffee79fa8);
          iVar6 = (int)*(short *)(lVar4 + -0x3ffee79faa);
        }
      }
    }
    else {
      *(short *)(lVar4 + -0x3ffee79faa) = sVar2;
      *(short *)(lVar4 + -0x3ffee79fa8) = sVar2;
      *(undefined2 *)(lVar4 + -0x3ffee79fb0) = 0;
      *(undefined2 *)(lVar4 + -0x3ffee79fa4) = 0;
      iVar6 = iVar9;
    }
    if (iVar6 - iVar9 != 1) {
      *(short *)(lVar7 * 0xe + -0x3ffee79fa6) = (short)((iVar6 + iVar9) / 2);
    }
    iVar9 = *(short *)(lVar7 * 0xe + -0x3ffee79fae) + iVar3;
    if (iVar3 != 0) {
      *(short *)(lVar7 * 0xe + -0x3ffee79fae) = (short)iVar3;
    }
    if ((iVar9 + 2U < 5) && (*(short *)(lVar7 * 0xe + -0x3ffee79fa4) < 0xb)) {
      *(undefined2 *)(param_2 + lVar7 * 2) = *(undefined2 *)(lVar7 * 0xe + -0x3ffee79fa6);
      goto joined_r0xffffffc0004454d0;
    }
  }
  else {
    iVar9 = 0;
  }
  lVar4 = lVar7 * 0xe;
  *(undefined2 *)(lVar4 + -0x3ffee79fb0) = 1;
  *(short *)(lVar4 + -0x3ffee79fa6) = sVar2;
  *(undefined2 *)(lVar4 + -0x3ffee79fae) = 0;
joined_r0xffffffc0004454d0:
  if ((uRamffffffc0010b5d22 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b5d00,0xffffffc000d9d7f0,lVar7,iVar3,iVar9,iVar8,
                       (long)*(short *)(lVar7 * 0xe + -0x3ffee79fa6));
  }
  *(short *)(lVar7 * 0xe + -0x3ffee79fac) = sVar2;
  return;
}



// ============================================================================
// Function: MC3XXX_ValidateSensorIC at 0xffffffc00044557c
// ============================================================================

undefined8 MC3XXX_ValidateSensorIC(byte *param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  
  if ((uRamffffffc0010b5d4a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b5d28,0xffffffc000d9d868,&__func___26058,*param_1,*param_2);
  }
  cVar1 = *param_2;
  if (((byte)(cVar1 - 3U) < 0xd) || (cVar1 == '\x01')) {
    if (((*param_1 + 0x78 & 0xf7) != 0) && (*param_1 != 0x19)) {
      return 0xfffffffa;
    }
  }
  else if (((cVar1 == '\x02') || (cVar1 == '!')) || ((byte)(cVar1 - 0x10U) < 0x10)) {
    bVar2 = *param_1;
    if (((bVar2 & 0xdf) != 0x19 && (bVar2 != 0x29 && (bVar2 != 0xb8 && bVar2 != 0x90))) &&
       ((bVar2 & 0xdf) != 0x88)) {
      return 0xfffffffa;
    }
  }
  else {
    if (0xf < (byte)(cVar1 + 0x40U)) {
      if (((byte)(cVar1 - 0x22U) < 0xe) || (cVar1 == ' ')) {
        bVar2 = *param_1;
        *param_1 = bVar2 & 0xf1;
        if ((byte)((bVar2 & 0x31) - 0x20) < 2) {
          return 0;
        }
        if ((byte)((bVar2 & 0x71) - 0x10) < 2) {
          return 0;
        }
      }
      return 0xfffffffa;
    }
    bVar2 = *param_1;
    *param_1 = bVar2 & 0x71;
    if (((bVar2 & 0x71) - 0x30 & 0xef) != 0) {
      return 0xfffffffa;
    }
  }
  return 0;
}



// ============================================================================
// Function: mc3xxx_set_delay at 0xffffffc000445710
// ============================================================================

undefined8 mc3xxx_set_delay(int param_1)

{
  if ((uRamffffffc0010b5d72 >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010b5d50,0xffffffc000d9d8a8,param_1 / 1000000);
  return 0;
}



// ============================================================================
// Function: mc3xxx_compat_ioctl at 0xffffffc00044576c
// ============================================================================

long mc3xxx_compat_ioctl(long param_1,uint param_2,int param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  
  if ((*(long *)(param_1 + 0x28) == 0) ||
     (pcVar3 = *(code **)(*(long *)(param_1 + 0x28) + 0x50), pcVar3 == (code *)0x0)) {
    lVar2 = -0x19;
  }
  else if (param_2 == 0x400c8506) {
    if (param_3 == 0) {
      return -0x16;
    }
    lVar1 = (*pcVar3)(param_1,0x400c8506);
    lVar2 = 0;
    if (lVar1 != 0) {
      printk(0xffffffc000d9d938);
      lVar2 = lVar1;
    }
  }
  else if (param_2 < 0x400c8507) {
    if (param_2 != 0x8508) {
code_r0xffffffc00044582c:
      printk(0xffffffc000d9d9f8,param_2);
      return -0x203;
    }
    if (param_3 == 0) {
      return -0x16;
    }
    lVar1 = (*pcVar3)();
    lVar2 = 0;
    if (lVar1 != 0) {
      printk(0xffffffc000d9d9b8);
      lVar2 = lVar1;
    }
  }
  else if (param_2 == 0x400c8507) {
    if (param_3 == 0) {
      return -0x16;
    }
    lVar1 = (*pcVar3)(param_1,0x400c8507);
    lVar2 = 0;
    if (lVar1 != 0) {
      printk(0xffffffc000d9d978);
      lVar2 = lVar1;
    }
  }
  else {
    if (param_2 != 0x80048503) goto code_r0xffffffc00044582c;
    if (param_3 == 0) {
      return -0x16;
    }
    lVar1 = (*pcVar3)(param_1,0x80048503);
    lVar2 = 0;
    if (lVar1 != 0) {
      printk(0xffffffc000d9d8f0);
      lVar2 = lVar1;
    }
  }
  return lVar2;
}



// ============================================================================
// Function: mc3xxx_remove at 0xffffffc0004458d8
// ============================================================================

undefined8 mc3xxx_remove(void)

{
  i2c_del_driver(0xffffffc00100c9b8);
  return 0;
}



// ============================================================================
// Function: MC3XXX_i2c_read_block at 0xffffffc0004458fc
// ============================================================================

undefined8 MC3XXX_i2c_read_block(long param_1,undefined1 param_2,undefined8 param_3,ushort param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_31;
  undefined8 uStack_30;
  undefined1 *puStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  uStack_30 = 0;
  puStack_28 = (undefined1 *)0x0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  uStack_8 = 0;
  uStack_31 = param_2;
  mutex_lock(0xffffffc00100caa0);
  uVar2 = uStack_18;
  puStack_28 = &uStack_31;
  uStack_30._0_6_ = CONCAT24(1,(uint)*(ushort *)(param_1 + 2));
  uStack_18._0_4_ = CONCAT22(1,*(ushort *)(param_1 + 2));
  uStack_18._6_2_ = SUB82(uVar2,6);
  uStack_18 = CONCAT26(uStack_18._6_2_,CONCAT24(param_4,(undefined4)uStack_18)) & 0xffff00ffffffffff
  ;
  uStack_10 = param_3;
  if (param_1 != 0) {
    if ((param_4 & 0xff) < 9) {
      uVar2 = 0;
      iVar1 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&uStack_30,2);
      if (iVar1 != 2) {
        uVar2 = 0xfffffffb;
        printk(0xffffffc000d9da78,param_2,param_3,param_4 & 0xff,iVar1);
      }
      mutex_unlock(0xffffffc00100caa0);
      return uVar2;
    }
    printk(0xffffffc000d9da50,param_4 & 0xff,8);
  }
  mutex_unlock(0xffffffc00100caa0);
  return 0xffffffea;
}



// ============================================================================
// Function: MC3XXX_ReadData at 0xffffffc000445a04
// ============================================================================

undefined8 MC3XXX_ReadData(long param_1,short *param_2)

{
  long lVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  undefined4 uStack_8;
  short sStack_4;
  
  uStack_8 = 0;
  lVar13 = *(long *)(param_1 + 0xc0);
  sStack_4 = 0;
  if (((*(uint *)(lVar13 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b5d9a >> 2 & 1) != 0)) {
    __dynamic_pr_debug(0xffffffc0010b5d78,0xffffffc000d9daa8,&__func___26121,0);
  }
  if (param_1 == 0) {
    printk(0xffffffc000d9dae0);
    return 0xfffffffe;
  }
  if (cRamffffffc00118607a == '\x01') {
    iVar10 = MC3XXX_i2c_read_block(param_1,0,&uStack_8,3);
    if (iVar10 != 0) {
code_r0xffffffc000445ea8:
      printk(0xffffffc000d9db00);
      return 0xffffffff;
    }
    *param_2 = (short)(char)uStack_8;
    param_2[1] = (short)uStack_8._1_1_;
    param_2[2] = (short)uStack_8._2_1_;
    if (((*(uint *)(lVar13 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b5dc2 >> 2 & 1) != 0)) {
      __dynamic_pr_debug(0xffffffc0010b5da0,0xffffffc000d9db30,&__func___26121);
    }
    _MC3XXX_LowResFilter(0,param_2);
    _MC3XXX_LowResFilter(1,param_2);
    _MC3XXX_LowResFilter(2,param_2);
  }
  else if (cRamffffffc00118607a == '\x02') {
    iVar10 = MC3XXX_i2c_read_block(param_1,0xd,&uStack_8,6);
    if (iVar10 != 0) goto code_r0xffffffc000445ea8;
    *param_2 = (short)uStack_8;
    param_2[1] = uStack_8._2_2_;
    param_2[2] = sStack_4;
    if (((*(uint *)(lVar13 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b5dea >> 2 & 1) != 0)) {
      __dynamic_pr_debug(0xffffffc0010b5dc8,0xffffffc000d9db68,&__func___26121);
    }
  }
  if (((*(uint *)(lVar13 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b5e12 >> 2 & 1) != 0)) {
    __dynamic_pr_debug(0xffffffc0010b5df0,0xffffffc000d9dba0,(long)*param_2,(long)param_2[1],
                       (long)param_2[2]);
  }
  lVar12 = *(long *)(param_1 + 0xc0);
  if (((*(int *)(lVar12 + 0x2c) != 0) && (*(int *)(lVar12 + 0x4c) != 0)) &&
     (*(int *)(lVar12 + 0x24) == 0)) {
    iVar10 = *(int *)(lVar12 + 0x48);
    iVar11 = *(int *)(lVar12 + 0x11c);
    if (iVar11 < iVar10) {
      lVar1 = lVar12 + (long)iVar11 * 6;
      *(short *)(lVar1 + 0x50) = *param_2;
      *(short *)(lVar1 + 0x52) = param_2[1];
      *(short *)(lVar1 + 0x54) = param_2[2];
      *(int *)(lVar12 + 0x110) = (int)*param_2 + *(int *)(lVar12 + 0x110);
      *(int *)(lVar12 + 0x114) = (int)param_2[1] + *(int *)(lVar12 + 0x114);
      *(int *)(lVar12 + 0x118) = (int)param_2[2] + *(int *)(lVar12 + 0x118);
      if (((*(uint *)(lVar12 + 0x20) & 1) != 0) && ((uRamffffffc0010b5e3a >> 2 & 1) != 0)) {
        __dynamic_pr_debug(0xffffffc0010b5e18,0xffffffc000d9dbd8,iVar11,
                           (long)*(short *)(lVar1 + 0x50),(long)*(short *)(lVar1 + 0x52));
        iVar11 = *(int *)(lVar12 + 0x11c);
      }
      *(int *)(lVar12 + 0x11c) = iVar11 + 1;
      *(int *)(lVar12 + 0x120) = *(int *)(lVar12 + 0x120) + 1;
    }
    else {
      iVar11 = *(int *)(lVar12 + 0x120);
      iVar6 = 0;
      if (iVar10 != 0) {
        iVar6 = iVar11 / iVar10;
      }
      iVar4 = iVar11 - iVar6 * iVar10;
      lVar1 = lVar12 + (long)iVar4 * 6;
      iVar6 = *(int *)(lVar12 + 0x110) - (int)*(short *)(lVar1 + 0x50);
      *(int *)(lVar12 + 0x110) = iVar6;
      iVar7 = *(int *)(lVar12 + 0x114) - (int)*(short *)(lVar1 + 0x52);
      *(int *)(lVar12 + 0x114) = iVar7;
      iVar8 = *(int *)(lVar12 + 0x118) - (int)*(short *)(lVar1 + 0x54);
      *(int *)(lVar12 + 0x118) = iVar8;
      *(short *)(lVar1 + 0x50) = *param_2;
      *(short *)(lVar1 + 0x52) = param_2[1];
      *(short *)(lVar1 + 0x54) = param_2[2];
      iVar6 = iVar6 + *param_2;
      *(int *)(lVar12 + 0x110) = iVar6;
      sVar2 = 0;
      if (iVar10 != 0) {
        sVar2 = (short)(iVar6 / iVar10);
      }
      *(int *)(lVar12 + 0x114) = iVar7 + param_2[1];
      sVar3 = param_2[2];
      *(int *)(lVar12 + 0x120) = iVar11 + 1;
      *(int *)(lVar12 + 0x118) = iVar8 + sVar3;
      *param_2 = sVar2;
      sVar3 = 0;
      if (iVar10 != 0) {
        sVar3 = (short)(*(int *)(lVar12 + 0x114) / iVar10);
      }
      param_2[1] = sVar3;
      sVar5 = 0;
      if (iVar10 != 0) {
        sVar5 = (short)(*(int *)(lVar12 + 0x118) / iVar10);
      }
      param_2[2] = sVar5;
      if (((*(uint *)(lVar12 + 0x20) & 1) != 0) && ((uRamffffffc0010b5e62 >> 2 & 1) != 0)) {
        __dynamic_pr_debug(0xffffffc0010b5e40,0xffffffc000d9dc20,iVar4,
                           (long)*(short *)(lVar1 + 0x50),(long)*(short *)(lVar1 + 0x52),
                           (long)*(short *)(lVar1 + 0x54),*(undefined4 *)(lVar12 + 0x110),
                           *(undefined4 *)(lVar12 + 0x114),*(undefined4 *)(lVar12 + 0x118),
                           (int)sVar2,(int)sVar3,(int)sVar5);
      }
    }
  }
  if (((*(uint *)(lVar13 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b5e8a >> 2 & 1) != 0)) {
    __dynamic_pr_debug(0xffffffc0010b5e68,0xffffffc000d9dc78,(long)*param_2,(long)param_2[1],
                       (long)param_2[2]);
  }
  bVar9 = bRamffffffc00118607c;
  if (cRamffffffc00118607b == -0x78) {
    sVar2 = *param_2;
    *param_2 = param_2[1];
    param_2[1] = -sVar2;
    if ((uRamffffffc0010b5eb2 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b5e90,0xffffffc000d9dcb0,&__func___26121);
    }
  }
  else {
    if ((bRamffffffc00118607c & 1) != 0) {
      *param_2 = -*param_2;
    }
    if ((bVar9 >> 1 & 1) != 0) {
      param_2[1] = -param_2[1];
      return 0;
    }
  }
  return 0;
}



// ============================================================================
// Function: MC3XXX_ReadOffset at 0xffffffc000445ebc
// ============================================================================

int MC3XXX_ReadOffset(undefined8 param_1,short *param_2)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uStack_8;
  short sStack_4;
  
  uStack_8 = 0;
  sStack_4 = 0;
  if (cRamffffffc00118607a == '\x02') {
    iVar3 = MC3XXX_i2c_read_block(param_1,0xd,&uStack_8,6);
    if (iVar3 != 0) {
code_r0xffffffc00044605c:
      printk(0xffffffc000d9dce0,iVar3);
      return iVar3;
    }
    param_2[2] = sStack_4;
    *param_2 = (short)uStack_8;
    param_2[1] = (short)((uint)uStack_8 >> 0x10);
  }
  else if (cRamffffffc00118607a == '\x01') {
    iVar3 = MC3XXX_i2c_read_block(param_1,0,&uStack_8,3);
    if (iVar3 != 0) goto code_r0xffffffc00044605c;
    *param_2 = (short)(char)uStack_8;
    param_2[1] = (short)uStack_8._1_1_;
    param_2[2] = (short)uStack_8._2_1_;
  }
  if ((uRamffffffc0010b5eda >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b5eb8,0xffffffc000d9dcf8,(long)*param_2,(long)param_2[1],
                       (long)param_2[2]);
  }
  bVar2 = bRamffffffc00118607c;
  if (cRamffffffc00118607b == -0x78) {
    sVar1 = *param_2;
    *param_2 = param_2[1];
    param_2[1] = -sVar1;
    if ((uRamffffffc0010b5f02 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b5ee0,0xffffffc000d9dcb0,&__func___26136);
      return 0;
    }
  }
  else {
    if ((bRamffffffc00118607c & 1) != 0) {
      *param_2 = -*param_2;
    }
    if ((bVar2 >> 1 & 1) != 0) {
      param_2[1] = -param_2[1];
      return 0;
    }
  }
  return 0;
}



// ============================================================================
// Function: mc3xxx_open at 0xffffffc000446070
// ============================================================================

undefined8 mc3xxx_open(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = lRamffffffc001186080;
  *(long *)(param_2 + 0xd0) = lRamffffffc001186080;
  if (lVar1 == 0) {
    printk(0xffffffc000d9dd30);
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = nonseekable_open();
  }
  return uVar2;
}



// ============================================================================
// Function: MC3XXX_show_acc_z_calibbias at 0xffffffc0004461d0
// ============================================================================

long MC3XXX_show_acc_z_calibbias(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  
  lVar1 = lRamffffffc001186080;
  if (lRamffffffc001186080 != 0) {
    printk(0xffffffc000d9de08);
    iVar2 = sprintf(param_3,0xffffffc000e8cd68,(long)*(short *)(*(long *)(lVar1 + 0xc0) + 0x34));
    return (long)iVar2;
  }
  printk(0xffffffc000d9dde0);
  return 0;
}



// ============================================================================
// Function: MC3XXX_show_acc_y_calibbias at 0xffffffc000446240
// ============================================================================

long MC3XXX_show_acc_y_calibbias(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001186080 != 0) {
    lVar2 = *(long *)(lRamffffffc001186080 + 0xc0);
    printk(0xffffffc000d9de40);
    iVar1 = sprintf(param_3,0xffffffc000e8cd68,(long)*(short *)(lVar2 + 0x32));
    return (long)iVar1;
  }
  printk(0xffffffc000d9dde0);
  return 0;
}



// ============================================================================
// Function: MC3XXX_show_acc_x_calibbias at 0xffffffc0004462ac
// ============================================================================

long MC3XXX_show_acc_x_calibbias(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (lRamffffffc001186080 != 0) {
    lVar2 = *(long *)(lRamffffffc001186080 + 0xc0);
    printk(0xffffffc000d9de78);
    iVar1 = sprintf(param_3,0xffffffc000e8cd68,(long)*(short *)(lVar2 + 0x30));
    return (long)iVar1;
  }
  printk(0xffffffc000d9dde0);
  return 0;
}



// ============================================================================
// Function: mc3xxx_i2c_remove at 0xffffffc000446318
// ============================================================================

undefined8 mc3xxx_i2c_remove(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  lVar1 = lRamffffffc00100c9b0 + 0x28;
  if (lVar1 == 0) {
    printk(0xffffffc000d9ded8,0xffffffea);
  }
  else {
    puVar3 = (undefined8 *)&mc3xxx_attr_list;
    do {
      puVar4 = puVar3 + 1;
      driver_remove_file(lVar1,*puVar3);
      puVar3 = puVar4;
    } while (puVar4 != (undefined8 *)&__func___26473);
  }
  iVar2 = misc_deregister(0xffffffc00100cac8);
  if (iVar2 != 0) {
    printk(0xffffffc000d9deb0,iVar2);
  }
  uRamffffffc001186080 = 0;
  i2c_unregister_device(param_1);
  kfree(*(undefined8 *)(param_1 + 0xc0));
  return 0;
}



// ============================================================================
// Function: MC3XXX_store_acc_z_offset at 0xffffffc000446c60
// ============================================================================

undefined8
MC3XXX_store_acc_z_offset
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 auStack_4 [2];
  
  if (lRamffffffc001186080 == 0) {
    printk(0xffffffc000d9dde0);
    uVar2 = 0;
  }
  else {
    lVar3 = *(long *)(lRamffffffc001186080 + 0xc0);
    iVar1 = kstrtoint(param_3,10,auStack_4);
    uVar2 = 0xffffffffffffffea;
    if (iVar1 == 0) {
      *(undefined2 *)(lVar3 + 0x34) = auStack_4[0];
      printk(0xffffffc000d9e2e8);
      uVar2 = param_4;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: MC3XXX_store_acc_y_offset at 0xffffffc000446cd8
// ============================================================================

undefined8
MC3XXX_store_acc_y_offset
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 auStack_4 [2];
  
  if (lRamffffffc001186080 == 0) {
    printk(0xffffffc000d9dde0);
    uVar2 = 0;
  }
  else {
    lVar3 = *(long *)(lRamffffffc001186080 + 0xc0);
    iVar1 = kstrtoint(param_3,10,auStack_4);
    uVar2 = 0xffffffffffffffea;
    if (iVar1 == 0) {
      *(undefined2 *)(lVar3 + 0x32) = auStack_4[0];
      printk(0xffffffc000d9e328);
      uVar2 = param_4;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: MC3XXX_store_acc_x_offset at 0xffffffc000446d50
// ============================================================================

undefined8
MC3XXX_store_acc_x_offset
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 auStack_4 [2];
  
  if (lRamffffffc001186080 == 0) {
    printk(0xffffffc000d9dde0);
    uVar2 = 0;
  }
  else {
    lVar3 = *(long *)(lRamffffffc001186080 + 0xc0);
    iVar1 = kstrtoint(param_3,10,auStack_4);
    uVar2 = 0xffffffffffffffea;
    if (iVar1 == 0) {
      *(undefined2 *)(lVar3 + 0x30) = auStack_4[0];
      printk(0xffffffc000d9e368);
      uVar2 = param_4;
    }
  }
  return uVar2;
}



// ============================================================================
// Function: mc3xxx_local_init at 0xffffffc000446f28
// ============================================================================

int mc3xxx_local_init(void)

{
  int iVar1;
  
  if ((uRamffffffc0010b6182 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6160,0xffffffc000d9e468);
  }
  iVar1 = i2c_register_driver(0,0xffffffc00100c9b8);
  if (iVar1 == 0) {
    iVar1 = -(uint)(iRamffffffc00100cb14 == -1);
  }
  else {
    printk(0xffffffc000d9e498);
    iVar1 = -1;
  }
  return iVar1;
}



// ============================================================================
// Function: MC3XXX_i2c_write_block at 0xffffffc000446f9c
// ============================================================================

undefined8 MC3XXX_i2c_write_block(long param_1,undefined1 param_2,undefined1 *param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  mutex_lock(0xffffffc00100caa0);
  if (param_1 != 0) {
    if (param_4 < 8) {
      if (param_4 == 0) {
        iVar1 = 1;
      }
      else {
        uStack_7 = *param_3;
        uVar2 = (uint)param_4;
        if ((((uVar2 != 1) && (uStack_6 = param_3[1], uVar2 != 2)) &&
            (uStack_5 = param_3[2], uVar2 != 3)) &&
           (((uStack_4 = param_3[3], uVar2 != 4 && (uStack_3 = param_3[4], uVar2 != 5)) &&
            (uStack_2 = param_3[5], uVar2 == 7)))) {
          uStack_1 = param_3[6];
        }
        iVar1 = uVar2 + 1;
      }
      uStack_8 = param_2;
      iVar1 = i2c_master_send(param_1,&uStack_8,iVar1);
      if (-1 < iVar1) {
        mutex_unlock(0xffffffc00100caa0);
        return 0;
      }
      printk(0xffffffc000d9e4e0);
      mutex_unlock(0xffffffc00100caa0);
      return 0xfffffff2;
    }
    printk(0xffffffc000d9da50,param_4,8);
  }
  mutex_unlock(0xffffffc00100caa0);
  return 0xffffffea;
}



// ============================================================================
// Function: MC3XXX_SetPowerMode at 0xffffffc0004470d8
// ============================================================================

undefined4 MC3XXX_SetPowerMode(long param_1,char param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  undefined2 uStack_8;
  
  uStack_8 = 0;
  lVar5 = *(long *)(param_1 + 0xc0);
  if ((cRamffffffc0011860e0 == param_2) && ((uRamffffffc0010b61d2 >> 2 & 1) != 0)) {
    __dynamic_pr_debug(0xffffffc0010b61b0,0xffffffc000d9e508);
  }
  iVar3 = MC3XXX_i2c_read_block(param_1,7,&uStack_8,1);
  if (iVar3 == 0) {
    if (param_2 == '\0') {
      uStack_8 = CONCAT11(uStack_8._1_1_,0x43);
      iVar3 = MC3XXX_i2c_write_block(param_1,7,&uStack_8,1);
    }
    else {
      uStack_8 = CONCAT11(uStack_8._1_1_,0x41);
      iVar3 = MC3XXX_i2c_write_block(param_1,7,&uStack_8,1);
    }
    if (iVar3 < 0) {
      uVar4 = 0xffffffff;
      cVar2 = cRamffffffc0011860e0;
      if ((uRamffffffc0010b61fa >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010b61d8,0xffffffc000d9e580);
        cVar2 = cRamffffffc0011860e0;
      }
    }
    else {
      uVar4 = 0;
      cVar2 = param_2;
      if (((*(uint *)(lVar5 + 0x20) >> 4 & 1) != 0) &&
         (cVar2 = param_2, (uRamffffffc0010b6222 >> 2 & 1) != 0)) {
        uStack_8._1_1_ = (undefined1)((ushort)uStack_8 >> 8);
        uVar1 = uStack_8._1_1_;
        __dynamic_pr_debug(0xffffffc0010b6200,0xffffffc000d9e5b8,uVar1);
        cVar2 = param_2;
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    printk(0xffffffc000d9e550);
    cVar2 = cRamffffffc0011860e0;
  }
  cRamffffffc0011860e0 = cVar2;
  return uVar4;
}



// ============================================================================
// Function: mc3xxx_enable_nodata at 0xffffffc000447210
// ============================================================================

uint mc3xxx_enable_nodata(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 3;
  do {
    iVar1 = MC3XXX_SetPowerMode(*puRamffffffc001186088,param_1 == 1);
    if (iVar1 == 0) {
      if ((uRamffffffc0010b624a >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010b6228,0xffffffc000d9e5f0);
      }
      if ((uRamffffffc0010b62c2 >> 2 & 1) == 0) {
        return uRamffffffc0010b62c2 >> 2 & 1;
      }
      __dynamic_pr_debug(0xffffffc0010b62a0,0xffffffc000d9e698);
      return 0;
    }
    if ((uRamffffffc0010b6272 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b6250,0xffffffc000d9e628);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if ((uRamffffffc0010b629a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6278,0xffffffc000d9e660);
  }
  return 0xffffffff;
}



// ============================================================================
// Function: mc3xxx_suspend at 0xffffffc000447304
// ============================================================================

int mc3xxx_suspend(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xc0);
  if ((uRamffffffc0010b62ea >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b62c8,0xffffffc000d9e6d0);
  }
  iVar2 = 0;
  if (param_2 == 2) {
    if (lVar3 == 0) {
      iVar2 = -0x16;
      printk(0xffffffc000d9dd30);
    }
    else {
      *(undefined4 *)(lVar3 + 0x24) = 1;
      down_interruptible(0xffffffc0011860e8);
      iVar1 = MC3XXX_SetPowerMode(param_1,0);
      up(0xffffffc0011860e8);
      if (iVar1 != 0) {
        printk(0xffffffc000d9e6f8);
        iVar2 = iVar1;
      }
    }
  }
  return iVar2;
}



// ============================================================================
// Function: MC3XXX_WriteCalibration at 0xffffffc0004475f4
// ============================================================================

int MC3XXX_WriteCalibration(long param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  int iVar19;
  byte bVar20;
  int iVar21;
  undefined8 uStack_10;
  byte bStack_8;
  
  uStack_10 = 0;
  bStack_8 = 0;
  lVar17 = *(long *)(param_1 + 0xc0);
  if ((uRamffffffc0010b63b2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6390,0xffffffc000d9e898,*param_2,param_2[1],param_2[2]);
  }
  uVar18 = (int)*(char *)(lVar17 + 0x10) * param_2[*(byte *)(lVar17 + 0x14)];
  uVar16 = (int)*(char *)(lVar17 + 0x11) * param_2[*(byte *)(lVar17 + 0x15)];
  iVar5 = (int)*(char *)(lVar17 + 0x12) * param_2[*(byte *)(lVar17 + 0x16)];
  if (cRamffffffc00118607b == -0x78) {
    iVar19 = -uVar16;
    if ((uRamffffffc0010b63da >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b63b8,0xffffffc000d9e8d0,&__func___26182);
    }
  }
  else {
    uVar12 = bRamffffffc00118607c >> 1 & 1;
    iVar19 = (uVar18 ^ -(bRamffffffc00118607c & 1)) + (bRamffffffc00118607c & 1);
    uVar18 = (uVar16 ^ -uVar12) + uVar12;
    if ((uRamffffffc0010b6402 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b63e0,0xffffffc000d9e900,&__func___26182);
    }
  }
  *(short *)(lVar17 + 0x30) = (short)iVar19;
  *(short *)(lVar17 + 0x32) = (short)uVar18;
  *(short *)(lVar17 + 0x34) = (short)iVar5;
  if ((uRamffffffc0010b642a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6408,0xffffffc000d9e898,iVar19,uVar18,iVar5);
  }
  iVar7 = MC3XXX_i2c_read_block(param_1,0x21,&uStack_10,3);
  if (((iVar7 == 0) &&
      (iVar7 = MC3XXX_i2c_read_block(param_1,0x24,(long)&uStack_10 + 3,3), iVar7 == 0)) &&
     (iVar7 = MC3XXX_i2c_read_block(param_1,0x27,(long)&uStack_10 + 6,3), iVar7 == 0)) {
    if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) ||
        ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)) || (cRamffffffc001186090 == ' ')) {
      bVar20 = 0x7f;
      iVar14 = -0x4000;
      iVar7 = 0x3fff;
      uVar12 = 0xffff8000;
      uVar16 = 0x4000;
      uVar9 = 0x7f;
    }
    else {
      bVar20 = 0x3f;
      iVar14 = -0x2000;
      iVar7 = 0x1fff;
      uVar12 = 0xffffc000;
      uVar16 = 0x2000;
      uVar9 = 0x3f;
    }
    uVar15 = (uint)(short)((ushort)(byte)uStack_10 + (uVar9 & uStack_10._1_1_) * 0x100);
    if ((uVar15 & uVar16) != 0) {
      uVar15 = uVar15 | uVar12;
    }
    uVar13 = (uint)(short)((ushort)uStack_10._2_1_ + (uVar9 & uStack_10._3_1_) * 0x100);
    if ((uVar13 & uVar16) != 0) {
      uVar13 = uVar13 | uVar12;
    }
    uVar8 = (uint)(short)((ushort)uStack_10._4_1_ + (uVar9 & uStack_10._5_1_) * 0x100);
    if ((uVar8 & uVar16) != 0) {
      uVar8 = uVar8 | uVar12;
    }
    iVar6 = 0;
    if (uRamffffffc0011860a8 != 0) {
      iVar6 = ((iVar19 << 0x13) / 3) / (int)(uint)uRamffffffc0011860a8;
    }
    uVar1 = (uint)bStack_8 + (uint)(uStack_10._5_1_ >> 7) * 0x100;
    uVar2 = (uint)uStack_10._6_1_ + (uint)(uStack_10._1_1_ >> 7) * 0x100;
    uVar3 = (uint)uStack_10._7_1_ + (uint)(uStack_10._3_1_ >> 7) * 0x100;
    uVar16 = uVar2 + 0x28;
    uVar12 = uVar3 + 0x28;
    iVar19 = 0;
    if (uRamffffffc0011860aa != 0) {
      iVar19 = ((int)(uVar18 << 0x13) / 3) / (int)(uint)uRamffffffc0011860aa;
    }
    uVar18 = uVar1 + 0x28;
    iVar21 = 0;
    if (uRamffffffc0011860ac != 0) {
      iVar21 = ((iVar5 * 0x80000) / 3) / (int)(uint)uRamffffffc0011860ac;
    }
    iVar5 = 0;
    if (uVar16 != 0) {
      iVar5 = iVar6 / (int)uVar16;
    }
    iVar5 = iVar5 + uVar15;
    iVar6 = 0;
    if (uVar12 != 0) {
      iVar6 = iVar19 / (int)uVar12;
    }
    iVar6 = iVar6 + uVar13;
    iVar19 = 0;
    if (uVar18 != 0) {
      iVar19 = iVar21 / (int)uVar18;
    }
    iVar19 = iVar19 + uVar8;
    iVar21 = iVar7;
    if ((iVar5 <= iVar7) && (iVar21 = iVar5, iVar5 < iVar14)) {
      iVar21 = iVar14;
    }
    iVar5 = iVar7;
    if ((iVar6 <= iVar7) && (iVar5 = iVar6, iVar6 < iVar14)) {
      iVar5 = iVar14;
    }
    if ((iVar19 <= iVar7) && (iVar7 = iVar19, iVar19 < iVar14)) {
      iVar7 = iVar14;
    }
    uRamffffffc001186110 = 0;
    if (uVar16 != 0) {
      uRamffffffc001186110 = 0x15555 / uVar16;
    }
    lVar17 = 0x32;
    uStack_10._0_1_ = 0x43;
    uRamffffffc001186114 = 0;
    if (uVar12 != 0) {
      uRamffffffc001186114 = 0x15555 / uVar12;
    }
    uRamffffffc001186118 = 0;
    if (uVar18 != 0) {
      uRamffffffc001186118 = 0x15555 / uVar18;
    }
    iRamffffffc001186100 = iVar21;
    iRamffffffc001186104 = iVar5;
    iRamffffffc001186108 = iVar7;
    MC3XXX_i2c_write_block(param_1,7,&uStack_10,1);
    bVar10 = 0x80;
    bVar4 = bVar10;
    if ((uVar2 & 0x100) == 0) {
      bVar4 = 0;
    }
    if ((uVar3 & 0x100) == 0) {
      bVar10 = 0;
    }
    bVar11 = 0x80;
    if ((uVar1 & 0x100) == 0) {
      bVar11 = 0;
    }
    uStack_10 = CONCAT35(CONCAT21(uStack_10._6_2_,bVar11 | bVar20 & (byte)((uint)iVar7 >> 8)),
                         CONCAT14((char)iVar7,
                                  CONCAT13(bVar10 | bVar20 & (byte)((uint)iVar5 >> 8),
                                           CONCAT12((char)iVar5,
                                                    CONCAT11(bVar4 | bVar20 & (byte)((uint)iVar21 >>
                                                                                    8),(char)iVar21)
                                                   ))));
    MC3XXX_i2c_write_block(param_1,0x21,&uStack_10,6);
    uStack_10 = CONCAT71(uStack_10._1_7_,0x41);
    MC3XXX_i2c_write_block(param_1,7,&uStack_10,1);
    do {
      __const_udelay(0x418958);
      lVar17 = lVar17 + -1;
    } while (lVar17 != 0);
    return 0;
  }
  printk(0xffffffc000d9dce0,iVar7);
  return iVar7;
}



// ============================================================================
// Function: MC3XXX_ResetCalibration at 0xffffffc000447a8c
// ============================================================================

int MC3XXX_ResetCalibration(long param_1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  
  uStack_7 = 0;
  lVar6 = *(long *)(param_1 + 0xc0);
  uStack_6 = 0;
  uStack_8 = 0x43;
  iVar1 = MC3XXX_i2c_write_block(param_1,7,&uStack_8,1);
  if (iVar1 != 0) {
    printk(0xffffffc000d9e938,iVar1);
  }
  iVar1 = MC3XXX_i2c_write_block(param_1,0x21,0xffffffc001186120,6);
  if (iVar1 != 0) {
    printk(0xffffffc000d9dce0,iVar1);
  }
  uStack_8 = 0x41;
  iVar1 = MC3XXX_i2c_write_block(param_1,7,&uStack_8,1);
  if (iVar1 != 0) {
    printk(0xffffffc000d9dce0,iVar1);
  }
  lVar5 = 0x14;
  do {
    __const_udelay(0x418958);
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) || ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)
      ) || (cRamffffffc001186090 == ' ')) {
    uVar4 = 0xffff8000;
    uVar3 = 0x4000;
    uVar2 = 0x7f;
  }
  else {
    uVar4 = 0xffffc000;
    uVar3 = 0x2000;
    uVar2 = 0x3f;
  }
  uRamffffffc001186100 =
       (uint)(short)((ushort)bRamffffffc001186120 + (uVar2 & bRamffffffc001186121) * 0x100);
  if ((uRamffffffc001186100 & uVar3) != 0) {
    uRamffffffc001186100 = uRamffffffc001186100 | uVar4;
  }
  uRamffffffc001186104 =
       (uint)(short)((ushort)bRamffffffc001186122 + (uVar2 & bRamffffffc001186123) * 0x100);
  if ((uRamffffffc001186104 & uVar3) != 0) {
    uRamffffffc001186104 = uRamffffffc001186104 | uVar4;
  }
  uRamffffffc001186108 =
       (uint)(short)((ushort)bRamffffffc001186124 + (uVar2 & bRamffffffc001186125) * 0x100);
  if ((uRamffffffc001186108 & uVar3) != 0) {
    uRamffffffc001186108 = uRamffffffc001186108 | uVar4;
  }
  *(undefined8 *)(lVar6 + 0x30) = 0;
  return iVar1;
}



// ============================================================================
// Function: MC3XXX_store_acc_calibration at 0xffffffc000447d64
// ============================================================================

undefined8 MC3XXX_store_acc_calibration(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_1c;
  undefined4 uStack_18;
  short sStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uVar1 = uRamffffffc001186080;
  uStack_18 = 0;
  sStack_14 = 0;
  iVar3 = sscanf(param_3,0xffffffc000e5d090,&iStack_1c);
  if ((iVar3 == 1) && (iStack_1c == 1)) {
    iVar7 = 0;
    iVar5 = 100;
    iVar6 = 0;
    iVar3 = 0;
    printk(0xffffffc000d9e9e0);
    uVar2 = uRamffffffc0011860e0;
    MC3XXX_SetPowerMode(uVar1,1);
    printk(0xffffffc000d9e9f8);
    MC3XXX_ResetCalibration(uVar1);
    do {
      lVar4 = 0x33;
      MC3XXX_ReadData(uVar1,&uStack_18);
      iVar3 = iVar3 + (short)uStack_18;
      iVar6 = iVar6 + uStack_18._2_2_;
      iVar7 = iVar7 + sStack_14;
      do {
        __const_udelay(0x418958);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iStack_10 = -(-iVar6 / 100);
    iStack_8 = iVar7 / 100;
    iStack_c = -iVar3 / 100;
    MC3XXX_WriteCalibration(uVar1,&iStack_10);
    printk(0xffffffc000d9ea28,iStack_10,iStack_c,iStack_8);
    MC3XXX_SetPowerMode(uVar1,uVar2);
  }
  return 0;
}



// ============================================================================
// Function: MC3XXX_reset at 0xffffffc000447eb4
// ============================================================================

void MC3XXX_reset(undefined8 param_1)

{
  byte abStack_8 [8];
  
  abStack_8[0] = 0x43;
  abStack_8[1] = 0;
  MC3XXX_i2c_write_block(param_1,7,abStack_8,1);
  MC3XXX_i2c_read_block(param_1,4,abStack_8,1);
  if ((abStack_8[0] >> 6 & 1) == 0) {
    abStack_8[0] = 0x6d;
    MC3XXX_i2c_write_block(param_1,0x1b,abStack_8,1);
    abStack_8[0] = 0x43;
    MC3XXX_i2c_write_block(param_1,0x1b,abStack_8,1);
  }
  abStack_8[0] = 0x43;
  MC3XXX_i2c_write_block(param_1,7,abStack_8,1);
  abStack_8[0] = 0x80;
  MC3XXX_i2c_write_block(param_1,0x1c,abStack_8,1);
  abStack_8[0] = 0x80;
  MC3XXX_i2c_write_block(param_1,0x17,abStack_8,1);
  __const_udelay(0x147aeb8);
  abStack_8[0] = 0;
  MC3XXX_i2c_write_block(param_1,0x1c,abStack_8,1);
  abStack_8[0] = 0;
  MC3XXX_i2c_write_block(param_1,0x17,abStack_8,1);
  __const_udelay(0x147aeb8);
  MC3XXX_i2c_read_block(param_1,0x21,0xffffffc001186120,6);
  MC3XXX_i2c_read_block(param_1,4,abStack_8,1);
  if ((abStack_8[0] >> 6 & 1) != 0) {
    abStack_8[0] = 0x6d;
    MC3XXX_i2c_write_block(param_1,0x1b,abStack_8,1);
    abStack_8[0] = 0x43;
    MC3XXX_i2c_write_block(param_1,0x1b,abStack_8,1);
  }
  abStack_8[0] = 0x41;
  MC3XXX_i2c_write_block(param_1,7,abStack_8,1);
  return;
}



// ============================================================================
// Function: _mc3xxx_i2c_auto_probe at 0xffffffc00044806c
// ============================================================================

undefined8 _mc3xxx_i2c_auto_probe(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  ushort auStack_28 [4];
  ushort auStack_20 [4];
  int aiStack_18 [6];
  
  aiStack_18[0] = 0;
  aiStack_18[1] = 0;
  aiStack_18[2] = 0;
  aiStack_18[3] = 0;
  auStack_28[0] = 0;
  auStack_20[0] = 0;
  aiStack_18[4] = 0;
  aiStack_18[5] = 0;
  cRamffffffc001186126 = '\0';
code_r0xffffffc0004480b8:
  lVar3 = 0;
  cRamffffffc00118607b = cRamffffffc001186126;
  cRamffffffc001186090 = cRamffffffc001186126;
  do {
    auStack_28[0] = auStack_28[0] & 0xff00;
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(&mc3xxx_i2c_auto_probe_addr + lVar3 * 2);
    iVar2 = MC3XXX_i2c_read_block(param_1,0x3b,auStack_28,1);
    if (-1 < iVar2) {
      iVar2 = aiStack_18[lVar3];
      cVar1 = (char)auStack_28[0];
      aiStack_18[lVar3] = iVar2 + 1;
      if ((char)auStack_28[0] == '\0') {
        if (iVar2 + 1 == 1) break;
      }
      else {
        auStack_20[0] = auStack_20[0] & 0xff00;
        MC3XXX_i2c_read_block(param_1,0x18,auStack_20,1);
        cRamffffffc001186126 = (char)auStack_28[0];
        iVar2 = MC3XXX_ValidateSensorIC(auStack_28,auStack_20);
        if (iVar2 == 0) {
          cRamffffffc00118607b = (char)auStack_28[0];
          cRamffffffc001186090 = (undefined1)auStack_20[0];
          if ((uRamffffffc0010b6452 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b6430,0xffffffc000d9dd50,&__func___26083);
          }
          MC3XXX_i2c_read_block(param_1,0x21,0xffffffc001186128,3);
          MC3XXX_i2c_read_block(param_1,0x24,0xffffffc00118612b,3);
          if ((uRamffffffc0010b647a >> 2 & 1) == 0) {
            return 0;
          }
          __dynamic_pr_debug(0xffffffc0010b6458,0xffffffc000d9ea80,uRamffffffc001186128,
                             uRamffffffc001186129,uRamffffffc00118612a,uRamffffffc00118612b,
                             uRamffffffc00118612c,uRamffffffc00118612d);
          return 0;
        }
      }
    }
    lVar3 = lVar3 + 1;
    if (lVar3 == 6) {
      return 0xffffffff;
    }
  } while( true );
  MC3XXX_reset(param_1);
  __const_udelay(0xc49c08);
  cRamffffffc001186126 = cVar1;
  goto code_r0xffffffc0004480b8;
}



// ============================================================================
// Function: MC3XXX_Init.isra.6 at 0xffffffc00044822c
// ============================================================================

undefined8 MC3XXX_Init_isra_6(long param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  ushort auStack_18 [4];
  byte abStack_10 [8];
  undefined2 uStack_8;
  
  auStack_18[0] = 0x43;
  MC3XXX_i2c_write_block(param_1,7,auStack_18,1);
  switch(uRamffffffc00118607b) {
  case 0x11:
  case 0x91:
    printk(0xffffffc000d9eae8);
  case 0x10:
  case 0x40:
  case 0x88:
  case 0x90:
  case 0xa8:
  case 0xb8:
    cRamffffffc00118607a = '\x02';
    break;
  default:
    printk(0xffffffc000d9eb08);
    break;
  case 0x20:
  case 0x21:
  case 0x61:
  case 0xa0:
  case 0xa1:
  case 0xe0:
  case 0xe1:
    printk(0xffffffc000d9eae8);
  case 0x19:
  case 0x29:
  case 0x30:
  case 0x39:
  case 0x60:
    cRamffffffc00118607a = '\x01';
    break;
  case 0x99:
    printk(0xffffffc000d9eae8);
  }
  abStack_10[0] = 8;
  abStack_10[1] = 0;
  if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) || (cRamffffffc001186090 == ' ')) ||
     ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)) {
    uStack_8._0_1_ = 0x2a;
    uStack_8._1_1_ = 0;
    MC3XXX_i2c_read_block(param_1,0x2a,&uStack_8,1);
    bVar2 = (byte)uStack_8 & 0xc0;
    bVar1 = (byte)uStack_8 & 0xc0;
    uStack_8 = CONCAT11(uStack_8._1_1_,(byte)uStack_8) & 0xffc0;
    if (bVar1 == 0x40) {
      abStack_10[0] = 8;
      bVar1 = abStack_10[0];
    }
    else {
      if (bVar1 < 0x41) {
        if (bVar2 == 0) goto code_r0xffffffc0004482cc;
      }
      else {
        if (bVar1 == 0x80) {
          abStack_10[0] = 9;
          bVar1 = abStack_10[0];
          goto code_r0xffffffc0004482cc;
        }
        if (bVar1 == 0xc0) {
          bVar1 = 10;
          goto code_r0xffffffc0004482cc;
        }
      }
      printk(0xffffffc000d9eb38,&__func___26239);
      bVar1 = abStack_10[0];
    }
  }
  else {
    abStack_10[1] = 0;
    bVar1 = 0;
  }
code_r0xffffffc0004482cc:
  abStack_10[0] = bVar1;
  MC3XXX_i2c_write_block(param_1,8,abStack_10,1);
  uStack_8 = 0xf;
  if (cRamffffffc00118607a == '\x01') {
    uStack_8 = 0x32;
    if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) ||
        ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)) || (cRamffffffc001186090 == ' ')) {
      uStack_8 = 2;
    }
  }
  else if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) ||
           ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)) || (cRamffffffc001186090 == ' ')) {
    uStack_8 = 0x25;
  }
  iVar3 = MC3XXX_i2c_write_block(param_1,0x20,&uStack_8,1);
  if (iVar3 < 0) {
    printk(0xffffffc000d9eb70);
  }
  uRamffffffc0011860ac = 0x400;
  uRamffffffc0011860aa = 0x400;
  uRamffffffc0011860a8 = 0x400;
  if (cRamffffffc00118607a == '\x01') {
    uRamffffffc0011860ac = 0x56;
    uRamffffffc0011860aa = 0x56;
    uRamffffffc0011860a8 = 0x56;
    if ((((byte)(cRamffffffc001186090 + 0x40U) < 0x10) || (cRamffffffc001186090 == ' ')) ||
       ((byte)(cRamffffffc001186090 - 0x22U) < 0xe)) {
      uRamffffffc0011860a8 = 0x40;
      uRamffffffc0011860ac = 0x40;
      uRamffffffc0011860aa = 0x40;
    }
  }
  auStack_18[0] = auStack_18[0] & 0xff00;
  MC3XXX_i2c_write_block(param_1,9,auStack_18,1);
  auStack_18[0] = auStack_18[0] & 0xff00;
  MC3XXX_i2c_write_block(param_1,6,auStack_18,1);
  auStack_18[0] = auStack_18[0] & 0xff00;
  MC3XXX_i2c_read_block(param_1,0x2a,auStack_18,1);
  uRamffffffc001186070 = 0;
  lVar4 = *(long *)(param_1 + 0xc0);
  *(undefined8 *)(lVar4 + 0x50) = 0;
  *(undefined8 *)(lVar4 + 0x58) = 0;
  *(undefined8 *)(lVar4 + 0x60) = 0;
  *(undefined8 *)(lVar4 + 0x68) = 0;
  *(undefined8 *)(lVar4 + 0x70) = 0;
  *(undefined8 *)(lVar4 + 0x78) = 0;
  *(undefined8 *)(lVar4 + 0x80) = 0;
  *(undefined8 *)(lVar4 + 0x88) = 0;
  *(undefined8 *)(lVar4 + 0x90) = 0;
  *(undefined8 *)(lVar4 + 0x98) = 0;
  *(undefined8 *)(lVar4 + 0xa0) = 0;
  *(undefined8 *)(lVar4 + 0xa8) = 0;
  *(undefined8 *)(lVar4 + 0xb0) = 0;
  *(undefined8 *)(lVar4 + 0xb8) = 0;
  *(undefined8 *)(lVar4 + 0xc0) = 0;
  *(undefined8 *)(lVar4 + 200) = 0;
  *(undefined8 *)(lVar4 + 0xd0) = 0;
  *(undefined8 *)(lVar4 + 0xd8) = 0;
  *(undefined8 *)(lVar4 + 0xe0) = 0;
  *(undefined8 *)(lVar4 + 0xe8) = 0;
  *(undefined8 *)(lVar4 + 0xf0) = 0;
  *(undefined8 *)(lVar4 + 0xf8) = 0;
  *(undefined8 *)(lVar4 + 0x100) = 0;
  *(undefined8 *)(lVar4 + 0x108) = 0;
  *(undefined8 *)(lVar4 + 0x110) = 0;
  *(undefined8 *)(lVar4 + 0x118) = 0;
  *(undefined4 *)(lVar4 + 0x120) = 0;
  uRamffffffc001186050 = 0;
  uRamffffffc001186058 = 0;
  bRamffffffc00118607c = (byte)auStack_18[0] & 3;
  uRamffffffc001186060 = 0;
  uRamffffffc001186068 = 0;
  uRamffffffc001186078 = 0;
  return 0;
}



// ============================================================================
// Function: mc3xxx_resume at 0xffffffc0004485b8
// ============================================================================

int mc3xxx_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xc0);
  if ((uRamffffffc0010b64a2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6480,0xffffffc000d9eb98);
  }
  if (lVar2 == 0) {
    printk(0xffffffc000d9dd30);
    iVar1 = -0x16;
  }
  else {
    down_interruptible(0xffffffc0011860e8);
    iVar1 = MC3XXX_Init_isra_6(param_1);
    if (iVar1 == 0) {
      iVar1 = MC3XXX_SetPowerMode(param_1,1);
      up(0xffffffc0011860e8);
      if (iVar1 == 0) {
        *(undefined4 *)(lVar2 + 0x24) = 0;
        iVar1 = 0;
      }
      else {
        printk(0xffffffc000d9e6f8);
      }
    }
    else {
      up(0xffffffc0011860e8);
      printk(0xffffffc000d9ebc0);
    }
  }
  return iVar1;
}



// ============================================================================
// Function: mc3xxx_i2c_probe at 0xffffffc000448698
// ============================================================================

int mc3xxx_i2c_probe(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 *puVar8;
  code *pcStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  code *pcStack_30;
  code *pcStack_28;
  code *pcStack_20;
  undefined8 uStack_18;
  long lStack_10;
  undefined8 uStack_8;
  
  uStack_38 = 0;
  pcStack_30 = (code *)0x0;
  pcStack_28 = (code *)0x0;
  pcStack_48 = (code *)0x0;
  uStack_40 = 0;
  pcStack_20 = (code *)0x0;
  uStack_18 = 0;
  lStack_10 = 0;
  uStack_8 = 0;
  if ((uRamffffffc0010b64ca >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b64a8,0xffffffc000d9ebe8);
  }
  iVar2 = _mc3xxx_i2c_auto_probe(param_1);
  if (iVar2 == 0) {
    plVar4 = (long *)kmem_cache_alloc_trace(uRamffffffc00115bd30,0x80d0,400);
    lVar7 = lRamffffffc00100c990;
    if (plVar4 == (long *)0x0) {
      iVar2 = -0xc;
    }
    else {
      plVar4[1] = lRamffffffc00100c990;
      iVar2 = hwmsen_get_convert(*(undefined4 *)(lVar7 + 4),plVar4 + 2);
      if (iVar2 == 0) {
        *plVar4 = param_1;
        *(long **)(param_1 + 0xc0) = plVar4;
        *(undefined4 *)(plVar4 + 4) = 0;
        *(undefined4 *)((long)plVar4 + 0x24) = 0;
        iVar3 = *(int *)(plVar4[1] + 0x10);
        if (0x20 < iVar3) {
          iVar3 = 0x20;
        }
        plRamffffffc001186088 = plVar4;
        *(int *)(plVar4 + 9) = iVar3;
        if (0 < (int)plVar4[9]) {
          *(undefined4 *)((long)plVar4 + 0x4c) = 1;
        }
        lRamffffffc001186080 = param_1;
        MC3XXX_reset(param_1);
        iVar3 = _mc3xxx_i2c_auto_probe(param_1);
        if (iVar3 == 0) {
          MC3XXX_i2c_read_block(param_1,0x21,0xffffffc001186120,6);
          iVar2 = MC3XXX_Init_isra_6(param_1);
          if (iVar2 == 0) {
            uRamffffffc0011860e8 = 0;
            uRamffffffc0011860ec = 1;
            uRamffffffc0011860f0 = 0xffffffc0011860f0;
            uRamffffffc0011860f8 = 0xffffffc0011860f0;
            uRamffffffc0011860ea = uRamffffffc0011860e8;
            iVar2 = misc_register(0xffffffc00100cac8);
            if (iVar2 == 0) {
              lStack_10._0_3_ = (uint3)(ushort)lStack_10;
              lVar7 = lRamffffffc00100c9b0 + 0x28;
              if (lVar7 == 0) {
                iVar2 = -0x16;
code_r0xffffffc000448a38:
                printk(0xffffffc000d9edc0,iVar2);
                misc_deregister(0xffffffc00100cac8);
              }
              else {
                puVar6 = (undefined8 *)&mc3xxx_attr_list;
                do {
                  puVar8 = (undefined8 *)*puVar6;
                  puVar6 = puVar6 + 1;
                  iVar2 = driver_create_file(lVar7,puVar8);
                  if (iVar2 != 0) {
                    printk(0xffffffc000d9ec70,*puVar8);
                    goto code_r0xffffffc000448a38;
                  }
                } while (puVar6 != (undefined8 *)&__func___26473);
                pcStack_20 = mc3xxx_set_delay;
                pcStack_28 = mc3xxx_enable_nodata;
                pcStack_30 = mc3xxx_open_report_data;
                lStack_10 = (ulong)CONCAT61(lStack_10._2_6_,*(undefined1 *)(plVar4[1] + 0x2c)) << 8;
                iVar2 = acc_register_control_path(&pcStack_30);
                if (iVar2 == 0) {
                  pcStack_48 = mc3xxx_get_data;
                  uStack_38 = CONCAT44(uStack_38._4_4_,1000);
                  iVar2 = acc_register_data_path(&pcStack_48);
                  if (iVar2 == 0) {
                    if ((uRamffffffc0010b64f2 >> 2 & 1) != 0) {
                      __dynamic_pr_debug(0xffffffc0010b64d0,0xffffffc000d9ed00,&__func___27207);
                    }
                    uRamffffffc00100cb14 = 0;
                    lRamffffffc001186130 = kmem_cache_alloc_trace(uRamffffffc00115bd30,0x80d0,0x1d0)
                    ;
                    if (lRamffffffc001186130 == 0) {
                      printk(0xffffffc000d9ed20);
                    }
                    lVar7 = lRamffffffc001186130;
                    *(undefined8 *)(lRamffffffc001186130 + 0x50) = 0xffffffc000d9ee20;
                    *(undefined8 *)(lVar7 + 0x1a8) = 0xffffffc001040d10;
                    iVar2 = device_register(lVar7);
                    if (iVar2 == 0) {
                      lVar7 = 0;
                      do {
                        iVar2 = (int)lVar7;
                        lVar1 = lVar7 * 8;
                        lVar7 = lVar7 + 1;
                        iVar3 = device_create_file(lRamffffffc001186130,
                                                   *(undefined8 *)
                                                    (&calibrate_dev_attributes + lVar1));
                        if (iVar3 != 0) {
                          lVar7 = 0;
                          printk(0xffffffc000d9ed70);
                          if (iVar2 != 0) {
                            do {
                              lVar1 = lVar7 * 8;
                              lVar7 = lVar7 + 1;
                              device_remove_file(lRamffffffc001186130,
                                                 *(undefined8 *)(&calibrate_dev_attributes + lVar1))
                              ;
                            } while ((int)lVar7 < iVar2);
                          }
                          device_unregister(lRamffffffc001186130);
                          kfree(lRamffffffc001186130);
                          goto code_r0xffffffc000448aec;
                        }
                      } while (lVar7 != 7);
                    }
                    else {
                      printk(0xffffffc000d9ed48);
                      kfree(lRamffffffc001186130);
code_r0xffffffc000448aec:
                      printk(0xffffffc000d9ede8);
                    }
                    plVar4[0x26] = (long)(plVar4 + 0x26);
                    plVar4[0x25] = 0xfffffffe0;
                    plVar4[0x27] = (long)(plVar4 + 0x26);
                    plVar4[0x28] = (long)mc3xxx_cali_work;
                    init_timer_key(plVar4 + 0x29,2,0,0);
                    plVar4[0x2e] = (long)(plVar4 + 0x25);
                    plVar4[0x2d] = (long)delayed_work_timer_fn;
                    msleep(10);
                    uVar5 = msecs_to_jiffies(5000);
                    queue_delayed_work_on(8,uRamffffffc00112e488,plVar4 + 0x25,uVar5);
                    if ((uRamffffffc0010b651a >> 2 & 1) == 0) {
                      return 0;
                    }
                    __dynamic_pr_debug(0xffffffc0010b64f8,0xffffffc000d9ed00,&__func___27207);
                    return 0;
                  }
                  printk(0xffffffc000d9ecd0,iVar2);
                }
                else {
                  printk(0xffffffc000d9eca0);
                }
              }
            }
            else {
              printk(0xffffffc000d9ec40);
            }
          }
        }
      }
      else {
        printk(0xffffffc000d9ec18,*(undefined4 *)(plVar4[1] + 4));
      }
      kfree(plVar4);
    }
  }
  printk(0xffffffc000d9eda0,&__func___27207,iVar2);
  uRamffffffc00100cb14 = 0xffffffff;
  return iVar2;
}



// ============================================================================
// Function: MC3XXX_ReadSensorData.isra.7 at 0xffffffc000448b84
// ============================================================================

undefined4 MC3XXX_ReadSensorData_isra_7(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  undefined4 uVar13;
  undefined8 uStack_10;
  int iStack_8;
  
  uStack_10 = 0;
  iStack_8 = 0;
  lVar12 = *(long *)(param_1 + 0xc0);
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar13 = 0xfffffffe;
    printk(0xffffffc000d9dae0);
  }
  else {
    if ((cRamffffffc0011860e0 == '\0') && (iVar11 = MC3XXX_SetPowerMode(param_1,1), iVar11 != 0)) {
      printk(0xffffffc000d9ee28);
    }
    iVar11 = MC3XXX_ReadData(param_1,lVar12 + 0x40);
    if (iVar11 == 0) {
      if (((*(uint *)(lVar12 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b6542 >> 2 & 1) != 0)) {
        __dynamic_pr_debug(0xffffffc0010b6520,0xffffffc000d9ee80,&__func___26267,
                           (long)*(short *)(lVar12 + 0x40),(long)*(short *)(lVar12 + 0x42),
                           (long)*(short *)(lVar12 + 0x44));
      }
      cVar4 = *(char *)(lVar12 + 0x11);
      sVar6 = *(short *)(lVar12 + 0x42);
      sVar7 = *(short *)(lVar12 + 0x44);
      bVar2 = *(byte *)(lVar12 + 0x15);
      cVar5 = *(char *)(lVar12 + 0x12);
      bVar3 = *(byte *)(lVar12 + 0x16);
      *(int *)((long)&uStack_10 + (long)(int)(uint)*(byte *)(lVar12 + 0x14) * 4) =
           (int)*(char *)(lVar12 + 0x10) * (int)*(short *)(lVar12 + 0x40);
      *(int *)((long)&uStack_10 + (long)(int)(uint)bVar2 * 4) = (int)cVar4 * (int)sVar6;
      uVar1 = *(uint *)(lVar12 + 0x20);
      *(int *)((long)&uStack_10 + (long)(int)(uint)bVar3 * 4) = (int)cVar5 * (int)sVar7;
      iVar10 = iStack_8;
      iVar11 = (int)uStack_10;
      iVar9 = uStack_10._4_4_;
      if (((uVar1 >> 4 & 1) != 0) && ((uRamffffffc0010b656a >> 2 & 1) != 0)) {
        __dynamic_pr_debug(0xffffffc0010b6548,0xffffffc000d9eeb8,&__func___26267,
                           uStack_10 & 0xffffffff,uStack_10._4_4_,iStack_8);
      }
      iVar8 = 0;
      if (uRamffffffc0011860a8 != 0) {
        iVar8 = (iVar11 * 0x264f) / (int)(uint)uRamffffffc0011860a8;
      }
      iVar11 = 0;
      if (uRamffffffc0011860aa != 0) {
        iVar11 = (iVar9 * 0x264f) / (int)(uint)uRamffffffc0011860aa;
      }
      iVar9 = 0;
      if (uRamffffffc0011860ac != 0) {
        iVar9 = (iVar10 * 0x264f) / (int)(uint)uRamffffffc0011860ac;
      }
      if (((*(uint *)(lVar12 + 0x20) >> 4 & 1) != 0) && ((uRamffffffc0010b6592 >> 2 & 1) != 0)) {
        __dynamic_pr_debug(0xffffffc0010b6570,0xffffffc000d9eef0,&__func___26267,iVar8,iVar11,iVar9)
        ;
      }
      sprintf(param_2,0xffffffc000d9ef28,iVar8,iVar11,iVar9);
      uVar13 = 0;
    }
    else {
      uVar13 = 0xffffffff;
      printk(0xffffffc000d9ee58);
    }
  }
  return uVar13;
}



// ============================================================================
// Function: mc3xxx_get_data at 0xffffffc000448e40
// ============================================================================

undefined8 mc3xxx_get_data(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined2 auStack_108 [4];
  undefined1 auStack_100 [256];
  
  auStack_108[0] = 0;
  MC3XXX_ReadSensorData_isra_7(*puRamffffffc001186088,auStack_100);
  sscanf(auStack_100,0xffffffc000d9d340,param_1,param_2,param_3);
  *param_4 = 2;
  iVar2 = *param_1;
  if (iRamffffffc001186138 == iVar2) {
    iVar1 = *param_2;
    if (iRamffffffc00118613c == iVar1) {
      if (iRamffffffc001186140 != *param_3) {
        iRamffffffc001186138 = iVar2;
        iRamffffffc001186140 = *param_3;
        iRamffffffc001186144 = 0;
        return 0;
      }
      if (3 < iRamffffffc001186144) {
        if ((uRamffffffc0010b65ba >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010b6598,0xffffffc000d9ef38);
        }
        iRamffffffc001186144 = 0;
        MC3XXX_Init_isra_6(uRamffffffc001186080);
        auStack_108[0] = CONCAT11(auStack_108[0]._1_1_,0x41);
        iVar2 = MC3XXX_i2c_write_block(uRamffffffc001186080,7,auStack_108,1);
        if (iVar2 != 0) {
          printk(0xffffffc000d9e6f8);
          return 0;
        }
        return 0;
      }
      iRamffffffc001186144 = iRamffffffc001186144 + 1;
      return 0;
    }
  }
  else {
    iVar1 = *param_2;
  }
  iRamffffffc001186144 = 0;
  iRamffffffc001186140 = *param_3;
  iRamffffffc00118613c = iVar1;
  iRamffffffc001186138 = iVar2;
  return 0;
}



// ============================================================================
// Function: mc3xxx_cali_work at 0xffffffc000448f8c
// ============================================================================

void mc3xxx_cali_work(long param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_10;
  undefined4 uStack_a;
  undefined4 uStack_4;
  
  plVar1 = (long *)(param_1 + -0x128);
  uStack_20 = 0;
  uStack_18 = 0;
  if (plVar1 == (long *)0x0) {
    printk(0xffffffc000d9ef68);
  }
  else if (*plVar1 == 0) {
    printk(0xffffffc000d9efc0);
  }
  else {
    iVar2 = emmc_read(0xffffffc000d11e28,0x300254,0x10,&uStack_10);
    if (-1 < iVar2) {
      uStack_18 = uStack_4;
      printk(0xffffffc000d9ef90,uStack_10,uStack_a,uStack_4);
      MC3XXX_ResetCalibration(*plVar1);
      MC3XXX_WriteCalibration(*plVar1,&uStack_20);
      return;
    }
    printk(0xffffffc000d9efe8);
  }
  return;
}



// ============================================================================
// Function: MC3XXX_show_acc_calibration at 0xffffffc000449058
// ============================================================================

long MC3XXX_show_acc_calibration(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_28;
  short sStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_10;
  undefined2 uStack_c;
  uint uStack_a;
  undefined2 uStack_6;
  uint uStack_4;
  
  uVar2 = uRamffffffc0011860e0;
  uVar1 = uRamffffffc001186080;
  uStack_28 = 0;
  iVar6 = 0;
  iVar5 = 0x32;
  sStack_24 = 0;
  iVar7 = 0;
  iVar3 = 0;
  MC3XXX_SetPowerMode(uRamffffffc001186080,1);
  printk(0xffffffc000d9e9f8);
  MC3XXX_ResetCalibration(uVar1);
  do {
    lVar4 = 0x33;
    MC3XXX_ReadData(uVar1,&uStack_28);
    iVar3 = iVar3 + (short)uStack_28;
    iVar7 = iVar7 + uStack_28._2_2_;
    iVar6 = iVar6 + sStack_24;
    do {
      __const_udelay(0x418958);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar6 = iVar6 / 0x32;
  uStack_20 = -(iVar3 / 0x32);
  uStack_1c = -(iVar7 / 0x32);
  if (iVar6 < 0) {
    uStack_18 = iVar6 + 0x400;
  }
  else {
    uStack_18 = -iVar6 - 0x400;
  }
  if ((((int)((uStack_20 ^ (int)uStack_20 >> 0x1f) - ((int)uStack_20 >> 0x1f)) < 0x12d) &&
      ((int)((uStack_1c ^ (int)uStack_1c >> 0x1f) - ((int)uStack_1c >> 0x1f)) < 0x12d)) &&
     ((int)((uStack_18 ^ (int)uStack_18 >> 0x1f) - ((int)uStack_18 >> 0x1f)) < 0x12d)) {
    uStack_c = 0;
    uStack_6 = 0;
    uStack_10 = uStack_20;
    uStack_4 = uStack_18;
    uStack_a = uStack_1c;
    emmc_write(0xffffffc000d11e28,0x300254,0x10,&uStack_10);
    MC3XXX_WriteCalibration(uVar1,&uStack_20);
    printk(0xffffffc000d9ea28,uStack_20,uStack_1c,uStack_18);
    MC3XXX_SetPowerMode(uVar1,uVar2);
    iVar3 = sprintf(param_3,0xffffffc000e8cd68,0);
    return (long)iVar3;
  }
  printk(0xffffffc000d9f018,uStack_20,uStack_1c,uStack_18);
  iVar3 = sprintf(param_3,0xffffffc000e8cd68,0xffffffff);
  return (long)iVar3;
}



// ============================================================================
// Function: mc3xxx_ioctl at 0xffffffc000449280
// ============================================================================

/* WARNING: Type propagation algorithm not settling */

long mc3xxx_ioctl(long param_1,uint param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  undefined4 uStack_128;
  short sStack_124;
  undefined8 uStack_120;
  int iStack_118;
  undefined8 uStack_110;
  int iStack_108;
  ulong uStack_100;
  undefined4 uStack_f8;
  
  lVar6 = *(long *)(param_1 + 0xd0);
  lVar7 = *(long *)(lVar6 + 0xc0);
  memset(&uStack_100,0,0x100);
  uStack_120 = 0;
  iStack_118 = 0;
  uStack_110 = 0;
  iStack_108 = 0;
  if ((((int)param_2 < 0) || ((param_2 >> 0x1e & 1) != 0)) &&
     (uVar3 = (ulong)(param_2 >> 0x10 & 0x3fff),
     CARRY8(param_3,uVar3) ||
     *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8) < param_3 + uVar3)) {
    printk(0xffffffc000d9f068,param_2,param_2 >> 0x1e,param_2 >> 0x10 & 0x3fff);
    return -0xe;
  }
  if (param_2 == 0x80048502) {
    if ((uRamffffffc0010b660a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b65e8,0xffffffc000d9f0c8);
    }
    if (param_3 == 0) {
      return -0x16;
    }
    if (lVar6 == 0) {
      uStack_100 = uStack_100 & 0xffffffffffffff00;
    }
    else {
      uStack_100 = uRamffffffc000d9f108;
      uStack_f8 = uRamffffffc000d9f110;
    }
  }
  else {
    if (param_2 < 0x80048503) {
      if (param_2 == 0x8508) {
        if ((uRamffffffc0010b66d2 >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010b66b0,0xffffffc000d9f260);
        }
        down_interruptible(0xffffffc0011860e8);
        iVar1 = MC3XXX_ResetCalibration(lVar6);
        up(0xffffffc0011860e8);
        return (long)iVar1;
      }
      if (param_2 < 0x8509) {
        if (param_2 == 0x8501) {
          if ((uRamffffffc0010b65e2 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b65c0,0xffffffc000d9f098);
          }
          down_interruptible(0xffffffc0011860e8);
          MC3XXX_Init_isra_6(lVar6);
          up(0xffffffc0011860e8);
          return 0;
        }
      }
      else {
        if (param_2 == 0x400c8506) {
          if ((uRamffffffc0010b66aa >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b6688,0xffffffc000d9f1f0);
          }
          if (param_3 == 0) {
            return -0x16;
          }
          if (0xfffffffffffffff3 < param_3 ||
              *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8) < param_3 + 0xc
             ) {
            return -0xe;
          }
          lVar2 = __copy_from_user(&uStack_120,param_3,0xc);
          if (lVar2 != 0) {
            return -0xe;
          }
          if (*(int *)(lVar7 + 0x24) != 0) {
            printk(0xffffffc000d9f228);
            return -0x16;
          }
          uVar5 = (uint)uRamffffffc0011860a8;
          uVar4 = (uint)uRamffffffc0011860aa;
          iStack_108 = (int)(iStack_118 * (uint)uRamffffffc0011860ac) / 0x264f;
          *(short *)(lVar7 + 0x30) = (short)uStack_120 + *(short *)(lVar7 + 0x30);
          *(short *)(lVar7 + 0x32) = (short)((ulong)uStack_120 >> 0x20) + *(short *)(lVar7 + 0x32);
          *(short *)(lVar7 + 0x34) = (short)iStack_118 + *(short *)(lVar7 + 0x34);
          uStack_110 = CONCAT44((int)(uStack_120._4_4_ * uVar4) / 0x264f,
                                (int)((int)uStack_120 * uVar5) / 0x264f);
          down_interruptible(0xffffffc0011860e8);
          iVar1 = MC3XXX_WriteCalibration(lVar6,&uStack_110);
          up(0xffffffc0011860e8);
          return (long)iVar1;
        }
        if (param_2 == 0x400c8507) {
          if ((uRamffffffc0010b66fa >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b66d8,0xffffffc000d9f298);
          }
          if (param_3 == 0) {
            return -0x16;
          }
          iStack_118 = (int)*(short *)(lVar7 + 0x34);
          uStack_120 = CONCAT44((int)*(short *)(lVar7 + 0x32),(int)*(short *)(lVar7 + 0x30));
          if (0xfffffffffffffff3 < param_3 ||
              *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8) < param_3 + 0xc
             ) {
            return -0xe;
          }
          uVar3 = __copy_to_user(param_3,&uStack_120,0xc);
          goto joined_r0xffffffc0004494bc;
        }
      }
code_r0xffffffc000449818:
      printk(0xffffffc000d9d9f8,param_2);
      return -0x203;
    }
    if (param_2 == 0x80048506) {
      if ((uRamffffffc0010b6682 >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010b6660,0xffffffc000d9f188);
      }
      if (param_3 == 0) {
        return -0x16;
      }
      down_interruptible(0xffffffc0011860e8);
      if (lVar6 != 0) {
        if ((cRamffffffc0011860e0 == '\0') && (iVar1 = MC3XXX_SetPowerMode(lVar6,1), iVar1 != 0)) {
          printk(0xffffffc000d9f1c8,iVar1);
        }
        uStack_128 = 0;
        sStack_124 = 0;
        iVar1 = MC3XXX_ReadData(lVar6,&uStack_128);
        if (iVar1 == 0) {
          sprintf(&uStack_100,0xffffffc000d9ef28,(long)(short)uStack_128,(long)uStack_128._2_2_,
                  (long)sStack_124);
        }
        else {
          printk(0xffffffc000d9e7b0,iVar1);
        }
      }
      up(0xffffffc0011860e8);
    }
    else {
      if (0x80048506 < param_2) {
        if (param_2 == 0x80068504) {
          if ((uRamffffffc0010b665a >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b6638,0xffffffc000d9f150);
          }
          if (param_3 == 0) {
            return -0x16;
          }
          if (0xfffffffffffffff9 < param_3 ||
              *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8) < param_3 + 6)
          {
            return -0xe;
          }
          uVar3 = __copy_to_user(param_3,0xffffffc001186148,6);
        }
        else {
          if (param_2 != 0x80068505) goto code_r0xffffffc000449818;
          if ((uRamffffffc0010b6632 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010b6610,0xffffffc000d9f118);
          }
          if (param_3 == 0) {
            return -0x16;
          }
          if (0xfffffffffffffff9 < param_3 ||
              *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8) < param_3 + 6)
          {
            return -0xe;
          }
          uVar3 = __copy_to_user(param_3,0xffffffc0011860a8,6);
        }
        goto joined_r0xffffffc0004494bc;
      }
      if (param_2 != 0x80048503) goto code_r0xffffffc000449818;
      if (param_3 == 0) {
        return -0x16;
      }
      down_interruptible(0xffffffc0011860e8);
      MC3XXX_ReadSensorData_isra_7(lVar6,&uStack_100);
      up(0xffffffc0011860e8);
    }
  }
  lVar6 = strlen(&uStack_100);
  uVar3 = lVar6 + 1;
  if (!CARRY8(param_3,uVar3) &&
      param_3 + uVar3 <= *(ulong *)(((ulong)&stack0xfffffffffffffea0 & 0xffffffffffffc000) + 8)) {
    uVar3 = __copy_to_user(param_3,&uStack_100);
  }
joined_r0xffffffc0004494bc:
  if (uVar3 != 0) {
    return -0xe;
  }
  return 0;
}



// ============================================================================
// Function: MC3XXX_Read_Reg_Map at 0xffffffc0004498fc
// ============================================================================

undefined8 MC3XXX_Read_Reg_Map(long param_1,long param_2)

{
  undefined1 *puVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  code *pcVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  undefined8 uStack_40;
  undefined5 uStack_38;
  short sStack_33;
  undefined1 uStack_31;
  undefined1 uStack_30;
  short sStack_2f;
  undefined5 uStack_2d;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined8 uStack_8;
  
  uStack_40 = 0;
  uStack_38 = 0;
  sStack_33 = 0;
  uStack_31 = 0;
  uStack_30 = 0;
  sStack_2f = 0;
  uStack_2d = 0;
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_10 = 0;
  uStack_8 = 0;
  if ((uRamffffffc0010b6722 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6700,0xffffffc000d9dd50,&__func___26074);
  }
  if (param_1 == 0) {
    return 0xffffffea;
  }
  uVar12 = 0;
  do {
    while( true ) {
      uVar14 = uVar12 & 0xffffffff;
      MC3XXX_i2c_read_block(param_1,uVar12 & 0xffffffff,(long)&uStack_40 + uVar12,1);
      if (param_2 != 0) {
        *(undefined1 *)(param_2 + uVar12) = *(undefined1 *)((long)&uStack_40 + uVar12);
      }
      if ((uRamffffffc0010b674a >> 2 & 1) == 0) break;
      puVar1 = (undefined1 *)((long)&uStack_40 + uVar12);
      uVar12 = uVar12 + 1;
      __dynamic_pr_debug(0xffffffc0010b6728,0xffffffc000d9f2d8,uVar14,*puVar1);
      if (uVar12 == 0x40) goto code_r0xffffffc0004499bc;
    }
    uVar12 = uVar12 + 1;
  } while (uVar12 != 0x40);
code_r0xffffffc0004499bc:
  uVar7 = uRamffffffc0010b6772;
  uRamffffffc001186150 = *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8)
  ;
  *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8) = 0xffffffffffffffff;
  if ((uVar7 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b6750,0xffffffc000d9f310);
  }
  uVar12 = filp_open(0xffffffc000d9f338,0x42,0);
  if ((0xfffffffffffff000 < uVar12) || (*(long *)(uVar12 + 0x28) == 0)) {
    if ((uRamffffffc0010b679a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b6778,0xffffffc000d9f358);
    }
    uRamffffffc001186158 = 0;
code_r0xffffffc000449c38:
    if ((uRamffffffc0010b67c2 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010b67a0,0xffffffc000d9f398);
    }
    return 0;
  }
  uRamffffffc001186158 = uVar12;
  if (uVar12 == 0) goto code_r0xffffffc000449c38;
  sVar6 = CONCAT11(uStack_30,uStack_31);
  iVar9 = (int)sStack_33;
  iVar5 = (int)sStack_2f;
  sVar2 = 0;
  if (iRamffffffc001186114 != 0) {
    sVar2 = (short)((int)(((int)sVar6 + iRamffffffc001186104 / 2) * (uint)uRamffffffc0011860aa) /
                   iRamffffffc001186114);
  }
  sVar3 = 0;
  if (iRamffffffc001186110 != 0) {
    sVar3 = (short)((int)((iVar9 + iRamffffffc001186100 / 2) * (uint)uRamffffffc0011860a8) /
                   iRamffffffc001186110);
  }
  sVar4 = 0;
  if (iRamffffffc001186118 != 0) {
    sVar4 = (short)((int)((iVar5 + iRamffffffc001186108 / 2) * (uint)uRamffffffc0011860ac) /
                   iRamffffffc001186118);
  }
  lVar10 = kmem_cache_alloc_trace(uRamffffffc00115bd48,0x80d0,0xce4);
  if (lVar10 == 0) {
    printk(0xffffffc000d9f3d8);
    return 0;
  }
  uVar12 = 0;
  memset(lVar10,0,0xce4);
  iVar8 = sprintf(lVar10,0xffffffc000d9f408,(int)sVar3,(int)sVar2,(int)sVar4);
  iVar9 = sprintf(lVar10 + iVar8,0xffffffc000d9f430,iVar9,(int)sVar6,iVar5);
  iVar8 = iVar8 + iVar9;
  do {
    puVar1 = (undefined1 *)((long)&uStack_40 + uVar12);
    uVar14 = uVar12 & 0xffffffff;
    uVar12 = uVar12 + 1;
    iVar9 = sprintf(lVar10 + iVar8,0xffffffc000d9f458,uVar14,*puVar1);
    iVar8 = iVar8 + iVar9;
  } while (uVar12 != 0x3f);
  lVar13 = 0x32;
  do {
    __const_udelay(0x418958);
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  if ((*(long *)(uRamffffffc001186158 + 0x28) == 0) ||
     (pcVar11 = *(code **)(*(long *)(uRamffffffc001186158 + 0x28) + 0x18), pcVar11 == (code *)0x0))
  {
    iVar9 = -1;
  }
  else {
    iVar9 = (*pcVar11)(uRamffffffc001186158,lVar10,(long)iVar8,uRamffffffc001186158 + 0x70);
    if (0 < iVar9) {
      if ((uRamffffffc0010b67ea >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010b67c8,0xffffffc000d9f480,lVar10);
      }
      goto code_r0xffffffc000449bb0;
    }
  }
  if ((uRamffffffc0010b6812 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010b67f0,0xffffffc000d9f4a0,iVar9);
  }
code_r0xffffffc000449bb0:
  kfree(lVar10);
  uVar12 = uRamffffffc001186158;
  *(undefined8 *)(((ulong)&stack0xffffffffffffff50 & 0xffffffffffffc000) + 8) = uRamffffffc001186150
  ;
  filp_close(uVar12,0);
  return 0;
}



// [-] Could not find function mc3xxx_attr_list at 0xffffffc000b6d158

// [-] Could not find function mc3xxx_i2c_auto_probe_addr at 0xffffffc000b6d228

// [-] Could not find function mc3xxx_fops at 0xffffffc000b6d4d0

// [-] Could not find function mc3xxx_i2c_id at 0xffffffc000b6d5b8

// ============================================================================
// Function: mc3xxx_init at 0xffffffc000f5c130
// ============================================================================

undefined8 mc3xxx_init(void)

{
  lRamffffffc00100c990 = get_accel_dts_func(0xffffffc000d9da20,lRamffffffc00100c990);
  if (lRamffffffc00100c990 == 0) {
    printk(0xffffffc000d9da30);
  }
  acc_driver_add(0xffffffc00100c998);
  return 0;
}



