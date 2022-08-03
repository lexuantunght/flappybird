#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "../controller/PipeController.h"
#include "../controller/MapController.h"
#include "../controller/BaseGroundController.h"
#include "../controller/BirdController.h"

USING_NS_CC;

class MainScene : public cocos2d::Scene
{
private:
    PipeController* pipeController;
    MapController* mapController;
    BaseGroundController* baseGroundController;
    BirdController* birdController;
    Layer* mainLayer;
    void initMainLayer();
    void initSounds();
    bool handleTouchMainLayer(Touch* touch, Event* event);
    bool handleCollide(PhysicsContact& contact);
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void update(float dt);

    CREATE_FUNC(MainScene);
};

#endif // __MAIN_SCENE_H__