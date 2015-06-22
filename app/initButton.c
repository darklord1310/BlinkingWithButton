#include "initButton.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

void initButton()	
{
	GPIO_InitTypeDef GpioInfo_PortA ;
	__GPIOA_CLK_ENABLE();

	GpioInfo_PortA.Mode = GPIO_MODE_INPUT ;
	GpioInfo_PortA.Pin = GPIO_PIN_0; // Init PA0
	GpioInfo_PortA.Pull = GPIO_NOPULL ;
	GpioInfo_PortA.Speed = GPIO_SPEED_HIGH ;

    //Init Push Button on PA0
    HAL_GPIO_Init(GPIOA,&GpioInfo_PortA);

}
