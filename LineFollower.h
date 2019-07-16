#ifndef LineFollower_h
#define	LineFollower_h

#include <Arduino.h>

//#define motorPWMR 4
//#define motorDR	5

class LineFollower
{
private:
	int leftPin;
	int rightPin;
	
public:
	//implemented
	LineFollower();
	LineFollower(String);
	void setPort(String);
	boolean getLeft();
	boolean getRight();

	//to be implemented
	boolean onLine();
	boolean offLine();
	boolean rightOfLine();
	boolean leftOfLine();
};

#endif