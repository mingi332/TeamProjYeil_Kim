#pragma once
#include <cocos2d.h>
#include "Carrot.h"
#include "appleItem.h"
#include "EnemyHeli.h"
USING_NS_CC;
using namespace std;
using namespace ui;
#include <ui/CocosGUI.h>
class GamePlayScene : public Scene
{
public:
	CREATE_FUNC(GamePlayScene);
	bool init();
	void update(float dt);
	int Maxitem;				//���� �ִ� ������ �����ϱ� ���� ���� (�⺻ 15)
	int ItemCnt;

	float upgradetime;			//���׷��̵� �� ������ �����ֱ� ����


	//���� ���߱�
	void StartGame();
	void StopGame();

	//�浹ó�� �ϴ� �Լ�

	//��� ������ ���� ���ǵ�
	
	float carrot_time;			//��� ���� �ֱ�
	void makeCarrot();			//����� �������ִ� �Լ�
	Vector<Carrot*> vCarrot;

	//��� ������ ���� ���ǵ�
	
	float apple_time;
	void makeApple();
	Vector<appleItem*> vApple;

	//���� ������ ���� ���ǵ�
	float bubble_time;			//���� �����ֱ� (���� �浹�� 9999), (��ֹ� �浹 �� 30)
	float upgradebubbletime;	//���׷��̵� ���
	void makeBubble();

	//heli �� ������ ���� ���ǵ�
	/*float heli_time;
	void makeEnmey_Heli();
	Vector<EnemyHeli*> vHeli;*/

	//ghost �� ������ ���� ���ǵ�
	float ghost_time;
	void makeGhost();
	
};

