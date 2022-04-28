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
			if (test_event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				_ataque = true;
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
			if (test_event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				_ataque = false;
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

/*

bool InputManager::getParado()
{
	return _parado;
}

*/