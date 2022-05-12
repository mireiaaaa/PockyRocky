#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Video.h"
#include "ResourceManager.h"

class Fantasmita :public Principal
{
public:
	~Fantasmita();
	Fantasmita();
	void init(const char* image);
	void update();
	void render();
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
};
