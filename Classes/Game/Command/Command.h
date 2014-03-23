#pragma once

#include "cocos2d.h"
#include "DataModel/BaseModel.h"
#include "../TimeMachine.h"

USING_NS_CC;

class BaseCommand : public Ref
{
public:
	BaseCommand();
	virtual void start()=0;
protected:
	virtual void run()=0;
	virtual bool init()=0;
};

class TimeCommand : public BaseCommand , public ITimeChangeListener
{
public:
	TimeCommand(GameTime cmdTime)
	{
		mCommandtime = cmdTime;
	}
	virtual void start();
protected:
	virtual bool init();
	virtual void onTimeChange(GameTime curtime);
private:
	GameTime mCommandtime;
};

class InstantCommand: public BaseCommand
{
public:
	InstantCommand(){}
	virtual void start();
protected:
	virtual bool init();
};