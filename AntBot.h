//#ifndef AntBot_h
#define	AntBot_h

#include <Arduino.h>
#include <LineFollower.h>
#include <Ultrasonic.h>
#include <Servo.h>
#include <PiezoBuzzer.h>
//#include "Display.h"

//#include "SPI.h"
//#include "Adafruit_GFX.h"
//#include "Adafruit_ILI9341.h"


#define motorPWMR 4
#define motorDR	5
#define motorPWML 7
#define motorDL	6
//#define buzzer 8

class AntBot
{
private:
	boolean isReversed;
	
public:
	//sensors
	LineFollower lineFollower;
	Ultrasonic ultrasonic;
	PiezoBuzzer Buzzer;
	//Display display;

	//implemented
	AntBot(boolean reverse);
	void stopMotion();
	void fullForward();
	void fullReverse();
	void forward(int);
	void reverse(int);
	void turnRight(int);
	void turnLeft(int);
	void forwardTimedSpeed(int, double);
	void reverseTimedSpeed(int, double);
	void setMotors(int, int);
	void turnRightTime(int, double);
	void turnLeftTime(int, double);
};

//#endif