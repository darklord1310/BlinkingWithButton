#include "unity.h"
#include "ButtonSM.h"
#include "Message.h"
#include "State.h"
#include "mock_Button.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_given_buttonPress_is_true_when_state_is_Release_ButtonSM_should_send_changeStateMsg_and_change_state_to_Press(void)
{
	ButtonData data;
  buttonInitData(&data); //initialize buttonData, state is DO_NOTHING
  
  //mock
  buttonPressed_IgnoreAndReturn(true);
  
  //run
  buttonSM(&data);
  
  TEST_ASSERT_EQUAL(Press, data.state);
  TEST_ASSERT_EQUAL(CHANGE_MODE, msg);
  
}

void test_given_buttonPress_is_true_when_state_is_Press_ButtonSM_should_send_DO_NOTHING_and_stay_at_Press_state(void)
{
	ButtonData data;
  buttonInitData(&data); //initialize buttonData, state is DO_NOTHING
  
  //mock
  buttonPressed_IgnoreAndReturn(true);         //button pressed, state change to Press, send changeStateMsg
  buttonPressed_IgnoreAndReturn(true);         //button pressed, state stay at Press, do_nothing
  
  //run
  buttonSM(&data);
  buttonSM(&data);
  TEST_ASSERT_EQUAL(Press, data.state);
  TEST_ASSERT_EQUAL(DO_NOTHING, msg);
  
}


void test_given_buttonPress_is_false_ButtonSM_should_send_DO_NOTHING_and_change_state_to_Release(void)
{
	ButtonData data;
  buttonInitData(&data); //initialize buttonData, state is DO_NOTHING
  
  //mock
  buttonPressed_IgnoreAndReturn(true);         //button pressed, state change to Press, send changeStateMsg
  buttonPressed_IgnoreAndReturn(false);        //button release, state change to Release, do_nothing
  
  //run
  buttonSM(&data);
  buttonSM(&data);
  TEST_ASSERT_EQUAL(Release, data.state);
  TEST_ASSERT_EQUAL(DO_NOTHING, msg);
  
}