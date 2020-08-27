#include "Carrot.h"

bool Carrot::init()
{
	carrotweight = 0.1f;
	Sprite* sp = Sprite::create("Item/carrot.png");
	this->addChild(sp, 1, "carrot");
	sp->setScale(0.3);

	


	return true;
}



Rect Carrot::gettheBox()
{
	Sprite* sp = (Sprite*)this->getChildByName("carrot");

	Rect rt = sp->getBoundingBox();
	rt.size.width *= this->getScale();
	rt.size.height *= this->getScale();
	rt.origin += this->getPosition();

	return rt;
}
