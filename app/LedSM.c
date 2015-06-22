#include "LedSM.h"
#include "Message.h"
#include "turnOffLED.h"
#include "turnOnLED.h"
#include "TimerExpires.h"
#include <stdio.h>

void ledInitData(LedData *data)
{
  data->state = Initial;

}



void ledSM(LedData *data)
{
  switch(data->state)
  {
    case Initial : data->state = LED_OFF;
                   break;
                   
    case LED_OFF : turnOffLED();
                   if(msg == CHANGE_MODE)
                   { 
                      data->state = LEDBlinking_ON;
                      msg = DO_NOTHING;
                   }
                   else
                      data->state = LED_OFF;
                   break;
                   
    case LEDBlinking_ON :   turnOnLED();
                            if( msg == CHANGE_MODE)
                            {
                              data->state = LED_ON;
                              msg = DO_NOTHING;
                            }
                            else if( isTimerExpires(500) )
                            {
                                data->state = LEDBlinking_OFF;
                            }
                            break;
                            
    case LEDBlinking_OFF :  turnOffLED();
                            if( msg == CHANGE_MODE)
                            {
                              data->state = LED_ON;
                              msg = DO_NOTHING;
                            }
                            else if( isTimerExpires(500) )
                            {
                                data->state = LEDBlinking_ON;
                            }
                            break;
                            
    case LED_ON :   turnOnLED();
                    if( msg == CHANGE_MODE)
                    {
                        data->state = LED_OFF;
                        msg = DO_NOTHING;
                    }
                    break;
    
  }
}
