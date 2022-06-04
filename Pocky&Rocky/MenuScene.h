#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"
#include "SceneDirector.h"


class MenuScene :public Scene
{
public:
	~MenuScene();
	MenuScene();
	//enum statesMenuScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();


	
private:
	Principal _imgMenu;
	Principal _arrow;
	//statesMenuScene _estadosMenuScene;
	int _arrowPos;
	int _cont;
	

};

