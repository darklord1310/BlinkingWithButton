  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  testFunc

  .section  .text.testFunc
  .type  testFunc, %function
testFunc: 
  movs  r0, 0x012
  movs	r1, 0x013
  movs	r2, 0x014
  ldr   r3, =0x1234face
  movw	r2, 0x1234
  movt  r2, 0xface
  bx	lr
