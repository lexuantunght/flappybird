#pragma once
#include "cocos2d.h"
#include "../entity/Bird.h"

USING_NS_CC;

class BirdController : public Node
{
private:
	Bird* bird;
public:
	BirdController();
	Bird* getBird();
};

