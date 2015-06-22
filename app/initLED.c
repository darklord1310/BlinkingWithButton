#include "initLED.h"

void initLED()	// Initialization for LEDs
{
    GPIO_InitTypeDef GpioInfo_PortG ;

    __GPIOG_CLK_ENABLE();

    // Init for the Port G
    GpioInfo_PortG.Mode = GPIO_MODE_OUTPUT_PP ;
    GpioInfo_PortG.Pin = GPIO_PIN_13 | GPIO_PIN_14; // Enable LED3 and LED4
    GpioInfo_PortG.Pull = GPIO_NOPULL ;
    GpioInfo_PortG.Speed = GPIO_SPEED_HIGH ;

    //Init LED on PG13 and PG14
    HAL_GPIO_Init(GPIOG,&GpioInfo_PortG);

}