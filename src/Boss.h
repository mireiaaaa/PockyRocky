#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Personaje.h"
#include <stdlib.h>
#include <time.h>

class Boss :public Principal
{
public:
	~Boss();
	Boss();
	enum statesBoss { WALK,ROLL,SHOOT, HURT, DEAD };
	void init(const char* image);
	void update();
	void render();

	void updateFrame();
	void walk();
	void roll();
	void shoot();
	void hurt();
	void dead();


	void setPos(Personaje* _personaje) { _instancePersonaje = _personaje; };
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	Personaje* _instancePersonaje;
	statesBoss _estadosBoss;

	int _contWalk;
	int _contRoll;
	int _contShoot;
	int _contHurt;

	int _distX;
	int _distY;
	bool _follow;
	int _numAle;
};

