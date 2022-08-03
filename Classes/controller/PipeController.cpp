#include "AudioEngine.h"
#include "PipeController.h"
#include "../common/GameConstants.h"

PipeController::PipeController()
{
	speed = 100;
	passed = 0;
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	for (int i = 0; i < 8; i++)
	{
		auto pipe = new PipeGroup("pipe-green.png");
		pipe->setPosition(visibleSize.width + origin.x + 240 * i, visibleSize.height / 2 + origin.y);
		auto topPipe = pipe->getTopPipe();
		topPipe->setPhysicsBody(PhysicsBody::createBox(topPipe->getContentSize()));
		topPipe->getPhysicsBody()->setDynamic(false);
		topPipe->getPhysicsBody()->setCategoryBitmask(GameConstants::PIPE_MASK);
		topPipe->getPhysicsBody()->setContactTestBitmask(GameConstants::PIPE_MASK);
		auto botPipe = pipe->getBotPipe();
		botPipe->setPhysicsBody(PhysicsBody::createBox(botPipe->getContentSize()));
		botPipe->getPhysicsBody()->setDynamic(false);
		botPipe->getPhysicsBody()->setCategoryBitmask(GameConstants::PIPE_MASK);
		botPipe->getPhysicsBody()->setContactTestBitmask(GameConstants::PIPE_MASK);
		this->addChild(pipe);
		pipes.pushBack(pipe);
	}
}

void PipeController::update(float dt)
{
	const auto visibleSize = Director::getInstance()->getVisibleSize();
	const Vec2 origin = Director::getInstance()->getVisibleOrigin();
	for (int i = 0; i < pipes.size(); i++)
	{
		if (!pipes.at(i)->getIsPassed() && pipes.at(i)->getPositionX() <= visibleSize.width / 2 + origin.x - pipes.at(i)->getTopPipe()->getContentSize().width / 2) {
			pipes.at(i)->setIsPassed(true);
			experimental::AudioEngine::play2d("sounds/point.mp3");
;			passed += 1;
		}
		if (pipes.at(i)->getPositionX() <= -100) {
			auto frontPipe = pipes.at(i == 0 ? pipes.size() - 1 : i - 1);
			pipes.at(i)->setPositionX(frontPipe->getPositionX() + RandomHelper::random_int(12, 28) * 10);
			pipes.at(i)->setIsPassed(false);
			continue;
		}
		pipes.at(i)->setPositionX(pipes.at(i)->getPositionX() - speed * dt);
	}
}

void PipeController::setSpeed(int speed)
{
	this->speed = speed;
}

int PipeController::getSpeed()
{
	return speed;
}

int PipeController::getPassed()
{
	return passed;
}