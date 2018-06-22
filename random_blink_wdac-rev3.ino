
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;


long randNumber; 
long randNumber2;
long divNumber;
int x = 0;
int y = 0;

int outhead;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2,OUTPUT);
  

    dac.begin(0x62);
}


void loop() {

  long charhead = analogRead(A3);
  long timehead = analogRead(A2);
  
   divNumber = random(1023);
 
  if (charhead > divNumber)
  {
   x++;
  // Serial.println("you are in counter augment x is"); 
  // Serial.println(x); 
  }
  else  
   {  
 //  Serial.println("you are in reset to zero, x is "); 
   //Serial.println(x); 
   x = 0;
   //y = 0; 
   }
 

  
  
  if ((x == 0) && (y == 0))
  {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(2,HIGH);
    outhead = (divNumber/20);
    dac.setVoltage(divNumber*4, false);
 
  //   Serial.println("x  and y value is this in 'x and y equals zero':");
   y = y + 1;
   // Serial.println(x);
 // Serial.println(y);
   
  }
 
  if (x < 1)
    
  {
    
  }
   
  if (x == 1)
  {
    
   digitalWrite(LED_BUILTIN, LOW);
   digitalWrite(2,LOW);
    outhead = (divNumber/20);
    dac.setVoltage(divNumber*4, false);
 //  Serial.println("x value is in else--x equals 1:");
 // Serial.println(x);
    y = 0;
  }
  
  
  //debug dookie . 
  
  

//  Serial.println("sensitivity value is:");
//  Serial.println(charhead, DEC);
//  Serial.println("randomnumber is:");
//  Serial.println(divNumber);
//  Serial.println("x value is:");
//  Serial.println(x);
//  Serial.println("---------");
  delay(timehead * 10);
}
