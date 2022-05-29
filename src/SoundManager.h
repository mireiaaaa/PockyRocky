#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <vector>
typedef struct Mix_Chunk {
	int allocated;
	Uint8* _abuf;
	Uint32 _alen;
	Uint8 _volume; /* Per-sample volume, 0-128 */
} Mix_Chunk;

class SoundManager
{
public:

	//! Destructor.
	~SoundManager();


	void removeSound(const char* file);


	Sint32 loadAndGetSoundID(SDL_Renderer* Renderer, const char* file);



	
	std::string getSoundPathByID(Sint32 ID);


	void getSoundSize(Sint32 img, int& width, int& height);

	
	Uint16 getSoundWidth(Sint32 img);

	
	Uint16 getSoundHeight(Sint32 img);

	

	SDL_Texture* getSoundByID(Sint32 ID);

	
	void setAlphaSound(Sint32 ID, Uint8 alpha_value);

	
	void printLoadedSounds();

	
	Sint32 createSound(const char* name, Uint16 width, Uint16 height);

	
	static SoundManager* getInstance();

protected:
	//! Constructor of an empty SoundManager.
	SoundManager();


private:

	
	Sint32 addSound(SDL_Renderer* Renderer, const char* file);

	
	Uint32 updateFirstFreeSlotSound();

	
	std::vector<SDL_Texture*>	_TexureVector;
	//std::vector<SDL_Surface*>	_SoundsVector;	/*!<  Vector that stores Surfaces. Useful in render methods and sequential access*/
	std::map<std::string, Sint32>	_IDMap;			/*!<  Map that stores ID. Links strings to ID, Useful for check if Sound is has been loaded previously*/
	Uint32				mFirstFreeSlot;		/*!<  First free slot in the mSoundsVector*/
	static SoundManager* pInstance;		/*!<  Singleton instance*/
	SDL_Rect mSize;
	SDL_Renderer* Renderezizador;
	Mix_Chunk _chunk;
};

#endif


