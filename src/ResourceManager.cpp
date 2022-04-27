#include "ResourceManager.h"
#include "SDL_image.h"
//#include "SDL_mixer.h"
#include "Principal.h"
#include <iostream>

ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::removeGraphic(const char* file)
{
}

Sint32 ResourceManager::loadAndGetGraphicID(SDL_Renderer* Renderer, const char* file)
{
	if (_IDMap.find(file) == _IDMap.end()) {
		return addGraphic(Renderer, file);
	}
	else {
		return _IDMap.find(file)->second;
	}
}

std::string ResourceManager::getGraphicPathByID(Sint32 ID)
{
	return "-1";
}

void ResourceManager::getGraphicSize(Sint32 img, int& width, int& height)
{
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
	SDL_RendererInfo* Info = NULL;
	SDL_GetRendererInfo(Renderezizador, Info);
	return Info->max_texture_width;
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
	SDL_RendererInfo* Info = NULL;
	SDL_GetRendererInfo(Renderezizador, Info);
	return Info->max_texture_height;
}

SDL_Texture* ResourceManager::getGraphicByID(Sint32 ID)
{
	return _TexureVector[ID];

}

void ResourceManager::setAlphaGraphic(Sint32 ID, Uint8 alpha_value)
{
	SDL_SetTextureAlphaMod(getGraphicByID(ID), alpha_value);
}

void ResourceManager::printLoadedGraphics()
{
}

Sint32 ResourceManager::createGraphic(const char* name, Uint16 width, Uint16 height)
{
	return 0;
}

ResourceManager* ResourceManager::getInstance()
{
	if (pInstance == NULL)pInstance = new ResourceManager();
	return pInstance;
}

Sint32 ResourceManager::addGraphic(SDL_Renderer* Renderer, const char* file)
{
	SDL_Texture* texture = IMG_LoadTexture(Renderer, file);
	// RAFEL: Image no se usa que es surface, TODO Texture
	if (!texture) {
		//error
		return -1;
	}

	_TexureVector.push_back(texture);

	_IDMap.insert(std::pair<std::string, int>(file, _TexureVector.size() - 1));

	return _IDMap.find(file)->second;
}

Uint32 ResourceManager::updateFirstFreeSlotGraphic()
{
	return 0;
}
