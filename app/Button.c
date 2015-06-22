#include "Button.h"

bool buttonPressed()
{
	GPIO_PinState result = 0;
	result = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

	if (result == 1)
		return 1 ;
	else
		return 0 ;
}