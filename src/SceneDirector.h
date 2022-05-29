#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <vector>
#include "Scene.h"

//! Enum Scenes.
/*! All the Scenes in the game. */


enum statesSceneDirector { MENU, SCORES, OPTIONS, ANIMATIC, MAIN, GAMEOVER, YOUWIN, _LASTSCENE };

#define NUM_SCENES _LASTSCENE

class SceneDirector
{
public:
	~SceneDirector();

	void init();

	void changeScene(statesSceneDirector next_scene, bool reinit = true);

	statesSceneDirector getCurrSceneEnum() { return mCurrScene; };

	Scene* getCurrentScene() { return mVectorScenes[mCurrScene]; };

	//! Gets pointer to instance
	static SceneDirector* getInstance();

protected:
	SceneDirector();
	static SceneDirector* pInstance;	/*!<  pointer instance*/

	std::vector<Scene*>	mVectorScenes;
	statesSceneDirector		mCurrScene;
};

#endif
