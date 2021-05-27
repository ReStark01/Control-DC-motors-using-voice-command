# Control-DC-motors-using-voice-command
This project uses machine learning to control DC motor
Use the machine learning program Wekinator and an Arduino UNO to control DC Motors with your voice.


MATERIALS:
 
 HARDWARE
 1- L298N 	
 2- FSA8049UCX 
 SOFTWARE
 1- Wekinator
 
 
In this project we control a DC motor by voice command. We will be using the Wekinator software as a machine learning platform, and after training Wekinator, we will get the output using processing and send it to the Arduino.


CIRCUIT DIAGRAM:

Make the connections as follows:

 -ENA of L298N to pin 11 of Arduino
 -ENB of L298N to pin 10 of Arduino
 -IN1 of L298N to pin 9 of Arduino
 -IN2 of L298N to pin 8 of Arduino
 -IN3 of L298N to pin 7 of Arduino
 -IN4 of L298N to pin 6 of Arduino
Connect the positive of battery source you are using to the 12V connector of L298N, the negative of the battery to GND of L298N, and the GND of L298N to the GND of Arduino
In the end, connect the two motors at the two ends of L298N



How to Run the Program
First of all, copy and paste the Arduino code at the end of this project in Arduino IDE and upload the code.
Then download the sketch from the example page of wekinator.
Download the executable file for MFCCs (mel-frequency cepstral coefficients).






After downloading, unzip it and run the “.exe” file. It will look like as shown below. Now you will need a microphone to give the input to Wekinator. If you have attached an external microphone, then make sure that it is selected in the sound settings.








You will need another sketch to get the output from Wekinator. This sketch is given at the end of this project. Paste it into the new processing window and run the sketch.
Open the Wekinator and make the settings as shown in the figure below. Set the inputs to 13 and the outputs to 1. Set the type to “All Dynamic time warping” with 5 gesture types and click on “next”.

Now hold the “+” button in front of output_1 and say “forward”.


Then hold the “+” button in front of output_2 and say “backward”.


Then hold the “+” button in front of output_3 and say “right”.


Then hold the “+” button in front of the output_4 and say “left”.



Then hold the “+” button in front of output_5 and say “stop”.



After that, click on “Train”, then click “Run”. Make sure you have uploaded the Arduino code and that the processing sketch is running on the background. Now the motor should move based on your voice commands. Try testing with your voice and re-train if needed by repeating the above steps.
How Does it Work?
In summary, there are three parts to this project: Wekinator, processing, and Arduino. Using machine learning, Wekinator is telling processing whether the voice it is listening to is a pre-trained voice command or not. Processing then reads that message and passes it to Arduino, then the Arduino decided whether to turn the motors clockwise/counterclockwise. All the communication that is happening between Wekinator and processing is through OSC (open sound control) protocol. The communication between processing and Arduino is done through serial.
