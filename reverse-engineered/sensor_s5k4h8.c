/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: S5K4H8_OFILM_MIPI_RAW_SensorInit at 0xffffffc0005c00dc
// ============================================================================

undefined8 S5K4H8_OFILM_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc00102fe80;
  }
  return 0;
}



// ============================================================================
// Function: S5k4h8otp_Ioctl_Compat at 0xffffffc0005c0188
// ============================================================================

long S5k4h8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

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
  
  if ((uRamffffffc0010d483a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d4818,0xffffffc000e14578,&__func___30633);
  }
  if ((uRamffffffc0010d4862 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d4840,0xffffffc000e145c8,&__func___30633,
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
          printk(0xffffffc000e14628,&__func___30633);
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
// Function: s5k4h8_ofilm_otp_cali at 0xffffffc0005c0844
// ============================================================================

void s5k4h8_ofilm_otp_cali(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  ushort uVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  long lStack_118;
  long lStack_110;
  ushort auStack_108 [8];
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  lVar19 = 0;
  do_gettimeofday(&lStack_118);
  uRamffffffc0011de4c1 = 99;
  uRamffffffc0011de4c0 = 1;
  uRamffffffc0011de4c2 = 0x69;
  uRamffffffc0011de4c4 = 99;
  uRamffffffc0011de4c3 = 0x68;
  bVar5 = eeprom_gt24c64a_read8(0x2c);
  bVar6 = eeprom_gt24c64a_read8(0x2d);
  bVar7 = eeprom_gt24c64a_read8(0x2e);
  bVar8 = eeprom_gt24c64a_read8(0x2f);
  uVar10 = eeprom_gt24c64a_read8(0x30);
  sVar11 = eeprom_gt24c64a_read8(0x31);
  uVar13 = eeprom_gt24c64a_read8(0x32);
  uVar14 = eeprom_gt24c64a_read8(0x33);
  uVar15 = eeprom_gt24c64a_read8(0x34);
  uVar16 = eeprom_gt24c64a_read8(0x35);
  uVar12 = eeprom_gt24c64a_read8(0x36);
  uVar17 = eeprom_gt24c64a_read8(0x37);
  uRamffffffc0011de4cd = (undefined1)(uVar13 & 0xffff);
  uRamffffffc0011de4ce = (undefined1)(uVar14 & 0xffff);
  uRamffffffc0011de4cf = (undefined1)(uVar15 & 0xffff);
  uRamffffffc0011de4d0 = (undefined1)(uVar16 & 0xffff);
  bRamffffffc0011de4c9 = bVar5;
  bRamffffffc0011de4ca = bVar6;
  bRamffffffc0011de4cb = bVar7;
  bRamffffffc0011de4cc = bVar8;
  printk(0xffffffc000e14938,(uint)bVar5 + (uint)bVar6 * 0x100,(uint)bVar7 + (uint)bVar8 * 0x100,
         sVar11 * 0x100 + (uVar10 & 0xff),(uVar13 & 0xffff) + (uVar14 & 0xffff) * 0x100,
         (uVar15 & 0xffff) + (uVar16 & 0xffff) * 0x100,(uVar17 & 0xffff) * 0x100 + (uint)uVar12);
  do {
    uVar10 = eeprom_gt24c64a_read8((int)lVar19 + 0x42);
    auStack_108[lVar19] = uVar10;
    uVar4 = auStack_108[5];
    uVar3 = auStack_108[4];
    uVar2 = auStack_108[3];
    uVar1 = auStack_108[2];
    uVar12 = auStack_108[1];
    uVar10 = auStack_108[0];
    lVar19 = lVar19 + 1;
  } while (lVar19 != 8);
  if ((uRamffffffc0010d4952 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d4930,0xffffffc000e14990,&__func___30380,
                       auStack_108[0] | auStack_108[1] << 8,auStack_108[4] | auStack_108[5] << 8,
                       auStack_108[5] | auStack_108[4] << 8,auStack_108[7] | auStack_108[6] << 8,
                       auStack_108[2] | auStack_108[3] << 8);
  }
  uRamffffffc0011de4d1 = (undefined1)uVar10;
  uRamffffffc0011de4d5 = 0x4c;
  uRamffffffc0011de4d2 = (undefined1)uVar12;
  uRamffffffc0011de4d3 = (undefined1)uVar3;
  uRamffffffc0011de4d4 = (undefined1)uVar4;
  uRamffffffc0011de4c5 = (undefined1)uVar1;
  uRamffffffc0011de4c6 = (undefined1)uVar2;
  uRamffffffc0011de4d6 = 7;
  puVar20 = (undefined1 *)0xffffffc0011de4d7;
  iVar18 = 0x51;
  do {
    uVar9 = eeprom_gt24c64a_read8(iVar18);
    puVar21 = puVar20 + 1;
    *puVar20 = uVar9;
    puVar20 = puVar21;
    iVar18 = iVar18 + 1;
  } while (puVar21 != (undefined1 *)0xffffffc0011dec23);
  do_gettimeofday(auStack_108);
  if (lStack_118 <
      CONCAT26(auStack_108[3],CONCAT24(auStack_108[2],CONCAT22(auStack_108[1],auStack_108[0])))) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4])));
  }
  else {
    lStack_110 = CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4]))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d497a >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d4958,0xffffffc000e14a10,&__func___30388,lStack_110);
  return;
}



