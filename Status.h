#pragma once
#include <cocos2d.h>
USING_NS_CC;
#include <ui/CocosGUI.h>
using namespace ui;


class Status : public Layer
{
public:
	CREATE_FUNC(Status);
	bool init();
	void update(float dt);


	void closeStatus(Ref* ref, Button::TouchEventType type);

	void TouchPlayer(Ref* ref, Button::TouchEventType type);

};

