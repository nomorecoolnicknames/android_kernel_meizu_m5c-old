/**
 * Decompiled driver logic for Meizu M5c (MT6737M)
 * Generated via Ghidra Headless
 */

// ============================================================================
// Function: lcd_bais_enn_enable at 0xffffffc0004e4b28
// ============================================================================

void lcd_bais_enn_enable(char param_1)

{
  if (param_1 == '\x01') {
    if (((ulong *)puRamffffffc0011a0280[1])[1] < 0xfffffffffffff001) {
      pinctrl_select_state(*puRamffffffc0011a0280);
      if ((uRamffffffc0010c01d2 >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010c01b0,0xffffffc000dd53f8);
      }
    }
    else if ((uRamffffffc0010c01aa >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0188,0xffffffc000dd53b0);
    }
  }
  else if (*(ulong *)puRamffffffc0011a0280[1] < 0xfffffffffffff001) {
    pinctrl_select_state(*puRamffffffc0011a0280);
    if ((uRamffffffc0010c0222 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0200,0xffffffc000dd5460);
    }
  }
  else if ((uRamffffffc0010c01fa >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010c01d8,0xffffffc000dd5418);
  }
  return;
}



// ============================================================================
// Function: lcd_bais_enp_enable at 0xffffffc0004e4c08
// ============================================================================

void lcd_bais_enp_enable(char param_1)

{
  if (param_1 == '\x01') {
    if (*(ulong *)(puRamffffffc0011a0280[1] + 0x18) < 0xfffffffffffff001) {
      pinctrl_select_state(*puRamffffffc0011a0280);
      if ((uRamffffffc0010c0272 >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010c0250,0xffffffc000dd54c8);
      }
    }
    else if ((uRamffffffc0010c024a >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0228,0xffffffc000dd5480);
    }
  }
  else if (*(ulong *)(puRamffffffc0011a0280[1] + 0x10) < 0xfffffffffffff001) {
    pinctrl_select_state(*puRamffffffc0011a0280);
    if ((uRamffffffc0010c02c2 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c02a0,0xffffffc000dd5530);
    }
  }
  else if ((uRamffffffc0010c029a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010c0278,0xffffffc000dd54e8);
  }
  return;
}



// ============================================================================
// Function: lp3101_pinctrl_remove at 0xffffffc0004e47c0
// ============================================================================

undefined8 lp3101_pinctrl_remove(void)

{
  return 0;
}



// ============================================================================
// Function: lp3101_probe at 0xffffffc0004e47c8
// ============================================================================

undefined8 lp3101_probe(long param_1)

{
  if ((uRamffffffc0010bffca >> 2 & 1) == 0) {
    lRamffffffc0011a0278 = param_1;
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010bffa8,0xffffffc000dd5040,param_1 + 4,*(undefined2 *)(param_1 + 2))
  ;
  lRamffffffc0011a0278 = param_1;
  return 0;
}



// ============================================================================
// Function: lp3101_remove at 0xffffffc0004e4830
// ============================================================================

undefined8 lp3101_remove(undefined8 param_1)

{
  if ((uRamffffffc0010c001a >> 2 & 1) == 0) {
    uRamffffffc0011a0278 = 0;
    i2c_unregister_device(param_1);
    return 0;
  }
  __dynamic_pr_debug(0xffffffc0010bfff8,0xffffffc000dd50a8);
  uRamffffffc0011a0278 = 0;
  i2c_unregister_device(param_1);
  return 0;
}



// ============================================================================
// Function: lp3101_pinctrl_probe at 0xffffffc0004e48a4
// ============================================================================

ulong lp3101_pinctrl_probe(long param_1)

