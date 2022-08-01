#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Bird : public Sprite
{
public:
	Bird(const std::string filename);
	void setAnimation(const std::string plist, const std::string pic, int frameCount, float delay);
};

