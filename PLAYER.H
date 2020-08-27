#pragma once
#include <cocos2d.h>
USING_NS_CC;

class Player : public Node
{
public:
	CREATE_FUNC(Player);
	bool init();
	void update(float dt);

	float scale;				//플레이어의 크기 (업그레이드 요소)
	float MoveSpeed;			//플레이어의 속도 (업그레이드 요소)
	float weight;				//플레이어의 체중 (기본 2.0f, 10배수 도달마다 스케일 0.1배 증가)

	

	void mouseDown(Event* ev);
	void dontGetout();			//화면 바깥으로 나가는 것 방지하기 위한 예외처리
	Vec2 Direction;				//방향
	Vec2 PlayerPos;				//플레이어 위치 저장
	Vec2 CursorPos;				//커서 위치 저장

	Rect gettheBox();

	
};

