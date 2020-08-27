#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include<ui/CocosGUI.h>
using namespace ui;
class how2playLayer:public Layer
{
public:
	CREATE_FUNC(how2playLayer);
	bool init();
	void update(float dt);

	void popDown(Ref* ref, Button::TouchEventType type);

};

