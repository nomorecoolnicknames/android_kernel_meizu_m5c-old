/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: DW9714OFILMAF_Ioctl at 0xffffffc0005d9608
// ============================================================================

undefined8 DW9714OFILMAF_Ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  lVar4 = lRamffffffc0011e3310;
  if (param_2 == 0x40044102) {
    _raw_spin_lock(uRamffffffc0011e3330);
    uRamffffffc0011e3318 = param_3;
    _raw_spin_unlock(uRamffffffc0011e3330);
    return 0;
  }
  if (param_2 < 0x40044103) {
    if (param_2 == 0x40044101) {
      if ((uRamffffffc001032dc8 < param_3) || (param_3 < uRamffffffc0011e3318)) {
        if ((uRamffffffc0010d7472 >> 2 & 1) == 0) {
          return 0xffffffffffffffea;
        }
        __dynamic_pr_debug(0xffffffc0010d7450,0xffffffc000e1b928,&__func___21888);
        return 0xffffffffffffffea;
      }
      if (*piRamffffffc0011e3328 == 1) {
        uStack_2f = 0xa3;
        uStack_30 = 0xec;
        uStack_27 = 0xd;
        uStack_1f = 0;
        uStack_28 = 0xa1;
        uStack_17 = 0x51;
        uStack_20 = 0xf2;
        *(undefined2 *)(lRamffffffc0011e3310 + 2) = 0xc;
        uStack_18 = 0xdc;
        i2c_master_send(lVar4,&uStack_30,2);
        i2c_master_send(lRamffffffc0011e3310,&uStack_28,2);
        i2c_master_send(lRamffffffc0011e3310,&uStack_20,2);
        i2c_master_send(lRamffffffc0011e3310,&uStack_18,2);
        lVar4 = lRamffffffc0011e3310;
        *(undefined2 *)(lRamffffffc0011e3310 + 2) = 0xc;
        uStack_10._0_2_ = uStack_10._1_2_;
        iVar3 = i2c_master_recv(lVar4,&uStack_10,2);
        if (iVar3 < 0) {
          if ((uRamffffffc0010d749a >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d7478,0xffffffc000e1b968,&__func___21869);
          }
          _raw_spin_lock(uRamffffffc0011e3330);
          uRamffffffc0011e3320 = 0;
          _raw_spin_unlock(uRamffffffc0011e3330);
        }
        else {
          uVar1 = ((ushort)uStack_10 & 0xff) * 0x10 + ((ushort)uStack_10 >> 0xc);
          if ((uRamffffffc0010d74c2 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d74a0,0xffffffc000e1b9a8,&__func___21888,uVar1);
          }
          _raw_spin_lock(uRamffffffc0011e3330);
          uRamffffffc0011e3320 = (ulong)uVar1;
          _raw_spin_unlock(uRamffffffc0011e3330);
        }
        _raw_spin_lock(uRamffffffc0011e3330);
        uVar2 = uRamffffffc0011e3330;
        *piRamffffffc0011e3328 = 2;
        _raw_spin_unlock(uVar2);
      }
      if (param_3 != uRamffffffc0011e3320) {
        _raw_spin_lock(uRamffffffc0011e3330);
        uRamffffffc0011e3338 = param_3;
        _raw_spin_unlock(uRamffffffc0011e3330);
        iVar3 = s4AF_WriteReg(uRamffffffc0011e3338 & 0xffff);
        if (iVar3 == 0) {
          _raw_spin_lock(uRamffffffc0011e3330);
          uRamffffffc0011e3320 = uRamffffffc0011e3338;
          _raw_spin_unlock(uRamffffffc0011e3330);
          return 0;
        }
        if ((uRamffffffc0010d74ea >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010d74c8,0xffffffc000e1b9e8,&__func___21888);
          return 0;
        }
        return 0;
      }
      return 0;
    }
  }
  else {
    if (param_2 == 0x40044103) {
      _raw_spin_lock(uRamffffffc0011e3330);
      uRamffffffc001032dc8 = param_3;
      _raw_spin_unlock(uRamffffffc0011e3330);
      return 0;
    }
    if (param_2 == 0x80104100) {
      uStack_2 = 1;
      uStack_c = (undefined4)uRamffffffc001032dc8;
      uStack_8 = (undefined4)uRamffffffc0011e3318;
      uStack_10 = (undefined4)uRamffffffc0011e3320;
      uStack_4 = 1;
      uStack_3 = 0 < *piRamffffffc0011e3328;
      if ((param_3 < 0xfffffffffffffff0 &&
           param_3 + 0x10 <= *(ulong *)(((ulong)&stack0xffffffffffffffa0 & 0xffffffffffffc000) + 8))
         && (lVar4 = __copy_to_user(param_3,&uStack_10,0x10), lVar4 == 0)) {
        return 0;
      }
      if ((uRamffffffc0010d744a >> 2 & 1) == 0) {
        return 0;
      }
      __dynamic_pr_debug(0xffffffc0010d7428,0xffffffc000e1b8c8,&__func___21882);
      return 0;
    }
  }
  if ((uRamffffffc0010d7512 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d74f0,0xffffffc000e1ba40,&__func___21915);
  }
  return 0xffffffffffffffff;
}



