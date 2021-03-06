#include "Button.h"
#include "ButtonSM.h"
#include "initButton.h"
#include "initLED.h"
#include "LEDSM.h"
#include "State.h"
#include "main.h"
#include "TimerExpires.h"
#include "turnOffLED.h"
#include "turnOnLED.h"
#include "Message.h"
#include "Task.h"
#include "LinkList.h"

void testFunc(void);
void taskSwitch(void);

int main(void)
{
	LedData ledData ;
	ButtonData buttonData ;

	initSysTick();
	initTcb();
	//initButton();
	//initLED();

	//ledInitData(&ledData);
	//buttonInitData(&buttonData);

	taskSwitch();

	while(1)
	{
		//buttonSM(&buttonData);
		//ledSM(&ledData);

	}
	return 0;
}

void initSysTick()
{
	if(SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}
}

int dummy(int value)
{
	return value *10;
}
