#pragma once
#include <cocos2d.h>
USING_NS_CC;
using namespace std;


class GamePlayScene : public Scene
{
public:
	CREATE_FUNC(GamePlayScene);
	bool init();
	void update(float dt);


	void mouseDown(Event* ev);
};

