#include "unity.h"
#include "LedSM.h"
#include "Message.h"
#include "mock_turnOffLED.h"
#include "mock_turnOnLED.h"
#include "mock_TimerExpires.h"
#include "mock_Button.h"
#include "ButtonSM.h"
#include <stdbool.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_given_initial_state_should_go_to_LEDOFF_state(void)
{
  LedData data;
  ledInitData(&data);
  TEST_ASSERT_EQUAL( Initial, data.state);
  ledSM(&data);
  TEST_ASSERT_EQUAL( LED_OFF, data.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);
  
}


void test_given_LEDOFF_state_should_go_to_LEDBlinkingON_state_if_button_pressed(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LED_OFF;      //change LED state to LED_OFF
  
  
  //mock
  buttonPressed_IgnoreAndReturn(true);
  turnOffLED_Expect();
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(CHANGE_MODE , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LEDBlinking_ON, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}


void test_given_LEDBlinkingON_state_should_go_to_LEDON_state_if_button_pressed(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LEDBlinking_ON;      //change LED state to LEDBlinking_ON
  
  
  //mock
  buttonPressed_IgnoreAndReturn(true);
  turnOnLED_Expect();
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(CHANGE_MODE , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LED_ON, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}


void test_given_LEDBlinkingON_state_should_go_to_LEDBlinkingOff_state_if_timer_reached_and_button_is_not_press(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LEDBlinking_ON;      //change LED state to LEDBlinking_ON
  
  
  //mock
  buttonPressed_IgnoreAndReturn(false);
  turnOnLED_Expect();
  isTimerExpires_ExpectAndReturn(500,1);
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LEDBlinking_OFF, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}



void test_given_LEDBlinkingOFF_state_should_go_to_LEDBlinkingON_state_if_timer_reached_and_button_is_not_press(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LEDBlinking_OFF;      //change LED state to LEDBlinking_OFF
  
  
  //mock
  buttonPressed_IgnoreAndReturn(false);
  turnOffLED_Expect();
  isTimerExpires_ExpectAndReturn(500,1);
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LEDBlinking_ON, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}



void test_given_LEDBlinkingOff_state_should_go_to_LEDON_state_if_button_pressed(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LEDBlinking_OFF;      //change LED state to LEDBlinking_Off
  
  
  //mock
  buttonPressed_IgnoreAndReturn(true);
  turnOffLED_Expect();
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(CHANGE_MODE , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LED_ON, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}



void test_given_LEDON_state_should_go_to_LEDOFF_state_if_button_pressed(void)
{
  //initialization
  LedData ledData;
  ButtonData buttonData;
  buttonInitData(&buttonData);
  ledInitData(&ledData);
  ledData.state = LED_ON;      //change LED state to LED_ON
  
  
  //mock
  buttonPressed_IgnoreAndReturn(true);
  turnOnLED_Expect();
  
  
  //run
  buttonSM(&buttonData);
  TEST_ASSERT_EQUAL(CHANGE_MODE , msg);
  ledSM(&ledData);
  TEST_ASSERT_EQUAL( LED_OFF, ledData.state);
  TEST_ASSERT_EQUAL(DO_NOTHING , msg);

}







