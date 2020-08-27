#include "effect.h"
#include "PLAYER.H"

bool effect::init()
{
    return true;
}

void effect::EatEffect()
{
    Player* p1 = (Player*)this->getParent()->getChildByName("player");
    Sprite* pSpr = Sprite::create("Player/eatingEffect00.png");
    Animation* pA = Animation::create();
    pSpr->setScale(0.5);
    pSpr->setPosition(p1->getPosition());


    pA->addSpriteFrameWithFile("Player/eatingEffect00.png");
    pA->addSpriteFrameWithFile("Player/eatingEffect01.png");
    pA->setLoops(4);
    pA->setDelayPerUnit(0.05);
    Animate* pAni = Animate::create(pA);

    RemoveSelf* pRemove = RemoveSelf::create(true);
    Sequence* pSeq = Sequence::create(pAni, pRemove, 0);
    pSpr->runAction(pSeq);
    this->addChild(pSpr);
    //2~4초 머물고 있는 액션 추가해야함
}

//void effect::ShokEffect()
//{
//   
//}