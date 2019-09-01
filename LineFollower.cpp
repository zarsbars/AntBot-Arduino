#include <LineFollower.h>

LineFollower::LineFollower() {
	setPort("C");
}

LineFollower::LineFollower(String port) {
	setPort(port);
}

void LineFollower::setPort(String port) {
	if(port.equals("C")){
		leftPin = C1;
		rightPin = C2;
	}else if(port.equals("D")){
		leftPin = D1;
		rightPin = D2;
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
	return getRight() && !getLeft();
}