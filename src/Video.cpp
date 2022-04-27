#include "Video.h"
#include "ResourceManager.h"
#include "sdl.h"
#include "Defines.h"

Video* Video::unica_instancia = NULL;
Video::Video() {
	_windowRect.x = 0;
	_windowRect.y = 0;
	_windowRect.w = SCREEN_WIDTH;
	_windowRect.h = SCREEN_HEIGHT;


	gWindow = NULL;
	gRenderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	gWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(gRenderer, 256, 224);
	SDL_RenderSetViewport(gRenderer, &_windowRect);
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	NowTime = 0;
	DeltaTime = 0;
	PastTime = 0;

}
Video::~Video() {
}

// RAFEL: Al hacer texture en RenderCopy, no puede haber un null. Se ha de especificar
//        X,Y,W,H del origen
void Video::renderGraphic(int img, int posXGfx, int posYGfx, int width, int height, int posXScreen, int posYScreen) {
	SDL_Rect rGfx, rScreen;
	rGfx.x = posXGfx;
	rGfx.y = posYGfx;
	rGfx.w = width;
	rGfx.h = height;
	rScreen.x = posXScreen;
	rScreen.y = posYScreen;
	rScreen.w = width;
	rScreen.h = height;
	SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);
	// RAFEL: Al hacer texture en RenderCopy, no puede haber un null. Se ha de especificar
	//        X,Y,W,H del origen
	SDL_RenderCopy(gRenderer, origin, &rGfx, &rScreen);
}

void Video::renderGraphic(int img, int posXGfx, int posYGfx, int width, int height, int posXScreen, int posYScreen,bool flip) {
	SDL_Rect rGfx, rScreen;
	rGfx.x = posXGfx;
	rGfx.y = posYGfx;
	rGfx.w = width;
	rGfx.h = height;
	rScreen.x = posXScreen;
	rScreen.y = posYScreen;
	rScreen.w = width;
	rScreen.h = height;
	SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);
	// RAFEL: Al hacer texture en RenderCopy, no puede haber un null. Se ha de especificar
	//        X,Y,W,H del origen
	SDL_RenderCopyEx(gRenderer, origin, &rGfx, &rScreen,0.0,0,SDL_FLIP_HORIZONTAL);
}

void Video::setRenderColor(int r, int g, int b, int a)
{
}
SDL_Renderer* Video::getRenderer()
{
	return gRenderer;
}

void Video::clearScreen() {
	SDL_RenderClear(gRenderer);
}

void Video::updateScreen() {
	// RAFEL: NOOO RenderUpdate. Nada de Surfaces
	//SDL_UpdateWindowSurface(gWindow);
	SDL_RenderPresent(gRenderer);
	NowTime = SDL_GetTicks();
	DeltaTime = NowTime - PastTime;
	PastTime = NowTime;
}
void Video::waitTime(int ms) {
	SDL_Delay(ms);
}
void Video::close() {
	// RAFEL: Aquí cerramos todo el sistema de SDL.
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}



