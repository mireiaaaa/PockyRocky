#pragma once
#include "Scene.h"
#include "Mapa.h"
#include "Principal.h"


class ScoresScene :public Scene
{
public:
	~ScoresScene();
	ScoresScene();
	//enum statesScoresScene { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _imgScores;

	//statesScoresScene _estadosScoresScene;



};

