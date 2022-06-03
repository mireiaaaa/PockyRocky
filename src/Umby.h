#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Personaje.h"


class Umby :public Principal
{
public:
	~Umby();
	Umby();
	enum statesUmby { IDLE, MOVE, DEAD };
	void init(const char* image, int PosX, int PosY);
	void update();
	void render();

	void updateFrame();
	void idle();
	void move();
	void hurt();
	void dead();


	void setPos(Personaje* _personaje) { _instancePersonaje = _personaje; };
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	Personaje* _instancePersonaje;
	statesUmby _estadosUmby;
	int _contIdle;
	int _distX;
	int _distY;
	bool _follow;

};

