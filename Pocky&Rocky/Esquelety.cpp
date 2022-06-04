#include "Esquelety.h"
#include "Esquelety.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>

extern Camera* sCamera;
Esquelety::~Esquelety()
{
}

Esquelety::Esquelety()
{
	frame = 0;
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;
	// RAFEL2
	_estadosEsquelety = Esquelety::SPAWN;
	_instanceMap = nullptr;
}

void Esquelety::init(const char* image, int PosX, int PosY)
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.y = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.w = 32; // RAFEL: Cambio valores para ejemplo con guybush
	SizeGfx.h = 39; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.h = SizeGfx.h; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.w = SizeGfx.w; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.x = PosX; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	PositionRender.y = PosY; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	//mudar variaveis pelas variaveis que tenho em video
	_follow = false;
	_dir = DOWN;
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));


}

void Esquelety::update()
{
	_distX = ((_instancePersonaje->getPositionX()) + (_instancePersonaje->getSizeWidth() / 2));
	_distY = ((_instancePersonaje->getPositionY()) + (_instancePersonaje->getSizeHeight() / 2));
	//_cont++;

	switch (_estadosEsquelety)
	{
	case SPAWN:
		_contSpawn++;

		if (_contSpawn >= 25) {
				
				_estadosEsquelety = Esquelety::MOVE;

		}
		spawn();

		break;
	case MOVE:
		if (_distY >= PositionRender.y-100 && _distY <= PositionRender.y+ 100 && _distX >= PositionRender.x - 100 && _distX <= PositionRender.x + 100) {
			move();
		}
		
			if (_distX > PositionRender.x) {
				_dir = RIGHT;

			}
			else {
				_dir = LEFT;

			}

		
		if (_distX >= PositionRender.x && _distX <= PositionRender.x ) {
			if (_distY > PositionRender.y) {
				_dir = UP;
			}
			else
			{
				_dir = DOWN;
			}


			//_estadosUmby = ESQUELETY::ATTACK;

		}


		break;
		//if personaje esta 60 px cerca(ejemplo) ir _estadosEsquelety=ATTACK;
	case HURT:
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

void Esquelety::render()
{
	int animX = SizeGfx.x + SizeGfx.w * frame;
	
	if (_dir == RIGHT) {
		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - sCamera->getX(), PositionRender.y - sCamera->getY(),1);
	}
	else {

		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - sCamera->getX(), PositionRender.y - sCamera->getY());

		//Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x , PositionRender.y , 1);
	}

}

void Esquelety::updateFrame()
{

	switch (_estadosEsquelety)
	{
	case SPAWN:
		Maxframe = 3;
		maxTimeFrame = 200;
		break;
	case MOVE:
		Maxframe = 2;
		maxTimeFrame = 80;
		break;
	case HURT:
		Maxframe = 0;
		maxTimeFrame = 80;
		break;
	case DEAD:
		Maxframe = 5;
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

void Esquelety::spawn()
{
	
	switch (_dir)
	{
	case UP:
		
		SizeGfx.y = 0;
		break;
	case DOWN:
		

		SizeGfx.y = 0;

		break;
	case LEFT:
		

		SizeGfx.y = 0;
		break;
	case RIGHT:
		

		SizeGfx.y = 0;
		break;
	default:
		break;
	}
}

void Esquelety::move()
{
	switch (_dir)
	{
	case UP:
		PositionRender.y -= 1;

		SizeGfx.y = (9 * 6) + (9 * 6);
		collider(8);
		
		break;
	case DOWN:
		PositionRender.y += 1;
		
		SizeGfx.y = (9 * 4) + (9 * 4);
		collider(8);
		break;
	case LEFT:
		PositionRender.x -= 1;
		
		SizeGfx.y= (9 * 2) + (9 * 2);
		
		collider(4);
		break;
	case RIGHT:
		PositionRender.x += 1;
		
		SizeGfx.y = (9 * 2) + (9 * 2);
		
		collider(6);
		break;
	default:
		break;
	}
}

void Esquelety::hurt()
{
	SizeGfx.y = (14 * 5) + (14 * 5);
}



void Esquelety::dead()
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

void Esquelety::collider(int _dir)
{
	switch (_dir) {
	case 8:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + 6, PositionRender.y)) {
			PositionRender.y++;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x - 6, PositionRender.y)) {
			PositionRender.y++;
		}

		break;
	case 6:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + SizeGfx.w - 6, PositionRender.y)) {
			PositionRender.x--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x - 6, SizeGfx.h + PositionRender.y)) {
			PositionRender.x--;
		}
		break;
	case 4:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + 6, PositionRender.y)) {
			PositionRender.x++;
		}
		while (!_instanceMap->getIDfromLayer(PositionRender.x + 6, SizeGfx.h + PositionRender.y)) {
			PositionRender.x++;
		}
		break;
	case 2:
		while (!_instanceMap->getIDfromLayer(PositionRender.x + 6, PositionRender.y + SizeGfx.h)) {
			PositionRender.y--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x - 6, SizeGfx.h + PositionRender.y)) {
			PositionRender.y--;
		}
		break;

	default:
		break;
	}
}
