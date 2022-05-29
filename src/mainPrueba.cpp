#include "sdl.h"
#include <stdlib.h>
#include <time.h>
#include "SDL_image.h" // RAFEL: Lo que son ficheros propios, de tu proyecto, se pone con "". <> se usa para los include del sistema C
#include "Principal.h"
#include "Video.h"
#include "InputManager.h"
#include "Mapa.h"
#include "Camera.h"
#include <vector>
#include "Balas.h"
#include "Fantasmita.h"
#include "Esquelety.h"
#include "Personaje.h"
#include "Umby.h"
#include "Boss.h"
using namespace std;
#include<iostream>

#define RECT_WIDTH  100
#define RECT_HEIGHT 80
Camera* _cam;

int main(int argc, char* args[]) {	
	_cam = Camera::getInstance();
	SDL_Event test_event;
	Video::getInstance();

	//int pos=0;
	int coiso = 1;
	srand(time(NULL));//gera numero aleatorio
	//const Uint8* state; // RAFEL: Si quieres usar el GetKeyboardState, se usa despues de hacer el bucle de Eventos.

	//Background Fondo;
	Personaje Player;
	Mapa Map;
	Fantasmita Ghost;
	Esquelety Esque;
	Umby Umb;
	Boss Nopino;
	vector<Balas*> Bala;

	// RAFEL: Tras crear el objeto, te falta iniciarlo
	Ghost.setPos(&Player);
	Esque.setPos(&Player);
	Umb.setPos(&Player);
	Nopino.setPos(&Player);
	Player.setPos(&Bala);
	

	Player.init("pocky.png");
	Ghost.init("fantasmita.png");
	Esque.init("esquelety.png");
	Umb.init("umby.png");
	Nopino.init("boss.png");
	Map.init("tilesetpoqui.png");
	
	Player.setPos(&Map);
	Esque.setPos(&Map);
	Umb.setPos(&Map);
	Nopino.setPos(&Map);
	
	
	_cam->setPos(&Player);
	_cam->setPos(&Map);
	_cam->init();
	//Rocks Piedra;
	
	//Fondo.setScreenSurface(screenSurface);
	//Player.setScreenSurface(screenSurface); E AGORA COM O VIDEO??
	//Piedra.setScreenSurface(screenSurface);

	//INIT
	//Fondo.init();
	//Player.init();
	//Piedra.init();

	while (InputManager::getInstance()->getOut() == false) { // RAFEL: Faltaba el ==, solo tenias 1 =

		InputManager::getInstance()->update();
		Video::getInstance()->clearScreen();
		for (size_t i = 0; i < Bala.size(); i++)
		{
			Bala[i]->update();
		}
		Player.update();
		Ghost.update();
		Esque.update();
		Umb.update();
		Nopino.update();
		_cam->update();
		Map.update();
		
		
		Map.render();
		Esque.render();
		Player.render();
		Ghost.render();
		Nopino.render();
		for (size_t i = 0; i < Bala.size(); i++)
		{
			Bala[i]->render();
		}
		Umb.render();
		
	
		Video::getInstance()->updateScreen();
		// RAFEL : En video tenemos las funciones que refrescan el frame
		//SDL_UpdateWindowSurface(window); // RAFEL: Nada de surface
		//SDL_Delay(10); // RAFEL: No hace falta esperar, porque el Renderer ya se espera los 60 fps necesarios.
	}

	//SDL_DestroyWindow(window); // RAFEL: Se encarga de esto Video, no el main
	Video::getInstance()->close();

	return 0;
}

