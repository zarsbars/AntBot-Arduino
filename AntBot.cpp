#include <AntBot.h>

IRrecv irrecv(2); //For remote


AntBot::AntBot() {
	pinMode(L, OUTPUT);
	pinMode(R, OUTPUT);
	pinMode(L_DIR, OUTPUT);
	pinMode(R_DIR, OUTPUT);
}

void AntBot::lineFollowerPort(String port) {
	lineFollower = LineFollower(port);
}

void AntBot::ultrasonicPort(String port) {
	ultrasonic = Ultrasonic(port);
}

void AntBot::stopMotion() {
	analogWrite(L, 0);
	analogWrite(R, 0);
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
				forward(255);
				break;
			case DOWN_ARROW:
				reverse(255);
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