// ============================================================================
// Function: S5K4H8_ST_MIPI_RAW_SensorInit at 0xffffffc0005c6d0c
// ============================================================================

undefined8 S5K4H8_ST_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc0010306b8;
  }
  return 0;
}



// ============================================================================
// Function: S5k4h8otp_Ioctl_Compat at 0xffffffc0005c6db8
// ============================================================================

long S5k4h8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

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
  
  if ((uRamffffffc0010d51ea >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d51c8,0xffffffc000e16028,&__func___30633);
  }
  if ((uRamffffffc0010d5212 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d51f0,0xffffffc000e16078,&__func___30633,
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
          printk(0xffffffc000e14628,&__func___30633);
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
// Function: s5k4h8_st_otp_cali at 0xffffffc0005c7474
// ============================================================================

void s5k4h8_st_otp_cali(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  ushort uVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  long lStack_118;
  long lStack_110;
  ushort auStack_108 [8];
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  lVar19 = 0;
  do_gettimeofday(&lStack_118);
  uRamffffffc0011df641 = 99;
  uRamffffffc0011df640 = 1;
  uRamffffffc0011df642 = 0x69;
  uRamffffffc0011df644 = 99;
  uRamffffffc0011df643 = 0x68;
  bVar5 = eeprom_gt24c64a_read8(0x2c);
  bVar6 = eeprom_gt24c64a_read8(0x2d);
  bVar7 = eeprom_gt24c64a_read8(0x2e);
  bVar8 = eeprom_gt24c64a_read8(0x2f);
  uVar10 = eeprom_gt24c64a_read8(0x30);
  sVar11 = eeprom_gt24c64a_read8(0x31);
  uVar13 = eeprom_gt24c64a_read8(0x32);
  uVar14 = eeprom_gt24c64a_read8(0x33);
  uVar15 = eeprom_gt24c64a_read8(0x34);
  uVar16 = eeprom_gt24c64a_read8(0x35);
  uVar12 = eeprom_gt24c64a_read8(0x36);
  uVar17 = eeprom_gt24c64a_read8(0x37);
  uRamffffffc0011df64d = (undefined1)(uVar13 & 0xffff);
  uRamffffffc0011df64e = (undefined1)(uVar14 & 0xffff);
  uRamffffffc0011df64f = (undefined1)(uVar15 & 0xffff);
  uRamffffffc0011df650 = (undefined1)(uVar16 & 0xffff);
  bRamffffffc0011df649 = bVar5;
  bRamffffffc0011df64a = bVar6;
  bRamffffffc0011df64b = bVar7;
  bRamffffffc0011df64c = bVar8;
  printk(0xffffffc000e14938,(uint)bVar5 + (uint)bVar6 * 0x100,(uint)bVar7 + (uint)bVar8 * 0x100,
         sVar11 * 0x100 + (uVar10 & 0xff),(uVar13 & 0xffff) + (uVar14 & 0xffff) * 0x100,
         (uVar15 & 0xffff) + (uVar16 & 0xffff) * 0x100,(uVar17 & 0xffff) * 0x100 + (uint)uVar12);
  do {
    uVar10 = eeprom_gt24c64a_read8((int)lVar19 + 0x42);
    auStack_108[lVar19] = uVar10;
    uVar4 = auStack_108[5];
    uVar3 = auStack_108[4];
    uVar2 = auStack_108[3];
    uVar1 = auStack_108[2];
    uVar12 = auStack_108[1];
    uVar10 = auStack_108[0];
    lVar19 = lVar19 + 1;
  } while (lVar19 != 8);
  if ((uRamffffffc0010d5302 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d52e0,0xffffffc000e16238,&__func___30380,
                       auStack_108[0] | auStack_108[1] << 8,auStack_108[4] | auStack_108[5] << 8,
                       auStack_108[5] | auStack_108[4] << 8,auStack_108[7] | auStack_108[6] << 8,
                       auStack_108[2] | auStack_108[3] << 8);
  }
  uRamffffffc0011df651 = (undefined1)uVar10;
  uRamffffffc0011df655 = 0x4c;
  uRamffffffc0011df652 = (undefined1)uVar12;
  uRamffffffc0011df653 = (undefined1)uVar3;
  uRamffffffc0011df654 = (undefined1)uVar4;
  uRamffffffc0011df645 = (undefined1)uVar1;
  uRamffffffc0011df646 = (undefined1)uVar2;
  uRamffffffc0011df656 = 7;
  puVar20 = (undefined1 *)0xffffffc0011df657;
  iVar18 = 0x51;
  do {
    uVar9 = eeprom_gt24c64a_read8(iVar18);
    puVar21 = puVar20 + 1;
    *puVar20 = uVar9;
    puVar20 = puVar21;
    iVar18 = iVar18 + 1;
  } while (puVar21 != (undefined1 *)0xffffffc0011dfda3);
  do_gettimeofday(auStack_108);
  if (lStack_118 <
      CONCAT26(auStack_108[3],CONCAT24(auStack_108[2],CONCAT22(auStack_108[1],auStack_108[0])))) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4])));
  }
  else {
    lStack_110 = CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4]))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d532a >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d5308,0xffffffc000e162b8,&__func___30388,lStack_110);
  return;
}



