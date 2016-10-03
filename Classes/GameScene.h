#pragma once
#include "cocos2d.h"
#include "Animator.h"
#include "Horse.h"
#include "Man.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    Sprite* mainground;
	Sprite* sideground[2];

	Horse* horse;
	Man*   man;

	Vec3 camlocation;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

public:
    // 앞의 배경 (타일류)를 생성하는 함수 
    void Inittiles();

    // 앞의 배경 (타일류)를 움직이는 함수
    void update(float delta);

    // 뒤의 배경 (하늘, 산)을 움직이는 함수
    void Initbackground();

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event) {};
	virtual void onTouchEnded(Touch* touch, Event* unused_event) {};
};
