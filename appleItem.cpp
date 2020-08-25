#include "appleItem.h"

bool appleItem::init()
{
	Sprite* pApple = Sprite::create("Item/apple1.png");
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
	Sprite* pApple = Sprite::create("Item/apple1.png");
	Rect rt = pApple->getBoundingBox();
	rt.origin += this->getPosition();
	return rt;
}

