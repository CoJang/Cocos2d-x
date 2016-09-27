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
	auto cam = Camera::createPerspective(60, 16/10.f , 0, 1000);
	//auto cam = Camera::create();
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
    Inittiles();
    
    // 카메라 [ 이 뒤에 생성되는 개체는 카메라의 영향을 안받는다. ]
    {
        // 카메라 넘버 지정. [ 이 씬에서는 이 카메라를 쓴다. ]
        this->setCameraMask((unsigned short)CameraFlag::USER1);

        Vec3 campos = { 640, -600, 500 }; // 태윤이가 원하는 각도 pos -400에 lookat 360 [Y]
        Vec3 camlookat = { 640, 360, 0 };

        MakeCamera(CameraFlag::USER1, campos, camlookat);
    }

    // 배경 화면 [ 뒷 배경 2개 - 하늘, 산 ]
    Initbackground();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void GameScene::Inittiles()
{
    sideground[0] = Sprite::create("side_ground.jpg");

    sideground[0]->setAnchorPoint(Vec2(1, 0));
    sideground[0]->setPosition(Vec2(250, -300));
	sideground[0]->setScale(1.6f, 2);
    sideground[0]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(sideground[0], 1, "side_left");

    sideground[1] = Sprite::create("side_ground.jpg");

    sideground[1]->setAnchorPoint(Vec2(0, 0));
    sideground[1]->setPosition(Vec2(1080, -300));
	sideground[1]->setScale(1.5f, 2);
    sideground[1]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(sideground[1], 1, "side_right");

    mainground = Sprite::create("main_ground.jpg");

    mainground->setAnchorPoint(Vec2(0, 0));
    mainground->setPosition(Vec2(0, -300));
	mainground->setScale(1.3f, 2);
    mainground->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

    this->addChild(mainground, 0, "mainground");

    auto object1 = Sprite::create("char.png");

    object1->setAnchorPoint(Vec2(0.5f, 0));
    object1->setPosition(Vec2(640, -280));
    object1->setRotation3D(Vec3(70, 0, 0));

    this->addChild(object1, 1, "object1");

	/*sideground[0] = DrawBox("side_ground.jpg", Vec2(-1320, -300), Vec2(1530, 1880), Vec2(0, 0),	"side_left",   1);
	sideground[1] = DrawBox("side_ground.jpg", Vec2(1080, -300),  Vec2(1530, 1880), Vec2(0, 0),	"side_right",  1);
	mainground =	DrawBox("main_ground.jpg", Vec2(0, -300),	  Vec2(1130, 1880), Vec2(0, 0),	"main_ground", 0);

	sideground[0]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });
	sideground[1]->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });
	mainground->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });*/

    this->scheduleUpdate();
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
}

bool GameScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	Vec2 touchlocate = touch->getLocation();

	return true;
}

Sprite* GameScene::DrawBox(std::string filename, Vec2 pos, Vec2 size, Vec2 anchor, std::string tagname, short int layer) {

	auto mySprite = Sprite::create();

	PolygonInfo inf;

	inf.filename = filename;

	inf.triangles.vertCount = 4;
	inf.triangles.verts = new V3F_C4B_T2F[inf.triangles.vertCount];
	inf.triangles.indexCount = 6;
	inf.triangles.indices = new unsigned short[inf.triangles.indexCount];

	inf.triangles.verts[0].vertices = Vec3(pos.x, pos.y, 0) + Vec3(0, 0, 0);
	inf.triangles.verts[0].texCoords = Tex2F(0, 1);
	inf.triangles.verts[0].colors = Color4B(255, 255, 255, 255);

	inf.triangles.verts[1].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x, 0, 0);
	inf.triangles.verts[1].texCoords = Tex2F(1, 1);
	inf.triangles.verts[1].colors = Color4B(255, 255, 255, 255);

	inf.triangles.verts[2].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x, size.y, 0);
	inf.triangles.verts[2].texCoords = Tex2F(1, 0.0);
	inf.triangles.verts[2].colors = Color4B(255, 255, 255, 255);

	inf.triangles.verts[3].vertices = Vec3(pos.x, pos.y, 0) + Vec3(0, size.y, 0);
	inf.triangles.verts[3].texCoords = Tex2F(0, 0);
	inf.triangles.verts[3].colors = Color4B(255, 255, 255, 255);

	inf.triangles.indices[0] = 0;
	inf.triangles.indices[1] = 1;
	inf.triangles.indices[2] = 2;

	inf.triangles.indices[3] = 2;
	inf.triangles.indices[4] = 3;
	inf.triangles.indices[5] = 0;

	inf.rect = Rect(Vec2(0, 0), Size(size.x, size.y));
	mySprite->initWithPolygon(inf);
	mySprite->setAnchorPoint(anchor);

	mySprite->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });
	this->addChild(mySprite, layer, tagname);

	return mySprite;
}