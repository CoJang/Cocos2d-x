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
    // ���� ��� (Ÿ�Ϸ�)�� �����ϴ� �Լ� 
    void Inittiles();

    // ���� ��� (Ÿ�Ϸ�)�� �����̴� �Լ�
    void update(float delta);

    // ���� ��� (�ϴ�, ��)�� �����̴� �Լ�
    void Initbackground();

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event) {};
	virtual void onTouchEnded(Touch* touch, Event* unused_event) {};
};
