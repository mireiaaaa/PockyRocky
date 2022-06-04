#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"


class YouWinScene :public Scene
{
public:
	~YouWinScene();
	YouWinScene();
	//enum statesYouWinScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _imgYouWin;

	//statesYouWinScene _estadosYouWinScene;



};

