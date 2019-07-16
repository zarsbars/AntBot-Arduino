#include <Ultrasonic.h>


Ultrasonic::Ultrasonic() {
	setPort("A");
}

Ultrasonic::Ultrasonic(String port) {
	setPort(port);
}

void Ultrasonic::setPort(String port) {
	if(port.equals("A")){
		pingPin = 12;
	}else if(port.equals("B")){
		pingPin = 10;
	}
	pinMode(pingPin, OUTPUT);
}

long Ultrasonic::measure() {
	pinMode(pingPin, OUTPUT);
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);

	pinMode(pingPin, INPUT);
	long duration = pulseIn(pingPin, HIGH);

	return duration;
}

long Ultrasonic::getDistCm() {
	long duration = measure();
	return duration / 58;
}

long Ultrasonic::getDistIn() {
	long duration = measure();
	return duration / 148;
}