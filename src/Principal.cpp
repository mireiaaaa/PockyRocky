#include "Principal.h"

Principal::Principal()
{
}

Principal::~Principal()
{
}



void Principal::init()
{
	// RAFEL: Nada de surface. Solo Texture y se guarda en el ResourceManager

	// Image = NULL;
	// RAFEL: Nada de SDL
	// ImageTexture = NULL;
	PositionRender.h = 0;
	PositionRender.w = 0;
	PositionRender.y = 0;
	PositionRender.x = 0;
	// RAFEL: Nada de SDL
	//ScreenSurface = nullptr;
	//renderer = nullptr;

	SizeGfx.h = 0;
	SizeGfx.w = 0;
	SizeGfx.x = 0;
	SizeGfx.y = 0;


}

/*
void Principal::loadImage( const char * file)
{

	Image= IMG_Load(file);

	PositionRender.w = Image->w;
	PositionRender.h = Image->h;

	ImageTexture = SDL_CreateTextureFromSurface(renderer, Image);
}
*/


void Principal::render()
{

}

// RAFEL: Nada de SDL
//void Principal::setScreenSurface(SDL_Surface* punterSurface)
//{
//	ScreenSurface = punterSurface;
//}
//
//void Principal::setRenderer(SDL_Renderer * punterRender)
//{
//	renderer = punterRender;
//}




void Principal::update()
{
}


