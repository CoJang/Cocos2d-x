#pragma once
#include "cocos2d.h"

class Parser
{	
public:
	Parser();
	virtual ~Parser();

	//virtual void update(float delta);
};

bool Save();

bool Load();