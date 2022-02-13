#include "variables.h"
// #define DEBUG
#pragma once

class Pot
{
public:
    // Vertical Motor's POT INPUT
    int Read_vertical1()
    {
        pot_value = analogRead(verpot1_pin);
        return pot_value;
    }

    int Read_vertical2()
    {
        pot_value = analogRead(verpot2_pin);
        return pot_value;
    }

    int Read_vertical3()
    {
        pot_value = analogRead(verpot3_pin);
        return pot_value;
    }
    int Read_vertical4()
    {
        pot_value = analogRead(verpot4_pin);
        return pot_value;
    }

    // Horizontal Motor's POT INPUT
    int Read_horizontal1()
    {
        pot_value = analogRead(horpot1_pin);
        return pot_value;
    }

    int Read_horizontal2()
    {
        pot_value = analogRead(horpot2_pin);
        return pot_value;
    }

    int Read_horizontal3()
    {
        pot_value = analogRead(horpot3_pin);
        return pot_value;
    }

    int Read_horizontal4()
    {
        pot_value = analogRead(horpot4_pin);
        return pot_value;
    }

    int lim_switch1()
    {
        if (digitalRead(ls_pin1) == LOW)
        {
            at_ground1 = true;
        }
        else
        {
            at_ground1 = false;
        }

        return at_ground1;
    }
    int lim_switch2()
    {
        if (digitalRead(ls_pin2) == LOW)
        {
            at_ground2 = true;
        }
        else
        {
            at_ground2 = false;
        }

        return at_ground2;
    }
    int lim_switch3()
    {
        if (digitalRead(ls_pin3) == LOW)
        {
            at_ground3 = true;
        }
        else
        {
            at_ground3 = false;
        }

        return at_ground3;
    }
    int lim_switch4()
    {
        if (digitalRead(ls_pin4) == LOW)
        {
            at_ground4 = true;
        }
        else
        {
            at_ground4 = false;
        }

        return at_ground4;
    }



    int hall_1(){
        if (digitalRead(hs_pin1) == LOW)
        {
            at_top1 = true;
        }
        else
        {
            at_top1 = false;
        }

        return at_top1;
    }

    int hall_2(){
        if (digitalRead(hs_pin2) == LOW)
        {
            at_top2 = true;
        }
        else
        {
            at_top2 = false;
        }

        return at_top2;
    }
    int hall_3(){
        if (digitalRead(hs_pin3) == LOW)
        {
            at_top3 = true;
        }
        else
        {
            at_top3 = false;
        }

        return at_top3;
    }
    int hall_4(){
        if (digitalRead(hs_pin4) == LOW)
        {
            at_top4 = true;
        }
        else
        {
            at_top4 = false;
        }

        return at_top4;
    }

#ifdef DEBUG
    void print_POT_reading()
    {
        Serial.print("Hor1: ");
        Serial.print(pot_obj.Read_horizontal1());
        Serial.print("    Hor2: ");
        Serial.print(pot_obj.Read_horizontal2());
        Serial.print("    Hor3: ");
        Serial.print(pot_obj.Read_horizontal3());
        Serial.print("    Hor4: ");
        Serial.print(pot_obj.Read_horizontal4());
        Serial.print("    Ver1: ");
        Serial.print(pot_obj.Read_vertical1());
        Serial.print("    Ver2: ");
        Serial.print(pot_obj.Read_vertical2());
        Serial.print("    Ver3: ");
        Serial.print(pot_obj.Read_vertical3());
        Serial.print("    Ver4: ");
        Serial.println(pot_obj.Read_vertical4());
    }
    void Print_limit()
    {
        Serial.print("LIM_S1: ");
        Serial.print(pot_read.lim_switch1());
        Serial.print("         LIM_S2: ");
        Serial.print(pot_read.lim_switch2());
        Serial.print("         LIM_S3: ");
        Serial.print(pot_read.lim_switch3());
        Serial.print("         LIM_S4: ");
        Serial.println(pot_read.lim_switch4());
    }
    
    
    void Print_hall()
    {
        Serial.print("HALL_S1: ");
        Serial.print(pot_read.hall_1());
        Serial.print("         HALL_S2: ");
        Serial.print(pot_read.hall_2());
        Serial.print("         HALL_S3: ");
        Serial.print(pot_read.hall_3());
        Serial.print("         HALL_S4: ");
        Serial.println(pot_read.hall_4());
    }
#endif
};