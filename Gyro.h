#pragma once
#include <Arduino.h>
#include <I2Cdev.h>
#include "helper_3dmath.h"
#define MPU6050_INCLUDE_DMP_MOTIONAPPS20
#include <MPU6050.h> 
#include <Wire.h>

//Remember that you must wait ~16 seconds for calibration 

class Gyro
{
public:
	Gyro();
	void setup();
	void reset();
	float read();
	
	
private:
	static void dmpDataReady();
	float homeAngle;
	MPU6050 mpu;

	// MPU control/status vars
	bool dmpReady;  // set true if DMP init was successful
	uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
	uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
	uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
	uint16_t fifoCount;     // count of all bytes currently in FIFO
	uint8_t fifoBuffer[64]; // FIFO storage buffer

	// orientation/motion vars
	Quaternion q;           // [w, x, y, z]         quaternion container
	VectorInt16 aa;         // [x, y, z]            accel sensor measurements
	VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
	VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
	VectorFloat gravity;    // [x, y, z]            gravity vector
	float euler[3];         // [psi, theta, phi]    Euler angle container
	float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

	static volatile bool mpuInterrupt;
};