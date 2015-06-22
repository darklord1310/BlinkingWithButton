#ifndef Button_H
#define Button_H

#include <stdbool.h>

#ifndef TEST
#include "stm32f4xx_hal.h"
#endif
#include "stm32f4xx_hal_gpio.h"
  
bool buttonPressed();


#endif // Button_H
