#include "TimeMechine.h"
#include "cocos2d.h"

USING_NS_CC;

static TimeMechine* s_TimeMechine = NULL;
TimeMechine::TimeMechine(void)
{
	memset(&mCurTime,0,sizeof(mCurTime));
	mTimeSpeed =60;
}


TimeMechine::~TimeMechine(void)
{
}

TimeMechine* TimeMechine::getInstance()
{
	if(NULL == s_TimeMechine)
	{
		s_TimeMechine = new TimeMechine();
	}
	return s_TimeMechine;
}
void TimeMechine::Start(GameTime starttime)
{
	mCurTime = starttime;
}
void TimeMechine::Stop()
{
}
void TimeMechine::Pause()
{
	Director::getInstance()->getScheduler()->unscheduleUpdate(this);
}
void TimeMechine::Resume()
{
	Director::getInstance()->getScheduler()->scheduleUpdate(
		this,-1,false);
	mCurFrames = 0;
}


void TimeMechine::RemoveTimeChangeListener(ITimeChangeListener* listener)
{
	auto it = mAllListeners.begin();
	for (; mAllListeners.end()!=it; it++)
	{
		if(listener == (*it))
		{
			mAllListeners.erase(it);
			break;
		}
	}
}
void TimeMechine::update(float dt)
{
	mCurFrames++;
	if(mCurFrames >= mTimeSpeed)
	{
		mCurTime.addhours(1);
		mCurFrames = 0;
		auto it = mAllListeners.begin();
		for (; mAllListeners.end()!=it; it++)
		{
			(*it)->OnTimeChange(mCurTime);
		}
		printf("cur time:%d:%d:%d:%d\n",mCurTime.year,
			mCurTime.month,mCurTime.day,mCurTime.hour);
	}
}