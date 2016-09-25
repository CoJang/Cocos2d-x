#pragma once
#include "cocos2d.h"

class GameScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

public:
    // 카메라를 만들 수 있게 해주는 함수. 
    // CameraFlag = 카메라의 ID 넘버, CameraPosition = 카메라의 위치 값, CameraLookAt = 카메라가 바라보는 좌표
    void MakeCamera(cocos2d::CameraFlag CameraFlag, cocos2d::Vec3 CameraPosition, cocos2d::Vec3 CameraLookAt);
};
