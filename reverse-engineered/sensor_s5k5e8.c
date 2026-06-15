/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: S5K5E8_ST_MIPI_RAW_SensorInit at 0xffffffc0005c38c8
// ============================================================================

undefined8 S5K5E8_ST_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc0010302a0;
  }
  return 0;
}



// ============================================================================
// Function: s5k5e8otp_Ioctl_Compat at 0xffffffc0005c39ac
// ============================================================================

long s5k5e8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  undefined4 *puVar21;
  
  if ((uRamffffffc0010d4fe2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d4fc0,0xffffffc000e158d8,&__func___30614);
  }
  if ((uRamffffffc0010d500a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d4fe8,0xffffffc000e15928,&__func___30614,
                       *(long *)(param_1 + 0x28),*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x50),
                       param_2,param_2 >> 0x10 & 0x3fff);
  }
  if ((*(long *)(param_1 + 0x28) == 0) || (*(long *)(*(long *)(param_1 + 0x28) + 0x50) == 0)) {
    lVar20 = -0x19;
  }
  else if (param_2 == 0xc00c6905) {
    puVar21 = (undefined4 *)(param_3 & 0xffffffff);
    puVar5 = (undefined4 *)compat_alloc_user_space(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      lVar20 = -0xe;
    }
    else {
      puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
      uVar8 = 0xfffffff2;
      uVar4 = 0;
      if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
        uVar8 = 0;
        uVar4 = *puVar21;
      }
      uVar17 = 0xfffffff2;
      if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
        uVar17 = 0;
        *puVar5 = uVar4;
      }
      puVar1 = puVar21 + 1;
      uVar9 = 0xfffffff2;
      uVar4 = 0;
      if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
        uVar9 = 0;
        uVar4 = *puVar1;
      }
      puVar2 = puVar5 + 1;
      uVar18 = 0xfffffff2;
      if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
        uVar18 = 0;
        *puVar2 = uVar4;
      }
      puVar3 = puVar21 + 2;
      uVar10 = 0xfffffff2;
      uVar16 = 0;
      if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
        uVar10 = 0;
        uVar16 = (ulong)*puVar3;
      }
      uVar11 = 0xfffffff2;
      if (puVar5 + 2 < (ulong *)0xfffffffffffffff8 && puVar5 + 4 <= puVar7) {
        uVar11 = 0;
        *(ulong *)(puVar5 + 2) = uVar16;
      }
      uVar11 = uVar17 | uVar8 | uVar9 | uVar18 | uVar10 | uVar11;
      if (uVar11 == 0) {
        lVar20 = (**(code **)(*(long *)(param_1 + 0x28) + 0x50))(param_1,0xc0106905,puVar5);
        puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
        iVar12 = -0xe;
        uVar4 = 0;
        if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
          uVar4 = *puVar5;
          iVar12 = 0;
        }
        iVar19 = -0xe;
        if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
          iVar19 = 0;
          *puVar21 = uVar4;
        }
        if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
          iVar13 = 0;
          uVar4 = *puVar2;
        }
        else {
          iVar13 = -0xe;
          uVar4 = 0;
        }
        iVar14 = -0xe;
        if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
          iVar14 = 0;
          *puVar1 = uVar4;
        }
        iVar15 = -0xe;
        uVar8 = 0;
        if (puVar5 + 8 < (uint *)0xfffffffffffffffc && puVar5 + 9 <= puVar7) {
          iVar15 = 0;
          uVar8 = puVar5[8];
        }
        iVar6 = -0xe;
        if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
          iVar6 = 0;
          *puVar3 = uVar8;
        }
        if (((((iVar19 != 0 || iVar12 != 0) || iVar13 != 0) || iVar14 != 0) || iVar15 != 0) ||
            iVar6 != 0) {
          printk(0xffffffc000e15988,&__func___30614);
        }
      }
      else {
        lVar20 = (long)(int)uVar11;
      }
    }
  }
  else {
    lVar20 = -0x203;
  }
  return lVar20;
}



