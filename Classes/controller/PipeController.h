#pragma once
#include "cocos2d.h"
#include "../entity/PipeGroup.h";

USING_NS_CC;

class PipeController : public Node
{
private:
	Vector<PipeGroup*> pipes;
	int speed;
	int passed;
public:
	PipeController();
	void update(float dt);
	void setSpeed(int speed);
	int getSpeed();
	int getPassed();
};

