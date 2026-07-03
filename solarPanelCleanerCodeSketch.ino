#include "ldr_sensor.h"
#include "servo_cleaner.h"
#include "voltage_sensor.h"

float panel_voltageReadings;
int transPin = 8; // pin connection to base of transistor that turns the LEDs ON and OFF

void setup() {
     ldrSetUp();
     myServoSetUp();  
     pinMode(transPin, OUTPUT);
     
     Serial.begin(9600);
//     execute(); // check -> insurance.h
}

void loop() {   
      mainSketch(); 
}

void mainSketch(){ 
     panel_voltageReadings = voltageSensorValues();
     
     if (panel_voltageReadings <= 0.1){   // turns LEDs ON when measured panel voltage is less than or equal to 0.1v
        digitalWrite(transPin, HIGH); 
        measure_light_intensity();       // check ldr_sensor.h file          
     }
     else if (panel_voltageReadings > 1){ // turns OFF LEDs when measured panel voltage is greater than 1v
        digitalWrite(transPin, LOW);     
               
        Serial.print("\n\npanel_voltageReadings: ");
        Serial.print(panel_voltageReadings, 3); // print to 3 decimal places
        Serial.print(" V");
        delay(500);
     }
}
