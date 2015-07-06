#include "Task.h"
#include <stdint.h>

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb TaskOneTcb;
Tcb TaskTwoTcb;

/* Task Switching Mechanism
 *
 * 1) push the rest of the registers
 * 2) let r0 points to mainTCB
 * 3) store the current SP into mainTCB(through R0),
 * 4) let r0 points to taskOneTCB
 * 5) load taskOneTcb(through R0) into current SP
 * 6) return from interrupt using "bx lr"
 *
 */
void taskOne()
{

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

	TaskTwoTcb.name = "thread #2";
    TaskTwoTcb.sp = (uint32_t)taskTwoStack[1028];
}
