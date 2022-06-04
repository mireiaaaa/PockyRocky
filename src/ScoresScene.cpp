
#include "ScoresScene.h"
#include "Video.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>
#include "SceneDirector.h"
extern InputManager* sInputControl;
extern SceneDirector* sDirector;


ScoresScene::~ScoresScene()
{
}

ScoresScene::ScoresScene()
{
}

void ScoresScene::init()
{
	IDGfx = ResourceManager::getInstance()->loadAndGetGraphicID(Video::getInstance()->getRenderer(), "pontuacionNum.png");
	setScore(0);
	_imgScores.init("score.png");
	_imgScores.setSize(258, 226);
	_imgScores.setPositionXY(0, 0);

	for (int i = 0; i <= 5; i++) {
		_text[i] = "0";
	}
}

void ScoresScene::update()
{
	if (sInputControl->getAtaque()) {
		sDirector->changeScene(MENU, 1);
	}
}
void ScoresScene::setScore(int _score)
{
	for (int i = 0; i <= 5; i++) {
		_text[i] = "0";
	}

	_text[5] = std::to_string(_score);
	_handler.open("highscore.txt", std::ios::in);

	if (!_handler.is_open()) {
		_handler.open("highscore.txt", std::ios::out);
		_handler << _text[5];
		_handler << std::endl;
	}
	else {
		for (int i = 0; i <= 4; i++) {
			if (_handler.eof()) {
				break;
			}
			getline(_handler, _text[i]);
			if (_text[i] == "") {
				_text[i] = "0";
			}
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				_text[6] = _text[j];
				if (_text[j + 1] == "") {
					_text[j + 1] = "0";
				}
				if (stoi(_text[j]) <= stoi(_text[j + 1])) {
					_text[j] = _text[j + 1];
					_text[j + 1] = _text[6];
				}
			}
		}
		_handler.close();
		_handler.open("highscore.txt", std::ios::out);
		for (int i = 0; i <= 5; i++) {
			if (_text[i] == "0") break;
			_handler << _text[i];
			_handler << std::endl;
		}
	}
	_handler.close();
}

void ScoresScene::ShowScore(int posX, int posY, int _score)
{
	int offset = 0;
	int numero = 0;
	int nScore = _score;


	offset = 9 * 4;
	numero = 0;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);


	numero = nScore % 100;
	if (numero != 0) {
		numero = numero / 10;
	}
	offset = 9 * 3;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);
	numero = nScore % 1000;
	if (numero != 0) {
		numero = numero / 100;
	}
	offset = 9 * 2;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);

	numero = nScore % 10000;
	if (numero != 0) {
		numero = numero / 1000;
	}
	offset = 9 * 1;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);

	numero = nScore % 100000;
	if (numero != 0) {
		numero = numero / 10000;
	}
	offset = 9 * 0;

	Video::getInstance()->renderGraphic(IDGfx, 0, 9 * numero, 9, 9, posX + offset, posY);


}

void ScoresScene::render()
{
	_imgScores.render();
	ShowScore(102,83,std::stoi(_text[0]));
	ShowScore(102,97,std::stoi(_text[1]));
	ShowScore(102,114,std::stoi(_text[2]));
	ShowScore(102,131,std::stoi(_text[3]));
	ShowScore(102,147,std::stoi(_text[4]));




}

void ScoresScene::reinit()
{
	
	mReinit = false;
}






