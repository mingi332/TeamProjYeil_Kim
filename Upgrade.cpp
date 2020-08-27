#pragma execution_character_set("UTF-8")
#include "Upgrade.h"
#include "GamePlayScene.h"
#include "PLAYER.H"

bool Upgrade::init()
{
	MoveUpgradeCnt = 0;
	FoodUpgradeCnt = 0;


	//���׷��̵� â ����
	Sprite* ugs = Sprite::create("UI/green_panel.png");
	this->addChild(ugs);
	ugs->setPosition(Vec2(300, 250));
	ugs->setScale(5, 3);

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
	back->Button::addTouchEventListener(CC_CALLBACK_2(Upgrade::CloseUpgrade, this));

	//�̵��ӵ� ���׷��̵� ��ư
	Button* MoveUp = Button::create("UI/green_button07.png", "UI/green_button08.png");
	this->addChild(MoveUp, 1);
	MoveUp->setPosition(Vec2(500, 350));
	MoveUp->Button::addTouchEventListener(CC_CALLBACK_2(Upgrade::MoveUpgrade, this));
	//�̵��ӵ� ���׷��̵� Ƚ�� ��Ÿ���ִ� ��
	Label* MoveUpcntLabel = Label::createWithTTF("0", "fonts/HoonWhitecatR.ttf", 40);
	this->addChild(MoveUpcntLabel, 2, "movecnt");
	MoveUpcntLabel->setPosition(Vec2(500, 350));




	//���� �ִ� ���� ���׷��̵� ��ư
	Button* FoodUp = Button::create("UI/green_button07.png", "UI/green_button08.png");
	this->addChild(FoodUp, 1);
	FoodUp->setPosition(Vec2(500, 250));
	FoodUp->Button::addTouchEventListener(CC_CALLBACK_2(Upgrade::FoodUpgrade, this));
	//���� ���׷��̵� Ƚ�� ��Ÿ���ִ� ��
	Label* FoodUpcntLabel = Label::createWithTTF("0", "fonts/HoonWhitecatR.ttf", 40);
	this->addChild(FoodUpcntLabel, 2, "foodcnt");
	FoodUpcntLabel->setPosition(Vec2(500, 250));





	//�̵��ӵ� ���� ��
	Sprite* MoveUpSp = Sprite::create("UI/green_button13.png");
	this->addChild(MoveUpSp, 1);
	MoveUpSp->setPosition(270, 348);
	MoveUpSp->setScale(2.0f, 1.3f);
	Label* MoveUpLabel = Label::createWithTTF("�̵��ӵ� ���׷��̵��Դϴ�. ���׷��̵帶�� 20�� �þ�ϴ�! �⺻�� 100, �ִ� 300 (10ȸ)", "fonts/HoonWhitecatR.ttf", 18, Size(350, 200), CCTextAlignment::LEFT);
	this->addChild(MoveUpLabel, 1);
	MoveUpLabel->setPosition(Vec2(270, 270));
	MoveUpLabel->setTextColor(Color4B(0, 0, 0, 255));

	//���İ��� ���� ��
	Sprite* FoodUpSp = Sprite::create("UI/green_button13.png");
	this->addChild(FoodUpSp, 1);
	FoodUpSp->setPosition(270, 248);
	FoodUpSp->setScale(2.0f, 1.3f);
	Label* FoodUpLabel = Label::createWithTTF("�����ϴ� ������ ������ �þ�ϴ�. ���׷��̵帶�� 2���� �þ�ϴ�. �⺻�� 15, �ִ� 35 (10ȸ)", "fonts/HoonWhitecatR.ttf", 18, Size(350, 200), CCTextAlignment::LEFT);
	this->addChild(FoodUpLabel, 1);
	FoodUpLabel->setPosition(Vec2(270, 170));
	FoodUpLabel->setTextColor(Color4B(0, 0, 0, 255));


	return true;

}

void Upgrade::CloseUpgrade(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::BEGAN)
	{
		GamePlayScene* gps = GamePlayScene::create();
		this->setVisible(false);
		gps->StartGame();
		
	}
}

void Upgrade::MoveUpgrade(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		if (MoveUpgradeCnt < 10)
		{
			GamePlayScene* gs = (GamePlayScene*)getParent()->getParent();
			Player* p1 = (Player*)getParent()->getParent()->getChildByName("player");
			p1->MoveSpeed += 20;
			MoveUpgradeCnt++;

			Label* lb = (Label*)this->getChildByName("movecnt");
			string str = StringUtils::format("%d", MoveUpgradeCnt);
			lb->setString(str);
		}
	}
	
}

void Upgrade::FoodUpgrade(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		if (FoodUpgradeCnt < 10)
		{
			GamePlayScene* gs = (GamePlayScene*)getParent()->getParent();
			gs->Maxitem += 2;
			FoodUpgradeCnt++;
			Label* lb = (Label*)this->getChildByName("foodcnt");
			string str = StringUtils::format("%d", FoodUpgradeCnt);
			lb->setString(str);
		}
	}
}

void Upgrade::FoodValueupgrade(Ref* ref, Button::TouchEventType type)
{
}
