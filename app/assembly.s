  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global  testFunc
  .extern  dummy

  .section  .text.testFunc
  .type  testFunc, %function
testFunc: 
  movs  r0, 0x12
  movs	r1, 0x13
  movs	r2, 0x14
  stmdb SP!, {r0,r1}
  push  {r0,r1}
  pop   {r10,r11}
  ldmia SP!, {r5,r6}
  movw	r2, 0x1234
  movt  r2, 0xface
  push  {lr}
  movs  r0,#12
  bl    dummy
  bx	lr
