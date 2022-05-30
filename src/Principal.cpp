#include "Principal.h"
#include "ResourceManager.h"
#include "Video.h"
Principal::Principal()
{
}

Principal::~Principal()
{
}



void Principal::init(const char* image)
{
	// RAFEL: Nada de surface. Solo Texture y se guarda en el ResourceManager

	// Image = NULL;
	// RAFEL: Nada de SDL
	// ImageTexture = NULL;
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
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
	Video::getInstance()->renderGraphic(IDGfx, SizeGfx.x, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x , PositionRender.y);
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




bool Principal::samePos(MyRectangle* _cube)
{
	if (_cube->x < PositionRender.x + SizeGfx.w &&
		_cube->x + _cube->w > PositionRender.x &&
		_cube->y < PositionRender.y + SizeGfx.h &&
		_cube->h + _cube->y > PositionRender.y) {
		return true;
	}
	return false;
}

MyRectangle* Principal::getCollision()
{
	MyRectangle _rect;
	_rect.x = PositionRender.x;
	_rect.y = PositionRender.y;
	_rect.h = SizeGfx.h;
	_rect.w = SizeGfx.w;
	return &_rect;
}

void Principal::isHurt()
{
	
}

void Principal::update()
{
}


