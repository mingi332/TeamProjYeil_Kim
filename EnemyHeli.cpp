#include "EnemyHeli.h"
#include "GamePlayScene.h"

bool EnemyHeli::init()
{
	Sprite* sp = Sprite::create("Enemy/flyMan_fly.png");
	this->addChild(sp, 1, "Heli");
	sp->setScale(0.3);
	
	fly_man_speed = 30;
	this->scheduleUpdate();

    return true;
}

void EnemyHeli::update(float dt)
{
	GamePlayScene* gs = (GamePlayScene*)this->getParent();
	//화면 밖으로 나갔을 때 삭제 되는 조건
	if (this->getPositionX() < -300 || this->getPositionX() > 900 ||
		this->getPositionY() < -300 || this->getPositionY() > 700)
	{
		
	}
}