// ============================================================================
// Function: s5k5e8_st_otp_cali at 0xffffffc0005c4068
// ============================================================================

void s5k5e8_st_otp_cali(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  long lStack_118;
  long lStack_110;
  undefined8 uStack_108;
  byte bStack_100;
  byte bStack_ff;
  byte bStack_fe;
  byte bStack_fd;
  undefined2 uStack_fc;
  undefined2 uStack_fa;
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  do_gettimeofday(&lStack_118);
  bStack_100 = 0;
  bStack_ff = 0;
  bStack_fe = 0;
  bStack_fd = 0;
  uStack_108 = 0;
  uRamffffffc0011ded81 = 99;
  uRamffffffc0011ded80 = 1;
  uRamffffffc0011ded82 = 0x69;
  uRamffffffc0011ded84 = 99;
  uRamffffffc0011ded83 = 0x68;
  uStack_fc = 0;
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa02,4);
  write_cmos_sensor_8(0xa00,1);
  __const_udelay(0x418958);
  uVar2 = eeprom_gt24c64a_read8(0xa04);
  sVar3 = eeprom_gt24c64a_read8(0xa05);
  sVar4 = eeprom_gt24c64a_read8(0xa06);
  printk(0xffffffc000e15c88,uVar2,sVar3,sVar4);
  iVar5 = 0;
  if (sVar3 == 1) {
    iVar5 = 0x10;
  }
  if (sVar4 == 1) {
    iVar8 = 0xa27;
    iVar5 = 0x20;
  }
  else {
    iVar8 = iVar5 + 0xa07;
  }
  uVar7 = 0;
  printk(0xffffffc000e15cd0,iVar5);
  do {
    iVar5 = (int)uVar7;
    uVar1 = eeprom_gt24c64a_read8(iVar8 + iVar5);
    uVar6 = uVar7 & 0xffffffff;
    *(undefined1 *)((long)&uStack_108 + uVar7) = uVar1;
    *(undefined1 *)(uVar7 - 0x3ffee2127b) = uVar1;
    uVar7 = uVar7 + 1;
    printk(0xffffffc000e15cf0,uVar6,iVar5 + 5,uVar1);
  } while (uVar7 != 0xe);
  printk(0xffffffc000e15d28,(uint)bStack_100 + (uint)bStack_ff * 0x100,
         (uint)bStack_fe + (uint)bStack_fd * 0x100,
         (uint)uStack_108._4_1_ + (uint)uStack_108._5_1_ * 0x100,
         (uint)uStack_108._6_1_ + (uint)uStack_108._7_1_ * 0x100);
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa00,0);
  do_gettimeofday(&uStack_108);
  if (lStack_118 < uStack_108) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100)))));
  }
  else {
    lStack_110 = CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100))))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d50fa >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d50d8,0xffffffc000e15d58,&__func___30369,lStack_110);
  return;
}



// ============================================================================
// Function: S5K5E8_QH_MIPI_RAW_SensorInit at 0xffffffc0005ca590
// ============================================================================

undefined8 S5K5E8_QH_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc001030ad8;
  }
  return 0;
}



// ============================================================================
// Function: s5k5e8otp_Ioctl_Compat at 0xffffffc0005ca674
// ============================================================================

