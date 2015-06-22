#include "TimerExpires.h"

static uint32_t currentTime = 0 ;
  
uint32_t getCurrentTime()
{
	static uint32_t counter = 0 ;

	if (counter++ >= 100)
	{
		counter = 0 ;
		currentTime ++ ;
	}

	return currentTime ;
}



int isTimerExpires(int timeConstraint)
{
	static uint32_t previousTime = 0;

	if( getCurrentTime() - previousTime == timeConstraint)
	{
		previousTime = getCurrentTime();
		return 1;
	}
	else
		return 0;
}