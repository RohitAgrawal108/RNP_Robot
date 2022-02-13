#ifndef _variables_H_
#define _variables_H_

// PIN numbers Variables
int pwmver1_pin = 10;
int pwmver2_pin = 4;
int pwmver3_pin = 6;
int pwmver4_pin = 8;
int dirver1_pin = 28;
int dirver2_pin = 24;
int dirver3_pin = 25;
int dirver4_pin = 29;

int pwmhor1_pin = 9;
int pwmhor2_pin = 3;
int pwmhor3_pin = 5;
int pwmhor4_pin = 7;
int dirhor1_pin = 26;
int dirhor2_pin = 22;
int dirhor3_pin = 23;
int dirhor4_pin = 27;

int verpot1_pin = A8;
int verpot2_pin = A9;
int verpot3_pin = A10;
int verpot4_pin = A11;
int horpot1_pin = A12;
int horpot2_pin = A13;
int horpot3_pin = A14;
int horpot4_pin = A15;

int ls_pin1 = 44;
int ls_pin2 = 30;
int ls_pin3 = 32;
int ls_pin4 = 42;

int hs_pin1;
int hs_pin2;
int hs_pin3;
int hs_pin4;

int at_ground1 = 0;
int at_ground2 = 0;
int at_ground3 = 0;
int at_ground4 = 0;

int at_top1 = 0;
int at_top2 = 0;
int at_top3 = 0;
int at_top4 = 0;
/**************************/

// PID Related Variables
int lastP = 0;
int P;
int I;
int D;
int setpoint;
int error;
int pos;
int output_value;
int ans;
int value;
/**************************/

// Setpoints 
int ver1_up_till = 460;//
int ver2_up_till = 515;//
int ver3_up_till = 255;//
int ver4_up_till = 595;//
int ver1_down_till = 550;//
int ver2_down_till = 430;//
int ver3_down_till = 340;//
int ver4_down_till = 530;//

int hor1_forward_till = 395;
int hor2_forward_till = 425;
int hor3_forward_till = 660;
int hor4_forward_till = 720;
int hor1_backward_till = 575;
int hor2_backward_till = 230;
int hor3_backward_till = 480;
int hor4_backward_till = 545;
/****************************/

int up_point1 = 140;
int up_point2 = 140;
int up_point3 = 140;
int up_point4 = 140;

int down_point1 = 10;
int down_point2 = 10;
int down_point3 = 10;
int down_point4 = 10;

int forward_point1 = 140;
int forward_point2 = 140;
int forward_point3 = 140;
int forward_point4 = 140;

int backward_point1 = 10;
int backward_point2 = 10;
int backward_point3 = 10;
int backward_point4 = 10;

int pot_value = 0;

unsigned long timer;

int start_down_completed = false;
int up1complete = false;
int down1complete = false;
int up2complete = false;
int down2complete = false;
int forward1complete = false;
int forward2complete = false;

int all_4_completed = 0;
int all_2_completed_up = 0;
int all_2_completed_down = 0;

int all_4_down_completed = 0;

int start_down_again;

int n_cycles;

#endif
