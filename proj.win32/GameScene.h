#pragma once
#include "cocos2d.h"

class GameScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

public:
    // ī�޶� ���� �� �ְ� ���ִ� �Լ�. 
    // CameraFlag = ī�޶��� ID �ѹ�, CameraPosition = ī�޶��� ��ġ ��, CameraLookAt = ī�޶� �ٶ󺸴� ��ǥ
    void MakeCamera(cocos2d::CameraFlag CameraFlag, cocos2d::Vec3 CameraPosition, cocos2d::Vec3 CameraLookAt);
};
