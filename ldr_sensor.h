#ifndef LDR_SENSOR_H
#define LDR_SENSOR_H
#include "servo_cleaner.h"

int pumpMotorPin = 6;              // Base transistor pin connection to the pump motor circuit

int ldrPinValues_1, ldrPin_1 = A2; // Arduino pin connection for the LDR 1 with variable
                                   //  to store the light intensity analog value readings
int ldrPinValues_2, ldrPin_2 = A3; // Arduino pin connection for the LDR 1 with variable
                                   //  to store the light intensity analog value readings
void ldrSetUp(){
     pinMode(pumpMotorPin, OUTPUT);
}

void measure_light_intensity(){
     /*
     Analog light intensity values range from 0 to 1023 where values starting 
     from 0 indicates very high light intensity(simulated with the LEDs' light) 
     hence low LDR resistance 
     
     For values increasing to 1023 it indicates low light intensity
     (might be night time) hence high LDR resistance
     */
        
     ldrPinValues_1 = analogRead(ldrPin_1);
     ldrPinValues_2 = analogRead(ldrPin_2);
     
     Serial.print("\n\nldrPinValues_1: ");
     Serial.print(ldrPinValues_1);
     
     Serial.print(" | ldrPinValues_2: ");
     Serial.print(ldrPinValues_2);
     delay(200);

     /*
     100 is the threshold used to determine whether the LED light is being 
     obstructed by dirt on the panel glass in the if condition below used by the 2 LDRs
     */
     if (ldrPinValues_1 > 100 or ldrPinValues_2 > 100){   
        digitalWrite(pumpMotorPin, HIGH); // Activate pump
        servoWipeCleaner(5, 500); 
        digitalWrite(pumpMotorPin, LOW);  // De-activate pump   
     }
}

#endif
