#include <Wire.h>                // Library for I2C communication
#include <LiquidCrystal_I2C.h>   // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

int right_forward = 7;
int right_backward = 6;
int left_forward = 5;
int left_backward = 4;
int pwm_left = 3;
int pwm_right = 2;
int pwm_speedR = 200;
int pwm_speedL = 200;

int Threshold = 200;

void forward();
void left();
void right();
void backward();

void forward()
{
    digitalWrite(right_forward, HIGH);
    digitalWrite(right_backward, LOW);
    digitalWrite(left_forward, HIGH);
    digitalWrite(left_backward, LOW);
    analogWrite(pwm_left,255);
    analogWrite(pwm_right,255);
}

void backward()
{
    digitalWrite(right_forward, LOW);
    digitalWrite(right_backward, HIGH);
    digitalWrite(left_forward, LOW);
    digitalWrite(left_backward, HIGH);
    analogWrite(pwm_left,255);
    analogWrite(pwm_right,255);
}

void left()
{
    digitalWrite(right_forward, HIGH);
    digitalWrite(right_backward, LOW);
    digitalWrite(left_forward, LOW);
    digitalWrite(left_backward, LOW);
    analogWrite(pwm_left,255);
    analogWrite(pwm_right,255);
}

void right()
{
    digitalWrite(right_forward, LOW);
    digitalWrite(right_backward, LOW);
    digitalWrite(left_forward, HIGH);
    digitalWrite(left_backward, LOW);
    analogWrite(pwm_left, 255);
    analogWrite(pwm_right,255);
}

void stopbot()
{
    digitalWrite(right_forward, LOW);
    digitalWrite(right_backward, LOW);
    digitalWrite(left_forward, LOW);
    digitalWrite(left_backward, LOW);
    analogWrite(pwm_left,0);
    analogWrite(pwm_right,0);
}

void setup() {
  
    Serial.begin(9600);
    
    lcd.init();
    lcd.backlight();

    pinMode(right_forward, OUTPUT);
    pinMode(right_backward, OUTPUT);
    pinMode(left_forward, OUTPUT);
    pinMode(left_backward, OUTPUT);
    pinMode(pwm_left, OUTPUT);
    pinMode(pwm_right, OUTPUT);
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);

    /*
    //LCD - Runs only once to print
    lcd.setCursor(2, 0);
    lcd.print("Wifey Ayaany");
    lcd.setCursor(0, 1); 
    lcd.print("I'm a Loyal wife.");
    */
      
}

void loop() {
  
     //Read and store input from all 4 sensors
     int MiddleLeft = analogRead(A0);    //Middle1
     int MiddleRight = analogRead(A1);    //Middle2
     int Right = analogRead(A2);      //Right
     int Left = analogRead(A3);       //LEFT

     /*
     //Serial Monitor Diagnostic
     Serial.println("------------------------------------------------------------------");
     Serial.print("-Left Sensor: ");
     Serial.println(Left);
     Serial.print("-MiddleLeft Sensor: ");
     Serial.println(MiddleLeft);
     Serial.print("-MiddleRight Sensor: ");
     Serial.println(MiddleRight);
     Serial.print("-Right Sensor: ");
     Serial.println(Right);
     //delay(1000); //Enable only when diagnosing sensors to establish a delay between sensor readings.
     */
     
     //LCD - Displays Sensor readings in the second row
     lcd.setCursor(2, 0);
     lcd.print("FAUS - BOT"); 
     lcd.setCursor(1, 1); //(column, row) (counting starts at 0!).
     lcd.print(Left);
     lcd.print("  ");
     lcd.setCursor(5, 1); //(column, row) (counting starts at 0!).
     lcd.print(MiddleLeft);
     lcd.print("  ");
     lcd.setCursor(9, 1); //(column, row) (counting starts at 0!).
     lcd.print(MiddleRight);
     lcd.print("  ");
     lcd.setCursor(13, 1); //(column, row) (counting starts at 0!).
     lcd.print(Right);
     lcd.print("  ");  


     //LFR Code
     if (Left < Threshold && MiddleLeft > Threshold && MiddleRight > Threshold && Right < Threshold)
        forward();
     else if (Left < Threshold && MiddleLeft < Threshold && MiddleRight > Threshold && Right > Threshold)
        right();
     else if (Left < Threshold && MiddleLeft < Threshold && MiddleRight < Threshold && Right > Threshold)
        right(); 
     else if (Left < Threshold && MiddleLeft > Threshold && MiddleRight > Threshold && Right > Threshold)
        right();
     else if (Left > Threshold && MiddleLeft > Threshold && MiddleRight < Threshold && Right < Threshold) 
        left();
     else if (Left > Threshold && MiddleLeft < Threshold && MiddleRight < Threshold && Right < Threshold)
        left();   
     else if (Left > Threshold && MiddleLeft > Threshold && MiddleRight > Threshold && Right < Threshold) 
        left();
      
}

//Note: PWM needs to be adjusted for each turn. TBD
