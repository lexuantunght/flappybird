#include "BaseGroundController.h"
#include "../common/GameConstants.h"

BaseGroundController::BaseGroundController()
{
	speed = 100;

    firstBase = TMXTiledMap::create("base.tmx");
    firstBase->setPosition(0, 0);
    firstBase->setPhysicsBody(PhysicsBody::createBox(firstBase->getContentSize()));
    firstBase->getPhysicsBody()->setDynamic(false);
    firstBase->getPhysicsBody()->setCategoryBitmask(GameConstants::FIRST_BASE_MASK);
    firstBase->getPhysicsBody()->setContactTestBitmask(GameConstants::FIRST_BASE_MASK);
    secondBase = TMXTiledMap::create("base.tmx");
    secondBase->setPosition(Vec2(firstBase->getPositionX() + firstBase->getContentSize().width, 0));
    secondBase->setPhysicsBody(PhysicsBody::createBox(secondBase->getContentSize()));
    secondBase->getPhysicsBody()->setDynamic(false);
    secondBase->getPhysicsBody()->setCategoryBitmask(GameConstants::SECOND_BASE_MASK);
    secondBase->getPhysicsBody()->setContactTestBitmask(GameConstants::SECOND_BASE_MASK);

    this->addChild(firstBase, 0, 1);
    this->addChild(secondBase, 0, 2);
}

void BaseGroundController::update(float dt)
{
    // handle first map
    if (firstBase->getPositionX() <= -firstBase->getContentSize().width - 100) {
        firstBase->setPositionX(secondBase->getPositionX() + secondBase->getContentSize().width - speed * dt);
    }
    else {
        firstBase->setPositionX(firstBase->getPositionX() - speed * dt);
    }
    // handle second map
    if (secondBase->getPositionX() <= -secondBase->getContentSize().width - 100) {
        secondBase->setPositionX(firstBase->getPositionX() + firstBase->getContentSize().width);
    }
    else {
        secondBase->setPositionX(secondBase->getPositionX() - speed * dt);
    }
}

int BaseGroundController::getSpeed()
{
    return speed;
}

void BaseGroundController::setSpeed(int speed)
{
    this->speed = speed;
}