long s5k5e8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  undefined4 *puVar21;
  
  if ((uRamffffffc0010d5992 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d5970,0xffffffc000e171c0,&__func___30614);
  }
  if ((uRamffffffc0010d59ba >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d5998,0xffffffc000e17210,&__func___30614,
                       *(long *)(param_1 + 0x28),*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x50),
                       param_2,param_2 >> 0x10 & 0x3fff);
  }
  if ((*(long *)(param_1 + 0x28) == 0) || (*(long *)(*(long *)(param_1 + 0x28) + 0x50) == 0)) {
    lVar20 = -0x19;
  }
  else if (param_2 == 0xc00c6905) {
    puVar21 = (undefined4 *)(param_3 & 0xffffffff);
    puVar5 = (undefined4 *)compat_alloc_user_space(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      lVar20 = -0xe;
    }
    else {
      puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
      uVar8 = 0xfffffff2;
      uVar4 = 0;
      if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
        uVar8 = 0;
        uVar4 = *puVar21;
      }
      uVar17 = 0xfffffff2;
      if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
        uVar17 = 0;
        *puVar5 = uVar4;
      }
      puVar1 = puVar21 + 1;
      uVar9 = 0xfffffff2;
      uVar4 = 0;
      if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
        uVar9 = 0;
        uVar4 = *puVar1;
      }
      puVar2 = puVar5 + 1;
      uVar18 = 0xfffffff2;
      if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
        uVar18 = 0;
        *puVar2 = uVar4;
      }
      puVar3 = puVar21 + 2;
      uVar10 = 0xfffffff2;
      uVar16 = 0;
      if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
        uVar10 = 0;
        uVar16 = (ulong)*puVar3;
      }
      uVar11 = 0xfffffff2;
      if (puVar5 + 2 < (ulong *)0xfffffffffffffff8 && puVar5 + 4 <= puVar7) {
        uVar11 = 0;
        *(ulong *)(puVar5 + 2) = uVar16;
      }
      uVar11 = uVar17 | uVar8 | uVar9 | uVar18 | uVar10 | uVar11;
      if (uVar11 == 0) {
        lVar20 = (**(code **)(*(long *)(param_1 + 0x28) + 0x50))(param_1,0xc0106905,puVar5);
        puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
        iVar12 = -0xe;
        uVar4 = 0;
        if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
          uVar4 = *puVar5;
          iVar12 = 0;
        }
        iVar19 = -0xe;
        if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
          iVar19 = 0;
          *puVar21 = uVar4;
        }
        if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
          iVar13 = 0;
          uVar4 = *puVar2;
        }
        else {
          iVar13 = -0xe;
          uVar4 = 0;
        }
        iVar14 = -0xe;
        if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
          iVar14 = 0;
          *puVar1 = uVar4;
        }
        iVar15 = -0xe;
        uVar8 = 0;
        if (puVar5 + 8 < (uint *)0xfffffffffffffffc && puVar5 + 9 <= puVar7) {
          iVar15 = 0;
          uVar8 = puVar5[8];
        }
        iVar6 = -0xe;
        if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
          iVar6 = 0;
          *puVar3 = uVar8;
        }
        if (((((iVar19 != 0 || iVar12 != 0) || iVar13 != 0) || iVar14 != 0) || iVar15 != 0) ||
            iVar6 != 0) {
          printk(0xffffffc000e17270,&__func___30614);
        }
      }
      else {
        lVar20 = (long)(int)uVar11;
      }
    }
  }
  else {
    lVar20 = -0x203;
  }
  return lVar20;
}



// ============================================================================
// Function: s5k5e8_qh_otp_cali at 0xffffffc0005cad30
// ============================================================================

