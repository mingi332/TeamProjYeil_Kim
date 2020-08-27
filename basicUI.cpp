#include "basicUI.h"
#include "Upgrade.h"
#include "Status.h"
#include "GamePlayScene.h"

bool basicUI::init()
{
	Upgrade* ug = Upgrade::create();
	this->addChild(ug,1,"ug");
	ug->setVisible(false);

	Status* st = Status::create();
	this->addChild(st, 1, "st");
	st->setVisible(false);

	//�⺻ Ui ��ư�� �� ��������Ʈ
	Button* pBtn1 = Button::create("UI/glassPanel1.png");			//���׷��̵� 1
	Button* pBtn2 = Button::create("UI/glassPanel1.png");
	Button* pBtn3 = Button::create("UI/glassPanel1.png");			//����â
	Button* pBtn4 = Button::create("UI/glassPanel1.png");

	this->addChild(pBtn1);
	this->addChild(pBtn2);
	this->addChild(pBtn3);
	this->addChild(pBtn4);


	//ui ��ư�� �� ��ġ ��ǥ
	pBtn1->setPosition(Vec2(120, 35));
	pBtn1->setScale(0.7);
	pBtn2->setPosition(Vec2(240, 35));
	pBtn2->setScale(0.7);
	pBtn3->setPosition(Vec2(360, 35));
	pBtn3->setScale(0.7);
	pBtn4->setPosition(Vec2(480, 35));
	pBtn4->setScale(0.7);

	
	pBtn1->Button::addTouchEventListener(CC_CALLBACK_2(basicUI::UpgradeUi, this));

	pBtn3->Button::addTouchEventListener(CC_CALLBACK_2(basicUI::StatusUi, this));
	





	return true;
}

void basicUI::update(float dt)
{
}

void basicUI::UpgradeUi(Ref* ref, Button::TouchEventType type)
{
	//��ư�� ������ ���� ���� �׼� Ȥ�� �˾�â
	if (type == Button::TouchEventType::ENDED)
	{
		GamePlayScene* gps = GamePlayScene::create();
		Upgrade* ug = (Upgrade*)getChildByName("ug");
		ug->setVisible(true);
		gps->StopGame();
	}
}

void basicUI::StatusUi(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		GamePlayScene* gps = GamePlayScene::create();
		Status* st = (Status*)getChildByName("st");
		st->setVisible(true);
		st->scheduleUpdate();
		gps->StopGame();
	}
}

