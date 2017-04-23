//code for rfduino - to be run with Evothings client


//the input pin must be connected to GPIO 4 on the RFduino

#include <RFduinoBLE.h>
int analogPin = 4;
int raw = 0;
double Vin= 3.3;
float Vout= 0;
float R1= 220000;
int R2= 0;
float buffer= 0;

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  RFduinoBLE.advertisementData = "strain";
  RFduinoBLE.advertisementInterval = 500;
  RFduinoBLE.deviceName = "RFduino";
  RFduinoBLE.begin();
  
  
}

  
void loop() 
{
  raw = analogRead(analogPin);
  if(raw) 
  {
    buffer= raw * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    R2= R1 * buffer;
    RFduinoBLE.sendInt(raw);
    delay(250);
  }
  
}