void s5k5e8_qh_otp_cali(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  long lStack_118;
  long lStack_110;
  undefined8 uStack_108;
  byte bStack_100;
  byte bStack_ff;
  byte bStack_fe;
  byte bStack_fd;
  undefined2 uStack_fc;
  undefined2 uStack_fa;
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  do_gettimeofday(&lStack_118);
  bStack_100 = 0;
  bStack_ff = 0;
  bStack_fe = 0;
  bStack_fd = 0;
  uStack_108 = 0;
  uRamffffffc0011dff09 = 99;
  uRamffffffc0011dff08 = 1;
  uRamffffffc0011dff0a = 0x69;
  uRamffffffc0011dff0c = 99;
  uRamffffffc0011dff0b = 0x68;
  uStack_fc = 0;
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa02,4);
  write_cmos_sensor_8(0xa00,1);
  __const_udelay(0x418958);
  uVar2 = eeprom_gt24c64a_read8(0xa04);
  sVar3 = eeprom_gt24c64a_read8(0xa05);
  sVar4 = eeprom_gt24c64a_read8(0xa06);
  printk(0xffffffc000e15c88,uVar2,sVar3,sVar4);
  iVar5 = 0;
  if (sVar3 == 1) {
    iVar5 = 0x10;
  }
  if (sVar4 == 1) {
    iVar8 = 0xa27;
    iVar5 = 0x20;
  }
  else {
    iVar8 = iVar5 + 0xa07;
  }
  uVar7 = 0;
  printk(0xffffffc000e15cd0,iVar5);
  do {
    iVar5 = (int)uVar7;
    uVar1 = eeprom_gt24c64a_read8(iVar8 + iVar5);
    uVar6 = uVar7 & 0xffffffff;
    *(undefined1 *)((long)&uStack_108 + uVar7) = uVar1;
    *(undefined1 *)(uVar7 - 0x3ffee200f3) = uVar1;
    uVar7 = uVar7 + 1;
    printk(0xffffffc000e17570,uVar6,iVar5 + 5,uVar1);
  } while (uVar7 != 0xe);
  printk(0xffffffc000e15d28,(uint)bStack_100 + (uint)bStack_ff * 0x100,
         (uint)bStack_fe + (uint)bStack_fd * 0x100,
         (uint)uStack_108._4_1_ + (uint)uStack_108._5_1_ * 0x100,
         (uint)uStack_108._6_1_ + (uint)uStack_108._7_1_ * 0x100);
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa00,0);
  do_gettimeofday(&uStack_108);
  if (lStack_118 < uStack_108) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100)))));
  }
  else {
    lStack_110 = CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100))))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d5aaa >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d5a88,0xffffffc000e175a8,&__func___30369,lStack_110);
  return;
}



// ============================================================================
// Function: S5K5E8_HOLITECH_MIPI_RAW_SensorInit at 0xffffffc0005d11f0
// ============================================================================

undefined8 S5K5E8_HOLITECH_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc001031310;
  }
  return 0;
}



// ============================================================================
// Function: s5k5e8otp_Ioctl_Compat at 0xffffffc0005d12d4
// ============================================================================

long s5k5e8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  undefined4 *puVar21;
  
  if ((uRamffffffc0010d6342 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6320,0xffffffc000e18eb0,&__func___30614);
  }
  if ((uRamffffffc0010d636a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6348,0xffffffc000e18f08,&__func___30614,
                       *(long *)(param_1 + 0x28),*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x50),
                       param_2,param_2 >> 0x10 & 0x3fff);
  }
  if ((*(long *)(param_1 + 0x28) == 0) || (*(long *)(*(long *)(param_1 + 0x28) + 0x50) == 0)) {
    lVar20 = -0x19;
  }
  else if (param_2 == 0xc00c6905) {
    puVar21 = (undefined4 *)(param_3 & 0xffffffff);
    puVar5 = (undefined4 *)compat_alloc_user_space(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      lVar20 = -0xe;
    }
    else {
      puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
      uVar8 = 0xfffffff2;
      uVar4 = 0;
      if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
        uVar8 = 0;
        uVar4 = *puVar21;
      }
      uVar17 = 0xfffffff2;
      if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
        uVar17 = 0;
        *puVar5 = uVar4;
      }
      puVar1 = puVar21 + 1;
      uVar9 = 0xfffffff2;
      uVar4 = 0;
      if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
        uVar9 = 0;
        uVar4 = *puVar1;
      }
      puVar2 = puVar5 + 1;
      uVar18 = 0xfffffff2;
      if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
        uVar18 = 0;
        *puVar2 = uVar4;
      }
      puVar3 = puVar21 + 2;
      uVar10 = 0xfffffff2;
      uVar16 = 0;
      if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
        uVar10 = 0;
        uVar16 = (ulong)*puVar3;
      }
      uVar11 = 0xfffffff2;
      if (puVar5 + 2 < (ulong *)0xfffffffffffffff8 && puVar5 + 4 <= puVar7) {
        uVar11 = 0;
        *(ulong *)(puVar5 + 2) = uVar16;
      }
      uVar11 = uVar17 | uVar8 | uVar9 | uVar18 | uVar10 | uVar11;
      if (uVar11 == 0) {
        lVar20 = (**(code **)(*(long *)(param_1 + 0x28) + 0x50))(param_1,0xc0106905,puVar5);
        puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
        iVar12 = -0xe;
        uVar4 = 0;
        if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
          uVar4 = *puVar5;
          iVar12 = 0;
        }
        iVar19 = -0xe;
        if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
          iVar19 = 0;
          *puVar21 = uVar4;
        }
        if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
          iVar13 = 0;
          uVar4 = *puVar2;
        }
        else {
          iVar13 = -0xe;
          uVar4 = 0;
        }
        iVar14 = -0xe;
        if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
          iVar14 = 0;
          *puVar1 = uVar4;
        }
        iVar15 = -0xe;
        uVar8 = 0;
        if (puVar5 + 8 < (uint *)0xfffffffffffffffc && puVar5 + 9 <= puVar7) {
          iVar15 = 0;
          uVar8 = puVar5[8];
        }
        iVar6 = -0xe;
        if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
          iVar6 = 0;
          *puVar3 = uVar8;
        }
        if (((((iVar19 != 0 || iVar12 != 0) || iVar13 != 0) || iVar14 != 0) || iVar15 != 0) ||
            iVar6 != 0) {
          printk(0xffffffc000e18f78,&__func___30614);
        }
      }
      else {
        lVar20 = (long)(int)uVar11;
      }
    }
  }
  else {
    lVar20 = -0x203;
  }
  return lVar20;
}



