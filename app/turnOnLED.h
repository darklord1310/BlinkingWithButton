#ifndef turnOnLED_H
#define turnOnLED_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

#if !defined(TEST)

#define turnOnLED() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);

#else

void turnOnLED();

#endif

#endif // turnOnLED_H
