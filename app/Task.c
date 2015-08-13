#include "Task.h"
#include <stdint.h>

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb TaskOneTcb;
Tcb TaskTwoTcb;
Tcb *runningTcb;
Tcb *readyQueue;

/* Task Switching Mechanism
 *
 * 1) push the rest of the registers
 * 2) load mainTCB
 * 3) store the current SP into mainTCB(through R0),
 * 4) load taskOneTcb
 * 5) load taskOneTcb into SP
 * 6) pop all pushed register
 * 7) return from interrupt using "bx lr"
 *
 *
 * 1) push the rest of the registers
 * 2) load runningTcb into R4
 * 3) store the current SP into runningTCB(through R0), push LR
 * 4) R5 = listRemoveHead()
 * 5) load R5.sp into SP
 * 6) let runningTcb = R5
 * 7) listAddTail(R4)
 * 8) Pop LR
 * 9) pop all pushed register
 * 10)return from interrupt
 *
 */
void taskOne()
{
  asm(
  "ldr  r0, =#0xdeadbeef\n\t"
  "ldr  r1, =#0xbeefdead\n\t"
  "ldr  r2, =#0xc222222c\n\t"
  "ldr  r3, =#0xd333333d\n\t"
  );

	while(1);
}


/* Initialize all the TCBs
 *
 *
 */
void initTcb()
{
	mainTcb.name = "main thread";
	mainTcb.sp = 0;

	TaskOneTcb.name = "thread #1";
    CpuContext *cc = (CpuContext *)(  (uint32_t)&taskOneStack[1024] - sizeof(CpuContext) );
    TaskOneTcb.sp = (uint32_t)cc;
    cc->R0 = 0x00;
    cc->R1 = 0x11;
    cc->R2 = 0x22;
    cc->R3 = 0x33;
    cc->R4 = 0x44;
    cc->R5 = 0x55;
    cc->R6 = 0x66;
    cc->R7 = 0x77;
    cc->R8 = 0x88;
    cc->R9 = 0x99;
    cc->R10 = 0xaa;
    cc->R11 = 0xbb;
    cc->R12 = 0xcc;
    cc->PC = (uint32_t)&taskOne;
    cc->xPSR = 0x01000000;


	TaskTwoTcb.name = "thread #2";
    TaskTwoTcb.sp = (uint32_t)taskTwoStack[1028];
    CpuContext *cc1 = (CpuContext *)(  (uint32_t)&taskTwoStack[1024] - sizeof(CpuContext) );
    TaskTwoTcb.sp = (uint32_t)cc1;
    cc1->R0 = 0xff;
    cc1->R1 = 0x11;
    cc1->R2 = 0x22;
    cc1->R3 = 0x33;
    cc1->R4 = 0x44;
    cc1->R5 = 0x55;
    cc1->R6 = 0x66;
    cc1->R7 = 0x77;
    cc1->R8 = 0x88;
    cc1->R9 = 0x99;
    cc1->R10 = 0xaa;
    cc1->R11 = 0xbb;
    cc1->R12 = 0xcc;
    cc1->PC = (uint32_t)&taskOne;
    cc1->xPSR = 0x01000000;
    
  runningTcb = &mainTcb;
  readyQueue = &TaskOneTcb;
}
