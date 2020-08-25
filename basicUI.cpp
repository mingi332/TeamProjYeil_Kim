#include "basicUI.h"

bool basicUI::init()
{
	//기본 Ui 버튼이 될 스프라이트
	Button* pBtn1 = Button::create("UI/glassPanel1.png");
	Button* pBtn2 = Button::create("UI/glassPanel2.png");
	Button* pBtn3 = Button::create("UI/glassPanel3.png");

	this->addChild(pBtn1);
	this->addChild(pBtn2);
	this->addChild(pBtn3);
	//ui 버튼이 올 위치 좌표
	pBtn1->setPosition(Vec2(150, 30));
	pBtn2->setPosition(Vec2(300, 30));
	pBtn3->setPosition(Vec2(450, 30));

	



	return true;
}

void basicUI::update(float dt)
{
}

void basicUI::uiclik(Ref* ref, Button::TouchEventType type)
{
	//버튼을 누르면 나올 다음 액션 혹은 팝업창
	if (type == Button::TouchEventType::ENDED)
	{

	}
}
