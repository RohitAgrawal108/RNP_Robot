#pragma once
#include "POT.h"
#include "Motor.h"
#include "At_point.h"

class RNP_Forward
{
public:
    void start_DOWN()
    {
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) > (down_point1 + 5))
        {
            Serial.print("V1POT = ");
            Serial.print(pot_atpoint.Read_vertical1());
            Serial.print("  Ver1 (if) =");
            Serial.print(map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
            test_motor.vertical_motor1(false, down_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) < (down_point1 - 5))
        {
            Serial.print("V1POT = ");
            Serial.print(pot_atpoint.Read_vertical1());
            Serial.print("  Ver1 (else if) =");
            Serial.print(map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
            test_motor.vertical_motor1(true, down_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else
        {
            Serial.print("V1POT = ");
            Serial.print(pot_atpoint.Read_vertical1());
            Serial.print("  Ver1 (else) =");
            Serial.print(map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
            analogWrite(pwmver1_pin, 0);
            all_4_down_completed = all_4_down_completed + 1;
            if (all_4_down_completed == 3)
            {
                start_down_completed = true;
            }
        }
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) > (down_point3 + 5))
        {
            Serial.print("   V3POT = ");
            Serial.print(pot_atpoint.Read_vertical3());
            Serial.print("  Ver3 (if) =");
            Serial.print(map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
            test_motor.vertical_motor3(true, down_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) < (down_point3 - 5))
        {
            Serial.print("   V3POT = ");
            Serial.print(pot_atpoint.Read_vertical3());
            Serial.print("  Ver3 (else if) =");
            Serial.print(map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
            test_motor.vertical_motor3(false, down_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else
        {
            Serial.print("   V3POT = ");
            Serial.print(pot_atpoint.Read_vertical3());
            Serial.print("  Ver3 (else) =");
            Serial.print(map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
            analogWrite(pwmver3_pin, 0);
            all_4_down_completed = all_4_down_completed + 1;
            if (all_4_down_completed == 3)
            {
                start_down_completed = true;
            }
        }

        /*************************************************************************************************************/
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) > (down_point2 + 5))
        {
            Serial.print("   V2POT = ");
            Serial.print(pot_atpoint.Read_vertical2());
            Serial.print("  Ver2 (if) =");
            Serial.print(map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
            test_motor.vertical_motor2(true, down_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) < (down_point2 - 5))
        {
            Serial.print("   V2POT = ");
            Serial.print(pot_atpoint.Read_vertical2());
            Serial.print("  Ver2 (else if) =");
            Serial.print(map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
            test_motor.vertical_motor2(false, down_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else
        {
            Serial.print("   V2POT = ");
            Serial.print(pot_atpoint.Read_vertical2());
            Serial.print("  Ver2 (else) =");
            Serial.print(map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
            analogWrite(pwmver2_pin, 0);
            all_4_down_completed = all_4_down_completed + 1;
            if (all_4_down_completed == 3)
            {
                start_down_completed = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) > (down_point4 + 5))
        {
            Serial.print("   V4POT = ");
            Serial.print(pot_atpoint.Read_vertical4());
            Serial.print("  Ver4 (if) =");
            Serial.println(map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
            test_motor.vertical_motor4(false, down_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) < (down_point4 - 5))
        {
            Serial.print("   V4POT = ");
            Serial.print(pot_atpoint.Read_vertical4());
            Serial.print("      Ver4 (else if) =");
            Serial.println(map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
            test_motor.vertical_motor4(true, down_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else
        {
            Serial.print("   V4POT = ");
            Serial.print(pot_atpoint.Read_vertical4());
            Serial.print("      Ver4 (else) =");
            Serial.println(map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
            analogWrite(pwmver4_pin, 0);
            all_4_down_completed = all_4_down_completed + 1;
            if (all_4_down_completed == 3)
            {
                start_down_completed = true;
            }
        }
    }

    void UP_1_3()
    {
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver4_pin, 0);

        if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) > (up_point1 + 5))
        {
            test_motor.vertical_motor1(false, up_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) < (up_point1 - 5))
        {
            test_motor.vertical_motor1(true, up_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver1_pin, 0);
            all_2_completed_up = all_2_completed_up + 1;
            if (all_2_completed_up == 2)
            {
                up1complete = true;
            }
        }
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) > (up_point3 + 5))
        {
            test_motor.vertical_motor3(true, up_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) < (up_point3 - 5))
        {
            test_motor.vertical_motor3(false, up_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver3_pin, 0);
            all_2_completed_up = all_2_completed_up + 1;
            if (all_2_completed_up == 2)
            {
                up1complete = true;
            }
        }
    }

    void Forward_1_3()
    {
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver3_pin, 0);
        analogWrite(pwmver4_pin, 0);
        if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) > (forward_point1 + 5))
        {
            test_motor.horizonal_motor1(true, forward_point1, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) < (forward_point1 - 5))
        {
            test_motor.horizonal_motor1(false, forward_point1, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor1_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward1complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) > (forward_point3 + 5))
        {
            test_motor.horizonal_motor3(false, forward_point3, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) < (forward_point3 - 5))
        {
            test_motor.horizonal_motor3(true, forward_point3, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor3_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward1complete = true;
            }
        }
        /******************************************BACKWARD_2_4***************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) > (backward_point2 + 5))
        {
            test_motor.horizonal_motor2(false, backward_point2, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) < (backward_point2 - 5))
        {
            test_motor.horizonal_motor2(true, backward_point2, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor2_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward1complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) > (backward_point4 + 5))
        {
            test_motor.horizonal_motor4(false, backward_point4, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) < (backward_point4 - 5))
        {
            test_motor.horizonal_motor4(true, backward_point4, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor4_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward1complete = true;
            }
        }
    }
    void DOWN_1_3()
    {
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver4_pin, 0);

        if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) > (down_point1 + 5))
        {
            test_motor.vertical_motor1(false, down_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150) < (down_point1 - 5))
        {
            test_motor.vertical_motor1(true, down_point1, map(pot_atpoint.Read_vertical1(), ver1_down_till, ver1_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver1_pin, 0);
            all_2_completed_down = all_2_completed_down + 1;
            if (all_2_completed_down == 2)
            {
                down1complete = true;
            }
        }
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        /*************************************************************************************************************/
        if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) > (down_point3 + 5))
        {
            test_motor.vertical_motor3(true, down_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150) < (down_point3 - 5))
        {
            test_motor.vertical_motor3(false, down_point3, map(pot_atpoint.Read_vertical3(), ver3_down_till, ver3_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver3_pin, 0);
            all_2_completed_down = all_2_completed_down + 1;
            if (all_2_completed_down == 2)
            {
                down1complete = true;
            }
        }
    }

    void UP_2_4()
    {
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver3_pin, 0);
        if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) > (up_point2 + 5))
        {
            test_motor.vertical_motor2(true, up_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) < (up_point2 - 5))
        {
            test_motor.vertical_motor2(false, up_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver2_pin, 0);
            all_2_completed_up = all_2_completed_up + 1;
            if (all_2_completed_up == 2)
            {
                up2complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) > (up_point4 + 5))
        {
            test_motor.vertical_motor4(false, up_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) < (up_point4 - 5))
        {
            test_motor.vertical_motor4(true, up_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver4_pin, 0);
            all_2_completed_up = all_2_completed_up + 1;
            if (all_2_completed_up == 2)
            {
                up2complete = true;
            }
        }
    }

    void Forward_2_4()
    {
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver2_pin, 0);
        analogWrite(pwmver3_pin, 0);
        analogWrite(pwmver4_pin, 0);
        if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) > (forward_point2 + 5))
        {
            test_motor.horizonal_motor2(false, forward_point2, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150) < (forward_point2 - 5))
        {
            test_motor.horizonal_motor2(true, forward_point2, map(pot_atpoint.Read_horizontal2(), hor2_backward_till, hor2_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor2_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward2complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) > (forward_point4 + 5))
        {
            test_motor.horizonal_motor4(false, forward_point4, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150) < (forward_point4 - 5))
        {
            test_motor.horizonal_motor4(true, forward_point4, map(pot_atpoint.Read_horizontal4(), hor4_backward_till, hor4_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor4_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward2complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) > (backward_point1 + 5))
        {
            test_motor.horizonal_motor1(true, backward_point1, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150) < (backward_point1 - 5))
        {
            test_motor.horizonal_motor1(false, backward_point1, map(pot_atpoint.Read_horizontal1(), hor1_backward_till, hor1_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor1_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward2complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) > (backward_point3 + 5))
        {
            test_motor.horizonal_motor3(false, backward_point3, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150) < (backward_point3 - 5))
        {
            test_motor.horizonal_motor3(true, backward_point3, map(pot_atpoint.Read_horizontal3(), hor3_backward_till, hor3_forward_till, 0, 150));
        }
        else
        {
            analogWrite(pwmhor3_pin, 0);
            all_4_completed = all_4_completed + 1;
            if (all_4_completed == 4)
            {
                forward2complete = true;
            }
        }
    }
    void DOWN_2_4()
    {
        analogWrite(pwmhor1_pin, 0);
        analogWrite(pwmhor2_pin, 0);
        analogWrite(pwmhor3_pin, 0);
        analogWrite(pwmhor4_pin, 0);
        analogWrite(pwmver1_pin, 0);
        analogWrite(pwmver3_pin, 0);
        
        if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) > (down_point2 + 5))
        {
            test_motor.vertical_motor2(true, down_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150) < (down_point2 - 5))
        {
            test_motor.vertical_motor2(false, down_point2, map(pot_atpoint.Read_vertical2(), ver2_down_till, ver2_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver2_pin, 0);
            all_2_completed_down = all_2_completed_down + 1;
            if (all_2_completed_down == 2)
            {
                down2complete = true;
            }
        }
        /***************************************************************************************************/
        /***************************************************************************************************/
        /***************************************************************************************************/
        if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) > (down_point4 + 5))
        {
            test_motor.vertical_motor4(false, down_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else if (map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150) < (down_point4 - 5))
        {
            test_motor.vertical_motor4(true, down_point4, map(pot_atpoint.Read_vertical4(), ver4_down_till, ver4_up_till, 0, 150));
        }
        else
        {
            analogWrite(pwmver4_pin, 0);
            all_2_completed_down = all_2_completed_down + 1;
            if (all_2_completed_down == 2)
            {
                down2complete = true;
            }
        }
    }
};
