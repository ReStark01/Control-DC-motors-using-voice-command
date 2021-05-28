import vsync.*; // Importing the library that will help us in sending and receiving the values from the Arduino
import processing.serial.*;  // Importing the serial library

// Below libraries will connect and send, receive the values from wekinator
import oscP5.*;  
import netP5.*;

// Creating the instances
OscP5 oscP5;
NetAddress dest;
ValueSender sender;

// This variable will be syncronized with the Arduino and it should be same on the Arduino side.
public int output;

void setup() 
{
  // Starting the serial communication, the baudrate and the com port should be same as on the Arduino side.
  Serial serial = new Serial(this, "COM10", 19200);
  sender = new ValueSender(this, serial);
  
  // Synchronizing the variable as on the Arduino side.
  sender.observe("output");
  
  // Starting the communication with wekinator. listen on port 12000, return messages on port 6448
  oscP5 = new OscP5(this, 12000); 
  dest = new NetAddress("127.0.0.1", 6448);
}

//This is called automatically when OSC message is received
void oscEvent(OscMessage theOscMessage) {
 if (theOscMessage.checkAddrPattern("/output_1")==true) 
 {
        output = 1;
 } 
 else if (theOscMessage.checkAddrPattern("/output_2")==true) 
 {
     output = 2;
 } 
 else if (theOscMessage.checkAddrPattern("/output_3") == true) 
 {
     output = 3;
 } 
 else if (theOscMessage.checkAddrPattern("/output_4") == true) 
 {
     output = 4;
 }
 else if (theOscMessage.checkAddrPattern("/output_5") == true) 
 {
     output = 5;
 }
 else 
 {
   
 }
}

void draw() 
{
  //  Nothing to be drawn for this example
}