// ============================================================================
// Function: DW9714OFILMAF_Release at 0xffffffc0005d9a38
// ============================================================================

undefined8 DW9714OFILMAF_Release(void)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((uRamffffffc0010d753a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d7518,0xffffffc000e1ba78,&__func___21921);
  }
  iVar2 = *piRamffffffc0011e3328;
  if (iVar2 == 2) {
    if ((uRamffffffc0010d7562 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d7540,0xffffffc000e1bab0,&__func___21921);
    }
    s4AF_WriteReg(0x118);
    msleep(0x14);
    s4AF_WriteReg(0xdc);
    msleep(0x14);
    s4AF_WriteReg(0x96);
    msleep(0x14);
    s4AF_WriteReg(100);
    msleep(0x14);
    iVar2 = *piRamffffffc0011e3328;
  }
  if (iVar2 != 0) {
    if ((uRamffffffc0010d758a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d7568,0xffffffc000e1bae8,&__func___21921);
    }
    _raw_spin_lock(uRamffffffc0011e3330);
    uVar1 = uRamffffffc0011e3330;
    *piRamffffffc0011e3328 = 0;
    _raw_spin_unlock(uVar1);
  }
  if ((uRamffffffc0010d75b2 >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010d7590,0xffffffc000e1bb20,&__func___21921);
  return 0;
}



// ============================================================================
// Function: DW9714OFILMAF_SetI2Cclient at 0xffffffc0005d9b9c
// ============================================================================

void DW9714OFILMAF_SetI2Cclient(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uRamffffffc0011e3310 = param_1;
  uRamffffffc0011e3330 = param_2;
  uRamffffffc0011e3328 = param_3;
  return;
}



// ============================================================================
// Function: DW9714STAF_Ioctl at 0xffffffc0005d9c38
// ============================================================================

