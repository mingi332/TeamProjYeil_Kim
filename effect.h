#pragma once
#include<cocos2d.h>
USING_NS_CC;
class effect :public Node
{
public:
	CREATE_FUNC(effect);
	bool init();

	void EatEffect();
	//���� �Դ� ����Ʈ
//	void ShokEffect();
	//��ֹ� �ݴ� ����Ʈ
};