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
    // 카메라를 만들 수 있게 해주는 함수. 
    // CameraFlag = 카메라의 ID 넘버, CameraPosition = 카메라의 위치 값, CameraLookAt = 카메라가 바라보는 좌표
    void MakeCamera(cocos2d::CameraFlag CameraFlag, cocos2d::Vec3 CameraPosition, cocos2d::Vec3 CameraLookAt);

    // 앞의 배경 (타일류)를 생성하는 함수 
    void Inittiles();

    // 앞의 배경 (타일류)를 움직이는 함수
    void update(float delta);

    // 뒤의 배경 (하늘, 산)을 움직이는 함수
    void Initbackground();

	Sprite* DrawBox(std::string filename, Vec2 pos, Vec2 size, Vec2 anchor, std::string tagname, short int layer);

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event) {};
	virtual void onTouchEnded(Touch* touch, Event* unused_event) {};
};
