#pragma once
// RAFEL: No ha de haber nada de SDL aqu�. Esto ya est� en Video
// #include "sdl.h"
// #include <cmath> //RAFEL: No la usas en este h. Has solo include de lo que se use.

// RAFEL: Dado que no puedes poner NADA de SDL fuera de los singletons, hay que inventarse nuestro propio Rectangle
struct MyRectangle
{
	int x,y,w,h;
};
enum Estado { IDLE,MOVE,ATTACK,HURT,DEAD };
enum Dir { UP, DOWN, LEFT, RIGHT };

class Principal
{
	
public:
	Principal();
	~Principal();

	int getPositionX() { return PositionRender.x; };
	int getPositionY() { return PositionRender.y; };
	int getSizeWidth() { return SizeGfx.w; }
	int getSizeHeight() { return SizeGfx.h; }
	double getAngulo() { return Angulo; }; // RAFEL: estaba a int en vez de double
	virtual void init();
	//void loadImage( const char* file);
	//void loadImage(SDL_Renderer *renderer,const char* file);
	virtual void render();
	void setAngulo(double value) { Angulo = value; };
	void setPositionX(int value) { PositionRender.x = value; };
	void setPositionXY(int valueX, int valueY) { PositionRender.x = valueX; PositionRender.y = valueY; };
	void setPositionY(int value) { PositionRender.y = value; };
	// RAFEL: Nada de surface. Solo Texture y se guarda en el ResourceManager
	//void setScreenSurface(SDL_Surface* punterSurface);
	// RAFEL: No ha de haber nada de SDL aqu�. Esto ya est� en Video
	//void setRenderer(SDL_Renderer* punterRender);
	void setSize(int valueW, int valueH) { SizeGfx.w = valueW; SizeGfx.h = valueH; };
	void setSizeHeight(int value) { SizeGfx.h = value; };
	void setSizeWidth(int value) { SizeGfx.w = value; };
	virtual void update();
protected:
	// RAFEL: Nada de surface. Solo Texture y se guarda en el ResourceManager
	// RAFEL: Guarda la ID que loadAndGetGraphicID te devuelve. No sabes que numero va a ocupar tu grafico en el almacen.
	int IDGfx;
	//SDL_Surface* Image;

	// RAFEL: No ha de haber nada de SDL aqu�.
	MyRectangle PositionRender;

	// RAFEL: No ha de haber nada de SDL aqu�. Esto ya est� en Video
	//SDL_Surface* ScreenSurface;
	//SDL_Renderer* renderer;

	// RAFEL: No ha de haber nada de SDL aqu�.
	MyRectangle SizeGfx;
	double Angulo;
	
	Estado _estado;
	Dir _dir;
	// RAFEL: No ha de haber nada de SDL aqu�. Esto ya est� en ResourceManager
	// SDL_Texture* ImageTexture;
};


