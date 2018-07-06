#include <SoftwareSerial.h>
#include <Encoder.h>
#include <MINDSi.h>
#include <PS2X_lib.h>

  #define SOUND_PIN       5   // Botboarduino JR pin number
  #define PS2_DAT         12//8        
  #define PS2_CMD         11//7
  #define PS2_SEL         10//6  // On the PS2 receiver this pin may be called ATT (attention)
  #define PS2_CLK         13//9

  #define cSSC_OUT       8//12   //Output pin for Botboard - Input of SSC32 (Yellow)
  #define cSSC_IN        9//13   //Input pin for Botboard - Output of SSC32 (Blue)
PS2X ps2x; // create PS2 Controller Class
//InputController  g_InputController;       // Our Input controller 

SoftwareSerial mySerial(9,8);
int currentP;
void setup() {
  pinMode(14,OUTPUT);
  Serial.begin(38400);
  mySerial.begin(38400);

  mySerial.println("#14 P1500");
  currentP = 1500;

}

void loop() {
  if (ps2x.Analog(PSS_RY)>137){
    mySerial.print("#14");
    int P = currentP;
    mySerial.print("P");
    mySerial.print(P +10,DEC);
    currentP = P;
  }
  else if(117< ps2x.Analog(PSS_RY) <137){
    mySerial.print("#14");
    int P = currentP;
    mySerial.print("P");
    mySerial.print(P,DEC);
    currentP = P;  
  }
  else if(117 > ps2x.Analog(PSS_RY)){
    mySerial.print("#14");
    int P = currentP;
    mySerial.print("P");
    mySerial.print(P -10,DEC);
    currentP = P; 
  }
  else{
  }
  }

