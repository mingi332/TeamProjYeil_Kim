#pragma once
#include<cocos2d.h>
USING_NS_CC;
#include <ui/CocosGUI.h>
using namespace ui;
class GameStartScene:public Scene
{
public:
	CREATE_FUNC(GameStartScene);
	bool init();
	void h2pClick(Ref* ref, Button::TouchEventType type);
	void rdyClick(Ref* ref, Button::TouchEventType type);
};

