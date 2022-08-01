#include "MainScene.h"
#include "../entity/Bird.h"
#include "../entity/Pipe.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

bool MainScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // init map
    auto background = TMXTiledMap::create("background.tmx");
    background->setScale(visibleSize.height / background->getContentSize().height);
    this->addChild(background, 0, 99);

    // init bird
    auto bird = new Bird("yellowbird-midflap.png");
    bird->setAnimation("bird-fly.plist", "bird-fly.png", 4, 0.15);
    bird->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    bird->setScale(1.5);
    this->addChild(bird);

    // init pipe
    auto pipe = new Pipe("pipe-green.png");
    pipe->setPosition(Vec2(visibleSize.width / 2 + origin.x + 100, visibleSize.height / 2 + origin.y));
    pipe->setScale(1.5);
    this->addChild(pipe);
    
    return true;
}