{
  ulong *puVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong *puVar5;
  ulong uVar6;
  
  if ((uRamffffffc0010c0042 >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010c0020,0xffffffc000dd50d0);
  }
  if (puRamffffffc0011a0280 == (ulong *)0x0) {
    puRamffffffc0011a0280 = (ulong *)kmem_cache_alloc_trace(uRamffffffc00115bd18,0x80d0,0x10);
  }
  puVar1 = puRamffffffc0011a0280;
  uVar2 = devm_pinctrl_get(param_1 + 0x10);
  *puVar1 = uVar2;
  if ((uRamffffffc0010c006a >> 2 & 1) != 0) {
    __dynamic_pr_debug(0xffffffc0010c0048,0xffffffc000dd5100);
    uVar2 = *puVar1;
  }
  if (0xfffffffffffff000 < uVar2) {
    if ((uRamffffffc0010c0092 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0070,0xffffffc000dd5130);
      uVar2 = *puVar1;
    }
    return uVar2 & 0xffffffff;
  }
  puVar3 = (undefined8 *)kmem_cache_alloc_trace(uRamffffffc00115bd18,0x80d0,0x20);
  puVar5 = puRamffffffc0011a0280;
  puVar1[1] = (ulong)puVar3;
  uVar4 = pinctrl_lookup_state(*puVar5,0xffffffc000dd5168);
  *puVar3 = uVar4;
  puVar5 = (ulong *)puVar1[1];
  uVar2 = *puVar5;
  if (uVar2 < 0xfffffffffffff001) {
    uVar2 = pinctrl_lookup_state(*puRamffffffc0011a0280,0xffffffc000dd51c8);
    puVar5[1] = uVar2;
    uVar6 = puVar1[1];
    uVar2 = *(ulong *)(uVar6 + 8);
    if (uVar2 < 0xfffffffffffff001) {
      uVar4 = pinctrl_lookup_state(*puRamffffffc0011a0280,0xffffffc000dd5228);
      *(undefined8 *)(uVar6 + 0x10) = uVar4;
      uVar6 = puVar1[1];
      uVar2 = *(ulong *)(uVar6 + 0x10);
      if (uVar2 < 0xfffffffffffff001) {
        uVar4 = pinctrl_lookup_state(*puRamffffffc0011a0280,0xffffffc000dd5288);
        *(undefined8 *)(uVar6 + 0x18) = uVar4;
        if (*(ulong *)(puVar1[1] + 0x18) < 0xfffffffffffff001) {
          uVar2 = 0;
          if ((uRamffffffc0010c015a >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010c0138,0xffffffc000dd52e8);
          }
        }
        else {
          uVar2 = *(ulong *)(puVar1[1] + 0x18) & 0xffffffff;
          if ((uRamffffffc0010c0132 >> 2 & 1) != 0) {
            __dynamic_pr_debug(0xffffffc0010c0110,0xffffffc000dd52a0);
          }
        }
      }
      else {
        uVar2 = uVar2 & 0xffffffff;
        if ((uRamffffffc0010c010a >> 2 & 1) != 0) {
          __dynamic_pr_debug(0xffffffc0010c00e8,0xffffffc000dd5240);
        }
      }
    }
    else {
      uVar2 = uVar2 & 0xffffffff;
      if ((uRamffffffc0010c00e2 >> 2 & 1) != 0) {
        __dynamic_pr_debug(0xffffffc0010c00c0,0xffffffc000dd51e0);
      }
    }
  }
  else {
    uVar2 = uVar2 & 0xffffffff;
    if ((uRamffffffc0010c00ba >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0098,0xffffffc000dd5180);
    }
  }
  return uVar2;
}



// ============================================================================
// Function: lp3101_write_bytes at 0xffffffc0004e4ce8
// ============================================================================

int lp3101_write_bytes(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 uStack_8;
  
  uStack_8 = 0;
  if (lRamffffffc0011a0278 == 0) {
    iVar1 = -1;
    printk(0xffffffc000dd5550);
  }
  else {
    uStack_8 = CONCAT11(param_2,param_1);
    iVar1 = i2c_master_send(lRamffffffc0011a0278,&uStack_8,2);
    if (iVar1 < 0) {
      printk(0xffffffc000dd5570);
    }
  }
  return iVar1;
}



// [-] Could not find function lp3101_id at 0xffffffc000b7e7a0

// [-] Could not find function lp3101_pinctrl_ids at 0xffffffc000b7e7e0

// ============================================================================
// Function: lp3101_i2c_init at 0xffffffc000f5f080
// ============================================================================

int lp3101_i2c_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __platform_driver_register(0xffffffc00101c538,0);
  if (iVar1 == 0) {
    iVar2 = i2c_register_driver(0,0xffffffc00101c450);
    if (iVar2 < 0) {
      iVar1 = -1;
      printk(0xffffffc000dd5350,&__func___23999);
    }
    else if ((uRamffffffc0010c0182 >> 2 & 1) != 0) {
      __dynamic_pr_debug(0xffffffc0010c0160,0xffffffc000dd5380);
    }
  }
  else {
    printk(0xffffffc000dd5320,&__func___23999);
  }
  return iVar1;
}



