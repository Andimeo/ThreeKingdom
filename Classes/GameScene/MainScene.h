#pragma once 
#include "cocos2d.h"
#include "../Game/TimeMachine.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace cocos2d::ui;

class MainScene : public Scene ,public ITimeChangeListener
{
public:
	MainScene();
	~MainScene();
	CREATE_FUNC(MainScene);
protected:
	virtual bool init();
	virtual void onTimeChange(GameTime curtime);
	void menuStartCallback(cocos2d::Ref* object ,TouchEventType type);
private:
	LabelTTF* mTimeLabel;
};