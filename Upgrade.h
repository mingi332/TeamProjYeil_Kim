#pragma once
#include <cocos2d.h>
USING_NS_CC;
#include <ui/CocosGUI.h>
using namespace ui;

class Upgrade : public Layer
{
public:
	CREATE_FUNC(Upgrade);
	bool init();
	
	void CloseUpgrade(Ref* ref, Button::TouchEventType type);
	void MoveUpgrade(Ref* ref, Button::TouchEventType type);
	int MoveUpgradeCnt;

	void FoodUpgrade(Ref* ref, Button::TouchEventType type);
	int FoodUpgradeCnt;

	void FoodValueupgrade(Ref* ref, Button::TouchEventType type);
	int FoodValueUpgradeCnt;
};

