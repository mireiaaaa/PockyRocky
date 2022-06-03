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
	PositionRender.x = 1700; 
	PositionRender.y = 100;
	
	_follow = false;
	_dir = LEFT;
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));
	_numAle = 2;
	_contShoot = 0;
	_contWalk = 0;
	_contRoll = 0;
	_contHurt = 0;
}

void Boss::update()
{
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));

	
	

	switch (_estadosBoss)
	{
	case WALK:
		srand(time(NULL));
		_contShoot = 0;
		_contWalk++;
		
		_contRoll = 0;
		if (_contWalk >= 25) {

			if (_numAle == 1) {
				_estadosBoss = Boss::SHOOT;
				_numAle = 0;
			}
			else if (_numAle == 2) {
				_estadosBoss = Boss::ROLL;
				_numAle = 0;
			}

		}
		walk();

		break;
	case ROLL:
		_contWalk = 0;
		_contRoll++;
		if (_contRoll <= 25) {

			if (_distY >= PositionRender.y - 2 && _distY <= PositionRender.y + 2) {

				if (_distX > PositionRender.x) {
					_dir = RIGHT;
					
				}
				else {
					_dir = LEFT;
					
				}

			}
			if (_distX >= PositionRender.x - 2 && _distX <= PositionRender.x + 2) {
				if (_distY > PositionRender.y) {
					_dir = DOWN;
				}
				else
				{
					_dir = UP;
				}


			}

		}

		else
		{
			_estadosBoss = Boss::WALK;
		}
		roll();


		break;
	case SHOOT:
		_contWalk = 0;
		_contShoot++;
		
		if (_contShoot <= 25) {

			if (_distY >= PositionRender.y - 2 && _distY <= PositionRender.y + 2) {

				if (_distX > PositionRender.x) {
					_dir = RIGHT;
					
				}
				else {
					_dir = LEFT;
					
				}

			}
			if (_distX >= PositionRender.x - 2 && _distX <= PositionRender.x + 2) {
				if (_distY > PositionRender.y) {
					_dir = DOWN;
				}
				else
				{
					_dir = UP;
				}


			}
		}
			break;
	case HURT:
		_contWalk = 0;
		_contHurt++;
		if (_contHurt <= 20) {
			_estadosBoss = Boss::DEAD;
		}
		hurt();
		break;
	case DEAD:
		
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
	case ROLL:
		Maxframe = 4;
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

	currentTimeFrame += Video::getInstance()->getDeltaTime();
	if (currentTimeFrame >= maxTimeFrame) {
		frame++;
		if (frame >= Maxframe)
		{
			frame = 0;
		}
		currentTimeFrame = 0;
	}

}

void Boss::roll()
{

	switch (_dir)
	{
	case UP:
		PositionRender.y -= 1;

		SizeGfx.y = (12 * 3) + (12 * 3);
		collider(8);

		break;
	case DOWN:
		PositionRender.y += 1;

		SizeGfx.y = (12 * 3) + (12 * 3);
		collider(8);
		break;
	case LEFT:
		PositionRender.x -= 1;

		SizeGfx.y += (12 * 3) + (12 * 3);

		collider(4);
		break;
	case RIGHT:
		PositionRender.x += 1;

		SizeGfx.y = (12 * 3) + (12 * 3);

		collider(6);
		break;
	default:
		break;
	}
}

void Boss::walk()
{
	switch (_dir)
	{
	
	case LEFT:
		PositionRender.x -= 3;

		SizeGfx.y = (12 * 0) + (12 * 0);

		collider(4);
		if (PositionRender.x <= 20) {
			_dir = RIGHT;
		}
		break;
	case RIGHT:
		PositionRender.x += 3;

		SizeGfx.y = (12 * 0) + (12 * 0);

		collider(6);
		break;
	default:
		break;
	}
}

void Boss::shoot()
{
	
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
