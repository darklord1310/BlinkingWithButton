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

void testFunc(void);

int main(void)
{
	LedData ledData ;
	ButtonData buttonData ;

	initSysTick();
	initButton();
	initLED();

	testFunc();
	ledInitData(&ledData);
	buttonInitData(&buttonData);

	while(1)
	{
		buttonSM(&buttonData);
		ledSM(&ledData);

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
