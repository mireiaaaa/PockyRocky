#pragma once

#include "Mapa.h"
#include "Principal.h"
#include "Personaje.h"


class Hud :public Principal
{
public:
	~Hud();
	Hud();
	void setPos(Personaje* _personaje) { _instancePersonaje = _personaje; };
	enum _ImgHud { PONTUACIONCERO,PONTUACIONNUM,CORAZON, ICONO };
	void init();
	void update();
	void render();
	void reinit();
	void ShowScore(int posY, int posX, int _score);
	void ShowLife(int posY, int posX, int _HP);



private:
	Personaje* _instancePersonaje;
	Principal _corazon;
	Principal _pontuacionCero;
	Principal _pontuacionNum;
	Principal _icono;

	int _mScore;
	_ImgHud _img;
	int IDHeart;
	void pontuacionCero();
	void pontuacionNum();
	void corazon();
	void icono();
};