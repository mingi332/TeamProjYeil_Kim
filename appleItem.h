#pragma once
#include<cocos2d.h>
USING_NS_CC;
class appleItem:public Node
{
public:
	CREATE_FUNC(appleItem);
	bool init();
	void update(float dt);

	Rect getBoundingBox();//�浹ó������ �ٿ���ڽ�

	

};

