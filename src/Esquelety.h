#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Personaje.h"


class Esquelety :public Principal
{
public:
	~Esquelety();
	Esquelety();
	enum statesEsquelety { SPAWN,MOVE,HURT, DEAD };
	void init(const char* image, int PosX, int PosY);
	void update();
	void render();

	void updateFrame();
	void spawn();
	void move();
	void hurt();
	void dead();


	void setPos(Personaje* _personaje) { _instancePersonaje = _personaje; };
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	Personaje* _instancePersonaje;
	statesEsquelety _estadosEsquelety;
	int _contSpawn;
	int _distX;
	int _distY;
	bool _follow;

};

