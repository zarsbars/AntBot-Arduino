#pragma once
#include <AntBot.h>

IRrecv irrecv(2); //For remote

AntBot::AntBot() {

}

AntBot::AntBot(boolean reverse) {
	isReversed = reverse;
	if(reverse){
		PORTD &= ~(1<<PD4);
		PORTD |= (1<<PD7);
	}else{
		PORTD |= (1<<PD4);
		PORTD &= ~(1<<PD7);
	}
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
}

void AntBot::stopMotion() {
	analogWrite(5,0);
	analogWrite(6,0);
}

void AntBot::fullForward() {
	PORTD |= (1<<PD4);
	analogWrite(5, 255);
	PORTD &= ~(1<<PD7);
	analogWrite(6, 255);
}

void AntBot::fullReverse() {
	PORTD &= ~(1<<PD4);
	analogWrite(5, 255);
	PORTD |= (1<<PD7);
	analogWrite(6, 255);
}

void AntBot::forward(int speed) {
	if(speed < 0){
		speed = 0;
	}else if(speed > 255){
		speed = 255;
	}
	PORTD |= (1<<PD4);
	analogWrite(5, speed);
	PORTD &= ~(1<<PD7);
	analogWrite(6, speed);
}

void AntBot::reverse(int speed) {
	if(speed < 0){
		speed = 0;
	}else if(speed > 255){
		speed = 255;
	}
	PORTD &= ~(1<<PD4);
	analogWrite(5, speed);
	PORTD |= (1<<PD7);
	analogWrite(6, speed);
}

void AntBot::forwardTime(int speed, double sec)
{
	forward(speed);
	delay(sec * 1000);
	stopMotion();
}

void AntBot::reverseTime(int speed, double sec)
{
	reverse(speed);
	delay(sec * 1000);
	stopMotion();
}

void AntBot::turnLeft(int speed)
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	PORTD &= ~(1 << PD7);
		analogWrite(6, speed);
}

void AntBot::turnRight(int speed) 
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 255) {
		speed = 255;
	}
	PORTD &= ~(1 << PD4);
	analogWrite(5, speed);
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

	PORTD &= ~(1 << PD4);
	analogWrite(5, left);

	PORTD &= ~(1 << PD4);
	analogWrite(5, right);
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