#include "Bird.h"

Bird::Bird(const std::string filename)
{
	this->initWithFile(filename);
}

void Bird::setAnimation(const std::string plist, const std::string pic, int frameCount, float delay)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist, pic);
	Vector<SpriteFrame*> frames;

	auto frameCache = SpriteFrameCache::getInstance();
	char file[100] = { 0 };
	for (int i = 0; i < frameCount; i++) {
		sprintf(file, "%d.png", i + 1);
		auto frame = frameCache->getSpriteFrameByName(file);
		frames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(frames, delay);
	auto animate = Animate::create(animation);
	this->runAction(RepeatForever::create(animate));
}
