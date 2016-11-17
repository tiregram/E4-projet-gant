#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;
char incomingByte;
float rx,ry,rz;

#define LED_PIN 13
bool blinkState = false;

void setup()
{

  rx = 0;
  ry = 0;
  rz = 0;
  
    // join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    Serial.begin(38400);

    accelgyro.initialize();

    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

 
    
    rx  = rx + float(gx) * 0.01/131;
    ry  = ry + float(gy) * 0.01/131;
    rz  = rz + float(gz) * 0.01/131;
    
    if (rx < 0)
      rx += 360;
    if (rx > 360)
      rx -= 360;    

    if (ry < 0)
      ry += 360;
    if (ry > 360)
      ry -= 360;

    if (rz < 0)
      rz += 360;
    if (rz > 360)
      rz -= 360;  
    
    if (Serial.available() > 0) {
               
      incomingByte = Serial.read();
      if (incomingByte == 'a')
      {
        Serial.print(ax); Serial.print(",");
        Serial.print(ay); Serial.print(",");
        Serial.print(az); Serial.print(",");
        Serial.print(rx); Serial.print(",");
        Serial.print(ry); Serial.print(",");
        Serial.print(rz); Serial.print("\r\n");
      }
    }
}
