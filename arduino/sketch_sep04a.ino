
#include <SerialCommand.h>
SerialCommand sCmd;

// potard decl

 int pinA = 3;  // Connected to CLK on KY-040
 int pinB = 4;  // Connected to DT on KY-040
 int encoderPosCount = 0; 
 int pinALast;  
 int aVal;
 int bVal;
 boolean bCW;

 // fin potard declar
 
void setup() {
// potard setup 
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   /* Read Pin A
   Whatever state it's in will reflect the last position   
   */
   pinALast = digitalRead(pinA);  

   // fin ppotard setup

  
  Serial.begin(9600);
  while (!Serial);
  sCmd.addCommand("PING", pingHandler);
  sCmd.addCommand("POTARD", potardHandler);
  //Serial.println("started");
 

}

void loop() {
  
  //Serial.println("looping");
    if (Serial.available() > 0)
    sCmd.readSerial();
  
    aVal = digitalRead(pinA);
    bVal = digitalRead(pinB);
    if ((aVal != pinALast)&&(aVal==LOW)) {
      
        // Knob Rotated l when aVal changes, BUT use only if aVal is LOW.
    
        if(bVal == LOW){ encoderPosCount++;} //
        else {encoderPosCount--;}

        //Serial.println(encoderPosCount);
    }
   pinALast = aVal;
   delay(1);


 
    //Serial.println(data);
}

void pingHandler () {
  Serial.println("PONG");
}

void potardHandler () {
  Serial.println(encoderPosCount);
}

void echoHandler () {
  char *arg;
  arg = sCmd.next();
  if (arg != NULL)
    Serial.println(arg);
  else
    Serial.println("nothing to echo");
}
