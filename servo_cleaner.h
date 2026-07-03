#ifndef SERVO_CLEANER_H
#define SERVO_CLEANER_H

#include <Servo.h>
Servo myServo; // instance of a servo object
int servoPin = 7;

void myServoSetUp(){
     myServo.attach(servoPin);
     myServo.write(0); // start position
     delay(2000);
}

void servoWipeCleaner(int duration_1, int duration_2){
     /*
     The following for loops use a smooth clockwise and anticlockwise motion to 
      move brush connected to the servo horn to clean the glass panel above the panel.
       
     duration_1 is for micro delays while moving through angles.
     duration_2 is for pausing in between the execution of the 2 for loops to create a
      smooth glide back and forth sweep motion of the servo horn.
     */
     for (int i = 0; i < 100; i++){ // clockwise sweep motion
          myServo.write(i);
          delay(duration_1); 
     }
     delay(duration_2);
     
     for (int i = 100; i > 1; i--){ // anti-clockwise sweep motion
          myServo.write(i);
          delay(duration_1); 
     }
     delay(duration_2);
}

#endif
