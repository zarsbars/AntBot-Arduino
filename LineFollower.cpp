#include <LineFollower.h>

LineFollower::LineFollower() {
	setPort("A");
}

LineFollower::LineFollower(String port) {
	setPort(port);
}

void LineFollower::setPort(String port) {
	if(port.equals("A")){
		leftPin = 11;
		rightPin = 12;
	}else if(port.equals("B")){
		leftPin = 10;
		rightPin = 9;
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

}

boolean LineFollower::offLine() {

}

boolean LineFollower::rightOfLine() {

}

boolean LineFollower::leftOfLine() {

}