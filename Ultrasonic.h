#ifndef Ultrasonic_h
#define	Ultrasonic_h

#include <Arduino.h>

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