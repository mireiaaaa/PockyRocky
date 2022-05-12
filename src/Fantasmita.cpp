#include "Fantasmita.h"
#include "Video.h"
#include "ResourceManager.h"
#include "Camera.h"

extern Camera* _cam;
Fantasmita::~Fantasmita()
{
}

Fantasmita::Fantasmita()
{
	frame = 0;
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;
	// RAFEL2
	_estadosFantasmita = Fantasmita::MOVE;
	_instanceMap = nullptr;
}

void Fantasmita::init(const char* image)
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.y = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.w = 19; // RAFEL: Cambio valores para ejemplo con guybush
	SizeGfx.h = 24; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.h = SizeGfx.h; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.w = SizeGfx.w; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.x = 100; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	PositionRender.y = 350; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	//mudar variaveis pelas variaveis que tenho em video
	
	_dir = DOWN;

}

void Fantasmita::update()
{
	_cont++;
	if (_cont == 30) {
		_zig = !_zig;
		_cont = 0;
	}
	switch (_estadosFantasmita)
	{
	case MOVE:
		floating();
	/*
		//zig-zag
		PositionRender.x +=2;
		PositionRender.x -= 2;
		*/

		//if personaje esta 60 px cerca(ejemplo) ir _estadosFantasmita=ATTACK;
		break;
	case ATTACK:
		//sigue el personaje
		break;
	case DEAD:
		break;
	default:
		break;
	}
	updateFrame();


}

void Fantasmita::render()
{
	int animX = SizeGfx.x + SizeGfx.w * frame;

	Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - _cam->getX(), PositionRender.y - _cam->getY());
		//Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x , PositionRender.y , 1);
	
	
}

void Fantasmita::updateFrame()
{
	
	switch (_estadosFantasmita)
	{
	case MOVE:
		Maxframe = 2;
		maxTimeFrame = 600;
		break;
	case ATTACK:

		break;
	case DEAD:
		
		break;
	default:
		break;
	}
	if (_estadosFantasmita != Fantasmita::MOVE) {
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
}

void Fantasmita::floating()
{
	switch (_dir)
	{
	case UP:
		
		break;
	case DOWN:
		PositionRender.y += 1;
		if (_zig==true) {
			PositionRender.x -= 1;
			frame = 0;
		}
		else {
			PositionRender.x += 1;
			frame = 1;
		}
		SizeGfx.y = (14 * 2) + (14 * 2);
		
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	default:
		break;
	}
}

void Fantasmita::dead()
{
}

void Fantasmita::collider(int _dir)
{
}
