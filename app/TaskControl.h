#ifndef TaskControl_H
#define TaskControl_H

#include <stdint.h>

typedef enum {
                RUNNING,
                READY,
                SPAWNED,
                TERMINATED,
                BLOCKING,
                SLEEPING
}TaskState;

typedef struct {
                  TaskState state;
                  uint32_t stack;
}Tcb;





#endif // TaskControl_H
