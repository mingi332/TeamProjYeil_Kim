#include "Bubble.h"

bool Bubble::init()
{
	Sprite* sp = Sprite::create("Item/bubble.png");
	this->addChild(sp, 1, "bubble");
	sp->setScale(0.3);

	return true;
}

Rect Bubble::gettheBox()
{
	Sprite* bubble = (Sprite*)this->getChildByName("bubble");

	Rect rt = bubble->getBoundingBox();
	rt.size.width *= this->getScale();
	rt.size.height *= this->getScale();
	rt.origin += this->getPosition();

	return rt;
}
