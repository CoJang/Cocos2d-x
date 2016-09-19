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


// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!LayerColor::initWithColor(Color4B::RED))
    {
        return false;
    }

    //auto spr = Sprite::create("wallpaper038-2560x1440.jpg"); // [ QHD ]
    auto spr = Sprite::create("wallpaper029-1920x1080.jpg"); // [ FHD ]
    
    spr->setAnchorPoint(Vec2(0, 0));
    spr->setPosition(Vec2(0, 0));

    this->addChild(spr);
    
    this->setCameraMask((unsigned short)CameraFlag::USER1);
    auto cam = Camera::create();
    //auto cam = Camera::createPerspective(40, 1280 / 720, 10, 1000);
    cam->setCameraFlag(CameraFlag::USER1);

    //cam->setPositionX(100);
    cam->setPosition3D(Vec3(640, 0, 500));
    cam->lookAt(Vec3(640, 360, 0), Vec3(0, 1, 0));
    //cam->lookAt(Vec3(0, 1, 0));

    this->addChild(cam, 1, "camera");


    return true;
}
