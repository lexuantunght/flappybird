#include "BirdController.h"
#include "../common/GameConstants.h"

BirdController::BirdController()
{
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2 origin = Director::getInstance()->getVisibleOrigin();
    bird = new Bird("yellowbird-midflap.png");
    bird->setAnimation("bird-fly.plist", "bird-fly.png", 4, 0.15);
    bird->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    bird->setPhysicsBody(PhysicsBody::createBox(bird->getContentSize()));
    bird->getPhysicsBody()->setRotationEnable(false);
    bird->getPhysicsBody()->setContactTestBitmask(GameConstants::BIRD_PHYSICS_MASK);
    bird->getPhysicsBody()->setCategoryBitmask(GameConstants::BIRD_PHYSICS_MASK);
    bird->getPhysicsBody()->setTag(GameConstants::BIRD_TAG);
    this->addChild(bird);
}

Bird* BirdController::getBird()
{
    return bird;
}