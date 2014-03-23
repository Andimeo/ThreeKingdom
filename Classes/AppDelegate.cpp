#include "AppDelegate.h"
#include "GameScene/MainScene.h"
#include "Game/TimeMachine.h"
#include "SimpleAudioEngine.h"
#include "GameScene/MessageDialog.h"

#include "Game/GameLogicController.h"
#include "Game/HistoryEventLogicController.h"

USING_NS_CC;

AppDelegate::AppDelegate() 
{ }

AppDelegate::~AppDelegate() 
{ }

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = MainScene::create();
	GameTime curtime;
	curtime.year = 190;
	curtime.month =1;
	curtime.day = 1;
	curtime.hour = 0;
	MessageDialog::getInstance();
	TimeMachine::getInstance()->start(curtime);
    // run
    director->runWithScene(scene);

	// initial
	GameLogicController::getInstance()->init();
	HistoryEventLogicController::getInstance()->initHistory();
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
     CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
