#include "SceneDirector.h"
#include "MenuScene.h"
#include "OptionsScene.h"
#include "ScoresScene.h"
#include "SceneMain.h"
#include "GameOverScene.h"
#include "YouWinScene.h"
#include "AnimaticScene.h"

#include <iostream>

SceneDirector* SceneDirector::pInstance = NULL;

SceneDirector* SceneDirector::getInstance() {
	if (!pInstance) {
		pInstance = new SceneDirector();
	}
	return pInstance;
}

SceneDirector::SceneDirector() {
	init();
}

SceneDirector::~SceneDirector() {
}

void SceneDirector::init() {
	mVectorScenes.resize(NUM_SCENES);
	

	ScoresScene* _scoresScene = new ScoresScene();
	OptionsScene* _optionsScene = new OptionsScene();
	AnimaticScene* _animaticScene = new AnimaticScene();
	MainScene* _mainScene = new MainScene();
	YouWinScene* _youWinScene = new YouWinScene();
	GameOverScene* _gameOver = new GameOverScene();
	
	mVectorScenes[SCORES] = main;
	mVectorScenes[SELECT_CHARACTER] = SelectCharacter;
	mVectorScenes[STATS] = Stats;
	mVectorScenes[INIT_LEVEL] = InitGame;
	mVectorScenes[PAUSE] = Pause;
	mVectorScenes[GAME] = game;
	mVectorScenes[GAMEOVER] = _gameOver;


	_gameOver->init();

	mCurrScene = MAIN;
}

void SceneDirector::changeScene(statesSceneDirector next_scene, bool reinit) {
	mVectorScenes[next_scene]->setReInit(reinit);
	mCurrScene = next_scene;
	std::cout << "Escena: " << next_scene << std::endl;
}
