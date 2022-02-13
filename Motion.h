#include "Step_Motion.h"
#include "variables.h"
#include "POT.h"
#include "Motor.h"
#pragma once
Motion_steps step_obj;

class Motion{
    public:

    void forward(){
        // Part1
        for (int i = pot_read.Read_vertical1(); i < (150); i = pot_read.Read_vertical1())
        {
            step_obj.first_up();
        }
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver3_pin, 0);
        for (int i = pot_read.Read_horizontal1(); i < (150); i = pot_read.Read_horizontal1())
        {
            step_obj.first_forward();
        }
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        for (int i = pot_read.Read_vertical1(); i < (0); i = pot_read.Read_vertical1())
        {
            step_obj.first_down();
        }
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver3_pin, 0);
        for (int i = pot_read.Read_horizontal2(); i < (0); i = pot_read.Read_horizontal2())
        {
            step_obj.second_backward();
        }
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor3_pin, 0);

        // Part 2
        for (int i = pot_read.Read_vertical2(); i < (150); i = pot_read.Read_vertical2())
        {
            step_obj.second_up();
        }
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver4_pin, 0);
        for (int i = pot_read.Read_horizontal2(); i < (150); i = pot_read.Read_horizontal2())
        {
            step_obj.second_forward();
        }
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        for (int i = pot_read.Read_vertical2(); i < (0); i = pot_read.Read_vertical2())
        {
            step_obj.second_down();
        }
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver4_pin, 0);
        for (int i = pot_read.Read_horizontal1(); i < (0); i = pot_read.Read_horizontal1())
        {
            step_obj.first_backward();
        }
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor4_pin, 0);
    }

    // void backward(){

    // }
    // void right(){
        
    // }
};