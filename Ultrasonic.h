#ifndef Ultrasonic_h
#define	Ultrasonic_h

#include <Arduino.h>

// Sensor and Display Ports
#define C1 A0;
#define C2 A1;
#define D1 A2;
#define D2 A3;


class Ultrasonic
{
private:
	int trig;
	int echo;
	
public:
	Ultrasonic();
	Ultrasonic(String);
	void setPort(String);
	long measure();
	long getDistCm();
	long getDistIn();
};

#endif