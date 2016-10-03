#include "GameScene.h"
#include "HelloWorldScene.h"
#include "Animator.h"
#include "MyCamera.h"
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

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // 바닥 화면 [ 사이드 바닥 2개, 메인 바닥 1개, 임시 캐릭터 ]
    Inittiles();
    
    // 카메라 [ 이 뒤에 생성되는 개체는 카메라의 영향을 안받는다. ]
    {
        // 카메라 넘버 지정. [ 이 씬에서는 이 카메라를 쓴다. ]
        this->setCameraMask((unsigned short)CameraFlag::USER1);
        Vec3 campos = { 640, -600, 500 };
        Vec3 camlookat = { 640, 360, 0 };

        MyCamera::MakeCamera(this, CameraFlag::USER1, campos, camlookat);
    }

    // 배경 화면 [ 뒷 배경 3개 - 하늘, 산, 그라데이션 ]
    Initbackground();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	horse = new Horse;
	horse->InitHorse(this);

	scheduleUpdate();
    return true;
}

void GameScene::Inittiles()
{
    sideground[0] = Sprite::create("side_ground1.png");

    sideground[0]->setAnchorPoint(Vec2(1, 0));
    sideground[0]->setPosition(Vec2(250, -300));
	sideground[0]->setScale(1.6f, 2);
    sideground[0]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(sideground[0], 1, "side_left");

    sideground[1] = Sprite::create("side_ground2.png");

    sideground[1]->setAnchorPoint(Vec2(0, 0));
    sideground[1]->setPosition(Vec2(1080, -300));
	sideground[1]->setScale(1.5f, 2);
    sideground[1]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(sideground[1], 1, "side_right");

    mainground = Sprite::create("main_ground.png");

    mainground->setAnchorPoint(Vec2(0, 0));
    mainground->setPosition(Vec2(0, -300));
	mainground->setScale(1.3f, 2);
    mainground->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(mainground, 0, "mainground");

   /* auto object1 = Sprite::create("char.png");

    object1->setAnchorPoint(Vec2(0.5f, 0));
    object1->setPosition(Vec2(640, -280));
    object1->setRotation3D(Vec3(70, 0, 0));

    this->addChild(object1, 1, "char");*/

    
}

void GameScene::Initbackground()
{
    auto skyground = Sprite::create("sky_ground.png");
    skyground->setAnchorPoint(Vec2(0, 0));
    skyground->setPosition(Vec2(-10, 520));

    this->addChild(skyground, 0, "sky");

    auto mountainground = Sprite::create("mountain_ground.png");
    mountainground->setAnchorPoint(Vec2(0, 0));
    mountainground->setPosition(Vec2(-10, 520));

    this->addChild(mountainground, 0, "mountain");

	auto gradaition = Sprite::create("gradaition.png");
	gradaition->setAnchorPoint(Vec2(0, 0));
	gradaition->setPosition(Vec2(0, 142));

	this->addChild(gradaition, 2, "gradaition");
}

void GameScene::update(float delta)
{
	static float scroll[3] = { 0.f };

	Rect rt[3];

	rt[0] = mainground->getTextureRect();
	rt[1] = sideground[0]->getTextureRect();
	rt[2] = sideground[1]->getTextureRect();

	for (int i = 0; i < 3; i++)
	{
		scroll[i] -= delta * 1000.f;
		if (scroll[i] > rt[i].size.height) scroll[i] = 0.f;
		rt[i].origin.y = scroll[i];
	}

	mainground->setTextureRect(rt[0]);
	sideground[0]->setTextureRect(rt[1]);
	sideground[1]->setTextureRect(rt[2]);

	horse->update(delta);
}

bool GameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	Vec2 touchlocate = touch->getLocation();

	return true;
}