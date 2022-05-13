#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Personaje.h"


class Fantasmita :public Principal
{
public:
	~Fantasmita();
	Fantasmita();
	enum statesFantasmita {ATTACK,MOVE,DEAD};
	void init(const char* image);
	void update();
	void render();

	void updateFrame();
	void floating();
	void dead();

	void setPos(Personaje* _pocky) { _instancePocky = _pocky; };
	
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	Personaje* _instancePocky;
	statesFantasmita _estadosFantasmita;
	bool _zig;
	int _cont;
	int _distX;
	int _distY;

};
