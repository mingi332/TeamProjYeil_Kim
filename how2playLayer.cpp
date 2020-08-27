#pragma execution_character_set("UTF-8")
#include "how2playLayer.h"
#include "GameStartScene.h"

bool how2playLayer::init()
{
	//팝업창 스프라이트
	Sprite* pSpr = Sprite::create("UI/how2playPopup.png");
	this->addChild(pSpr);
	pSpr->setPosition(290, 230);
	pSpr->setScale(5, 3);
		//setScale할 때 ()안에 ','로 x축y축 각각 맞출 수 있다.
	

	//how to play 작성해야함!
	Label* pBoard = Label::createWithTTF("테스트중입니다.", "fonts/HoonWhitecatR.ttf", 30,Size(300, 100), CCTextAlignment::LEFT);
	this->addChild(pBoard);
	pBoard->setPosition(Vec2(210, 230));
	pBoard->setTextColor(Color4B(0, 0, 0, 255));
	
	//팝업창을 눌렀을 때 팝다운(게임씬으로 돌아감)
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
