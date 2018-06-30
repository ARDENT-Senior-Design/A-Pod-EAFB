#include <PixyI2C.h>
#include <Wire.h>  
#define X_CENTER    160L
#define Y_CENTER    100L
#define RCS_MIN_POS     0L
#define RCS_MAX_POS     1000L
#define RCS_CENTER_POS  ((RCS_MAX_POS-RCS_MIN_POS)/2)

int32_t panError, tiltError;

PixyI2C UpdateCamera(PixyI2C pixy)
{
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  int largestArea =0;
  int largestAreaPos=0;
  
  // grab blocks!
  blocks = pixy.getBlocks();
  Serial.println(pixy.getBlocks());
  // If there are detect blocks, print them!
  if(blocks)
  {
    i++;
    
    Serial.println("This running");
    // do this (print) every 50 frames because printing every
    // frame would bog down the Arduino
    if (i%5==0)
    {
      for (j=0; j<blocks; j++)
      {
        if(largestArea<pixy.blocks[j].width*pixy.blocks[j].height && pixy.blocks[j].width*pixy.blocks[j].height > 150)
        {
          Serial.println("This is running");
          sprintf(buf, "Detected %d:\n", blocks);
          Serial.print(buf);
          largestArea=pixy.blocks[j].width*pixy.blocks[j].height;
          largestAreaPos = j;
        }
      }
      if(largestArea!=0)
      {
        Serial.println("This is also running");
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[largestAreaPos].print();
        Serial.println(largestArea);
        panError = X_CENTER-pixy.blocks[largestAreaPos].x;
        tiltError = pixy.blocks[largestAreaPos].y-Y_CENTER;
        Serial.print("Horizontal Error: ");
        Serial.println(panError);
        Serial.print("Vertical Error: ");
        Serial.println(tiltError);
      }
      else
      {
        largestArea = 0;
      }
    }
  }  
  return pixy;  //returns the update pixy camera image pixel
}

