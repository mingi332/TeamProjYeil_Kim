#include "EnemyGhost.h"
#include "Player.h"

bool EnemyGhost::init()
{
	Sprite* ghost = Sprite::create("Enemy/Ghost.png");
	this->addChild(ghost,1,"ghost");
	ghost->setScale(0.3);
	ghost_speed = 80.0f;


	return true;
}

void EnemyGhost::update(float dt)
{
	Sprite* ghost = (Sprite*)this->getChildByName("ghost");

	
	if (ghost == NULL) return;


	ghost->setPosition(ghost->getPosition() + PlayerDir * dt * ghost_speed);



}

void EnemyGhost::FindPlayer()
{
	Player* p1 = (Player*)this->getParent()->getChildByName("player");

	if (p1 == NULL) return;
	
	PlayerPos = p1->getPosition();

	Vec2 nor = PlayerPos - this->getPosition();

	PlayerDir = nor.getNormalized();


}

Rect EnemyGhost::Getthebox()
{
	Sprite* ghost = (Sprite*)this->getChildByName("ghost");
	Rect rt = ghost->getBoundingBox();
	rt.size.width += this->getScale();
	rt.size.height += this->getScale();
	rt.origin += this->getPosition();

	return rt;
}
