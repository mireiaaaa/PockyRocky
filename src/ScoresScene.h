#pragma once
#include "Scene.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <fstream>
#include "Principal.h"
class ScoresScene : public Scene
{
    Principal _imgScores;

    std::string _text[7];
    std::fstream _handler;
    int IDGfx;
public:
    ScoresScene();
    ~ScoresScene();
    void init();
    void render();
    void update();
    void ShowScore(int posY, int posX, int _score);
    void reinit();
    void setScore(int score);

};
