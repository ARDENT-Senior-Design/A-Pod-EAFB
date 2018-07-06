#include <SoftwareSerial.h>
#include <Encoder.h>
#include <MINDSi.h>

SoftwareSerial mySerial(9,8);
 int i = 0;

 

void setup() {
          //1800-1850 - 12 inches; 1600-1650 - 10 inches; 1200-1250 - 8 inches; 920 - 980 - 6 inches; 675 - 700 - 4 inches; 325 - 375 - 2 inches; 220 - 325 last indicator
pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(3,OUTPUT);
Serial.begin(9600);
mySerial.begin(38400);



  
//right side. Down is up.
mySerial.println("#0 P1000 T600 #1 P1000 T600 #2 P1000 T600"); //right back
mySerial.println("#4 P1500 T600 #5 P1100 T600 #6 P1100 T600"); //right mid
mySerial.println("#8 P1700 T600 #9 P1000 T600 #10 P1000 T600"); //right front
mySerial.println("#16 P1700 T600 #17 P2000 T600 #18 P2100 T600"); //left back
mySerial.println("#20 P1500 T600 #21 P1900 T600 #22 P2100 T600"); //left mid
mySerial.println("#24 P1000 T600 #25 P2000 T600 #26 P2100 T600"); //left front
mySerial.println(" #30 P1500 T600 #31 P1800 T600"); //tail
delay(2500);
}

void loop() {


//mySerial.println("#0 P1000 T600 #1 P1000 T600 #2 P1000 T600"); //right back
//mySerial.println("#4 P1500 T600 #5 P800 T600 #6 P1100 T600"); //right mid
//mySerial.println("#8 P1700 T600 #9 P1000 T600 #10 P1000 T600"); //right front
//mySerial.println("#16 P1700 T600 #17 P2300 T600 #18 P2100 T600"); //left back
//mySerial.println("#20 P1500 T600 #21 P1900 T600 #22 P2100 T600"); //left mid
//mySerial.println("#24 P1000 T600 #25 P2300 T600 #26 P2100 T600"); //left front
//delay(1000);
//mySerial.println("#0 P800 T600 #1 P1000 T600 #2 P1000 T600"); //right back
//mySerial.println("#4 P1500 T600 #5 P1100 T600 #6 P1100 T600"); //right mid
//mySerial.println("#8 P1500 T600 #9 P1000 T600 #10 P1000 T600"); //right front
//mySerial.println("#16 P1700 T600 #17 P2000 T600 #18 P2100 T600"); //left back
//mySerial.println("#20 P1700 T600 #21 P1900 T600 #22 P2100 T600"); //left mid
//mySerial.println("#24 P1000 T600 #25 P2000 T600 #26 P2100 T600"); //left front

if(getPing(7)>1700){
   // mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);}

else if(getPing(7)>1600 && getPing(7)<1700){
   // mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);}
else if(getPing(7)<1600 && getPing(7)>1200){
  //mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(6,LOW);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);}
else if(getPing(7)<1200 && getPing(7)>920){
 // mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(6,HIGH);
digitalWrite(5,LOW);
digitalWrite(4,LOW);
digitalWrite(3,LOW);}
else if(getPing(7)<920 && getPing(7)>675){
  //mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
digitalWrite(4,LOW);
digitalWrite(3,LOW);}
else if(getPing(7)<675 && getPing(7)>325){
  //mySerial.println("#28 P800 #29 P2200 T500");
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
digitalWrite(3,LOW);}
else if(getPing(7)<325){
   digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
digitalWrite(6,HIGH);
digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
digitalWrite(3,HIGH);


    mySerial.println("#28 P2400 #29 P600 T500");// claw
  mySerial.println(" #30 P1000 T500 #31 P1800 T500"); //tail
  delay(100);
      mySerial.println(" #30 P2000 T500 #31 P1800 T500"); //tail
  delay(100);
  mySerial.println(" #30 P1600 T500 #31 P1800 T500"); //tail
  delay(100);
  i=i+1;}



else{
      mySerial.println("#28 P800 #29 P2200 T500");
}

 
Serial.println(getPing(7));
  
  
  
 

}


