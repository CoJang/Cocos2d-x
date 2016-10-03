#pragma once
#include "cocos2d.h"
#include "Animator.h"

USING_NS_CC;

class Horse : public Animator
{
private:
	float m_fHeightMover;
	float m_fHeight;

public:
	Animator*	Head;
	Animator*	Body;

	float	  m_Level;

	Horse();
	virtual ~Horse();

	Horse* InitHorse(cocos2d::Layer* scene);

	virtual void update(float delta);

	Vec2 SpritePos[2];
	Vec2 SpriteAnchor[2];
};
