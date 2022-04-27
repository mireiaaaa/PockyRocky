#pragma once
#include "Principal.h"
#include "Mapa.h"

class Personaje :public Principal
{
public:
	~Personaje();
	Personaje();
	void init(const char* image);
	void update();
	void render();
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;

	int frame;
	int timeFrame;
	int maxTimeFrame;
};
