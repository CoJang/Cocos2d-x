#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


USING_NS_CC;

using namespace cocostudio::timeline;

void HelloWorld::DrawBitch(Vec2 pos, cocos2d::Vec2 size) {

    auto mySprite = Sprite::create();

    PolygonInfo inf;

    inf.filename = "HelloWorld.png";

    inf.triangles.vertCount = 3;
    inf.triangles.verts = new V3F_C4B_T2F[inf.triangles.vertCount];
    inf.triangles.indexCount = 3;
    inf.triangles.indices = new unsigned short[inf.triangles.indexCount];


    inf.triangles.verts[0].vertices = Vec3(pos.x, pos.y, 0) + Vec3(0, 0, 0);
    inf.triangles.verts[0].texCoords = Tex2F(0, 1);
    inf.triangles.verts[0].colors = Color4B(255, 255, 255, 255);

    inf.triangles.verts[1].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x, 0, 0);
    inf.triangles.verts[1].texCoords = Tex2F(1.0, 1);
    inf.triangles.verts[1].colors = Color4B(255, 255, 255, 255);

    inf.triangles.verts[2].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x * 0.5f, size.y, 0);
    inf.triangles.verts[2].texCoords = Tex2F(0.5, 0.0);
    inf.triangles.verts[2].colors = Color4B(255, 255, 255, 255);

    inf.triangles.indices[0] = 0;
    inf.triangles.indices[1] = 1;
    inf.triangles.indices[2] = 2;

    inf.rect = Rect(Vec2(0, 0), Size(size.x, size.y));
    mySprite->initWithPolygon(inf);
    mySprite->setAnchorPoint(Vec2(0.0f, 0.0f));
    mySprite->setCameraMask((unsigned short)CameraFlag::DEFAULT, true);
    this->addChild(mySprite);

    
    
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    auto newscene = Layer::create();
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !LayerColor::initWithColor(Color4B::BLUE) )
    {
        return false;
    }

    Vec2 pos = { 0, 0 };
    Vec2 size = { 1280, 720 };
    DrawBitch(pos, size);

    //this->setCameraMask((unsigned short)CameraFlag::DEFAULT);
    //auto cam = Camera::create();
    ////auto cam = Camera::createPerspective(40, 1280 / 720, 10, 1000);
    //cam->setCameraFlag(CameraFlag::DEFAULT);

    ////cam->setPositionX(100);
    //cam->setPosition3D(Vec3(640, 0, 500));
    //cam->lookAt(Vec3(640, 360, 0), Vec3(0, 1, 0));
    ////cam->lookAt(Vec3(0, 1, 0));

    //this->addChild(cam, 1, "camera");

    this->setRotation3D(Vec3(-45, 0, 0));

    return true;
}
