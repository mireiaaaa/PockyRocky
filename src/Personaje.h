#pragma once
#include "Principal.h"
#include "Balas.h"
//#include "Fantasmita.h"
#include "Mapa.h"
#include<vector>


class Personaje :public Principal
{
public:
	//RAFEL 2
	enum StatesPersonaje {
		ST_IDLE, ST_WALK, ST_IDLEATTACK, ST_WALKATTACK, ST_DEFEND, ST_SLIDE,ST_SPECIAL, ST_HURT,ST_DEAD
	};
	
	~Personaje();
	Personaje();
	void init(const char* image);
	void update();
	void render();
	void setPos(Mapa* _map) { _instanceMap = _map; };
	void collider(int _dir);
	void setPos( vector<Balas*> *_bala) { _instanceBala = _bala; };
	void isHurt();
	void moreScore();
	int getScore();
	int getHP();
	int PockyEstado();
	bool getDead();
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
	void slide();
	void special();
	void hurt();
	void dead();
	
	int _score;
	int _cont;
	bool _ground;
	int _specialCount;
	bool _oneTime;
	int _hurting;
	//variables test
	int _hurtCount;
	int _deadCount;
	int _life;
	bool _isHurt;
	bool _isDead;
	int _contBalas;
	vector<Balas*> * _instanceBala;
};
