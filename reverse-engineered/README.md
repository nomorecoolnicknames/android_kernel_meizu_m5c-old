# Reverse-engineered component drivers — Meizu M5c (MT6737M)

Ghidra decompilations of the board-specific component drivers extracted from the
stock Meizu M5c kernel (Linux 3.18). Reference material only — not compilable source.

| file | component |
|------|-----------|
| driver_lp3101.c  | LCD bias regulator (LP3101) |
| lcm_ili9881c.c   | display panel ILI9881C |
| lcm_jd9365.c     | display panel JD9365 |
| sensor_mc3xxx.c  | accelerometer (mCube MC3xxx / MC3410) |
| sensor_stk3x1x.c | ambient-light / proximity (Sensortek STK3x1x) |
| sensor_s5k4h8.c  | main camera (Samsung S5K4H8) |
| sensor_s5k5e8.c  | front camera (Samsung S5K5E8) |
| af_dw9714.c      | camera auto-focus (DW9714) |
| touch_ft5x46.c   | touchscreen (FocalTech FT5x46) |
