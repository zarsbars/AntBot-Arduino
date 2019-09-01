#include <LineFollower.h>

LineFollower::LineFollower() {
	setPort("C");
}

LineFollower::LineFollower(String port) {
	setPort(port);
}

void LineFollower::setPort(String port) {
	if(port.equals("C")){
		leftPin = A0;
		rightPin = A1;
	}else if(port.equals("D")){
		leftPin = A2;
		rightPin = A3;
	}
	pinMode(leftPin, OUTPUT);
	pinMode(rightPin, OUTPUT);
}
		

boolean LineFollower::getRight() {
	return digitalRead(rightPin);
}

boolean LineFollower::getLeft() {
	return digitalRead(leftPin);
}

boolean LineFollower::onLine() {
	return getRight() && getLeft();
}

boolean LineFollower::offLine() {
	return !(getRight() || getLeft());
}

boolean LineFollower::rightOfLine() {
	return getLeft() && !getRight();
}

boolean LineFollower::leftOfLine() {
	return ~getLeft() && getRight();
}