#pragma once
#include <cocos2d.h>
USING_NS_CC;

class Carrot : public Node
{
public:
	CREATE_FUNC(Carrot);

	bool init();
	

	float carrotweight;			//��ٸ԰� ��� ����


	Rect gettheBox();
};

