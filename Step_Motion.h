#include "Motor.h"
#include "variables.h"
#include "POT.h"
#pragma once

motors Motor_obj;
Pot pot_read;


class Motion_steps
{
    public:

    void first_up(){
        Motor_obj.vertical_motor1(true,150,map(pot_read.Read_vertical1(),420,240,0,150));
        Motor_obj.vertical_motor3(false,150,map(pot_read.Read_vertical3(),750,620,0,150));
    }
    void second_up(){
        Motor_obj.vertical_motor2(false,150,map(pot_read.Read_vertical2(),720,900,0,150));
        Motor_obj.vertical_motor4(true,150,map(pot_read.Read_vertical4(),780,970,0,150));
    }

    void first_down(){
        Motor_obj.vertical_motor1(false,0,map(pot_read.Read_vertical1(),420,240,0,150));
        Motor_obj.vertical_motor3(true,0,map(pot_read.Read_vertical3(),750,620,0,150));
    }
    void second_down(){
        Motor_obj.vertical_motor2(true,0,map(pot_read.Read_vertical2(),720,900,0,150));
        Motor_obj.vertical_motor4(false,0,map(pot_read.Read_vertical4(),780,970,0,150));
    }

    void first_forward(){
        Motor_obj.horizonal_motor1(false,150,map(pot_read.Read_horizontal1(),1000,800,0,150));
        Motor_obj.horizonal_motor3(true,150,map(pot_read.Read_horizontal3(),250,450,0,150));
    }
    void second_forward(){
        Motor_obj.horizonal_motor2(true,150,map(pot_read.Read_horizontal2(),410,200,0,150));
        Motor_obj.horizonal_motor4(true,150,map(pot_read.Read_horizontal4(),430,640,0,150));
    }
    void first_backward(){
        Motor_obj.horizonal_motor1(true,0,map(pot_read.Read_horizontal1(),1000,800,0,150));
        Motor_obj.horizonal_motor3(false,0,map(pot_read.Read_horizontal3(),250,450,0,150));
    }
    void second_backward(){
        Motor_obj.horizonal_motor2(false,0,map(pot_read.Read_horizontal2(),410,200,0,150));
        Motor_obj.horizonal_motor4(false,0,map(pot_read.Read_horizontal4(),430,640,0,150));
    }
};