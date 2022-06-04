#pragma once
#include "Principal.h"
#include "Mapa.h"
#include "Personaje.h"
#include <stdlib.h>
#include <time.h>
#include "Balas.h"
class Boss :public Principal
{
public:
	~Boss();
	Boss();
	enum statesBoss { WALK,SHOOT, DEAD };
	void init(const char* image);
	void update();
	void render();

	void updateFrame();
	void walk();
	void shoot();
	
	void dead();
	void isHurt();
	bool getDead() { return _dead; };
	int getHP() { return _life; };
	void setPos(Personaje* _personaje) { _instancePersonaje = _personaje; };
	void setPos(vector<Balas*>* _bala) { _instanceBala = _bala; };
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);

	int BossEstado() { return (int)_estadosBoss; };
private:
	Mapa* _instanceMap;
	Personaje* _instancePersonaje;
	statesBoss _estadosBoss;
	vector<Balas*>* _instanceBala;

	int _contWalk;

	int _contShoot;
	int _life;
	bool _dead;
	int _contMov;
	bool _dirShoot;
	int _contBalas;
	int _deadCount;
	int _distX;
	int _distY;
	
	
	

		
};

