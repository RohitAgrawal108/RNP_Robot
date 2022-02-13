#include "variables.h"
#include "POT.h"
#include "Step_Motion.h"
#include "At_point.h"
#include "Forward.h"

RNP_Forward forward_obj;

#define DEBUG_inDriver
// #include "Motor.h"
// AtPoint atpoint_obj;
// motors test_motor;
Pot pot_obj;
// Pot pot_read;
// Motion_steps test_step_obj;

void setup()
{
  Serial.begin(115200);
  pinMode(ls_pin1, INPUT_PULLUP);
  pinMode(ls_pin2, INPUT_PULLUP);
  pinMode(ls_pin3, INPUT_PULLUP);
  pinMode(ls_pin4, INPUT_PULLUP);
  pinMode(hs_pin1, INPUT_PULLUP);
  pinMode(hs_pin2, INPUT_PULLUP);
  pinMode(hs_pin3, INPUT_PULLUP);
  pinMode(hs_pin4, INPUT_PULLUP);
  pinMode(pwmver1_pin, OUTPUT);
  pinMode(pwmver3_pin, OUTPUT);
  pinMode(pwmver2_pin, OUTPUT);
  pinMode(pwmver4_pin, OUTPUT);
  timer = 0;
  start_down_again = true;
  // n_cycles = 0;
}

void loop()
{
  // timer = millis();
  /*By Keeping the 1,3 at backmost and 2,4 at frount most*/

  while ((!start_down_completed) && start_down_again)
  {
    forward_obj.start_DOWN();
  }
  delay(1000);
  while (start_down_completed && (!up1complete))
  {
    start_down_again = false;
    forward_obj.UP_1_3();
  }
  delay(1000);
  while (up1complete && (!forward1complete))
  {
    all_2_completed_up = 0;
    start_down_completed = false;
    forward_obj.Forward_1_3();
  }
  delay(1000);
  while (forward1complete && (!down1complete))
  {
    up1complete = false;
    all_4_completed = 0;
    forward_obj.DOWN_1_3();
  }
  delay(1000);
  while (down1complete && (!up2complete))
  {
    forward1complete = false;
    all_2_completed_down = 0;
    forward_obj.UP_2_4();
  }
  delay(1000);
  while (up2complete && (!forward2complete))
  {
    all_2_completed_up = 0;
    down1complete = false;
    forward_obj.Forward_2_4();
  }
  delay(1000);
  while (forward2complete && (!down2complete))
  {
    up2complete = false;
    all_4_completed = 0;
    forward_obj.DOWN_2_4();
  }
  delay(1000);
  if (down2complete)
  {
    forward2complete = false;
    start_down_completed = true;
    down2complete = false;
    //  n_cycles = n_cycles + 1;
  }

  //  if (start_down_again)
  //  {
  //    forward_obj.start_DOWN();
  //  }
  //  if (timer > (2000 + (12000*n_cycles)) && timer < (4000 + (12000*n_cycles)))
  //  {
  //
  //    if (start_down_completed)
  //    {
  //      start_down_again = false;
  //      forward_obj.UP_1_3();
  //    }
  //  }
  //  if (timer > (4000 + (12000*n_cycles)) && timer < (6000 + (12000*n_cycles)))
  //  {
  //    if (up1complete)
  //    {
  //      all_2_completed_up = 0;
  //      start_down_completed = false;
  //      forward_obj.Forward_1_3();
  //    }
  //  }
  //  if (timer > (6000 + (12000*n_cycles)) && timer < (8000 + (12000*n_cycles)))
  //  {
  //    if (forward1complete)
  //    {
  //      up1complete = false;
  //      all_4_completed = 0;
  //      forward_obj.DOWN_1_3();
  //    }
  //  }
  //  if (timer > (8000 + (12000*n_cycles)) && timer < (10000 + (12000*n_cycles)))
  //  {
  //    if (down1complete)
  //    {
  //      forward1complete = false;
  //      all_2_completed_down = 0;
  //      forward_obj.UP_2_4();
  //    }
  //  }
  //  if (timer > (10000 + (12000*n_cycles)) && timer < (12000 + (12000*n_cycles)))
  //  {
  //    if (up2complete)
  //    {
  //      all_2_completed_up = 0;
  //      down1complete = false;
  //      forward_obj.Forward_2_4();
  //    }
  //  }
  //  if (timer > (12000 + (12000*n_cycles)) && timer < (14000 + (12000*n_cycles)))
  //  {
  //    if (forward2complete)
  //    {
  //      up2complete = false;
  //      all_4_completed = 0;
  //      forward_obj.DOWN_2_4();
  //    }
  //  }
  //    if (down2complete)
  //    {
  //      forward2complete = false;
  //      start_down_completed = true;
  //      down2complete = false;
  //      n_cycles = n_cycles + 1;
  //    }
}