// ============================================================================
// Function: s5k5e8_holitech_otp_cali at 0xffffffc0005d1990
// ============================================================================

void s5k5e8_holitech_otp_cali(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  long lStack_118;
  long lStack_110;
  undefined8 uStack_108;
  byte bStack_100;
  byte bStack_ff;
  byte bStack_fe;
  byte bStack_fd;
  undefined2 uStack_fc;
  undefined2 uStack_fa;
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  do_gettimeofday(&lStack_118);
  bStack_100 = 0;
  bStack_ff = 0;
  bStack_fe = 0;
  bStack_fd = 0;
  uStack_108 = 0;
  uRamffffffc0011e1089 = 99;
  uRamffffffc0011e1088 = 1;
  uRamffffffc0011e108a = 0x69;
  uRamffffffc0011e108c = 99;
  uRamffffffc0011e108b = 0x68;
  uStack_fc = 0;
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa02,4);
  write_cmos_sensor_8(0xa00,1);
  __const_udelay(0x418958);
  uVar2 = eeprom_gt24c64a_read8(0xa04);
  sVar3 = eeprom_gt24c64a_read8(0xa05);
  sVar4 = eeprom_gt24c64a_read8(0xa06);
  printk(0xffffffc000e15c88,uVar2,sVar3,sVar4);
  iVar5 = 0;
  if (sVar3 == 1) {
    iVar5 = 0x10;
  }
  if (sVar4 == 1) {
    iVar8 = 0xa27;
    iVar5 = 0x20;
  }
  else {
    iVar8 = iVar5 + 0xa07;
  }
  uVar7 = 0;
  printk(0xffffffc000e15cd0,iVar5);
  do {
    iVar5 = (int)uVar7;
    uVar1 = eeprom_gt24c64a_read8(iVar8 + iVar5);
    uVar6 = uVar7 & 0xffffffff;
    *(undefined1 *)((long)&uStack_108 + uVar7) = uVar1;
    *(undefined1 *)(uVar7 - 0x3ffee1ef73) = uVar1;
    uVar7 = uVar7 + 1;
    printk(0xffffffc000e192d8,uVar6,iVar5 + 5,uVar1);
  } while (uVar7 != 0xe);
  printk(0xffffffc000e15d28,(uint)bStack_100 + (uint)bStack_ff * 0x100,
         (uint)bStack_fe + (uint)bStack_fd * 0x100,
         (uint)uStack_108._4_1_ + (uint)uStack_108._5_1_ * 0x100,
         (uint)uStack_108._6_1_ + (uint)uStack_108._7_1_ * 0x100);
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa00,0);
  do_gettimeofday(&uStack_108);
  if (lStack_118 < uStack_108) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100)))));
  }
  else {
    lStack_110 = CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100))))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d645a >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d6438,0xffffffc000e19310,&__func___30369,lStack_110);
  return;
}



