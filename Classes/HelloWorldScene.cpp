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

    
    float ratio = 1280 / 720;

    this->setCameraMask((unsigned short)CameraFlag::DEFAULT, true);
    auto cam = Camera::create();
    cam->setAnchorPoint(Vec2(0, 0));
    cam->setPosition3D(Vec3(0, 0, 700));
    cam->lookAt(Vec3(0, 1, 0));
    cam->setCameraFlag(CameraFlag::DEFAULT);
    this->addChild(cam);

    //we are making sprite with the same height and width
    auto mySprite = Sprite::create();
    //create a PolygonInfo object to store all the data needed for polygon drawing
    PolygonInfo inf;
    // assigning texture file
    inf.filename = "HelloWorld.png";
    //
    // setting the number of vertices in the desired polygon (3 because triangle)
    inf.triangles.vertCount = 3;
    // allocating memory for vertices (vertex position on the screen, vertex color Color4B, corresponding texture point)
    inf.triangles.verts = new V3F_C4B_T2F[inf.triangles.vertCount];
    // triangles are drawn based on the indices of vertices, hence the count is always divisible by 3
    inf.triangles.indexCount = 3;
    // the triangle are actually polygon vertices stored in inf.triangles.verts. To draw one triangle one provides a set of 3 indices
    inf.triangles.indices = new unsigned short[inf.triangles.indexCount];
    //Now setting up triangle vertices
    //first, lower left point
    inf.triangles.verts[0].vertices = Vec3(pos.x, pos.y, 0) + Vec3(0, 0, 0);
    inf.triangles.verts[0].texCoords = Tex2F(0, 1);
    inf.triangles.verts[0].colors = Color4B(255, 255, 255, 255);

    //second, lower right point
    inf.triangles.verts[1].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x, 0, 0);
    inf.triangles.verts[1].texCoords = Tex2F(1.0, 1);
    inf.triangles.verts[1].colors = Color4B(255, 255, 255, 255);
    //third, top point
    inf.triangles.verts[2].vertices = Vec3(pos.x, pos.y, 0) + Vec3(size.x * 0.5f, size.y, 0);
    inf.triangles.verts[2].texCoords = Tex2F(0.5, 0.0);
    inf.triangles.verts[2].colors = Color4B(255, 255, 255, 255);
    // setting the vertex indices to draw polygon
    inf.triangles.indices[0] = 0;
    inf.triangles.indices[1] = 1;
    inf.triangles.indices[2] = 2;
    //setting the rectangle containing the sprite

    inf.rect = Rect(Vec2(0, 0), Size(size.x, size.y));
    mySprite->initWithPolygon(inf);
    mySprite->setAnchorPoint(Vec2(0.0f, 0.0f));

    addChild(mySprite);
    
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
    if ( !LayerColor::initWithColor(Color4B::BLACK) )
    {
        return false;
    }

    Vec2 pos = { 0, 0 };
    Vec2 size = { 1280, 720 };
    DrawBitch(pos, size);
   

    return true;
}
