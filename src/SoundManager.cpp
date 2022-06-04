#include "SoundManager.h"
SoundManager* SoundManager::pInstance = NULL;
SoundManager::~SoundManager()
{
}

void SoundManager::removeSound()
{
	Mix_CloseAudio();
}

Sint32 SoundManager::loadAndGetSoundID( const char* file)
{

	sound= Mix_LoadMUS(file);
	sounds.push_back(sound);
	return Sint32();
}

std::string SoundManager::getSoundPathByID(Sint32 ID)
{
	return std::string();
}

SDL_Texture* SoundManager::getSoundByID(Sint32 ID)
{
	return nullptr;
}

void SoundManager::setAlphaSound(Sint32 ID, Uint8 alpha_value)
{
}

void SoundManager::playLoadedSounds()
{
	Mix_PlayMusic(sound,-1);
}

Sint32 SoundManager::createSound()
{

	frequency = 44100;
	format = MIX_DEFAULT_FORMAT;
	channels = 2;
	chunksize = 1024;
	Mix_AllocateChannels(1);
	Mix_OpenAudio(frequency, format, channels, chunksize);
	return Sint32();
}

SoundManager* SoundManager::getInstance()
{
	return nullptr;
}

SoundManager::SoundManager()
{
}

Sint32 SoundManager::addSound(SDL_Renderer* Renderer, const char* file)
{
	return Sint32();
}

Uint32 SoundManager::updateFirstFreeSlotSound()
{
	return Uint32();
}
