#include "Animator.h"
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
	TotalHorzCount = 0;	TotalAniCount = 0;
	AniDuration = 0;
}

Animator::~Animator()
{
}

Animator* Animator::InitAnimation(cocos2d::Layer* scene, int animationCnt, int unitsizeX, int unitsizeY, int imagewidth, int imageheight, float anidelay, char* spritefile, char* imagefile)
{
	Animator* _new = nullptr;

	CCTexture2D* texture = nullptr;
	CCAnimation* animation = nullptr;

	_new = new (std::nothrow) Animator();
	if (!_new)goto FAILED_FUNC;

	if (!_new->initWithFile(spritefile))goto FAILED_FUNC;

	_new->autorelease();

	_new->UnitSizeX = unitsizeX;
	_new->UnitSizeY = unitsizeY;
	_new->ImageWidth = imagewidth;
	_new->ImageHeight = imageheight;
	_new->AniDelay = anidelay;
	_new->TotalHorzCount = imagewidth / unitsizeX;
	_new->TotalAniCount = animationCnt;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	texture = CCTextureCache::sharedTextureCache()->addImage(imagefile);
	if(!texture)goto FAILED_FUNC;

	animation = CCAnimation::create();
	if(!animation)goto FAILED_FUNC;

	for (size_t i = 0; i < _new->TotalAniCount; ++i) {
		size_t x = i % _new->TotalHorzCount;
		size_t y = i / _new->TotalHorzCount;

		Rect rt = Rect(
			_new->UnitSizeX * x,
			_new->UnitSizeY * y,
			_new->UnitSizeX,
			_new->UnitSizeY
		);

		animation->addSpriteFrame(CCSpriteFrame::createWithTexture(texture, rt));
	}

	animation->setDelayPerUnit(_new->AniDelay);

	_new->runAction(RepeatForever::create(Animate::create(animation)));

	scene->addChild(_new, 4, imagefile);
	return _new;

FAILED_FUNC:
	if (_new)delete _new;
	if (texture)delete texture;
	if (animation)delete animation;
	return nullptr;
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