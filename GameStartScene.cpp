#include "GameStartScene.h"
#include "BackGround.h"
#include "GamePlayScene.h"
#include "how2playLayer.h"

bool GameStartScene::init()
{
	//시작씬의 배경
	BackGround* bg = BackGround::create();
	this->addChild(bg);

	//HowToPlay 버튼
	Button* pBtn = Button::create("UI/how2play.png"); 
	this->addChild(pBtn);
	pBtn->setPosition(Vec2(500, 50));
	pBtn->addTouchEventListener(CC_CALLBACK_2(GameStartScene::h2pClick, this));

	//HowToPlay 문구
	Label* pButton = Label::createWithTTF("How to Play", "fonts/HoonWhitecatR.ttf", 30, Size(300, 100), CCTextAlignment::LEFT);
	this->addChild(pButton);
	pButton->setPosition(Vec2(600, 20)); //버튼에 새길 how to play 문구 위치
	pButton->setTextColor(Color4B(0, 0, 0, 255)); //문구 색

	//Play버튼(!h2p버튼과 동일한 png파일!)
	Button* pBtn2 = Button::create("UI/how2play.png");
	this->addChild(pBtn2);
	pBtn2->setPosition(Vec2(500, 110));
	pBtn2->addTouchEventListener(CC_CALLBACK_2(GameStartScene::rdyClick, this));

	//Play문구
	Label* pButton2 = Label::createWithTTF("PLAY", "fonts/HoonWhitecatR.ttf", 30, Size(300, 100), CCTextAlignment::LEFT);
	this->addChild(pButton2);
	pButton2->setPosition(Vec2(600, 75)); //버튼에 새길 play 문구 위치
	pButton2->setTextColor(Color4B(0, 0, 0, 255)); //문구 색
	

	return true;
}

void GameStartScene::h2pClick(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		how2playLayer* h2p = how2playLayer::create();
		this->addChild(h2p);
		//Director::getInstance()->replaceScene(h2p);
	}
}

void GameStartScene::rdyClick(Ref* ref, Button::TouchEventType type)
{
	if (type == Button::TouchEventType::ENDED)
	{
		GamePlayScene* go = GamePlayScene::create();
		this->addChild(go);
		Director::getInstance()->replaceScene(go);
	}
}
