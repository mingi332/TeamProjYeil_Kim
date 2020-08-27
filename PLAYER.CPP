#include "Player.h"

bool Player::init()
{
	scale = 0.3;
	MoveSpeed = 100;
	weight = 2.0f;

	Sprite* Player = Sprite::create("Player/wingMan1.png");
	this->addChild(Player, 1, "player");
	Player->setScale(scale);


	Animation* pAni = Animation::create();
	pAni->addSpriteFrameWithFileName("Player/wingMan1.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan2.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan3.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan4.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan5.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan4.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan3.png");
	pAni->addSpriteFrameWithFileName("Player/wingMan2.png");

	pAni->setDelayPerUnit(0.1);
	pAni->setLoops(-1);

	Animate* pAnime = Animate::create(pAni);

	Player->runAction(pAnime);


	EventListenerMouse* mouseL = EventListenerMouse::create();
	mouseL->onMouseDown = CC_CALLBACK_1(Player::mouseDown, this);


	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseL, this);

	this->scheduleUpdate();


	return true;
}

void Player::update(float dt)
{

	//클릭한 위치로 이동, 도착 시 정지
	float dist;
	PlayerPos = this->getPosition();	
	dist = CursorPos.distance(PlayerPos);
	if (dist > 1)
		this->setPosition(this->getPosition() + Direction * dt * MoveSpeed);
	else
		this->setPosition(this->getPosition());

	//화면 밖으로 못나가게
	dontGetout();


}

void Player::mouseDown(Event* ev)
{

	EventMouse* em = (EventMouse*)ev;
	CursorPos = Vec2(em->getCursorX(), em->getCursorY());
	Vec2 nor = CursorPos - this->getPosition();
	Direction = nor.getNormalized();
	

}

void Player::dontGetout()
{
	if (this->getPositionX() < 20)
		this->setPositionX(20);
	if (this->getPositionY() < 20)
		this->setPositionY(20);
	if (this->getPositionX() > 580)
		this->setPositionX(580);
	if (this->getPositionY() > 380)
		this->setPositionY(380);
}

Rect Player::gettheBox()
{
	Sprite* p1 = (Sprite*)this->getChildByName("player");

	Rect rt = p1->getBoundingBox();
	rt.size.width *= this->getScale();
	rt.size.height *= this->getScale();
	rt.origin += this->getPosition();

	return rt;
}
