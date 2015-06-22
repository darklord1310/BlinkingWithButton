#ifndef turnOffLED_H
#define turnOffLED_H

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"

#if !defined(TEST)

#define turnOffLED() HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);

#else

void turnOffLED();

#endif

#endif // turnOffLED_H
