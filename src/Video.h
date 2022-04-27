#include "sdl.h"

class Video
{
	SDL_Rect _windowRect;
	static Video* unica_instancia;
	Video();

	Uint32 NowTime, DeltaTime, PastTime;

public:

	~Video();
	// RAFEL: Al hacer texture en RenderCopy, no puede haber un null. Se ha de especificar
	//        X,Y,W,H del origen
	void renderGraphic(int img, int posXGfx, int posYGfx, int width, int height, int posXScreen, int posYScreen);
	void renderGraphic(int img, int posXGfx, int posYGfx, int width, int height, int posXScreen, int posYScreen,bool flip);

	void setRenderColor(int r, int g, int b, int a = 255);
	// RAFEL: No la has definido. Si lo haces, recuerda: Nada de surface. Se hace con renderer.
	void clearScreen();
	SDL_Renderer* getRenderer();
	void updateScreen();
	void waitTime(int ms);
	Uint32 getDeltaTime() { return DeltaTime; };
	void close();


	static Video* getInstance()
	{
		if (unica_instancia == NULL)
			unica_instancia = new Video();

		return unica_instancia;
	}

	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;

};
