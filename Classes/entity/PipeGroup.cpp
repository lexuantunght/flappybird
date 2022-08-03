#include "PipeGroup.h"

PipeGroup::PipeGroup(const std::string filename)
{
	isPassed = false;
	topPipe = new Pipe(filename);
	topPipe->setFlippedY(true);
	topPipe->setPhysicsBody(PhysicsBody::createBox(topPipe->getContentSize()));
	topPipe->getPhysicsBody()->setDynamic(false);
	botPipe = new Pipe(filename);
	botPipe->setPhysicsBody(PhysicsBody::createBox(botPipe->getContentSize()));
	botPipe->getPhysicsBody()->setDynamic(false);
	this->addChild(topPipe, 0, 1);
	this->addChild(botPipe, 0, 2);
	pipeHeight = topPipe->getContentSize().height;
	topPipe->setPositionY(pipeHeight / 2);
	botPipe->setPositionY(-pipeHeight / 2);
	randPipePos();
}

void PipeGroup::randPipePos()
{
	topPipe->setPositionY(pipeHeight / 2 + RandomHelper::random_int(4, 20) * 10);
	botPipe->setPositionY(-pipeHeight / 2 - RandomHelper::random_int(4, 20) * 10);
}

Pipe* PipeGroup::getTopPipe()
{
	return topPipe;
}

Pipe* PipeGroup::getBotPipe()
{
	return botPipe;
}

bool PipeGroup::getIsPassed()
{
	return isPassed;
}

void PipeGroup::setIsPassed(bool passed)
{
	isPassed = passed;
}