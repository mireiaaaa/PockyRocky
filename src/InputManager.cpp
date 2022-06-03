#include "InputManager.h"
#include <iostream>
using namespace std;

InputManager* InputManager::unica_instancia = NULL;


InputManager::InputManager() {

	right = false;
	left = false;
	up = false;
	down = false;
	_parado = true;
	_out = false;
}
InputManager::~InputManager()
{
}
void InputManager::update()
{

	while (SDL_PollEvent(&test_event)) {
		switch (test_event.type) {
		case SDL_KEYDOWN:

			if (test_event.key.keysym.scancode == SDL_SCANCODE_D) {
				right = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_A) {
				left = true;
				//_parado = false;
			}

			if (test_event.key.keysym.scancode == SDL_SCANCODE_S) {
				down = true;
				//_parado = false;
			}

			if (test_event.key.keysym.scancode == SDL_SCANCODE_W) {
				up = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_P) {
				_protect = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_E) {
				_slide = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_Z) {
				_special = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_H) {
				_hurt = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_M) {
				_dead = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				_ataque = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				_out = true;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				_enter = true;
				//_parado = false;
			}

			break;
		case SDL_KEYUP:

			if (test_event.key.keysym.scancode == SDL_SCANCODE_D) {
				right = false;
				//_parado = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_A) {
				left = false;
				//_parado = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_S) {
				down = false;
				//_parado = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_W) {
				up = false;
				//_parado = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_P) {
				_protect = false;
				//_parado = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_E) {
				_slide = false;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_Z) {
				_special = false;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_H) {
				_hurt = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_M) {
				_dead = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				_ataque = false;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				_out = false;
				//_parado = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				_enter = false;
				//_parado = false;
			}

			break;
		default: break;
		}

	}
}
//hacer un update que cuando se da la tecla se pone a true y cuando solta la tecla se pone a false
bool InputManager::getRight()
{
	return right;
}

bool InputManager::getLeft()
{
	return left;
}

bool InputManager::getDown()
{
	return down;
}

bool InputManager::getUp()
{
	return up;
}


bool InputManager::getAtaque()
{
	return _ataque;
}

bool InputManager::getProtect()
{
	return _protect;
}

bool InputManager::getSlide()
{
	return _slide;
}

bool InputManager::getSpecial()
{
	return _special;
}

bool InputManager::getHurt()
{
	return _hurt;
}

bool InputManager::getDead()
{
	return _dead;
}

bool InputManager::getOut()
{
	return _out;
}

bool InputManager::getEnter()
{
	return _enter;
}


/*

bool InputManager::getParado()
{
	return _parado;
}

*/