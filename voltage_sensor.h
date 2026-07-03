#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

const int voltagePin = A0;
const float ADC_REF = 5.0;  // arduino voltage reference
const int ADC_RES = 1023.0; // 10 bit ADC Resolution value mapped to arduino reference voltage
                            // 0 - 1023 -> 0 - 5v(arduino reference voltage) used when  
                            // getting voltage reading of ADC raw values by arduino

const float DIV_RATIO = 5.10; // voltage divider ratio used to scale up the voltage value because
                              // the real voltage is 5.10 × bigger than what Arduino measures
                              // and also because hardware divider scales voltage down
                              
int analogValues;  // used by the arduino to get the ADC values
float vOut, vIn;

float voltageSensorValues(){
      analogValues = analogRead(voltagePin);
      vOut = (analogValues * ADC_REF) / ADC_RES;
      vIn = vOut * DIV_RATIO;
      return vIn;
}

#endif
