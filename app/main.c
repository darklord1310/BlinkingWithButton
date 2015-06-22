#include "Button.h"
#include "ButtonSM.h"
#include "initButton.h"
#include "initLED.h"
#include "LEDSM.h"
#include "State.h"
#include "TimerExpires.h"
#include "turnOffLED.h"
#include "turnOnLED.h"
#include "Message.h"



int main(void)
{
	LedData ledData ;
	ButtonData buttonData ;

	initButton();
	initLED();

	ledInitData(&ledData);
	buttonInitData(&buttonData);

	while(1)
	{
		buttonSM(&buttonData);
		ledSM(&ledData);

	}
	return 0;
}

