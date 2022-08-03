#include "AudioEngine.h"
#include "MainScene.h"
#include "../common/GameConstants.h"

Scene* MainScene::createScene()
{
    return MainScene::create();
}

bool MainScene::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    this->initSounds();
    this->initMainLayer();
    this->scheduleUpdate();
 
    return true;
}

void MainScene::initMainLayer()
{
    mainLayer = Layer::create();

    // init map
    mapController = new MapController();
    mainLayer->addChild(mapController);

    // init bird
    birdController = new BirdController();
    mainLayer->addChild(birdController);

    // init pipe
    pipeController = new PipeController();
    mainLayer->addChild(pipeController);

    // init base ground
    baseGroundController = new BaseGroundController();
    mainLayer->addChild(baseGroundController);

    this->addChild(mainLayer);

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(false);
    listener->onTouchBegan = CC_CALLBACK_2(MainScene::handleTouchMainLayer, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, mainLayer);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(MainScene::handleCollide, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, mainLayer);
}

bool MainScene::handleTouchMainLayer(Touch* touch, Event* event) 
{
    auto birdPhysicsBody = birdController->getBird()->getPhysicsBody();
    if (birdPhysicsBody->getVelocity().y <= 0) {
        experimental::AudioEngine::play2d("sounds/wing.mp3");
        birdPhysicsBody->applyImpulse(Vec2(0, 30000));
    }
    return true;
}

bool MainScene::handleCollide(PhysicsContact& contact)
{
    auto tagA = contact.getShapeA()->getBody()->getTag();
    auto tagB = contact.getShapeB()->getBody()->getTag();
    if (tagA == GameConstants::BIRD_TAG || tagB == GameConstants::BIRD_TAG)
    {
        experimental::AudioEngine::play2d("sounds/hit.mp3");
        experimental::AudioEngine::play2d("sounds/die.mp3");
        this->unscheduleUpdate();
        birdController->getBird()->stopAllActions();
        this->getPhysicsWorld()->setSpeed(0);
    }
    return true;
}

void MainScene::initSounds()
{
    experimental::AudioEngine::preload("sounds/wing.mp3");
    experimental::AudioEngine::preload("sounds/hit.mp3");
    experimental::AudioEngine::preload("sounds/point.mp3");
    experimental::AudioEngine::preload("sounds/die.mp3");
}

void MainScene::update(float dt)
{
    pipeController->update(dt);
    mapController->update(dt);
    baseGroundController->update(dt);
}
