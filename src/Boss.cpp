#include "Boss.h"
#include "Boss.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>

extern Camera* sCamera;
Boss::~Boss()
{
}

Boss::Boss()
{
	frame = 0;
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;
	// RAFEL2
	_estadosBoss = Boss::WALK;
	_instanceMap = nullptr;
}

void Boss::init(const char* image)
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; 
	SizeGfx.y = 0; 
	SizeGfx.w = 69;
	SizeGfx.h = 76; 
	PositionRender.h = SizeGfx.h;
	PositionRender.w = SizeGfx.w; 
	PositionRender.x = 1555;
	PositionRender.y = 90;


	_dir = LEFT;
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));

	_contShoot = 0;
	_contWalk = 0;

	_dead = false;
	_life = 30;
	_contMov = 0;
	_contShoot=0;
	_dirShoot = false;
	_contBalas = 0;
}

void Boss::update()
{
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));

	
	int distx = (PositionRender.x + PositionRender.w / 2) - _distX;
	int disty = (PositionRender.y + PositionRender.h / 2) - _distY;


	switch (_estadosBoss)
	{
	case WALK:
	
		_contShoot = 0;
		_contWalk++;
		
		
		
		if (_contWalk >= 250) {
			
			
			
			
			_estadosBoss = Boss::SHOOT;
			_dirShoot = true;
			

			

		}
		walk();

		break;

	case SHOOT:
		
		_contWalk = 0;
		_contShoot++;
		_contBalas++;
		if (_contBalas >= 10) {
			Balas* bala;
			bala = new Balas();
			bala->init(1, _dir, PositionRender.x + PositionRender.w / 2-10, PositionRender.y + PositionRender.h / 2+10);
			_instanceBala->push_back(bala);
			_contBalas = 0;
		}
		

		if (_dirShoot == true) {

			if (abs(distx) >= abs(disty)) {//muda valor negativo pra positivo
				if (distx >= 0) {
					_dir = LEFT;
				}
				else {
					_dir = RIGHT;
				}
			}
			else {
				if (disty >= 0) {
					_dir = UP;
				}
				else {
					_dir = DOWN;
				}
			}
			shoot();
			_dirShoot = false;
		}
		
		if (_contShoot >= 120) {
			_estadosBoss = Boss::WALK;
		}

		break;
	case HURT:
		_contWalk = 0;
		if (_life <= 0) {
			_estadosBoss = Boss::DEAD;
		}
		hurt();
		break;
	case DEAD:
		_dead = true;
		dead();
		
		break;

	default:
		break;
		
		
	}
	updateFrame();
}

void Boss::render()
{
	int animX = SizeGfx.x + SizeGfx.w * frame;
	if (_dir == RIGHT) {
		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - sCamera->getX(), PositionRender.y - sCamera->getY(), 1);
	}
	else {

		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - sCamera->getX(), PositionRender.y - sCamera->getY());
	}
	


}

void Boss::updateFrame()
{

	switch (_estadosBoss)
	{
	case WALK:
		Maxframe = 3;
		maxTimeFrame = 80;
		break;
	case SHOOT:
		Maxframe = 5;
		maxTimeFrame = 80;
		break;
	case HURT:
		Maxframe = 1;
		maxTimeFrame = 80;
		break;
	case DEAD:
		Maxframe = 2;
		maxTimeFrame = 80;
	default:
		break;
	}
	if(_estadosBoss != Boss::SHOOT){
	currentTimeFrame += Video::getInstance()->getDeltaTime();
	if (currentTimeFrame >= maxTimeFrame) {
		frame++;
		if (frame >= Maxframe)
		{
			frame = 0;
		}
		currentTimeFrame = 0;
	}}

}


void Boss::walk()
{
	switch (_dir)
	{
	
	case LEFT:
		_contMov++;
		PositionRender.x -= 1;

		SizeGfx.y = (12 * 0) + (12 * 0);
		if(_contMov>=200){
			_dir = RIGHT;
			_contMov = 0;
		}
		collider(4);
		
		break;
	case RIGHT:
		_contMov++;
		PositionRender.x += 1;

		SizeGfx.y = (12 * 0) + (12 * 0);
		if (_contMov >= 200) {
			_dir = LEFT;
			_contMov = 0;
		}
		collider(6);
		break;
	default:
		_dir = RIGHT;
		break;
	}
}

void Boss::shoot()
{
	SizeGfx.y = (12 * 5) + (12 * 5);
	switch (_dir)
	{
	case UP:
		frame = 3;
		break;
	case DOWN:
		frame = 1;
		break;
	case LEFT:
		frame = 2;
		break;
	case RIGHT:
		frame = 2;
		break;
	default:
		break;
	}
}

void Boss::hurt()
{
	SizeGfx.y = (14 * 5) + (14 * 5);
}



void Boss::dead()
{
	switch (_dir) {
	case UP:
		SizeGfx.y = (14 * 6) + (14 * 6);
		break;
	case DOWN:
		SizeGfx.y = (14 * 6) + (14 * 6);
		break;
	case LEFT:
		SizeGfx.y = (14 * 6) + (14 * 6);

		break;

	case RIGHT:
		SizeGfx.y = (14 * 6) + (14 * 6);
		break;
	default:
		break;
	}
}

void Boss::isHurt()
{
	
	_life--;
	
}

//ERRO COM A COLISAO DO BOSS, FICA PRESO NA PAREDE
void Boss::collider(int _dir)
{
	switch (_dir) {
	case 8:
		while (!_instanceMap->getIDfromLayer(PositionRender.x, PositionRender.y)) {
			PositionRender.y++;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x , PositionRender.y)) {
			PositionRender.y++;
		}

		break;
	case 6:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + SizeGfx.w , PositionRender.y)) {
			PositionRender.x--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x , SizeGfx.h + PositionRender.y)) {
			PositionRender.x--;
		}
		break;
	case 4:
		while (!_instanceMap->getIDfromLayer(PositionRender.x , PositionRender.y)) {
			PositionRender.x++;
		}
		while (!_instanceMap->getIDfromLayer(PositionRender.x , SizeGfx.h + PositionRender.y)) {
			PositionRender.x++;
		}
		break;
	case 2:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + 4, PositionRender.y + SizeGfx.h)) {
			PositionRender.y--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x - 4, SizeGfx.h + PositionRender.y)) {
			PositionRender.y--;
		}
		break;

	default:
		break;
	}
}
