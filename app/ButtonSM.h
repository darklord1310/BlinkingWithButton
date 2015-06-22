#ifndef ButtonSM_H
#define ButtonSM_H

#include <stdint.h>
#include "State.h"
#include "Message.h"

typedef struct{

  State state;

} ButtonData;


void buttonSM(ButtonData *data);
void buttonInitData(ButtonData *data);

#endif // ButtonSM_H
