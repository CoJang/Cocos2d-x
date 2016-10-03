#include "Horse.h"

USING_NS_CC;

Horse::Horse()
	: 
	m_Level(1),
	Head(new Animator),
	Body(new Animator)
{
	for (int i = 0; i > 2; i++)
	{
		SpritePos[i] = Vec2(0, 0);
		SpriteAnchor[i] = Vec2(0, 0);
	}

	m_fHeightMover = 0;
	m_fHeight = 0;
}

Horse::~Horse()
{
	
}

Horse* Horse::InitHorse(cocos2d::Layer* scene)
{
	Head = Head->InitAnimation(scene, 
								12,
								300, 400,
								1200, 1200,
								0.05f,
								"horse_head_00.png",
								"horse_head.png");

	Head->setAnchorPoint(Vec2(0.5f, 0));
	Head->setPosition(Vec2(640, m_fHeight));

	Body = Body->InitAnimation(scene, 
								24,
								300, 400,
								1500, 2000,
								0.05f,
								"horse_body_00.png",
								"horse_body.png");

	Body->setAnchorPoint(Vec2(0.5f, 0));
	Body->setPosition(Vec2(640, m_fHeight));

	return this;
}

void Horse::update(float delta)
{
	static const float PI = 3.14159265359f;
	static const int power = -10;		// ÀÛ¾ÆÁú¼ö·Ï ÁøÆøÀÌ Ä¿Áü
	static const float speed = 10.f;	// Å¬¼ö·Ï ÁÖ±â°¡ »¡¶óÁü

	m_fHeight = MathUtil::lerp(0, power, sin(m_fHeightMover) * 0.5f + 0.5f);

	m_fHeightMover += delta * speed;
	if (m_fHeightMover > 2 * PI)m_fHeightMover = 0;

	Head->setPosition(Vec2(640, m_fHeight));
	Body->setPosition(Vec2(640, m_fHeight));

	Sprite::update(delta);
}