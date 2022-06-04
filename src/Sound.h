#pragma once
#include "sdl.h"

class Sound
{
	static Sound* pInstance;
public:
	Sound();
	~Sound();
	void close();

	int playAudio(int channel, int chunk, int loops);
	void stopAudio(int channel);
	static Sound* getInstance();
};