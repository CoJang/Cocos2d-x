#include "GameScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

USING_NS_CC;

using namespace cocostudio::timeline;


Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto GameScene = Scene::create();

    // 'layer' is an autorelease object
    auto GameSceneLayer = GameScene::create();

    // add layer as a child to scene
    GameScene->addChild(GameSceneLayer);

    // return the scene
    return GameScene;
}


void GameScene::MakeCamera(cocos2d::CameraFlag CameraFlag, cocos2d::Vec3 CameraPosition, cocos2d::Vec3 CameraLookAt)
{
    auto cam = Camera::create();
    cam->setCameraFlag(CameraFlag);

    cam->setPosition3D(CameraPosition);
    cam->lookAt(CameraLookAt);

    this->addChild(cam, 0, "camera");
}


bool GameScene::init()
{
    if (!LayerColor::initWithColor(Color4B::RED))
    {
        return false;
    }

    
    // 바닥 화면 [ 사이드 바닥 2개, 메인 바닥 1개 ]
    {
        auto sideground0 = Sprite::create("side_ground.png");
    
        sideground0->setAnchorPoint(Vec2(0, 0));
        sideground0->setPosition(Vec2(-600, 0));

        this->addChild(sideground0, 1, "side_left");

        auto sideground1 = Sprite::create("side_ground.png");

        sideground1->setAnchorPoint(Vec2(0, 0));
        sideground1->setPosition(Vec2(1000, 0));

        this->addChild(sideground1, 1, "side_right");

        auto mainground = Sprite::create("main_ground.png");

        mainground->setAnchorPoint(Vec2(0, 0));
        mainground->setAnchorPoint(Vec2(0, 0));

        this->addChild(mainground, 0, "mainground");
    }

    // 카메라
    {
        // 카메라 넘버 지정. [ 이 씬에서는 이 카메라를 쓴다. ]
        this->setCameraMask((unsigned short)CameraFlag::USER1);

        Vec3 campos = { 640, -100, 500 };
        Vec3 camlookat = { 640, 360, 0 };

        MakeCamera(CameraFlag::USER1, campos, camlookat);
    }

    // 배경 화면 [ 뒷 배경 2개 - 하늘, 산 ]
    {
        auto skyground = Sprite::create("sky_ground.png");

        skyground->setAnchorPoint(Vec2(0, 0));
        skyground->setPosition(Vec2(-10, 450));

        this->addChild(skyground, 2, "sky");

        auto mountainground = Sprite::create("mountain_ground.png");

        mountainground->setAnchorPoint(Vec2(0, 0));
        mountainground->setPosition(Vec2(-10, 550));

        this->addChild(mountainground, 2, "mountain");
    }


    return true;
}
