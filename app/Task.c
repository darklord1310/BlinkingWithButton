#include "Task.h"
#include <stdint.h>

uint8_t taskOneStack[1028];
uint8_t taskTwoStack[1028];

Tcb mainTcb;
Tcb TaskOneTcb;
Tcb TaskTwoTcb;

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
    TaskOneTcb.sp = (uint32_t)taskOneStack[1028];

	TaskTwoTcb.name = "thread #2";
    TaskTwoTcb.sp = (uint32_t)taskTwoStack[1028];
}
