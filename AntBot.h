#ifndef AntBot_h
#define	AntBot_h

#include <Arduino.h>
#include <LineFollower.h>
#include <Ultrasonic.h>
#include <IRremote.h>
#include <Gyro.h> 
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

//Remote button codes
#define UP_ARROW 16712445
#define DOWN_ARROW 16750695
#define RIGHT_ARROW 16748655
#define LEFT_ARROW 16769055
#define HOLD 4294967295
#define ONE 16724175
#define TWO 16718055
#define THREE 16743045
#define FOUR 16716015
#define FIVE 16726215

class AntBot
{
private:
	bool isReversed;

	//For remote
	decode_results results;
	unsigned long int irsignal;
	unsigned long int var;
	
public:
	//sensors
	LineFollower lineFollower;
	Ultrasonic ultrasonic;
	PiezoBuzzer Buzzer;
	//Display display;
	Gyro gyro;

	//implemented
	AntBot();
	AntBot(boolean reverse);
	void stopMotion();
	void fullForward();
	void fullReverse();
	void forward(int);
	void reverse(int);
	void turnRight(int);
	void turnLeft(int);
	void forwardTime(int, double);
	void reverseTime(int, double);
	void setMotors(int, int);
	void turnRightTime(int, double);
	void turnLeftTime(int, double);

	//Remote stuff
	void remoteSetup();
	void remotePlay();
};

#endif
