#pragma once

#include "Mapa.h"
#include "Principal.h"


class Hud :public Principal
{
public:
	~Hud();
	Hud();
	//enum statesHud { SPAWN, MOVE, HURT, DEAD };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _img;

	//statesHud _estadosHud;



};