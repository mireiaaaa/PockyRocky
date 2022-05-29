#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"


class OptionsScene :public Scene
{
public:
	~OptionsScene();
	OptionsScene();
	//enum statesOptionsScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _imgOptions;

	//statesOptionsScene _estadosOptionsScene;



};