// ============================================================================
// Function: S5K5E8_SUNWIN_MIPI_RAW_SensorInit at 0xffffffc0005d7e50
// ============================================================================

undefined8 S5K5E8_SUNWIN_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc001031b48;
  }
  return 0;
}



// ============================================================================
// Function: s5k5e8otp_Ioctl_Compat at 0xffffffc0005d7f34
// ============================================================================

long s5k5e8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  undefined4 *puVar21;
  
  if ((uRamffffffc0010d6cf2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6cd0,0xffffffc000e1ab78,&__func___30614);
  }
  if ((uRamffffffc0010d6d1a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6cf8,0xffffffc000e1abd0,&__func___30614,
                       *(long *)(param_1 + 0x28),*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x50),
                       param_2,param_2 >> 0x10 & 0x3fff);
  }
  if ((*(long *)(param_1 + 0x28) == 0) || (*(long *)(*(long *)(param_1 + 0x28) + 0x50) == 0)) {
    lVar20 = -0x19;
  }
  else if (param_2 == 0xc00c6905) {
    puVar21 = (undefined4 *)(param_3 & 0xffffffff);
    puVar5 = (undefined4 *)compat_alloc_user_space(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      lVar20 = -0xe;
    }
    else {
      puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
      uVar8 = 0xfffffff2;
      uVar4 = 0;
      if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
        uVar8 = 0;
        uVar4 = *puVar21;
      }
      uVar17 = 0xfffffff2;
      if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
        uVar17 = 0;
        *puVar5 = uVar4;
      }
      puVar1 = puVar21 + 1;
      uVar9 = 0xfffffff2;
      uVar4 = 0;
      if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
        uVar9 = 0;
        uVar4 = *puVar1;
      }
      puVar2 = puVar5 + 1;
      uVar18 = 0xfffffff2;
      if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
        uVar18 = 0;
        *puVar2 = uVar4;
      }
      puVar3 = puVar21 + 2;
      uVar10 = 0xfffffff2;
      uVar16 = 0;
      if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
        uVar10 = 0;
        uVar16 = (ulong)*puVar3;
      }
      uVar11 = 0xfffffff2;
      if (puVar5 + 2 < (ulong *)0xfffffffffffffff8 && puVar5 + 4 <= puVar7) {
        uVar11 = 0;
        *(ulong *)(puVar5 + 2) = uVar16;
      }
      uVar11 = uVar17 | uVar8 | uVar9 | uVar18 | uVar10 | uVar11;
      if (uVar11 == 0) {
        lVar20 = (**(code **)(*(long *)(param_1 + 0x28) + 0x50))(param_1,0xc0106905,puVar5);
        puVar7 = *(undefined4 **)(((ulong)&stack0xffffffffffffffb0 & 0xffffffffffffc000) + 8);
        iVar12 = -0xe;
        uVar4 = 0;
        if (puVar5 < (undefined4 *)0xfffffffffffffffc && puVar5 + 1 <= puVar7) {
          uVar4 = *puVar5;
          iVar12 = 0;
        }
        iVar19 = -0xe;
        if (puVar21 < (undefined4 *)0xfffffffffffffffc && puVar21 + 1 <= puVar7) {
          iVar19 = 0;
          *puVar21 = uVar4;
        }
        if (puVar2 < (undefined4 *)0xfffffffffffffffc && puVar5 + 2 <= puVar7) {
          iVar13 = 0;
          uVar4 = *puVar2;
        }
        else {
          iVar13 = -0xe;
          uVar4 = 0;
        }
        iVar14 = -0xe;
        if (puVar1 < (undefined4 *)0xfffffffffffffffc && puVar21 + 2 <= puVar7) {
          iVar14 = 0;
          *puVar1 = uVar4;
        }
        iVar15 = -0xe;
        uVar8 = 0;
        if (puVar5 + 8 < (uint *)0xfffffffffffffffc && puVar5 + 9 <= puVar7) {
          iVar15 = 0;
          uVar8 = puVar5[8];
        }
        iVar6 = -0xe;
        if (puVar3 < (uint *)0xfffffffffffffffc && puVar21 + 3 <= puVar7) {
          iVar6 = 0;
          *puVar3 = uVar8;
        }
        if (((((iVar19 != 0 || iVar12 != 0) || iVar13 != 0) || iVar14 != 0) || iVar15 != 0) ||
            iVar6 != 0) {
          printk(0xffffffc000e1ac38,&__func___30614);
        }
      }
      else {
        lVar20 = (long)(int)uVar11;
      }
    }
  }
  else {
    lVar20 = -0x203;
  }
  return lVar20;
}



