#include <Servo.h>

int myoware1 = A0;

int servo_1 = 7;            // 肘关节
int servo_2 = 2;            // 腕关节1
int servo_3 = 3;            // 腕关节2
int servo_4 = 4;            // 母指
int servo_5 = 5;            // 食指
int servo_6 = 6;            // 剩余手指

void setup() {
    // put your setup code here, to run when Arduino is powered on:
    Serial.begin(9600);
    // 初始化
    pinMode(servo_1,OUTPUT);
    pinMode(servo_2,OUTPUT);
    pinMode(servo_3,OUTPUT);
    pinMode(servo_4,OUTPUT);
    pinMode(servo_5,OUTPUT);
    pinMode(servo_6,OUTPUT);
    // myoware IO鍙ｅ垵濮嬪寲
    Serial.println("寮�濮嬩簡锛乗n");
    // 复位
    analogWrite(servo_1,0);
    analogWrite(servo_2,0);
    analogWrite(servo_3,0);
    analogWrite(servo_4,0);
    analogWrite(servo_5,0);
    analogWrite(servo_6,0);
}

void loop()
{
    int i = analogRead(myoware1);
    Serial.println(i);
    delay(1000);

    // 拧门把手
    if( i > 500)
    {
        Serial.println("拧门把手中!\n");
        Serial.print("i = ");
        Serial.println(i);
        // 拇指和食指
        analogWrite(servo_6,255);        
        analogWrite(servo_2,255);        
        analogWrite(servo_3,255);        
        analogWrite(servo_4,255);        
        analogWrite(servo_5,255);
        // 延时     
        delay(2000);        
        // 复位 
        analogWrite(servo_6,0);        
        analogWrite(servo_2,0);        
        analogWrite(servo_3,0);        
        analogWrite(servo_4,0);  
        analogWrite(servo_5,0);
        delay(5000);
    }
    // 端盘子
    if( i > 200 && i < 500 ) 
    { 
        Serial.println("端盘子中！\n");
        Serial.print("i = ");
        Serial.println(i);
        // 做动作
        analogWrite(servo_4,255);
        analogWrite(servo_5,255);
        analogWrite(servo_6,255);
        // 延迟
        delay(2000);
        // 复位
        analogWrite(servo_4,0);
        analogWrite(servo_5,0);
        analogWrite(servo_6,0);
        delay(5000);
    }
    // 夹东西 
    if(i > 150 && i < 200 )
    {
        Serial.println("加东西中！\n");
        Serial.print("i = ");
        Serial.println(i);
        // 食指和母指
        analogWrite(servo_4,255);
        analogWrite(servo_5,255);
        
        // 延迟
        delay(2000);
        analogWrite(servo_4,0);
        analogWrite(servo_5,0);
        delay(5000);
    }
}




