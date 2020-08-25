#pragma once
#include<cocos2d.h>
USING_NS_CC;
#include <ui/CocosGUI.h>
using namespace ui;
class basicUI:public Node
{
public:
	CREATE_FUNC(basicUI);
	bool init();
	void update(float dt);
	void uiclik(Ref* ref, Button::TouchEventType type);
};

