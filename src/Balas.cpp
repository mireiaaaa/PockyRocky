#include "Balas.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>

extern Camera* _cam;
Balas::~Balas()
{
}

Balas::Balas()
{
	frame = 0;
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 60;
	// RAFEL2
	_estadosBalas = Balas::ATTACK;
	_instanceMap = nullptr;
}

void Balas::init(int _tipoSprite,int dir,int PosX,int PosY)
{
	//IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.y = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.w = 19; // RAFEL: Cambio valores para ejemplo con guybush
	SizeGfx.h = 27; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.h = SizeGfx.h; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.w = SizeGfx.w; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.x = PosX;
	PositionRender.y = PosY;

	//mudar variaveis pelas variaveis que tenho em video
	_follow = false;
	_dir = (Dir)dir;
	switch (_dir)
	{
	case UP:
		PositionRender.x -= 8  ;
		PositionRender.y -= 35;
		break;
	case DOWN:
		PositionRender.x -= 8;
		PositionRender.y += 2;
		break;
	case LEFT:
		PositionRender.x -= 34 / 2;
		PositionRender.y -= 28 / 2;
		break;
	
	default:
		break;

	}
	switch (_tipoSprite) {
	case POCKY:
		IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "balas.png");
		break;
	case ESQUELETY:
		//IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "balas.png");
		break;
	case BOSS:
		//IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "balas.png");
		break;
	default:
		break;
		

	}
}

void Balas::update()
{

	
	switch (_estadosBalas)
	{
	
	case ATTACK:
		//sigue el personaje
		attacking();

		break;
	case DEAD:
		dead();


		break;
	default:
		break;
	}
	


}

void Balas::render()
{
	

	Video::getInstance()->renderGraphic(IDGfx, 0, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - _cam->getX(), PositionRender.y - _cam->getY());
	//Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x , PositionRender.y , 1);


}




void Balas::attacking()
{
	switch (_dir) {


	case LEFT:
		PositionRender.x -= 5;
		SizeGfx.y = (14 * 1) + (14 * 1);

		break;

	case RIGHT:
		PositionRender.x += 5;
		SizeGfx.y = (14 * 3) + (14 * 3);
		break;
	case UP:
		PositionRender.y -= 5;
		SizeGfx.y = 0;

		break;
	case DOWN:
		PositionRender.y += 5;
		SizeGfx.y = (14 * 2) + (14 * 2);

		break;
	default:
		break;
	}

}

void Balas::dead()
{

}

void Balas::collider(int _dir)
{
}
