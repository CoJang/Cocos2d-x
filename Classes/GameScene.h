#pragma once
#include "cocos2d.h"
#include "Animator.h"
#include "Horse.h"
#include "Man.h"
#include "UI.h"
#include "tile&background.h"
#include "Parser.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    Sprite* mainground;

	Horse* horse;
	Man*   man;
	UI*	   InGame_UI;
	tile_background* Tile_Background;

	Vec3 camlocation;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);

public:
    // Scene내의 모든 객체의 update를 담당
    void update(float delta);

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event) {};
	virtual void onTouchEnded(Touch* touch, Event* unused_event) {};
};
