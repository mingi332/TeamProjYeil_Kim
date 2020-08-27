#pragma once
#include <cocos2d.h>
USING_NS_CC;

class EnemyGhost : public Node
{
public:
	CREATE_FUNC(EnemyGhost);

	float ghost_speed;
	Vec2 PlayerDir;			//�÷��̾�� ���ϴ� ����
	Vec2 PlayerPos;		//�÷��̾� ��ġ ã�� ���� ����
	

	bool init();
	void update(float dt);
	void FindPlayer();

	Rect Getthebox();
};

