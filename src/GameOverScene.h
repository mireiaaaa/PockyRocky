#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"


class GameOverScene :public Scene
{
public:
	~GameOverScene();
	GameOverScene();
	//enum statesGameOverScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _imgGameOver;

	//statesGameOverScene _estadosGameOverScene;



};

