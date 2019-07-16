#ifndef Ultrasonic_h
#define	Ultrasonic_h

#include <Arduino.h>

//#define motorPWMR 4
//#define motorDR	5

class Ultrasonic
{
private:
	int pingPin;
	
public:
	Ultrasonic();
	Ultrasonic(String);
	void setPort(String);
	long measure();
	long getDistCm();
	long getDistIn();
};

#endif