// ============================================================================
// Function: S5K4H8_HOLITECH_MIPI_RAW_SensorInit at 0xffffffc0005cd9d4
// ============================================================================

undefined8 S5K4H8_HOLITECH_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc001030ef0;
  }
  return 0;
}



// ============================================================================
// Function: S5k4h8otp_Ioctl_Compat at 0xffffffc0005cda80
// ============================================================================

long S5k4h8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

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
  
  if ((uRamffffffc0010d5b9a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d5b78,0xffffffc000e17a70,&__func___30633);
  }
  if ((uRamffffffc0010d5bc2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d5ba0,0xffffffc000e17ac8,&__func___30633,
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
          printk(0xffffffc000e17b38,&__func___30633);
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
// Function: s5k4h8_holitech_otp_cali at 0xffffffc0005ce13c
// ============================================================================

void s5k4h8_holitech_otp_cali(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  ushort uVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  long lStack_118;
  long lStack_110;
  ushort auStack_108 [8];
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  lVar19 = 0;
  do_gettimeofday(&lStack_118);
  uRamffffffc0011e07c9 = 99;
  uRamffffffc0011e07c8 = 1;
  uRamffffffc0011e07ca = 0x69;
  uRamffffffc0011e07cc = 99;
  uRamffffffc0011e07cb = 0x68;
  bVar5 = eeprom_gt24c64a_read8(0x2c);
  bVar6 = eeprom_gt24c64a_read8(0x2d);
  bVar7 = eeprom_gt24c64a_read8(0x2e);
  bVar8 = eeprom_gt24c64a_read8(0x2f);
  uVar10 = eeprom_gt24c64a_read8(0x30);
  sVar11 = eeprom_gt24c64a_read8(0x31);
  uVar13 = eeprom_gt24c64a_read8(0x32);
  uVar14 = eeprom_gt24c64a_read8(0x33);
  uVar15 = eeprom_gt24c64a_read8(0x34);
  uVar16 = eeprom_gt24c64a_read8(0x35);
  uVar12 = eeprom_gt24c64a_read8(0x36);
  uVar17 = eeprom_gt24c64a_read8(0x37);
  uRamffffffc0011e07d5 = (undefined1)(uVar13 & 0xffff);
  uRamffffffc0011e07d6 = (undefined1)(uVar14 & 0xffff);
  uRamffffffc0011e07d7 = (undefined1)(uVar15 & 0xffff);
  uRamffffffc0011e07d8 = (undefined1)(uVar16 & 0xffff);
  bRamffffffc0011e07d1 = bVar5;
  bRamffffffc0011e07d2 = bVar6;
  bRamffffffc0011e07d3 = bVar7;
  bRamffffffc0011e07d4 = bVar8;
  printk(0xffffffc000e14938,(uint)bVar5 + (uint)bVar6 * 0x100,(uint)bVar7 + (uint)bVar8 * 0x100,
         sVar11 * 0x100 + (uVar10 & 0xff),(uVar13 & 0xffff) + (uVar14 & 0xffff) * 0x100,
         (uVar15 & 0xffff) + (uVar16 & 0xffff) * 0x100,(uVar17 & 0xffff) * 0x100 + (uint)uVar12);
  do {
    uVar10 = eeprom_gt24c64a_read8((int)lVar19 + 0x42);
    auStack_108[lVar19] = uVar10;
    uVar4 = auStack_108[5];
    uVar3 = auStack_108[4];
    uVar2 = auStack_108[3];
    uVar1 = auStack_108[2];
    uVar12 = auStack_108[1];
    uVar10 = auStack_108[0];
    lVar19 = lVar19 + 1;
  } while (lVar19 != 8);
  if ((uRamffffffc0010d5cb2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d5c90,0xffffffc000e17e98,&__func___30380,
                       auStack_108[0] | auStack_108[1] << 8,auStack_108[4] | auStack_108[5] << 8,
                       auStack_108[5] | auStack_108[4] << 8,auStack_108[7] | auStack_108[6] << 8,
                       auStack_108[2] | auStack_108[3] << 8);
  }
  uRamffffffc0011e07d9 = (undefined1)uVar10;
  uRamffffffc0011e07dd = 0x4c;
  uRamffffffc0011e07da = (undefined1)uVar12;
  uRamffffffc0011e07db = (undefined1)uVar3;
  uRamffffffc0011e07dc = (undefined1)uVar4;
  uRamffffffc0011e07cd = (undefined1)uVar1;
  uRamffffffc0011e07ce = (undefined1)uVar2;
  uRamffffffc0011e07de = 7;
  puVar20 = (undefined1 *)0xffffffc0011e07df;
  iVar18 = 0x51;
  do {
    uVar9 = eeprom_gt24c64a_read8(iVar18);
    puVar21 = puVar20 + 1;
    *puVar20 = uVar9;
    puVar20 = puVar21;
    iVar18 = iVar18 + 1;
  } while (puVar21 != (undefined1 *)0xffffffc0011e0f2b);
  do_gettimeofday(auStack_108);
  if (lStack_118 <
      CONCAT26(auStack_108[3],CONCAT24(auStack_108[2],CONCAT22(auStack_108[1],auStack_108[0])))) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4])));
  }
  else {
    lStack_110 = CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4]))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d5cda >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d5cb8,0xffffffc000e17f20,&__func___30388,lStack_110);
  return;
}



