#pragma once
#include "cocos2d.h"

USING_NS_CC;

class MapController : public Node
{
private:
	TMXTiledMap* firstMap;
	TMXTiledMap* secondMap;
	int speed;
public:
	MapController();
	void update(float dt);
	void setSpeed(int speed);
	int getSpeed();
};

