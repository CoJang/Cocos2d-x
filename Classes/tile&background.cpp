#include "tile&background.h"

USING_NS_CC;

tile_background::tile_background()
	: 
	Sky(new Sprite),
	Mountain(new Sprite),
	Tile(new Sprite),
	Sky_Gradaition(new Sprite)
{}

tile_background::~tile_background()
{}

tile_background* tile_background::InitBackground(cocos2d::Layer* scene)
{
	Sky = Sprite::create("./tile_ground/sky_ground.png");
	Sky->setAnchorPoint(Vec2(0, 0));
	Sky->setPosition(Vec2(-10, 520));

	scene->addChild(Sky, 0, "sky");

	Mountain = Sprite::create("./tile_ground/mountain_ground.png");
	Mountain->setAnchorPoint(Vec2(0, 0));
	Mountain->setPosition(Vec2(-10, 520));

	scene->addChild(Mountain, 0, "mountain");

	Sky_Gradaition = Sprite::create("./tile_ground/sky_gradaition.png");
	Sky_Gradaition->setAnchorPoint(Vec2(0, 0));
	Sky_Gradaition->setPosition(Vec2(0, 142));

	scene->addChild(Sky_Gradaition, 2, "sky_gradaition");

	return this;
}

tile_background* tile_background::InitTile(cocos2d::Layer* scene)
{
	Tile = Sprite::create("./tile_ground/ground.png");

	Tile->setAnchorPoint(Vec2(0.5, 0));
	Tile->setPosition(Vec2(640, -300));
	Tile->setScale(1.3f, 2);
	Tile->getTexture()->setTexParameters({ GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT });

	scene->addChild(Tile, 0, "Tile");

	return this;
}

void tile_background::update(float delta)
{
	static float scroll = 0.f;

	Rect rt;

	rt = Tile->getTextureRect();

	scroll -= delta * 1000.f;
	if (scroll > rt.size.height) scroll = 0.f;

	rt.origin.y = scroll;

	Tile->setTextureRect(rt);
}