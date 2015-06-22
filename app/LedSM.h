#ifndef LedSM_H
#define LedSM_H

#include <stdint.h>
#include "Message.h"
#include "State.h"


typedef struct{

  State state;
  uint32_t time;
} LedData;




void ledSM(LedData *data);
void ledInitData(LedData *data);


#endif // LedSM_H
