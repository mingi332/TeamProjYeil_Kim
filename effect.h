#pragma once
#include<cocos2d.h>
USING_NS_CC;
class effect :public Node
{
public:
	CREATE_FUNC(effect);
	bool init();

	void EatEffect();
	//ธิภฬ ธิดย ภฬฦๅฦฎ
//	void ShokEffect();
	//ภๅพึนฐ ดÝดย ภฬฦๅฦฎ
};