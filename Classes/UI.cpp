#include "UI.h"

USING_NS_CC;

UI::UI()
	: 
	ingame_UI(new Animator)
{
}

UI::~UI()
{
}

UI* UI::InitUI(cocos2d::Layer* scene)
{
	ingame_UI = ingame_UI->InitAnimation(scene, 0.08f, "./ui/ui.txt");

	ingame_UI->setAnchorPoint(Vec2(0, 0));
	ingame_UI->setPosition(Vec2(0, 0));

	return this;
}

void UI::update(float delta)
{
	Sprite::update(delta);
} 