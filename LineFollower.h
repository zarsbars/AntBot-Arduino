#ifndef LineFollower_h
#define	LineFollower_h

#include <Arduino.h>

// Sensor and Display Ports
#define C1 A0;
#define C2 A1;
#define D1 A2;
#define D2 A3;

class LineFollower
{
private:
	int leftPin;
	int rightPin;
	
public:
	LineFollower();
	LineFollower(String);
	void setPort(String);
	
	boolean getLeft();
	boolean getRight();
	boolean onLine();
	boolean offLine();
	boolean rightOfLine();
	boolean leftOfLine();
};

#endif