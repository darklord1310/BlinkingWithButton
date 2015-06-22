#include "ButtonSM.h"
#include "Message.h"
#include "Button.h"
#include <stdio.h>

void buttonInitData(ButtonData *data)
{
  data->state = Release;

}


void buttonSM(ButtonData *data)
{

  switch(data->state)
  {
    case Release : if( buttonPressed() == true)
                   {
                      msg = CHANGE_MODE;       // if button pressed, send changeStateMsg and go to Press
                      data->state = Press;
                   }
                   break;
    
    case Press :   if( buttonPressed() == true )
                   {
                      data->state = Press;   // if button is hold, stay at Press and do nothing
                      msg = DO_NOTHING;
                   }
                   else
                   {
                    data->state = Release;   // if button is release, do nothing and go to Release
                    msg = DO_NOTHING;
                   }
                   break;
    
  }
}
