
#pragma once
#include "POT.h"
#include "Motor.h"

motors test_motor;
Pot pot_atpoint;

class AtPoint
{
public:
    void vertical_atpoint(int at_point)
    {
        if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) > (at_point + 5))
        {
            test_motor.vertical_motor1(false, at_point, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) < (at_point - 5))
        {
            test_motor.vertical_motor1(true, at_point, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver1_pin, 0);
        }

        /*****************************************************************************************************/
        /*****************************************************************************************************/
        /*****************************************************************************************************/
        if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) > (at_point + 5))
        {
            test_motor.vertical_motor2(true, at_point, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) < (at_point - 5))
        {
            test_motor.vertical_motor2(false, at_point, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver2_pin, 0);
        }
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) > (at_point + 5))
        {
            test_motor.vertical_motor3(true, at_point, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) < (at_point - 5))
        {
            test_motor.vertical_motor3(false, at_point, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver3_pin, 0);
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) > (at_point + 5))
        {
            test_motor.vertical_motor4(false, at_point, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) < (at_point - 5))
        {
            test_motor.vertical_motor4(true, at_point, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver4_pin, 0);
        }
    }
/**************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
/**************************************************************************************************************************************************************/
    void horizontal_atpoint(int at_point)
    {
        if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) > (at_point + 5))
        {
            test_motor.horizonal_motor1(true, at_point, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) < (at_point - 5))
        {
            test_motor.horizonal_motor1(false, at_point, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor1_pin, 0);
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) > (at_point + 5))
        {
            test_motor.horizonal_motor2(false, at_point, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) < (at_point - 5))
        {
            test_motor.horizonal_motor2(true, at_point, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor2_pin, 0);
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) > (at_point + 5))
        {
            test_motor.horizonal_motor3(false, at_point, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) < (at_point - 5))
        {
            test_motor.horizonal_motor3(true, at_point, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor3_pin, 0);
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) > (at_point + 5))
        {
            test_motor.horizonal_motor4(false, at_point, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) < (at_point - 5))
        {
            test_motor.horizonal_motor4(true, at_point, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor4_pin, 0);
        }
    }
};
