#include "MapController.h"

MapController::MapController()
{
    speed = 50;

    const Size winSize = Director::getInstance()->getWinSize();
    const Vec2 origin = Director::getInstance()->getVisibleOrigin();

    firstMap = TMXTiledMap::create("background.tmx");
    firstMap->setScale(winSize.height / firstMap->getContentSize().height);
    firstMap->setPosition(0, 0);
    secondMap = TMXTiledMap::create("background.tmx");
    secondMap->setScale(winSize.height / secondMap->getContentSize().height);
    secondMap->setPosition(Vec2(firstMap->getPositionX() + firstMap->getContentSize().width, 0));

    this->addChild(firstMap, 0, 1);
    this->addChild(secondMap, 0, 2);
}

void MapController::update(float dt)
{
    // handle first map
    if (firstMap->getPositionX() <= -firstMap->getContentSize().width - 100) {
        firstMap->setPositionX(secondMap->getPositionX() + secondMap->getContentSize().width - speed * dt);
    }
    else {
        firstMap->setPositionX(firstMap->getPositionX() - speed * dt);
    }
    // handle second map
    if (secondMap->getPositionX() <= -secondMap->getContentSize().width - 100) {
        secondMap->setPositionX(firstMap->getPositionX() + firstMap->getContentSize().width);
    }
    else {
        secondMap->setPositionX(secondMap->getPositionX() - speed * dt);
    }
}

int MapController::getSpeed()
{
    return speed;
}

void MapController::setSpeed(int speed)
{
    this->speed = speed;
}