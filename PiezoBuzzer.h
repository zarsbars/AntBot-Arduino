#pragma once
//#ifndef PiezoBuzzer_h
//#define PiezoBuzzer_h
#include <Arduino.h>
//#include <AntBot.h>

class PiezoBuzzer
{
private:
	int tempo;
	//typedef enum notes;
	float noteLookUp[17][2];
	int pin;

public:
	enum notes { C, Cs, Db, D, Ds, Eb, E, F, Fs, Gb, G, Gs, Ab, A, As, Bb, B };


	PiezoBuzzer();
	
	void setTempo(int);
	//pause with translation to tempo
	void rest(float);
	//note,octave,length of note
	void playNote(int,int, float);
	//play melody

};

#endif