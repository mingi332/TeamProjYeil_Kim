#pragma once
#include <cocos2d.h>
USING_NS_CC;


class EnemyHeli : public Node
{
public:
	CREATE_FUNC(EnemyHeli);
	bool init();
	void update(float dt);

	float fly_man_speed;
	
};

