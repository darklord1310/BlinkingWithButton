#include "unity.h"
#include "Message.h"
#include "ButtonSM.h"
#include "mock_Button.h"
#include "mock_turnOnLED.h"
#include "mock_turnOffLED.h"
#include "mock_TimerExpires.h"
#include "LedSM.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*
void test_message_passing_given_send_a_message_LedSate_should_change_state_to_LED_ON(void)
{
  LedData ledData;
  ButtonData buttonData;
  
  ledInitData(&ledData);
  buttonInitData(&buttonData);
  
  //mock
  buttonPressed_ExpectAndReturn(true);
  
  //run
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_OFF, ledData.state);
  
  buttonSM(&buttonData);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL(LED_ON, ledData.state);
}
*/