// ============================================================================
// Function: S5K4H8_SUNWIN_MIPI_RAW_SensorInit at 0xffffffc0005d4634
// ============================================================================

undefined8 S5K4H8_SUNWIN_MIPI_RAW_SensorInit(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 0xffffffc001031728;
  }
  return 0;
}



// ============================================================================
// Function: S5k4h8otp_Ioctl_Compat at 0xffffffc0005d46e0
// ============================================================================

long S5k4h8otp_Ioctl_Compat(long param_1,uint param_2,ulong param_3)

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
  
  if ((uRamffffffc0010d654a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6528,0xffffffc000e197b8,&__func___30633);
  }
  if ((uRamffffffc0010d6572 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6550,0xffffffc000e19810,&__func___30633,
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
          printk(0xffffffc000e19878,&__func___30633);
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
// Function: s5k4h8_sunwin_otp_cali at 0xffffffc0005d4d9c
// ============================================================================

void s5k4h8_sunwin_otp_cali(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  ushort uVar10;
  short sVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  long lVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  long lStack_118;
  long lStack_110;
  ushort auStack_108 [8];
  undefined1 auStack_f8 [248];
  
  memset(auStack_f8,0,0xf4);
  lVar19 = 0;
  do_gettimeofday(&lStack_118);
  uRamffffffc0011e1949 = 99;
  uRamffffffc0011e1948 = 1;
  uRamffffffc0011e194a = 0x69;
  uRamffffffc0011e194c = 99;
  uRamffffffc0011e194b = 0x68;
  bVar5 = eeprom_gt24c64a_read8(0x2c);
  bVar6 = eeprom_gt24c64a_read8(0x2d);
  bVar7 = eeprom_gt24c64a_read8(0x2e);
  bVar8 = eeprom_gt24c64a_read8(0x2f);
  uVar10 = eeprom_gt24c64a_read8(0x30);
  sVar11 = eeprom_gt24c64a_read8(0x31);
  uVar13 = eeprom_gt24c64a_read8(0x32);
  uVar14 = eeprom_gt24c64a_read8(0x33);
  uVar15 = eeprom_gt24c64a_read8(0x34);
  uVar16 = eeprom_gt24c64a_read8(0x35);
  uVar12 = eeprom_gt24c64a_read8(0x36);
  uVar17 = eeprom_gt24c64a_read8(0x37);
  uRamffffffc0011e1955 = (undefined1)(uVar13 & 0xffff);
  uRamffffffc0011e1956 = (undefined1)(uVar14 & 0xffff);
  uRamffffffc0011e1957 = (undefined1)(uVar15 & 0xffff);
  uRamffffffc0011e1958 = (undefined1)(uVar16 & 0xffff);
  bRamffffffc0011e1951 = bVar5;
  bRamffffffc0011e1952 = bVar6;
  bRamffffffc0011e1953 = bVar7;
  bRamffffffc0011e1954 = bVar8;
  printk(0xffffffc000e14938,(uint)bVar5 + (uint)bVar6 * 0x100,(uint)bVar7 + (uint)bVar8 * 0x100,
         sVar11 * 0x100 + (uVar10 & 0xff),(uVar13 & 0xffff) + (uVar14 & 0xffff) * 0x100,
         (uVar15 & 0xffff) + (uVar16 & 0xffff) * 0x100,(uVar17 & 0xffff) * 0x100 + (uint)uVar12);
  do {
    uVar10 = eeprom_gt24c64a_read8((int)lVar19 + 0x42);
    auStack_108[lVar19] = uVar10;
    uVar4 = auStack_108[5];
    uVar3 = auStack_108[4];
    uVar2 = auStack_108[3];
    uVar1 = auStack_108[2];
    uVar12 = auStack_108[1];
    uVar10 = auStack_108[0];
    lVar19 = lVar19 + 1;
  } while (lVar19 != 8);
  if ((uRamffffffc0010d6662 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d6640,0xffffffc000e19bc8,&__func___30380,
                       auStack_108[0] | auStack_108[1] << 8,auStack_108[4] | auStack_108[5] << 8,
                       auStack_108[5] | auStack_108[4] << 8,auStack_108[7] | auStack_108[6] << 8,
                       auStack_108[2] | auStack_108[3] << 8);
  }
  uRamffffffc0011e1959 = (undefined1)uVar10;
  uRamffffffc0011e195d = 0x4c;
  uRamffffffc0011e195a = (undefined1)uVar12;
  uRamffffffc0011e195b = (undefined1)uVar3;
  uRamffffffc0011e195c = (undefined1)uVar4;
  uRamffffffc0011e194d = (undefined1)uVar1;
  uRamffffffc0011e194e = (undefined1)uVar2;
  uRamffffffc0011e195e = 7;
  puVar20 = (undefined1 *)0xffffffc0011e195f;
  iVar18 = 0x51;
  do {
    uVar9 = eeprom_gt24c64a_read8(iVar18);
    puVar21 = puVar20 + 1;
    *puVar20 = uVar9;
    puVar20 = puVar21;
    iVar18 = iVar18 + 1;
  } while (puVar21 != (undefined1 *)0xffffffc0011e20ab);
  do_gettimeofday(auStack_108);
  if (lStack_118 <
      CONCAT26(auStack_108[3],CONCAT24(auStack_108[2],CONCAT22(auStack_108[1],auStack_108[0])))) {
    lStack_110 = (lStack_110 + 1000000) -
                 CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4])));
  }
  else {
    lStack_110 = CONCAT26(auStack_108[7],
                          CONCAT24(auStack_108[6],CONCAT22(auStack_108[5],auStack_108[4]))) -
                 lStack_110;
  }
  if ((uRamffffffc0010d668a >> 2 & 1) == 0) {
    return;
  }
  __dynamic_pr_debug(0xffffffc0010d6668,0xffffffc000e19c48,&__func___30388,lStack_110);
  return;
}



