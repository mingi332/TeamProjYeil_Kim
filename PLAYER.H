#pragma once
#include <cocos2d.h>
USING_NS_CC;

class Player : public Node
{
public:
	CREATE_FUNC(Player);
	bool init();
	void update(float dt);

	float scale;				//�÷��̾��� ũ�� (���׷��̵� ���)
	float MoveSpeed;			//�÷��̾��� �ӵ� (���׷��̵� ���)
	float weight;				//�÷��̾��� ü�� (�⺻ 2.0f, 10��� ���޸��� ������ 0.1�� ����)

	

	void mouseDown(Event* ev);
	void dontGetout();			//ȭ�� �ٱ����� ������ �� �����ϱ� ���� ����ó��
	Vec2 Direction;				//����
	Vec2 PlayerPos;				//�÷��̾� ��ġ ����
	Vec2 CursorPos;				//Ŀ�� ��ġ ����

	Rect gettheBox();

	
};
