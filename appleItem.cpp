#include "appleItem.h"

bool appleItem::init()
{
	appleweight = 0.2f;
	Sprite* pApple = Sprite::create("Item/apple.png");
	this->addChild(pApple);
	pApple->setName("Apple");
	pApple->setScale(0.3);
	return true;
}

void appleItem::update(float dt)
{
}

Rect appleItem::getBoundingBox()
{
	Sprite* pApple = (Sprite*)this->getChildByName("Apple");
	Rect rt = pApple->getBoundingBox();
	rt.size.width *= pApple->getScaleX();
	rt.size.height *= pApple->getScaleY();
	rt.origin += this->getPosition();
	return rt;
}
