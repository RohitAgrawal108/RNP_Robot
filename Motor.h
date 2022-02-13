#include "variables.h"
#include "POT.h"
#include "PID.h"
// #define DEBUG
#pragma once

class motors
{
public:
    int PID_positive(float Kp, float Kd, float Ki, int setpoint, int pos)
    {
        lastP = P;
        P = setpoint - pos;
        D = P - lastP;
        if (pos >= setpoint - 10)
        {
            I += P;
            // output_value = Kp * P + Kd * D + Ki * I;
            output_value = 0;
#ifdef DEBUG
            Serial.print("P= ");
            Serial.println(Kp * P);

            Serial.print("Kd2*D");
            Serial.println(Kd * D);

            Serial.print("I");
            Serial.println(Ki * I);

            Serial.print("output_value");
            Serial.println(output_value);
#endif
        }
        else
        {
            // output_value = Kp * P + Kd * D;
            output_value = 50;
        }
        /******************************************/


        ans = constrain(output_value, 0,80);
#ifdef DEBUG
        Serial.print("Kp * P = ");
        Serial.print(Kp * P);

        Serial.print("     Kd2*D =");
        Serial.print(Kd * D);

        Serial.print("     Ans = ");
        Serial.println(ans);
#endif
        return ans;
    }

    int PID_negative(float Kp, float Kd, float Ki, int setpoint, int pos)
    {
        lastP = P;
        P = setpoint - pos;
        D = P - lastP;
        if (pos <= setpoint + 10)
        {
            // I += P;
            // output_value = Kp * P + Kd * D + Ki * I;
            output_value = 0;
#ifdef DEBUG
            Serial.print("P= ");
            Serial.println(Kp * P);

            Serial.print("Kd2*D");
            Serial.println(Kd * D);

            Serial.print("I");
            Serial.println(Ki * I);

            Serial.print("output_value");
            Serial.println(output_value);
#endif
        }
        else
        {
            // output_value = Kp * P + Kd * D;
            output_value = 50;
        }

        // ans = constrain((-1) * output_value, 0, 80);
        ans = constrain(output_value, 0,80);
#ifdef DEBUG
        Serial.print("Kp * P = ");
        Serial.print(Kp * P);

        Serial.print("     Kd2*D =");
        Serial.print(Kd * D);

        Serial.print("     Ans = ");
        Serial.println(ans);
#endif
        return ans;
    }
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/

    void vertical_motor1(int dir, int setpoint, int pos)
    {
        if (dir)//UP
        {
            digitalWrite(dirver1_pin, HIGH);
            value = PID_positive(Kv1u[0],Kv1u[1], Kv1u[2], setpoint, pos);
            analogWrite(pwmver1_pin, value);
        }
        else//DOWN
        {
            digitalWrite(dirver1_pin, LOW);
            value = PID_negative(Kv1d[0],Kv1d[1], Kv1d[2], setpoint, pos);
            analogWrite(pwmver1_pin, value);
        }
    }
    void vertical_motor2(int dir, int setpoint, int pos)
    {
        if (dir) //DOWN
        {
            digitalWrite(dirver2_pin, HIGH);
            value = PID_negative(Kv2d[0], Kv2d[1], Kv2d[2], setpoint, pos);
            analogWrite(pwmver2_pin, value);
        }
        else //UP
        {
            digitalWrite(dirver2_pin, LOW);
            value = PID_positive(Kv2u[0], Kv2u[1], Kv2u[2], setpoint, pos);
            analogWrite(pwmver2_pin, value);
        }
    }
    void vertical_motor3(int dir, int setpoint, int pos)
    {
        if (dir) //DOWN
        {
            digitalWrite(dirver3_pin, HIGH);
            value = PID_negative(Kv3d[0], Kv3d[1], Kv3d[2], setpoint, pos);
            analogWrite(pwmver3_pin, value);
        }
        else //UP
        {
            digitalWrite(dirver3_pin, LOW);
            value = PID_positive(Kv3u[0], Kv3u[1], Kv3u[2], setpoint, pos);
            analogWrite(pwmver3_pin, value);
        }
    }
    void vertical_motor4(int dir, int setpoint, int pos)
    {
        if (dir) //UP
        {
            digitalWrite(dirver4_pin, HIGH);
            value = PID_positive(Kv4u[0], Kv4u[1], Kv4u[2], setpoint, pos);
            analogWrite(pwmver4_pin, value);
        }
        else//DOWN
        {
            digitalWrite(dirver4_pin, LOW);
            value = PID_negative(Kv4d[0], Kv4d[1], Kv4d[2], setpoint, pos);
            analogWrite(pwmver4_pin, value);
        }
    }

    void horizonal_motor1(int dir, int setpoint, int pos)
    {
        if (dir) //BACKWARD
        {
          Serial.println("HOR1 BACKWARD");
            digitalWrite(dirhor1_pin, HIGH);
            value = PID_negative(Kh1[0], Kh1[1], Kh1[2], setpoint, pos);
            analogWrite(pwmhor1_pin, value);
        }
        else //FORWARD
        {
          Serial.println("HOR1 FORWARD");
            digitalWrite(dirhor1_pin, LOW);
            value = PID_positive(Kh1[0], Kh1[1], Kh1[2], setpoint, pos);
            analogWrite(pwmhor1_pin, value);
        }
    }
    void horizonal_motor2(int dir, int setpoint, int pos)
    {
        if (dir) //FORWARD
        {
          Serial.println("HOR2 FORWARD");
            digitalWrite(dirhor2_pin, HIGH);
            value = PID_positive(Kh2[0], Kh2[1], Kh2[2], setpoint, pos);
            analogWrite(pwmhor2_pin, value);
        }
        else //BACKWARD
        {
          Serial.println("HOR2 BACKWARD");
            digitalWrite(dirhor2_pin, LOW);
            value = PID_negative(Kh2[0], Kh2[1], Kh2[2], setpoint, pos);
            analogWrite(pwmhor2_pin, value);
        }
    }
    void horizonal_motor3(int dir, int setpoint, int pos)
    {
        if (dir) //FORWARD
        {
          Serial.println("HOR3 FORWARD");
            digitalWrite(dirhor3_pin, HIGH);
            value = PID_positive(Kh3[0], Kh3[1], Kh3[2], setpoint, pos);
            analogWrite(pwmhor3_pin, value);
        }
        else //BACKWARD
        {
          Serial.println("HOR3 BACKWARD");
            digitalWrite(dirhor3_pin, LOW);
            value = PID_negative(Kh3[0], Kh3[1], Kh3[2], setpoint, pos);
            analogWrite(pwmhor3_pin, value);
        }
    }
    void horizonal_motor4(int dir, int setpoint, int pos)
    {
        if (dir) //FORWARD
        {
          Serial.println("HOR4 FORWARD");
            digitalWrite(dirhor4_pin, HIGH);
            value = PID_positive(Kh4[0], Kh4[1], Kh4[2], setpoint, pos);
            analogWrite(pwmhor4_pin, value);
        }
        else //BACKWARD
        {
          Serial.println("HOR4 BACKWARD");
            digitalWrite(dirhor4_pin, LOW);
            value = PID_negative(Kh4[0], Kh4[1], Kh4[2], setpoint, pos);
            analogWrite(pwmhor4_pin, value);
        }
    }
};
