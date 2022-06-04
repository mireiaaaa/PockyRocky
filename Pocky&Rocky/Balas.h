#pragma once
#include "Principal.h"
#include "Mapa.h"

class Balas :public Principal
{
public:
	~Balas();
	Balas();
	enum statesBalas { ATTACK, DEAD };
	enum typeSprite {POCKY,BOSS};
	void init(int _tipoSprite, int dir, int PosX, int PosY);
	void update();
	void render();

	/*
	void updateFrame();
	void floating();*/
	void attacking();
	void dead();
	
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
private:
	Mapa* _instanceMap;
	statesBalas _estadosBalas;
	typeSprite _tipoSprite;
	bool _zig;
	int _cont;
	int _distX;
	int _distY;
	bool _follow;

};
