#include "I2Cdev.h"
#include "MPU6050.h"

#include <map>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


typedef struct 
{
  stack;
}

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t vx, vy, vz;
int16_t px, py, pz;
int16_t gx, gy, gz;
char incomingByte;
float rx,ry,rz;

enum GANT_CHOISE_CAPTEUR
  {
    OPT_A   = 0X1,
    OPT_V   = 0X1 << 1,
    OPT_P   = 0X1 << 2,
    OPT_G   = 0X1 << 3,
    OPT_R   = 0X1 << 3,
    OPT_Ff1 = 0X1 << 4,
    OPT_Ff2 = 0X1 << 5,
    OPT_Ff3 = 0X1 << 6
  };



// Finger 1 flex 1
float Ff1, Ff2, Ff3;

int pin_Ff1 = 1;
int pin_Ff2 = 2;
int pin_Ff3 = 3;

#define LED_PIN 13
bool blinkState = false;

void setup()
{
  //start serial with message
  Serial.begin(38400);
  Serial.print("!");
  Serial.print("{'name':'GANT', 'version':'1.0', 'capteur':[Ff1,Ff2,Ff3,A,V,P,G,R],'cmd':['help','status','r<in_list>','R<cap_list>','s<out_list>t<val>']}");
  
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    
        Wire.begin();
        
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    

    accelgyro.initialize();

    pinMode(LED_PIN, OUTPUT);
}


void a()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    rx  = rx + float(gx) * 0.01/131;
    ry  = ry + float(gy) * 0.01/131;
    rz  = rz + float(gz) * 0.01/131;

    vx  = vx + float(ax) * 0.01/131;
    vy  = vy + float(ay) * 0.01/131;
    vz  = vz + float(az) * 0.01/131;
    
    px  = px + vx;
    py  = py + vy;
    pz  = pz + vz;
    
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


void read_acelero()
{
  
  }

void read_flex()
{
  Ff1 = analogRead(pin_Ff1);
  Ff2 = analogRead(pin_Ff2);
  Ff3 = analogRead(pin_Ff3);
    
  }

String parseInput(String func, String param)
{
  String returnvar = String();
  
  if ((in & OPT_A) == OPT_A)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.A");
      returnvar += String("A:["+String(ax)+","+ay+","+az+"],");
    }
    
  if ((in & OPT_V) == OPT_V)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.V");
      returnvar += String("V:["+String(vx)+","+vy+","+vz+"],");
    }
    
  if ((in & OPT_P) == OPT_P)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.P");
      returnvar += String("P:["+String(px)+","+py+","+pz+"],");
    }


    if ((in & OPT_G) == OPT_G)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.G");
      returnvar += String("G:["+String(gx)+","+gy+","+gz+"]");
    }

    if ((in & OPT_R) == OPT_R)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.R");
      returnvar += String("R:["+String(rx)+","+ry+","+rz+"]");
    }

    if ((in & OPT_Ff1) == OPT_Ff1)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.Ff1");
      returnvar += String("Ff1:"+String(Ff1)+",");
    }

    if ((in & OPT_Ff2) == OPT_Ff2)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.Ff2");
      returnvar += String("Ff2:"+String(Ff2)+",");
    }
     if ((in & OPT_Ff3) == OPT_Ff3)
    {
      //Serial.print("GANT_CHOISE_CAPTEUR.Ff3");
      returnvar += String("Ff3:"+String(Ff3)+",");
    }

    
    return returnvar;
}


void reset_position()
{
  gx=0;gy=0;gz=0;
  rx=0;ry=0;rz=0;
  ax=0;ay=0;az=0;
  vx=0;vy=0;vz=0;
  px=0;pz=0;py=0;
  
}

void reset_pos_at(float p_px,float p_py, float p_pz)
{
  px=p_px;pz=p_py;py=p_pz;
}

void reset_rot_at(float p_rx,float p_ry,float p_rz)
{
  rx=p_rx;ry=p_ry;rz=p_rz;
}

void reset_at(float p_px,float p_py, float p_pz,float p_rx,float p_ry,float p_rz)
{
  reset_pos_at(p_px, p_py, p_pz);
  reset_rot_at(p_rx, p_ry, p_rz);
}



void loop()
{
  if (Serial.available() > 0) {
               
      char func = Serial.read();
      
      if (incomingByte == 'r')
      {
        char c = 0;
        String param = ""; 
        while(c!=")"){
          while(Serial.available() == 0);
          c = Serial.read();
          param += c;
        }
        
        
        String a = parseInput(func,param);
        Serial.println(a);
      }
      
  }

}

