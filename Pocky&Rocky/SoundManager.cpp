#include "SoundManager.h"
#include <iostream>

SoundManager* SoundManager::pInstance = NULL;

SoundManager::SoundManager()
{
	_FirstFreeSlot = 0;
}

SoundManager::~SoundManager()
{
}

Mix_Chunk* SoundManager::getAudioByID(Sint32 ID)
{
	return _AudioVector.at(ID);
}


int SoundManager::loadAndGetAudioID(const char* file)
{
	if (_IDMap.find(file) == _IDMap.end()) { return addAudio(file); }; 

	return _IDMap.find(file)->second;
}

int SoundManager::addAudio(const char* file)
{
	_FirstFreeSlot = updateFirstFreeSlotAudio();

	Mix_Chunk* audio = Mix_LoadWAV(file);
	if (!audio) {
		std::cout << Mix_GetError() << std::endl;
		system("pause");
		return -1;
	}
	if (!(_FirstFreeSlot == -1)) { 
		_AudioVector[_FirstFreeSlot] = audio;
		_IDMap.insert(std::pair<std::string, int>(file, _FirstFreeSlot));
	}
	else { 
		_AudioVector.push_back(audio);
		_IDMap.insert(std::pair<std::string, int>(file, _AudioVector.size() - 1));
	}

	return _IDMap.find(file)->second;
}

Uint32 SoundManager::updateFirstFreeSlotAudio()
{
	for (size_t i = 0; i < _AudioVector.size(); i++)
	{
		if (_AudioVector[i] == NULL) {
			return i;
		}
	}

	return -1;
}

SoundManager* SoundManager::getInstance()
{
	if (pInstance == NULL)pInstance = new SoundManager();
	return pInstance;
}