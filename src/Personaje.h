#pragma once
#include "Principal.h"
#include "Mapa.h"

class Personaje :public Principal
{
public:
	//RAFEL 2
	enum StatesPersonaje {
		ST_IDLE, ST_WALK, ST_IDLEATTACK, ST_WALKATTACK, ST_DEFEND
	};
	~Personaje();
	Personaje();
	void init(const char* image);
	void update();
	void render();
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	// RAFEL2
	StatesPersonaje _state;
	void updateFrame();
	void idleaction();
	void walking();
	void walkandAttack();
	void idleandAttack();
	void protecting();
};
