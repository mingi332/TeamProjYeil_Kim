#include "basicUI.h"

bool basicUI::init()
{
	//�⺻ Ui ��ư�� �� ��������Ʈ
	Button* pBtn1 = Button::create("UI/glassPanel1.png");
	Button* pBtn2 = Button::create("UI/glassPanel2.png");
	Button* pBtn3 = Button::create("UI/glassPanel3.png");

	this->addChild(pBtn1);
	this->addChild(pBtn2);
	this->addChild(pBtn3);
	//ui ��ư�� �� ��ġ ��ǥ
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
	//��ư�� ������ ���� ���� �׼� Ȥ�� �˾�â
	if (type == Button::TouchEventType::ENDED)
	{

	}
}
