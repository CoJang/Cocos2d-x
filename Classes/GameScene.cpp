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
    auto GameSceneLayer = HelloWorld::create();

    auto newscene = Layer::create();
    // add layer as a child to scene
    GameScene->addChild(GameSceneLayer);

    // return the scene
    return GameScene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!LayerColor::initWithColor(Color4B::BLUE))
    {
        return false;
    }

    auto spr = Sprite::create("watchpoint.jpg");
    
    spr->setAnchorPoint(Vec2(0, 0));
    spr->setPosition(Vec2(0, 0));

    this->addChild(spr);
    //this->setRotation3D(Vec3(-45, 0, 0));

    return true;
}
