#include <VSync.h>    //Including the library that will help us in receiving and sending the values from processing
ValueReceiver<1> receiver;  /*Creating the receiver that will receive only one value. 
Put the number of values to synchronize in the brackets */

/* The below variable will be synchronized in the processing 
and it should be same on both sides. */
int output;

//Motor Pins
int EN_A = 11;      
int IN1 = 9;      
int IN2 = 8;       
int IN3 = 7;        
int IN4 = 6;       
int EN_B = 10;      

void setup()
{
  /* Starting the serial communication because we are communicating with the 
  Processing through serial. The baudrate should be same as on the processing side. */
  Serial.begin(19200);
  //Initializing the motor pins as output
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);

  digitalWrite(EN_A, HIGH);
  digitalWrite(EN_B, HIGH);
  
  // Synchronizing the variable with the processing. The variable must be int type.
  receiver.observe(output);
}

void loop()
{
  // Receiving the output from the processing.
  receiver.sync();
  
  // Matching the received output to light up led's
  if (output == 1) 
  {
    //Forward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else if (output == 2)
  {
    //Backward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
  }
  else if (output == 3)
  {
    //Right
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else if (output == 4)
  {
    //Left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if (output == 5)
  {
    //Stop
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
