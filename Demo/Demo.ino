#include <Servo.h>

int myoware1 = A0;

int servo_1 = 7;            // ��ؽ�
int servo_2 = 2;            // ��ؽ�1
int servo_3 = 3;            // ��ؽ�2
int servo_4 = 4;            // ĸָ
int servo_5 = 5;            // ʳָ
int servo_6 = 6;            // ʣ����ָ

void setup() {
    // put your setup code here, to run when Arduino is powered on:
    Serial.begin(9600);
    // ��ʼ��
    pinMode(servo_1,OUTPUT);
    pinMode(servo_2,OUTPUT);
    pinMode(servo_3,OUTPUT);
    pinMode(servo_4,OUTPUT);
    pinMode(servo_5,OUTPUT);
    pinMode(servo_6,OUTPUT);
    // myoware IO口初始化
    Serial.println("开始了！\n");
    // ��λ
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

    // š�Ű���
    if( i > 500)
    {
        Serial.println("š�Ű�����!\n");
        Serial.print("i = ");
        Serial.println(i);
        // Ĵָ��ʳָ
        analogWrite(servo_6,255);        
        analogWrite(servo_2,255);        
        analogWrite(servo_3,255);        
        analogWrite(servo_4,255);        
        analogWrite(servo_5,255);
        // ��ʱ     
        delay(2000);        
        // ��λ 
        analogWrite(servo_6,0);        
        analogWrite(servo_2,0);        
        analogWrite(servo_3,0);        
        analogWrite(servo_4,0);  
        analogWrite(servo_5,0);
        delay(5000);
    }
    // ������
    if( i > 200 && i < 500 ) 
    { 
        Serial.println("�������У�\n");
        Serial.print("i = ");
        Serial.println(i);
        // ������
        analogWrite(servo_4,255);
        analogWrite(servo_5,255);
        analogWrite(servo_6,255);
        // �ӳ�
        delay(2000);
        // ��λ
        analogWrite(servo_4,0);
        analogWrite(servo_5,0);
        analogWrite(servo_6,0);
        delay(5000);
    }
    // �ж��� 
    if(i > 150 && i < 200 )
    {
        Serial.println("�Ӷ����У�\n");
        Serial.print("i = ");
        Serial.println(i);
        // ʳָ��ĸָ
        analogWrite(servo_4,255);
        analogWrite(servo_5,255);
        
        // �ӳ�
        delay(2000);
        analogWrite(servo_4,0);
        analogWrite(servo_5,0);
        delay(5000);
    }
}