undefined8 DW9714STAF_Ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  lVar4 = lRamffffffc0011e3340;
  if (param_2 == 0x40044102) {
    _raw_spin_lock(uRamffffffc0011e3360);
    uRamffffffc0011e3348 = param_3;
    _raw_spin_unlock(uRamffffffc0011e3360);
    return 0;
  }
  if (param_2 < 0x40044103) {
    if (param_2 == 0x40044101) {
      if ((uRamffffffc001032dd0 < param_3) || (param_3 < uRamffffffc0011e3348)) {
        if ((uRamffffffc0010d762a >> 2 & 1) == 0) {
          return 0xffffffffffffffea;
        }
        __dynamic_pr_debug(0xffffffc0010d7608,0xffffffc000e1bc90,&__func___21888);
        return 0xffffffffffffffea;
      }
      if (*piRamffffffc0011e3358 == 1) {
        uStack_2f = 0xa3;
        uStack_30 = 0xec;
        uStack_27 = 0xd;
        uStack_1f = 0;
        uStack_28 = 0xa1;
        uStack_17 = 0x51;
        uStack_20 = 0xf2;
        *(undefined2 *)(lRamffffffc0011e3340 + 2) = 0xc;
        uStack_18 = 0xdc;
        i2c_master_send(lVar4,&uStack_30,2);
        i2c_master_send(lRamffffffc0011e3340,&uStack_28,2);
        i2c_master_send(lRamffffffc0011e3340,&uStack_20,2);
        i2c_master_send(lRamffffffc0011e3340,&uStack_18,2);
        lVar4 = lRamffffffc0011e3340;
        *(undefined2 *)(lRamffffffc0011e3340 + 2) = 0xc;
        uStack_10._0_2_ = uStack_10._1_2_;
        iVar3 = i2c_master_recv(lVar4,&uStack_10,2);
        if (iVar3 < 0) {
          if ((uRamffffffc0010d7652 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d7630,0xffffffc000e1bcc8,&__func___21869);
          }
          _raw_spin_lock(uRamffffffc0011e3360);
          uRamffffffc0011e3350 = 0;
          _raw_spin_unlock(uRamffffffc0011e3360);
        }
        else {
          uVar1 = ((ushort)uStack_10 & 0xff) * 0x10 + ((ushort)uStack_10 >> 0xc);
          if ((uRamffffffc0010d767a >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d7658,0xffffffc000e1bd08,&__func___21888,uVar1);
          }
          _raw_spin_lock(uRamffffffc0011e3360);
          uRamffffffc0011e3350 = (ulong)uVar1;
          _raw_spin_unlock(uRamffffffc0011e3360);
        }
        _raw_spin_lock(uRamffffffc0011e3360);
        uVar2 = uRamffffffc0011e3360;
        *piRamffffffc0011e3358 = 2;
        _raw_spin_unlock(uVar2);
      }
      if (param_3 != uRamffffffc0011e3350) {
        _raw_spin_lock(uRamffffffc0011e3360);
        uRamffffffc0011e3368 = param_3;
        _raw_spin_unlock(uRamffffffc0011e3360);
        iVar3 = s4AF_WriteReg(uRamffffffc0011e3368 & 0xffff);
        if (iVar3 == 0) {
          _raw_spin_lock(uRamffffffc0011e3360);
          uRamffffffc0011e3350 = uRamffffffc0011e3368;
          _raw_spin_unlock(uRamffffffc0011e3360);
          return 0;
        }
        if ((uRamffffffc0010d76a2 >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010d7680,0xffffffc000e1bd40,&__func___21888);
          return 0;
        }
        return 0;
      }
      return 0;
    }
  }
  else {
    if (param_2 == 0x40044103) {
      _raw_spin_lock(uRamffffffc0011e3360);
      uRamffffffc001032dd0 = param_3;
      _raw_spin_unlock(uRamffffffc0011e3360);
      return 0;
    }
    if (param_2 == 0x80104100) {
      uStack_2 = 1;
      uStack_c = (undefined4)uRamffffffc001032dd0;
      uStack_8 = (undefined4)uRamffffffc0011e3348;
      uStack_10 = (undefined4)uRamffffffc0011e3350;
      uStack_4 = 1;
      uStack_3 = 0 < *piRamffffffc0011e3358;
      if ((param_3 < 0xfffffffffffffff0 &&
           param_3 + 0x10 <= *(ulong *)(((ulong)&stack0xffffffffffffffa0 & 0xffffffffffffc000) + 8))
         && (lVar4 = __copy_to_user(param_3,&uStack_10,0x10), lVar4 == 0)) {
        return 0;
      }
      if ((uRamffffffc0010d7602 >> 2 & 1) == 0) {
        return 0;
      }
      __dynamic_pr_debug(0xffffffc0010d75e0,0xffffffc000e1bc30,&__func___21882);
      return 0;
    }
  }
  if ((uRamffffffc0010d76ca >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d76a8,0xffffffc000e1bd90,&__func___21915);
  }
  return 0xffffffffffffffff;
}



