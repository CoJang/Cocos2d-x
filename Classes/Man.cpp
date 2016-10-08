#include "Man.h"

USING_NS_CC;

Man::Man()
	: 
	m_Level(1),
	Head(new Animator),
	Body(new Animator),
	Legs(new Animator)
{
	m_fHeightMover = 0;
}

Man::~Man()
{
}

Man* Man::InitMan(cocos2d::Layer* scene)
{
	Head = Head->InitAnimation(
								scene, 
								6,
								300, 400,
								1200, 800,
								0.07f,
								"./man/man_head.png"
							);

	Head->setAnchorPoint(Vec2(0.5f, 0));
	Head->setPosition(Vec2(640, 0));

	Legs = Legs->InitAnimation(
								scene,
								6,
								300, 400,
								1200, 800,
								0.1f,
								"./man/man_legs.png"
						);

	Legs->setAnchorPoint(Vec2(0.5f, 0));
	Legs->setPosition(Vec2(640, 0));

	Body = Body->InitAnimation(
								scene, 
								6,
								300, 400,
								1200, 800,
								0.07f,
								"./man/man_body.png"
						);

	Body->setAnchorPoint(Vec2(0.5f, 0));
	Body->setPosition(Vec2(640, 0));

	return this;
}

void Man::update(float delta)
{
	static const float PI = 3.14159265359f;
	static const int power = -10;		// ÀÛ¾ÆÁú¼ö·Ï ÁøÆøÀÌ Ä¿Áü
	static const float speed = 10.f;	// Å¬¼ö·Ï ÁÖ±â°¡ »¡¶óÁü

	float fHeight = MathUtil::lerp(0, power, sin(m_fHeightMover) * 0.5f + 0.5f);
	//float fHeight_undernation = MathUtil::lerp(0, power, sin(m_fHeightMover + PI * 1.25f) * 0.5f + 0.5f);

	m_fHeightMover += delta * speed;
	if (m_fHeightMover > 2 * PI)m_fHeightMover = 0;

	Head->setPosition(Vec2(640, fHeight));
	Body->setPosition(Vec2(640, fHeight));
	Legs->setPosition(Vec2(640, fHeight));

	Sprite::update(delta);
}