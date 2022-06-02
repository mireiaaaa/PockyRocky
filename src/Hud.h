#pragma once

#include "Mapa.h"
#include "Principal.h"
#include "Personaje.h"


class Hud :public Principal
{
public:
	~Hud();
	Hud();
	enum _ImgHud { PONTUACIONCERO,PONTUACIONNUM,CORAZON, ICONO };
	void init();
	void update();
	void render();
	void reinit();



private:
	Principal _corazon;
	Principal _pontuacionCero;
	Principal _pontuacionNum;
	Principal _icono;

	_ImgHud _img;

	void pontuacionCero();
	void pontuacionNum();
	void corazon();
	void icono();
};