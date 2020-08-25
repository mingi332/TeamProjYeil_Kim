#include "Player.h"

bool Player::init()
{
	float scale = 0.3;

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



	return true;
}

void Player::update(float dt)
{
	Sprite* p1 = (Sprite*)this->getChildByName("player");

	//플레이어가 화면 밖으로 못나가게 하기 위한 예외처리
	if (p1->getPositionY() > 380)
		p1->setPositionY(380);

	if (p1->getPositionY() < 20)
		p1->setPositionY(20);

	if (p1->getPositionX() > 580)
		p1->setPositionX(580);

	if (p1->getPositionX() < 20)
		p1->setPositionX(20);




}
