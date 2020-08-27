#include "BackGround.h"

bool BackGround::init()
{
	Sprite* sp = Sprite::create("Background/SkyBack.jpg");
	this->addChild(sp,-1);
	sp->setPosition(313, 208);

	return true;
}
