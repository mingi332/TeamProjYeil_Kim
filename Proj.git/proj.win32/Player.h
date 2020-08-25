#pragma once
#include <cocos2d.h>
USING_NS_CC;

class Player : public Node
{
public:
	CREATE_FUNC(Player);
	bool init();
	void update(float dt);

	
};