// ============================================================================
// Function: DW9714STAF_Release at 0xffffffc0005da068
// ============================================================================

undefined8 DW9714STAF_Release(void)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((uRamffffffc0010d76f2 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d76d0,0xffffffc000e1bdc0,&__func___21921);
  }
  iVar2 = *piRamffffffc0011e3358;
  if (iVar2 == 2) {
    if ((uRamffffffc0010d771a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d76f8,0xffffffc000e1bdf0,&__func___21921);
    }
    s4AF_WriteReg(0x118);
    msleep(0x14);
    s4AF_WriteReg(0xdc);
    msleep(0x14);
    s4AF_WriteReg(0x96);
    msleep(0x14);
    s4AF_WriteReg(100);
    msleep(0x14);
    iVar2 = *piRamffffffc0011e3358;
  }
  if (iVar2 != 0) {
    if ((uRamffffffc0010d7742 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d7720,0xffffffc000e1be20,&__func___21921);
    }
    _raw_spin_lock(uRamffffffc0011e3360);
    uVar1 = uRamffffffc0011e3360;
    *piRamffffffc0011e3358 = 0;
    _raw_spin_unlock(uVar1);
  }
  if ((uRamffffffc0010d776a >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010d7748,0xffffffc000e1be50,&__func___21921);
  return 0;
}



// ============================================================================
// Function: DW9714STAF_SetI2Cclient at 0xffffffc0005da1cc
// ============================================================================

void DW9714STAF_SetI2Cclient(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uRamffffffc0011e3340 = param_1;
  uRamffffffc0011e3360 = param_2;
  uRamffffffc0011e3358 = param_3;
  return;
}



// ============================================================================
// Function: DW9714HOLITECHAF_Ioctl at 0xffffffc0005da268
// ============================================================================

