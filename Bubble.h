#pragma once
#include <cocos2d.h>
USING_NS_CC;

class Bubble : public Node
{
public:
	CREATE_FUNC(Bubble);
	bool init();


	Rect gettheBox();
};

