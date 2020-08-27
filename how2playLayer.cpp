#pragma execution_character_set("UTF-8")
#include "how2playLayer.h"
#include "GameStartScene.h"

bool how2playLayer::init()
{
	//�˾�â ��������Ʈ
	Sprite* pSpr = Sprite::create("UI/how2playPopup.png");
	this->addChild(pSpr);
	pSpr->setPosition(290, 230);
	pSpr->setScale(5, 3);
		//setScale�� �� ()�ȿ� ','�� x��y�� ���� ���� �� �ִ�.
	

	//how to play �ۼ��ؾ���!
	Label* pBoard = Label::createWithTTF("�׽�Ʈ���Դϴ�.", "fonts/HoonWhitecatR.ttf", 30,Size(300, 100), CCTextAlignment::LEFT);
	this->addChild(pBoard);
	pBoard->setPosition(Vec2(210, 230));
	pBoard->setTextColor(Color4B(0, 0, 0, 255));
	
	//�˾�â�� ������ �� �˴ٿ�(���Ӿ����� ���ư�)
	Button* popDown = Button::create("UI/popDownKey.png");
	this->addChild(popDown);
	popDown->setPosition(Vec2(520, 365));
	popDown->addTouchEventListener(CC_CALLBACK_2(how2playLayer::popDown, this));
	
	
	Button* back = Button::create("Background/SkyBack.jpg");

	this->addChild(back);
	back->setPosition(Vec2(300, 200));
	back->setOpacity(0);
	back->addTouchEventListener(CC_CALLBACK_2(how2playLayer::popDown, this));

	return true;
}

void how2playLayer::update(float dt)
{
}

void how2playLayer::popDown(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		//GameStartScene* pScene = GameStartScene::create();
		//Director::getInstance()->replaceScene(pScene);
		this->setVisible(false);

	}
}
