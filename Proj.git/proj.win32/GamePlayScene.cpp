#include "GamePlayScene.h"
#include "BackGround.h"
#include "Player.h"

bool GamePlayScene::init()
{
	BackGround* bg = BackGround::create();
	this->addChild(bg);

	Player* p1 = Player::create();
	this->addChild(p1);
	p1->setName("player");
	p1->setPosition(300, 150);



	EventListenerMouse* mouseL = EventListenerMouse::create();
	mouseL->onMouseDown = CC_CALLBACK_1(GamePlayScene::mouseDown, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseL, this);

	return true;
}

void GamePlayScene::update(float dt)
{

}

void GamePlayScene::mouseDown(Event* ev)
{
	

	EventMouse* em = (EventMouse*)ev;
	Sprite* p1 = (Sprite*)this->getChildByName("player");
	p1->stopAllActions();
	MoveTo* mt = MoveTo::create(2, Vec2(em->getCursorX(), em->getCursorY()));
	p1->runAction(mt);

}
