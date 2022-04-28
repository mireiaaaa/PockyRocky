#include "Personaje.h"
#include "Video.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include<iostream>
extern int tecla;
extern Camera* _cam;
Personaje::~Personaje()
{


}

Personaje::Personaje()
{
	frame = 0;
	timeFrame = 0;
	maxTimeFrame = 100;

}



void Personaje::init(const char* image)
{

	//DANDO ERRO N SEI PQ AAAA
	// RAFEL: Guarda la ID que loadAndGetGraphicID te devuelve. No sabes que numero va a ocupar tu grafico en el almacen.
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), image);
	SizeGfx.x = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.y = 0; // RAFEL: Si queremos cambiar el frame, estos son los valores a tocar.
	SizeGfx.w = 34; // RAFEL: Cambio valores para ejemplo con guybush
	SizeGfx.h = 28; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.h = SizeGfx.h; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.w = SizeGfx.w; // RAFEL: Cambio valores para ejemplo con guybush
	PositionRender.x = 200; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	PositionRender.y = 350; // RAFEL: Estos son los valores a cambiar si lo quiero mover.
	//mudar variaveis pelas variaveis que tenho em video
	 _dir= DOWN;


}


void Personaje::update()
{
	

	timeFrame += Video::getInstance()->getDeltaTime();
	if (timeFrame >= maxTimeFrame) {
		frame++;
		if (frame > 4) frame = 0;
		timeFrame = 0;
	}
	
	if (InputManager::getInstance()->getAtaque() == true) {

		_atacando = true;

		//collider(6);

	}
	if (InputManager::getInstance()->getRight() == true) {
		PositionRender.x += 5; 
		_estado = MOVE;
		_dir = RIGHT;

		collider(6);
		
	}

	if (InputManager::getInstance()->getLeft() == true) {
		PositionRender.x -= 5;
		_estado = MOVE;
		_dir = LEFT;
		collider(4);
		
	}
	if (InputManager::getInstance()->getUp() == true) {
		PositionRender.y -= 5;
		_estado = MOVE;
		_dir = UP;
		collider(8);
		
	}
	if (InputManager::getInstance()->getDown() == true) {
		PositionRender.y += 5;
		_estado = MOVE;
		_dir = DOWN;
		collider(2);
		
	}
	/*
	if (InputManager::getInstance()->getParado()||) {
		_estado = IDLE;
		frame = 0;
	}
	*/
	if (!InputManager::getInstance()->getRight() && !InputManager::getInstance()->getLeft() && !InputManager::getInstance()->getUp() && !InputManager::getInstance()->getDown()) {
		_estado = IDLE;
		frame = 0;
	}

	switch (_dir)
	{
	case DOWN:
		if (_estado == MOVE) {
			SizeGfx.x = 0;
			SizeGfx.y = 0;
			/*
			if (_atacando) {
				SizeGfx.x = 0;
				SizeGfx.y = (27 * 6) + (7 * 6);
			}
			*/
	
			//colocar animacao
		}

		if (_estado == IDLE) {
			
			SizeGfx.x = 0;
			SizeGfx.y = 0;
		}
		break;
	case UP:
		if (_estado == MOVE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27*4)+(7*4);

	
			//colocar animacao
		}

		if (_estado == IDLE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27 * 4) + (7* 4);
		}
		break;
	case LEFT:
		if (_estado == MOVE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27 * 2) + (7 * 2);
			//colocar animacao
		}

		if (_estado == IDLE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27 * 2) + (7 * 2);
		}
		break;
	case RIGHT:
		if (_estado == MOVE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27 * 2) + (7 * 2);
			//colocar animacao
		}

		if (_estado == IDLE) {
			SizeGfx.x = 0;
			SizeGfx.y = (27 * 2) + (7 * 2);
		}
		break;
	default:
		break;
	}

}
void Personaje::render() {
	// RAFEL: Usa la ID que loadAndGetGraphicID te devuelve. No sabes que numero va a ocupar tu grafico en el almacen.
	
	int animX = SizeGfx.x + SizeGfx.w * frame;

	if (_dir == RIGHT) {
		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - _cam->getX(), PositionRender.y - _cam->getY(),1);
	}
	else {
		Video::getInstance()->renderGraphic(IDGfx, animX, SizeGfx.y, SizeGfx.w, SizeGfx.h, PositionRender.x - _cam->getX(), PositionRender.y - _cam->getY());
	}
}

void Personaje::collider(int _dir)
{
	switch (_dir) {
	case 8:
		while (!_instanceMap->getIDfromLayer(PositionRender.x+6, PositionRender.y)) {
			PositionRender.y++;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x-6, PositionRender.y)) {
			PositionRender.y++;
		}

		break;
	case 6:
		while (!_instanceMap->getIDfromLayer(PositionRender.x+SizeGfx.w-6, PositionRender.y)) {
			PositionRender.x--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x-6, SizeGfx.h + PositionRender.y)) {
			PositionRender.x--;
		}
		break;
	case 4:
		while (!_instanceMap->getIDfromLayer(PositionRender.x+6, PositionRender.y)) {
			PositionRender.x++;
		}
		while (!_instanceMap->getIDfromLayer(PositionRender.x+6, SizeGfx.h + PositionRender.y)) {
			PositionRender.x++;
		}
		break;
	case 2:
		while (!_instanceMap->getIDfromLayer(PositionRender.x +6, PositionRender.y+SizeGfx.h)) {
			PositionRender.y--;
		}
		while (!_instanceMap->getIDfromLayer(SizeGfx.w + PositionRender.x-6, SizeGfx.h + PositionRender.y)) {
			PositionRender.y--;
		}
		break;
		
	default:
		break;
	}
}
