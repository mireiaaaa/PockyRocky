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
	Maxframe = 0;
	currentTimeFrame = 0;
	maxTimeFrame = 100;
	// RAFEL2
	_state = Personaje::ST_IDLE;
	_instanceMap = nullptr;
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
	switch (_state)
	{
	case Personaje::ST_IDLE:
		idleaction();
		if (InputManager::getInstance()->getAtaque() == true) {//tá atacando
			_state = Personaje::ST_IDLEATTACK;
		}
		if (InputManager::getInstance()->getRight() ||
			InputManager::getInstance()->getLeft() ||
			InputManager::getInstance()->getUp() ||
			InputManager::getInstance()->getDown()) {
			_state = Personaje::ST_WALK;
		}
		if (InputManager::getInstance()->getProtect() == true) { // Se proteje
			_state = Personaje::ST_DEFEND;
		}
		break;
	case Personaje::ST_WALK:
		walking();
		if (InputManager::getInstance()->getAtaque() == true) {//tá atacando
			_state = Personaje::ST_WALKATTACK;
		}
		if (!InputManager::getInstance()->getRight() &&
			!InputManager::getInstance()->getLeft() &&
			!InputManager::getInstance()->getUp() &&
			!InputManager::getInstance()->getDown()) {
			_state = Personaje::ST_IDLE;
		}
		break;

		break;
	case Personaje::ST_IDLEATTACK:
		idleaction();
		idleandAttack();
		if (InputManager::getInstance()->getRight() ||
			InputManager::getInstance()->getLeft() ||
			InputManager::getInstance()->getUp() ||
			InputManager::getInstance()->getDown()) {
			_state = Personaje::ST_WALKATTACK;
		}
		if (InputManager::getInstance()->getAtaque() == false) {//deja de atacar
			_state = Personaje::ST_IDLE;
		}
		break;
	case Personaje::ST_WALKATTACK:
		walking();
		walkandAttack();
		if (!InputManager::getInstance()->getRight() &&
			!InputManager::getInstance()->getLeft() &&
			!InputManager::getInstance()->getUp() &&
			!InputManager::getInstance()->getDown()) {
			_state = Personaje::ST_IDLEATTACK;
		}
		if (InputManager::getInstance()->getAtaque() == false) {//deja de atacar
			_state = Personaje::ST_WALK;
		}
		break;
	case Personaje::ST_DEFEND:
		protecting();
		if (InputManager::getInstance()->getProtect() == false) {// deja de proteger
			_state = Personaje::ST_IDLE;
		}
		break;
	default:
		break;
	}
	updateFrame();

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

// RAFEL2
void Personaje::updateFrame()
{
	switch (_state)
	{
	case Personaje::ST_IDLE:
		Maxframe = 1;
		maxTimeFrame = 0;
		break;
	case Personaje::ST_WALK:
		Maxframe = 5;
		maxTimeFrame = 80;
		break;
	case Personaje::ST_IDLEATTACK:
		// RAFEL2 : Preparalo tu
		Maxframe = 3;
		maxTimeFrame = 80;
		break;
	case Personaje::ST_WALKATTACK:
		// RAFEL2 : Preparalo tu
		Maxframe = 3;
		maxTimeFrame = 80;
		break;
	case Personaje::ST_DEFEND:
		// RAFEL2 : Preparalo tu
		Maxframe = 5;
		maxTimeFrame = 80;
		break;
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

void Personaje::idleaction()
{
	switch (_dir)
	{
	case UP:
		SizeGfx.y = (27 * 4) + (7 * 4);
		break;
	case DOWN:
		SizeGfx.y = 0;
		break;
	case LEFT:
		SizeGfx.y = (27 * 2) + (7 * 2);
		break;
	case RIGHT:
		SizeGfx.y = (27 * 2) + (7 * 2);
		break;
	default:
		break;
	}
}

void Personaje::walking()
{
	if (InputManager::getInstance()->getRight() == true) {
		PositionRender.x += 5;
		SizeGfx.y = (27 * 2) + (7 * 2);
		_dir = RIGHT;
		collider(6);
	}
	if (InputManager::getInstance()->getLeft() == true) {
		PositionRender.x -= 5;
		SizeGfx.y = (27 * 2) + (7 * 2);
		_dir = LEFT;
		collider(4);

	}
	if (InputManager::getInstance()->getUp() == true) {
		PositionRender.y -= 5;
		SizeGfx.y = (27 * 4) + (7 * 4);
		_dir = UP;
		collider(8);

	}
	if (InputManager::getInstance()->getDown() == true) {
		PositionRender.y += 5;
	
		SizeGfx.y = 0;
		_dir = DOWN;
		collider(2);

	}
}

void Personaje::walkandAttack()
{
	switch (_dir)
	{
	case UP:
		SizeGfx.y += (27 * 5) + (7 * 5);
		break;
	case DOWN:
		SizeGfx.y += (27 * 5) + (7 * 5);
		break;
	case LEFT:
		SizeGfx.y += (27 * 5) + (7 * 5);
		break;
	case RIGHT:
		SizeGfx.y += (27 * 5) + (7 * 5);
		break;
	default:
		break;
	}
}

void Personaje::idleandAttack()
{
	switch (_dir)
	{
	case UP:
		SizeGfx.y += (27 * 10) + (7 * 10);
		break;
	case DOWN:
		SizeGfx.y += (27 * 10) + (7 * 10);
		break;
	case LEFT:
		SizeGfx.y += (27 * 10) + (7 * 10);
		break;
	case RIGHT:
		SizeGfx.y += (27 * 10) + (7 * 10);
		break;
	default:
		break;
	}
}

void Personaje::protecting()
{
	switch (_dir)
	{
	case UP:
		SizeGfx.y = (27 * 19) + (7 * 19);
		break;
	case DOWN:
		SizeGfx.y = (27 * 15) + (7 * 15);
		break;
	case LEFT:
		SizeGfx.y = (27 * 17) + (7 * 17);
		break;
	case RIGHT:
		SizeGfx.y = (27 * 17) + (7 * 17);
		break;
	default:
		break;
	}
}
