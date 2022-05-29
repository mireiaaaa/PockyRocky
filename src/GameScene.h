#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"
#include "sdl.h"
#include <stdlib.h>
#include <time.h>
#include "SDL_image.h" // RAFEL: Lo que son ficheros propios, de tu proyecto, se pone con "". <> se usa para los include del sistema C
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

class GameScene :public Scene
{
public:
	~GameScene();
	GameScene();
	//enum statesGameScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	//Principal _imgGame;
	Personaje Player;
	Mapa Map;
	Fantasmita Ghost;
	Esquelety Esque;
	Umby Umb;
	Boss Nopino;
	vector<Balas*> Bala;

	//statesGameScene _estadosGameScene;



};