undefined8 DW9714HOLITECHAF_Ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  lVar4 = lRamffffffc0011e3370;
  if (param_2 == 0x40044102) {
    _raw_spin_lock(uRamffffffc0011e3390);
    uRamffffffc0011e3378 = param_3;
    _raw_spin_unlock(uRamffffffc0011e3390);
    return 0;
  }
  if (param_2 < 0x40044103) {
    if (param_2 == 0x40044101) {
      if ((uRamffffffc001032dd8 < param_3) || (param_3 < uRamffffffc0011e3378)) {
        if ((uRamffffffc0010d77e2 >> 2 & 1) == 0) {
          return 0xffffffffffffffea;
        }
        __dynamic_pr_debug(0xffffffc0010d77c0,0xffffffc000e1bfc8,&__func___21888);
        return 0xffffffffffffffea;
      }
      if (*piRamffffffc0011e3388 == 1) {
        uStack_2f = 0xa3;
        uStack_30 = 0xec;
        uStack_27 = 0xd;
        uStack_1f = 0;
        uStack_28 = 0xa1;
        uStack_17 = 0x51;
        uStack_20 = 0xf2;
        *(undefined2 *)(lRamffffffc0011e3370 + 2) = 0xc;
        uStack_18 = 0xdc;
        i2c_master_send(lVar4,&uStack_30,2);
        i2c_master_send(lRamffffffc0011e3370,&uStack_28,2);
        i2c_master_send(lRamffffffc0011e3370,&uStack_20,2);
        i2c_master_send(lRamffffffc0011e3370,&uStack_18,2);
        lVar4 = lRamffffffc0011e3370;
        *(undefined2 *)(lRamffffffc0011e3370 + 2) = 0xc;
        uStack_10._0_2_ = uStack_10._1_2_;
        iVar3 = i2c_master_recv(lVar4,&uStack_10,2);
        if (iVar3 < 0) {
          if ((uRamffffffc0010d780a >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d77e8,0xffffffc000e1c008,&__func___21869);
          }
          _raw_spin_lock(uRamffffffc0011e3390);
          uRamffffffc0011e3380 = 0;
          _raw_spin_unlock(uRamffffffc0011e3390);
        }
        else {
          uVar1 = ((ushort)uStack_10 & 0xff) * 0x10 + ((ushort)uStack_10 >> 0xc);
          if ((uRamffffffc0010d7832 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d7810,0xffffffc000e1c050,&__func___21888,uVar1);
          }
          _raw_spin_lock(uRamffffffc0011e3390);
          uRamffffffc0011e3380 = (ulong)uVar1;
          _raw_spin_unlock(uRamffffffc0011e3390);
        }
        _raw_spin_lock(uRamffffffc0011e3390);
        uVar2 = uRamffffffc0011e3390;
        *piRamffffffc0011e3388 = 2;
        _raw_spin_unlock(uVar2);
      }
      if (param_3 != uRamffffffc0011e3380) {
        _raw_spin_lock(uRamffffffc0011e3390);
        uRamffffffc0011e3398 = param_3;
        _raw_spin_unlock(uRamffffffc0011e3390);
        iVar3 = s4AF_WriteReg(uRamffffffc0011e3398 & 0xffff);
        if (iVar3 == 0) {
          _raw_spin_lock(uRamffffffc0011e3390);
          uRamffffffc0011e3380 = uRamffffffc0011e3398;
          _raw_spin_unlock(uRamffffffc0011e3390);
          return 0;
        }
        if ((uRamffffffc0010d785a >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010d7838,0xffffffc000e1c090,&__func___21888);
          return 0;
        }
        return 0;
      }
      return 0;
    }
  }
  else {
    if (param_2 == 0x40044103) {
      _raw_spin_lock(uRamffffffc0011e3390);
      uRamffffffc001032dd8 = param_3;
      _raw_spin_unlock(uRamffffffc0011e3390);
      return 0;
    }
    if (param_2 == 0x80104100) {
      uStack_2 = 1;
      uStack_c = (undefined4)uRamffffffc001032dd8;
      uStack_8 = (undefined4)uRamffffffc0011e3378;
      uStack_10 = (undefined4)uRamffffffc0011e3380;
      uStack_4 = 1;
      uStack_3 = 0 < *piRamffffffc0011e3388;
      if ((param_3 < 0xfffffffffffffff0 &&
           param_3 + 0x10 <= *(ulong *)(((ulong)&stack0xffffffffffffffa0 & 0xffffffffffffc000) + 8))
         && (lVar4 = __copy_to_user(param_3,&uStack_10,0x10), lVar4 == 0)) {
        return 0;
      }
      if ((uRamffffffc0010d77ba >> 2 & 1) == 0) {
        return 0;
      }
      __dynamic_pr_debug(0xffffffc0010d7798,0xffffffc000e1bf60,&__func___21882);
      return 0;
    }
  }
  if ((uRamffffffc0010d7882 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d7860,0xffffffc000e1c0e8,&__func___21915);
  }
  return 0xffffffffffffffff;
}



// ============================================================================
// Function: DW9714HOLITECHAF_Release at 0xffffffc0005da698
// ============================================================================

undefined8 DW9714HOLITECHAF_Release(void)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((uRamffffffc0010d78aa >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d7888,0xffffffc000e1c128,&__func___21921);
  }
  iVar2 = *piRamffffffc0011e3388;
  if (iVar2 == 2) {
    if ((uRamffffffc0010d78d2 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d78b0,0xffffffc000e1c168,&__func___21921);
    }
    s4AF_WriteReg(0x118);
    msleep(0x14);
    s4AF_WriteReg(0xdc);
    msleep(0x14);
    s4AF_WriteReg(0x96);
    msleep(0x14);
    s4AF_WriteReg(100);
    msleep(0x14);
    iVar2 = *piRamffffffc0011e3388;
  }
  if (iVar2 != 0) {
    if ((uRamffffffc0010d78fa >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d78d8,0xffffffc000e1c1a0,&__func___21921);
    }
    _raw_spin_lock(uRamffffffc0011e3390);
    uVar1 = uRamffffffc0011e3390;
    *piRamffffffc0011e3388 = 0;
    _raw_spin_unlock(uVar1);
  }
  if ((uRamffffffc0010d7922 >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010d7900,0xffffffc000e1c1d8,&__func___21921);
  return 0;
}



