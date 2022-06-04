#ifndef SoundMANAGER_H
#define SoundMANAGER_H

#include <string>
#include <map>
#include <vector>
#include "SDL.h"
#include "sdl_mixer.h"

class SoundManager
{
public:

	
	~SoundManager();



	void removeSound();


	
	Sint32 loadAndGetSoundID(const char* file);


	
	
	std::string getSoundPathByID(Sint32 ID);



	SDL_Texture* getSoundByID(Sint32 ID);

	
	void setAlphaSound(Sint32 ID, Uint8 alpha_value);

	
	void playLoadedSounds();

	
	Sint32 createSound();

	
	static SoundManager* getInstance();

protected:
	
	SoundManager();


private:

	
	Sint32 addSound(SDL_Renderer* Renderer, const char* file);


	Uint32 updateFirstFreeSlotSound();

	Mix_Chunk* sound;
	
	std::map<std::string, Sint32>	_IDMap;	
	Uint32				mFirstFreeSlot;		
	static SoundManager* pInstance;		
	SDL_Rect mSize;
	Mix_Chunk* Renderezizador;
	int frequency;
	Uint16 format;
	int channels;
	int chunksize;
	std::vector<Mix_Chunk*> sounds;
};

#endif