// ============================================================================
// Function: s5k5e8_sunwin_otp_cali at 0xffffffc0005d85f0
// ============================================================================

void s5k5e8_sunwin_otp_cali(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  long lStack_118;
  long lStack_110;
  undefined8 uStack_108;
  byte bStack_100;
  byte bStack_ff;
  byte bStack_fe;
  byte bStack_fd;
  undefined2 uStack_fc;
  undefined2 uStack_fa;
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  do_gettimeofday(&lStack_118);
  bStack_100 = 0;
  bStack_ff = 0;
  bStack_fe = 0;
  bStack_fd = 0;
  uStack_108 = 0;
  uRamffffffc0011e2209 = 99;
  uRamffffffc0011e2208 = 1;
  uRamffffffc0011e220a = 0x69;
  uRamffffffc0011e220c = 99;
  uRamffffffc0011e220b = 0x68;
  uStack_fc = 0;
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa02,4);
  write_cmos_sensor_8(0xa00,1);
  __const_udelay(0x418958);
  uVar2 = eeprom_gt24c64a_read8(0xa04);
  sVar3 = eeprom_gt24c64a_read8(0xa05);
  sVar4 = eeprom_gt24c64a_read8(0xa06);
  printk(0xffffffc000e15c88,uVar2,sVar3,sVar4);
  iVar5 = 0;
  if (sVar3 == 0x40) {
    iVar5 = 0x10;
  }
  if (sVar4 == 0x40) {
    iVar8 = 0xa27;
    iVar5 = 0x20;
  }
  else {
    iVar8 = iVar5 + 0xa07;
  }
  uVar7 = 0;
  printk(0xffffffc000e15cd0,iVar5);
  do {
    iVar5 = (int)uVar7;
    uVar1 = eeprom_gt24c64a_read8(iVar8 + iVar5);
    uVar6 = uVar7 & 0xffffffff;
    *(undefined1 *)((long)&uStack_108 + uVar7) = uVar1;
    *(undefined1 *)(uVar7 - 0x3ffee1ddf3) = uVar1;
    uVar7 = uVar7 + 1;
    printk(0xffffffc000e1af88,uVar6,iVar5 + 5,uVar1);
  } while (uVar7 != 0xe);
  printk(0xffffffc000e15d28,(uint)bStack_100 + (uint)bStack_ff * 0x100,
         (uint)bStack_fe + (uint)bStack_fd * 0x100,
         (uint)uStack_108._4_1_ + (uint)uStack_108._5_1_ * 0x100,
         (uint)uStack_108._6_1_ + (uint)uStack_108._7_1_ * 0x100);
  write_cmos_sensor_8(0xa00,4);
  write_cmos_sensor_8(0xa00,0);
  do_gettimeofday(&uStack_108);
  if (lStack_118 < uStack_108) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100)))));
  }
  else {
    lStack_110 = CONCAT26(uStack_fa,
                          CONCAT24(uStack_fc,
                                   CONCAT13(bStack_fd,
                                            CONCAT12(bStack_fe,CONCAT11(bStack_ff,bStack_100))))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d6e0a >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d6de8,0xffffffc000e1afc0,&__func___30369,lStack_110);
  return;
}



