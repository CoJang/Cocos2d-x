#pragma once
#include "cocos2d.h"
#include "Animator.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    Sprite* mainground;
	Sprite* sideground[2];

	Animator* a_Horse_head;

	Vec3 camlocation;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

public:
    // ī�޶� ���� �� �ְ� ���ִ� �Լ�. 
    // CameraFlag = ī�޶��� ID �ѹ�, CameraPosition = ī�޶��� ��ġ ��, CameraLookAt = ī�޶� �ٶ󺸴� ��ǥ
    void MakeCamera(cocos2d::CameraFlag CameraFlag, cocos2d::Vec3 CameraPosition, cocos2d::Vec3 CameraLookAt);

    // ���� ��� (Ÿ�Ϸ�)�� �����ϴ� �Լ� 
    void Inittiles();

    // ���� ��� (Ÿ�Ϸ�)�� �����̴� �Լ�
    void update(float delta);

    // ���� ��� (�ϴ�, ��)�� �����̴� �Լ�
    void Initbackground();

	Sprite* DrawBox(std::string filename, Vec2 pos, Vec2 size, Vec2 anchor, std::string tagname, short int layer);

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event) {};
	virtual void onTouchEnded(Touch* touch, Event* unused_event) {};
};
