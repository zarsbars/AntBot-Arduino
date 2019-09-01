#include <AntBot.h>

//IRrecv irrecv(2); //For remote
#define L 5
#define R 6
#define L_DIR 24
#define R_DIR 23


AntBot::AntBot() {
	pinMode(L, OUTPUT);
	pinMode(R, OUTPUT);
	pinMode(L_DIR, OUTPUT);
	pinMode(R_DIR, OUTPUT);
}

void AntBot::addLineFollower(String port) {
	lineFollower = LineFollower(port);
}

void AntBot::addUltrasonic(String port) {
	ultrasonic = Ultrasonic(port);
}

void AntBot::stopMotion() {
	analogWrite(L, 0);
	analogWrite(R, 0);
}

void AntBot::fullForward() {
	digitalWrite(L_DIR, HIGH);
	digitalWrite(R_DIR, LOW);
	analogWrite(L, 255);
	analogWrite(R, 255);
}

void AntBot::fullReverse() {
	digitalWrite(L_DIR, LOW);
	digitalWrite(R_DIR, HIGH);
	analogWrite(L, 255);
	analogWrite(R, 255);
}

void AntBot::forward(int speed) {
	if(speed < 0){
		speed = 0;
	}else if(speed > 255){
		speed = 255;
	}
	digitalWrite(L_DIR, HIGH);
	digitalWrite(R_DIR, LOW);
	analogWrite(L, speed);
	analogWrite(R, speed);
}

void AntBot::reverse(int speed) {
	if(speed < 0){
		speed = 0;
	}else if(speed > 255){
		speed = 255;
	}
	digitalWrite(L_DIR, LOW);
	digitalWrite(R_DIR, HIGH);
	analogWrite(L, speed);
	analogWrite(R, speed);
}

void AntBot::forwardTime(int speed, double sec) {
	forward(speed);
	delay(sec * 1000);
	stopMotion();
}

void AntBot::reverseTime(int speed, double sec) {
	reverse(speed);
	delay(sec * 1000);
	stopMotion();
}

void AntBot::turnLeft(int speed) {
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	digitalWrite(R_DIR, LOW);
	digitalWrite(L_DIR, LOW);
	analogWrite(R, speed);
	analogWrite(L, speed);
}

void AntBot::turnRight(int speed) 
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	digitalWrite(L_DIR, HIGH);
	digitalWrite(R_DIR, HIGH);
	analogWrite(L, speed);
	analogWrite(R, speed);
}

void AntBot::setMotors(int left, int right)
{
	if (left < 0) {
		left = 0;
	}
	else if (left > 255) {
		left = 255;
	}

	if (right < 0) {
		right = 0;
	}
	else if (right > 255) {
		right = 255;
	}

	digitalWrite(L_DIR, HIGH);
	digitalWrite(R_DIR, LOW);
	analogWrite(L, left);
	analogWrite(R, right);
}

void AntBot::turnRightTime(int speed, double sec)
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	turnRight(speed);
	delay(1000 * sec);
	stopMotion();
}

void AntBot::turnLeftTime(int speed, double sec)
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	turnLeft(speed);
	delay(1000 * sec);
	stopMotion();
}
/*
void AntBot::remoteSetup()
{
	irrecv.enableIRIn();
}

//Allows for driving of the robot
void AntBot::remotePlay()
{
	var = 0;

	while (true) {
		if (irrecv.decode(&results)) {
			if (results.value != HOLD)
				irsignal = results.value;

			//Stops the motors when a different button is pressed (in case we decide to 
			//program the other buttons)
			if (var != irsignal) {
				stopMotion();
				var = irsignal;
			}

			if (results.value == HOLD)
				results.value = irsignal;

			switch (results.value) {
			case UP_ARROW:
				fullForward();
				break;
			case DOWN_ARROW:
				fullReverse();
				break;
			case LEFT_ARROW:
				turnLeft(210);
				break;
			case RIGHT_ARROW:
				turnRight(210);
				break;
			}

			irrecv.resume();
		}
		else
			stopMotion();

		delay(150);
	}
}
*/