// ============================================================================
// Function: DW9714HOLITECHAF_SetI2Cclient at 0xffffffc0005da7fc
// ============================================================================

void DW9714HOLITECHAF_SetI2Cclient(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uRamffffffc0011e3370 = param_1;
  uRamffffffc0011e3390 = param_2;
  uRamffffffc0011e3388 = param_3;
  return;
}



// ============================================================================
// Function: DW9714SUNWINAF_Ioctl at 0xffffffc0005da898
// ============================================================================

undefined8 DW9714SUNWINAF_Ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  lVar4 = lRamffffffc0011e33a0;
  if (param_2 == 0x40044102) {
    _raw_spin_lock(uRamffffffc0011e33c0);
    uRamffffffc0011e33a8 = param_3;
    _raw_spin_unlock(uRamffffffc0011e33c0);
    return 0;
  }
  if (param_2 < 0x40044103) {
    if (param_2 == 0x40044101) {
      if ((uRamffffffc001032de0 < param_3) || (param_3 < uRamffffffc0011e33a8)) {
        if ((uRamffffffc0010d799a >> 2 & 1) == 0) {
          return 0xffffffffffffffea;
        }
        __dynamic_pr_debug(0xffffffc0010d7978,0xffffffc000e1c368,&__func___21888);
        return 0xffffffffffffffea;
      }
      if (*piRamffffffc0011e33b8 == 1) {
        uStack_2f = 0xa3;
        uStack_30 = 0xec;
        uStack_27 = 0xd;
        uStack_1f = 0;
        uStack_28 = 0xa1;
        uStack_17 = 0x51;
        uStack_20 = 0xf2;
        *(undefined2 *)(lRamffffffc0011e33a0 + 2) = 0xc;
        uStack_18 = 0xdc;
        i2c_master_send(lVar4,&uStack_30,2);
        i2c_master_send(lRamffffffc0011e33a0,&uStack_28,2);
        i2c_master_send(lRamffffffc0011e33a0,&uStack_20,2);
        i2c_master_send(lRamffffffc0011e33a0,&uStack_18,2);
        lVar4 = lRamffffffc0011e33a0;
        *(undefined2 *)(lRamffffffc0011e33a0 + 2) = 0xc;
        uStack_10._0_2_ = uStack_10._1_2_;
        iVar3 = i2c_master_recv(lVar4,&uStack_10,2);
        if (iVar3 < 0) {
          if ((uRamffffffc0010d79c2 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d79a0,0xffffffc000e1c3a8,&__func___21869);
          }
          _raw_spin_lock(uRamffffffc0011e33c0);
          uRamffffffc0011e33b0 = 0;
          _raw_spin_unlock(uRamffffffc0011e33c0);
        }
        else {
          uVar1 = ((ushort)uStack_10 & 0xff) * 0x10 + ((ushort)uStack_10 >> 0xc);
          if ((uRamffffffc0010d79ea >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010d79c8,0xffffffc000e1c3f0,&__func___21888,uVar1);
          }
          _raw_spin_lock(uRamffffffc0011e33c0);
          uRamffffffc0011e33b0 = (ulong)uVar1;
          _raw_spin_unlock(uRamffffffc0011e33c0);
        }
        _raw_spin_lock(uRamffffffc0011e33c0);
        uVar2 = uRamffffffc0011e33c0;
        *piRamffffffc0011e33b8 = 2;
        _raw_spin_unlock(uVar2);
      }
      if (param_3 != uRamffffffc0011e33b0) {
        _raw_spin_lock(uRamffffffc0011e33c0);
        uRamffffffc0011e33c8 = param_3;
        _raw_spin_unlock(uRamffffffc0011e33c0);
        iVar3 = s4AF_WriteReg(uRamffffffc0011e33c8 & 0xffff);
        if (iVar3 == 0) {
          _raw_spin_lock(uRamffffffc0011e33c0);
          uRamffffffc0011e33b0 = uRamffffffc0011e33c8;
          _raw_spin_unlock(uRamffffffc0011e33c0);
          return 0;
        }
        if ((uRamffffffc0010d7a12 >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010d79f0,0xffffffc000e1c430,&__func___21888);
          return 0;
        }
        return 0;
      }
      return 0;
    }
  }
  else {
    if (param_2 == 0x40044103) {
      _raw_spin_lock(uRamffffffc0011e33c0);
      uRamffffffc001032de0 = param_3;
      _raw_spin_unlock(uRamffffffc0011e33c0);
      return 0;
    }
    if (param_2 == 0x80104100) {
      uStack_2 = 1;
      uStack_c = (undefined4)uRamffffffc001032de0;
      uStack_8 = (undefined4)uRamffffffc0011e33a8;
      uStack_10 = (undefined4)uRamffffffc0011e33b0;
      uStack_4 = 1;
      uStack_3 = 0 < *piRamffffffc0011e33b8;
      if ((param_3 < 0xfffffffffffffff0 &&
           param_3 + 0x10 <= *(ulong *)(((ulong)&stack0xffffffffffffffa0 & 0xffffffffffffc000) + 8))
         && (lVar4 = __copy_to_user(param_3,&uStack_10,0x10), lVar4 == 0)) {
        return 0;
      }
      if ((uRamffffffc0010d7972 >> 2 & 1) == 0) {
        return 0;
      }
      __dynamic_pr_debug(0xffffffc0010d7950,0xffffffc000e1c300,&__func___21882);
      return 0;
    }
  }
  if ((uRamffffffc0010d7a3a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d7a18,0xffffffc000e1c488,&__func___21915);
  }
  return 0xffffffffffffffff;
}



