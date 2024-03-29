#include <Ultrasonic.h>


Ultrasonic::Ultrasonic() {
	setPort("A");
}

Ultrasonic::Ultrasonic(String port) {
	setPort(port);
}

void Ultrasonic::setPort(String port) {
	if(port.equals("C")){
		trig = C1;
		echo = C2;
	}else if(port.equals("D")){
		trig = D1;
		echo = D2;
	}
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

long Ultrasonic::measure() {
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);

	long duration = pulseIn(echo, HIGH);

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