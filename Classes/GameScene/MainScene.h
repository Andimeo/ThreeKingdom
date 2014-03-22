#pragma once 
#include "cocos2d.h"
#include "../Game/TimeMechine.h"

USING_NS_CC;

class MainScene : public Scene ,public ITimeChangeListener
{
public:
	MainScene();
	~MainScene();
	CREATE_FUNC(MainScene);
protected:
	virtual bool init();
	virtual void onTimeChange(GameTime curtime);
	virtual void onTimeFly(long timePassed, GameTime curtime);
	void menuStartCallback(cocos2d::Ref* pSender);
private:
	LabelTTF* mTimeLabel;
};