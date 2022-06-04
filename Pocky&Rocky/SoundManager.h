#pragma once
#include <map>
#include <vector>
#include <string>
#include "SDL_mixer.h"

class SoundManager
{
	SoundManager();

	static SoundManager* pInstance;

	int addAudio(const char* file);
	Uint32 updateFirstFreeSlotAudio();

	std::vector<Mix_Chunk*>			_AudioVector;
	std::map<std::string, Sint32>	_IDMap;
	Uint32							_FirstFreeSlot;
public:
	~SoundManager();

	Mix_Chunk* getAudioByID(Sint32 ID);
	int loadAndGetAudioID(const char* file);

	static SoundManager* getInstance();
};
