#ifndef LineFollower_h
#define	LineFollower_h

#include <Arduino.h>

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