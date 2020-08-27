#pragma execution_character_set("UTF-8")
#include "Status.h"
#include "PLAYER.H"
#include "GamePlayScene.h"

bool Status::init()
{
	//�������ͽ� â ����
	Sprite* ugs = Sprite::create("UI/green_panel.png");
	this->addChild(ugs);
	ugs->setPosition(Vec2(300, 250));
	ugs->setScale(5, 3);

	//�������ͽ� â ���� Ŭ�� ����
	Button* ug = Button::create("UI/green_panel.png");
	this->addChild(ug);
	ug->setPosition(Vec2(300, 250));
	ug->setScale(5, 3);
	ug->setOpacity(0);

	//���׷��̵� â �ݱ�(�����)
	Button* back = Button::create("Background/SkyBack.jpg");
	this->addChild(back);
	back->setZOrder(-999);
	back->setPosition(Vec2(300, 200));
	back->setOpacity(0);
	back->Button::addTouchEventListener(CC_CALLBACK_2(Status::closeStatus, this));


	//�÷��̾� ���� :)
	Button* PlayerSprite = Button::create("Player/wingMan1.png");
	this->addChild(PlayerSprite);
	PlayerSprite->setPosition(Vec2(130, 250));
	PlayerSprite->setScale(0.5);
	PlayerSprite->Button::addTouchEventListener(CC_CALLBACK_2(Status::TouchPlayer, this));


	//�÷��̾� ���� ���
	//����
	Label* Weight = Label::createWithTTF("0", "fonts/HoonWhitecatR.ttf", 40);
	this->addChild(Weight,1,"WL");
	Weight->setPosition(400, 330);
	//string strW = StringUtils::format("���� : %.1lf kg", p1->weight);
	//Weight->setString(strW);

	//�̵��ӵ�
	Label* MoveSpeed = Label::createWithTTF("0", "fonts/HoonWhitecatR.ttf", 40);
	this->addChild(MoveSpeed,1,"MSL");
	MoveSpeed->setPosition(400, 280);
	/*string strM = StringUtils::format("�ӵ� : %.1lf ", p1->MoveSpeed);
	MoveSpeed->setString(strM);*/

	//���� ���� ���� ����
	Label* FoodCount = Label::createWithTTF("0", "fonts/HoonWhitecatR.ttf", 40);
	this->addChild(FoodCount, 1, "FCL");
	FoodCount->setPosition(400, 230);

	
	

	this->scheduleUpdate();
	





	return true;
}

void Status::update(float dt)
{
	Player* p1 = (Player*)getParent()->getParent()->getChildByName("player");
	GamePlayScene* gp = (GamePlayScene*)this->getParent()->getParent();

	Label* Weight = (Label*)getChildByName("WL");
	string strW = StringUtils::format("���� : %.1lf kg", p1->weight);
	Weight->setString(strW);

	Label* MoveSpeed = (Label*)getChildByName("MSL");
	string strM = StringUtils::format("�ӵ� : %.1lf ", p1->MoveSpeed);
	MoveSpeed->setString(strM);

	Label* FoodCount = (Label*)getChildByName("FCL");
	string strF = StringUtils::format("�ִ� ���� ���� : %d", gp->Maxitem);
	FoodCount->setString(strF);
}



void Status::closeStatus(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::BEGAN)
	{
		GamePlayScene* gps = GamePlayScene::create();
		this->setVisible(false);
		gps->StartGame();
	}
}

void Status::TouchPlayer(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::BEGAN)
	{
		Label* Saying = Label::createWithTTF("���Ӿƾƾƾ�", "fonts/HoonWhitecatR.ttf", 20);
		this->addChild(Saying, 2, "say1");
		Saying->setPosition(Vec2(130, 280));
		
		DelayTime* dt = DelayTime::create(2);
		FadeOut* fo = FadeOut::create(2);
		Sequence* seq = Sequence::create(dt, fo, 0);

		Saying->runAction(seq);		
	}
}


