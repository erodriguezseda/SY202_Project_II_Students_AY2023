/*************************************************************
[MODIFY] Description of program, authors, dates, etc... 
[MODIFY] Include pseudo code between these lines
*************************************************************/

#include "mbed.h"
#include "platform/mbed_thread.h"

#define SERVO_CAN_ID 	 1   //[DO NOT MODIFY]  Address of mbed/servo CAN device
#define SENSOR_CAN_ID    2   //[DO NOT MODIFY]  Address of mbed/sensor CAN device
#define CONTROL_CAN_ID   3   //[DO NOT MODIFY]  Address of THIS mbed device

Serial Object;			    //[MODIFY]  To talk to Tera Term
CAN can(p30,p29); 		    //[DO NOT MODIFY]  Set CAN Interface (assume using pins p30 and p29).
				
DigitalOut LEDobject;		//[MODIFY]  Declare LED #1. You will use it as a Heartbeat signal of your program
DigitalOut LEDobject;       //[MODIFY]  Declare LED #2. You will toggle its value when reading a CAN message
DigitalOut LEDobject;     	//[MODIFY]  Declare LED #3. You will toggle its value when writing a CAN message
Timer tlog;			        //[DO NOT MODIFY]  For printing/logging time data

/*************************************************************
[OPTIONAL]  Declare and initialize variables of your choice
*************************************************************/

/*************************************************************
[OPTIONAL]  PART A - Task 2: Write a function that converts a 
string CAN Message into a float number
*************************************************************/

int main() {
	//[MODIFY]  Set baudrate for communication with pc and tera term to 115200
	//[MODIFY]  Initialize your program by printing to Tera Term the name of your group along with the last name of each
	//individual in the group
	thread_sleep_for(1000);		//[DO NOT MODIFY]  To allow user to read initial info
	CANMessage msg_read; 	    //[DO NOT MODIFY]  Defines empty CAN message to store message from sensor
	CANMessage msg_write; 	    //[DO NOT MODIFY]  Defines empty CAN message to store message to servo
	can.frequency(500000);
	tlog.start();			    //[DO NOT MODIFY]  Start counter for time
	int pcmWidth = 900;		    //[TO BE MODIFIED IN PART A - TASK 3]  This is the control signal to be sent to the 
							    //servo motor. It is an integer value between 900 and 2100 representing in microseconds 				
							    //the width of the Pulse-Code-Modulated signal (PCM) to servo.
	int motionDir = -1;		    //[TO BE MODIFIED IN PART A - TASK 3]  Direction of motion for servo motor
	char msg_send[8];		    //[DO NOT MODIFY]  Define empty data string for CAN Message to be sent to servo
    float desiredAngle = 0; 	//[TO BE MODIFIED IN PART A - TASK 5]  This is the desired angle
    float integralError = 0;	//[DO NOT MODIFY]  This is the integral of the error for the PI control
	float Ts = 0.05;        	//[DO NOT MODIFY]  This is the approximated period of the control cycle in seconds
	
	while(1){   			    //[DO NOT MODIFY]  This your cyclic control loop (the one to be executed indefinitely)

        /****************CONVERT MESSAGE TO FLOAT*********************
        if(can.read(msg_read)) { 		//[DO NOT MODIFY]  If message is available, read into msg_read
			if(msg_read.id == SENSOR_CAN_ID){	//[DO NOT MODIFY]  Check if the id of message received is the ID of the sensor
                //[MODIFY]  Print to Tera Term the current time and the sensor's message. Note that the message is a string %s
				//[MODIFY]  Toggle the value of LED#2
				
				/****************CONVERT MESSAGE TO FLOAT*********************
				[MODIFY]  PART A - Task 2: Convert to string data message (angle 
				in radians) to a float number
				*************************************************************/
				
				/**********************PI CONTROL*****************************
				[MODIFY]  PART A - Task 4 & 5: Compute error, integral of error, and 
				command signal to servo motor using a PI controller
				*************************************************************/
				
				/******************WRITE CAN MESSAGE**************************
				[MODIFY]  PART A - Task 3: Write CAN Message. 
				//Convert pcmWidth to a string and send it in a CAN Message and
				save value into msg_send using sprintf()
				//Write the message into the CAN Bus using can.write (see inst.)
				*************************************************************/
				
				thread_sleep_for(20);			//[DO NOT MODIFY]  Wait for a little bit after
									            //reading/sending a message
			}
		}
	}
}
