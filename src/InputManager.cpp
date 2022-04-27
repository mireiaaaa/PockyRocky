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
			_parado = false;
			if (test_event.key.keysym.scancode == SDL_SCANCODE_D) {
				right = true;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_A) {
				left = true;
			}
			
			if (test_event.key.keysym.scancode == SDL_SCANCODE_S) {
				down = true;
			}
			
			if (test_event.key.keysym.scancode == SDL_SCANCODE_W) {
				up = true;
			}
			
			break;
		case SDL_KEYUP:
			_parado = true;
			if (test_event.key.keysym.scancode == SDL_SCANCODE_D) {
				right = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_A) {
				left = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_S) {
				down = false;
			}
			if (test_event.key.keysym.scancode == SDL_SCANCODE_W) {
				up = false;
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

bool InputManager::getParado()
{
	return _parado;
}
