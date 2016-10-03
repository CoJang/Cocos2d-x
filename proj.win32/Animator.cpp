include "Animator.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

USING_NS_CC;

using namespace cocostudio::timeline;

Animator::Animator()
{
	UnitSizeX = 0;			UnitSizeY = 0;
	AniDelay = 0; 			AniIndex = 0;
	ImageWidth = 0;			ImageHeight = 0;
	CurrentFrame = 0;
	TotalFrameCount = 0;	TotalAniCount = 0;
	AniDuration = 0;
}

Animator::~Animator()
{
}

Animator* Animator::InitAnimation(cocos2d::Layer* scene, int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay)
{
	auto _new = new Animator();

	_new->UnitSizeX = unitsizeX;
	_new->UnitSizeY = unitsizeY;
	_new->ImageWidth = imagewidth;
	_new->ImageHeight = imageheight;
	_new->AniDelay = anidelay;
	_new->TotalFrameCount = imagewidth / unitsizeX;
	_new->TotalAniCount = imageheight / unitsizeY;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	CCSprite* sprite = CCSprite::create("horse_head_00.png");
	

	CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("horse_head.png");

	CCAnimation* animation = CCAnimation::create();

	for (size_t i = 0; i < _new->TotalAniCount * _new->TotalFrameCount; ++i) {
		size_t x = i % _new->TotalFrameCount;
		size_t y = i / _new->TotalFrameCount;

		Rect rt = Rect(
			_new->UnitSizeX * x,
			_new->UnitSizeY * y,
			_new->UnitSizeX,
			_new->UnitSizeY
		);

		animation->addSpriteFrame(CCSpriteFrame::createWithTexture(texture, rt));
	}

	animation->setDelayPerUnit(_new->AniDelay);

	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(640, 150));
	sprite->runAction(CCAnimate::create(animation));

	scene->addChild(sprite, 4);
	return _new;
}

void Animator::UpdateAni(float Elapsed)
{
	AniDuration -= Elapsed;

	if (AniDuration < 0)
	{
		AniDuration += AniDelay;
		++CurrentFrame;
		if (CurrentFrame >= TotalFrameCount)
			CurrentFrame = 0;
	}
}

void Animator::SetAniIndex(int index)
{
	AniIndex = index;
}

int Animator::GetSrcTop()
{
	return AniIndex * UnitSizeY;
}

int Animator::GetSrcLeft()
{
	return CurrentFrame * UnitSizeX;
}