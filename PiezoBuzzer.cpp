#include "PiezoBuzzer.h"
//enum notes = { Ab = 25.96,A = 27.5 };

PiezoBuzzer::PiezoBuzzer()
{
	noteLookUp[C][1] = 16.35;
	noteLookUp[Cs][1] = 17.32;
	noteLookUp[Db][1] = 17.32;
	noteLookUp[D][1] = 18.35;
	noteLookUp[Ds][1] = 19.45;//30.87
	noteLookUp[Eb][1] = 19.45;
	noteLookUp[E][1] = 20.60;
	noteLookUp[F][1] = 21.83;
	noteLookUp[Fs][1] = 23.12;
	noteLookUp[Gb][1] = 23.12;
	noteLookUp[G][1] = 24.50;
	noteLookUp[Gs][1] = 25.96;
	noteLookUp[Ab][1] = 25.96;
	noteLookUp[A][1] = 27.50;
	noteLookUp[As][1] = 29.14;
	noteLookUp[Bb][1] = 29.14;
	noteLookUp[B][1] = 30.87;
	pin = 8;
	pinMode(pin, OUTPUT);
}

void PiezoBuzzer::rest(float restLength)
{
	noTone(pin);
	delay(restLength * tempo);
}

void PiezoBuzzer::playNote(int note, int octave, float noteLength)
{
	tone(pin,(noteLookUp[note][1]*(octave + 1)));
	delay(noteLength*tempo);
	noTone(pin);
	
}

void PiezoBuzzer::setTempo(int bpm)
{
	tempo = 60000 / bpm;
}

