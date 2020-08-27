#include "GamePlayScene.h"
#include "BackGround.h"
#include "Player.h"
#include "basicUI.h"
#include "Bubble.h"
#include "appleItem.h"
#include "GameStartScene.h"
#include "effect.h"
#include "EnemyGhost.h"


bool GamePlayScene::init()
{
	//����
	Maxitem = 15;			//�� ������ �� �ִ� ���� �⺻�� (���)
	ItemCnt = 0;


	//���� �ð�
	upgradetime = 1.0f;		//���ĵ� ���� �ð� �⺻ 10��
	carrot_time = 0;		//���
	apple_time = 0;			//���
	bubble_time = 0;		//��
	upgradebubbletime = 30.0f; // �� ���� �ð� �⺻ 30��

	//�� ���� �ð�
	ghost_time = 0.0f;		//�⺻ 30�� 

	BackGround* bg = BackGround::create();
	this->addChild(bg);

	Player* p1 = Player::create();
	this->addChild(p1,1,"player");
	p1->setPosition(300, 150);

	basicUI* ui = basicUI::create();
	this->addChild(ui,10);

	effect* ef = effect::create();
	this->addChild(ef, 1, "ef");

	this->scheduleUpdate();

	return true;
}

void GamePlayScene::update(float dt)
{
	Player* p1 = (Player*)this->getChildByName("player");
	effect* ef = (effect*)this->getChildByName("ef");
	
	//��� �浹ó��
	Carrot* ct = (Carrot*)this->getChildByName("carrot");
	for (Carrot* ct : vCarrot)
	{
		if (p1 != nullptr && ct != nullptr)
		{
			Rect rt = p1->gettheBox();
			Rect rt2 = ct->gettheBox();
			
			if (rt.intersectsRect(rt2) == true)
			{
				ef->EatEffect();
				p1->weight += ct->carrotweight;
				vCarrot.eraseObject(ct);
				ct->removeFromParentAndCleanup(true);
				ItemCnt--;
				break;			
			}
		}
	}


	//��� �浹ó��
	appleItem* app = (appleItem*)this->getChildByName("carrot");
	for (appleItem* app : vApple)
	{
		if (p1 != nullptr && app != nullptr)
		{
			Rect rt = p1->gettheBox();
			Rect rt2 = app->getBoundingBox();

			if (rt.intersectsRect(rt2) == true)
			{
				ef->EatEffect();
				p1->weight += app->appleweight;
				vApple.eraseObject(app);
				app->removeFromParentAndCleanup(true);
				ItemCnt--;
				break;
			}
		}
	}

	//���� �浹ó��
	Bubble* bub = (Bubble*)this->getChildByName("bubble");
	if (p1 != nullptr && bub != nullptr)
	{
		Rect rt = p1->gettheBox();
		Rect rt2 = bub->gettheBox();

		if (rt.intersectsRect(rt2) == true)
		{
			bub->setPosition(p1->getPosition());
		}
	}
	




	//������ ���� (���)
	carrot_time += dt;

	if (carrot_time >= upgradetime)
	{
		makeCarrot();
		carrot_time = 0;
	}

	//������ ���� (���)

	apple_time += dt;

	if (apple_time >= upgradetime)
	{
		makeApple();
		apple_time = 0;
	}

	//������ ���� (����)

	bubble_time += dt;

	if (bubble_time >= upgradebubbletime)
	{
		makeBubble();
		bubble_time = -9999; //(1���� �����ǰ� �ϱ� ����, �浹 �� ����)
	}

	//�� ���� (����)
	ghost_time += dt;

	if (ghost_time >= 5)
	{
		makeGhost();
		ghost_time -= 6;
	}



}

void GamePlayScene::StartGame()
{
	CCDirector::sharedDirector()->resume();
}

void GamePlayScene::StopGame()
{
	CCDirector::sharedDirector()->pause();
}



void GamePlayScene::makeCarrot()
{

	int random_Y = CCRANDOM_0_1() * 280 + 100;
	int random_X = CCRANDOM_0_1() * 500 + 50;


	if (ItemCnt < Maxitem)
	{
		Carrot* ct = Carrot::create();
		this->addChild(ct, 1, "carrot");

		ct->setPosition(random_X, random_Y);

		vCarrot.pushBack(ct);
		ItemCnt++;
	}

	else return;
}

void GamePlayScene::makeApple()
{
	int random_Y = CCRANDOM_0_1() * 280 + 100;
	int random_X = CCRANDOM_0_1() * 500 + 50;


	if (ItemCnt < Maxitem)
	{
		appleItem* app = appleItem::create();
		this->addChild(app, 1, "apple");

		app->setPosition(random_X, random_Y);

		vApple.pushBack(app);
		ItemCnt++;
	}

	else return;
}

void GamePlayScene::makeBubble()
{
	int random_Y = CCRANDOM_0_1() * 280 + 100;
	int random_X = CCRANDOM_0_1() * 500 + 50;

	Bubble* bub = Bubble::create();
	this->addChild(bub, 1, "bubble");

	bub->setPosition(random_X, random_Y);

}

void GamePlayScene::makeGhost()
{
	//int random_X = CCRANDOM_0_1() * 700 + 400;
	//int random_Y = CCRANDOM_0_1() * 500 + 300;

	EnemyGhost* eg = EnemyGhost::create();
	this->addChild(eg, 1, "ghost");
	eg->setPosition(400, 400);
}

//void GamePlayScene::makeEnmey_Heli()
//{
//}


