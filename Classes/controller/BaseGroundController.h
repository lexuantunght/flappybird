#pragma once
#include "cocos2d.h"

USING_NS_CC;

class BaseGroundController : public Node
{
private:
	TMXTiledMap* firstBase;
	TMXTiledMap* secondBase;
	int speed;
public:
	BaseGroundController();
	void update(float dt);
	void setSpeed(int speed);
	int getSpeed();
};