// ============================================================================
// Function: DW9714SUNWINAF_Release at 0xffffffc0005dacc8
// ============================================================================

undefined8 DW9714SUNWINAF_Release(void)

{
  undefined8 uVar1;
  int iVar2;
  
  if ((uRamffffffc0010d7a62 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010d7a40,0xffffffc000e1c4c0,&__func___21921);
  }
  iVar2 = *piRamffffffc0011e33b8;
  if (iVar2 == 2) {
    if ((uRamffffffc0010d7a8a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d7a68,0xffffffc000e1c4f8,&__func___21921);
    }
    s4AF_WriteReg(0x118);
    msleep(0x14);
    s4AF_WriteReg(0xdc);
    msleep(0x14);
    s4AF_WriteReg(0x96);
    msleep(0x14);
    s4AF_WriteReg(100);
    msleep(0x14);
    iVar2 = *piRamffffffc0011e33b8;
  }
  if (iVar2 != 0) {
    if ((uRamffffffc0010d7ab2 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010d7a90,0xffffffc000e1c530,&__func___21921);
    }
    _raw_spin_lock(uRamffffffc0011e33c0);
    uVar1 = uRamffffffc0011e33c0;
    *piRamffffffc0011e33b8 = 0;
    _raw_spin_unlock(uVar1);
  }
  if ((uRamffffffc0010d7ada >> 2 & 1) == 0) {
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010d7ab8,0xffffffc000e1c568,&__func___21921);
  return 0;
}



// ============================================================================
// Function: DW9714SUNWINAF_SetI2Cclient at 0xffffffc0005dae2c
// ============================================================================

void DW9714SUNWINAF_SetI2Cclient(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uRamffffffc0011e33a0 = param_1;
  uRamffffffc0011e33c0 = param_2;
  uRamffffffc0011e33b8 = param_3;
  return;
}



