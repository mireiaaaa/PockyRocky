#include "Sound.h"
#include "SoundManager.h"
#include "SDL_mixer.h"

Sound* Sound::pInstance = NULL;

Sound::Sound()
{
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_AllocateChannels(128);
}

Sound::~Sound()
{
}

void Sound::close()
{
	Mix_CloseAudio();
}

int Sound::playAudio(int channel, int soundID, int loops)
{
	Mix_Chunk* chunk = SoundManager::getInstance()->getAudioByID(soundID);
	return Mix_PlayChannel(channel, chunk, loops);
}

void Sound::stopAudio(int channel)
{
	Mix_HaltChannel(channel);
}

Sound* Sound::getInstance()
{
	if (pInstance == NULL) pInstance = new Sound();

	return pInstance;
}