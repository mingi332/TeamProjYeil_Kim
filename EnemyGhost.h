#pragma once
#include <cocos2d.h>
USING_NS_CC;

class EnemyGhost : public Node
{
public:
	CREATE_FUNC(EnemyGhost);

	float ghost_speed;
	Vec2 PlayerDir;			//플레이어로 향하는 방향
	Vec2 PlayerPos;		//플레이어 위치 찾기 위한 변수
	

	bool init();
	void update(float dt);
	void FindPlayer();

	Rect Getthebox();
};

