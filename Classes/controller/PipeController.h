#pragma once
#include "cocos2d.h"
#include "../entity/PipeGroup.h";

USING_NS_CC;

class PipeController : public Node
{
private:
	Vector<PipeGroup*> pipes;
	int speed;
public:
	PipeController();
	void update(float dt);
	void setSpeed(int speed);
	int getSpeed();
};

