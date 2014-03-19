#include "TimeMechine.h"
#include "cocos2d.h"

USING_NS_CC;

static TimeMechine* s_TimeMechine = NULL;
TimeMechine::TimeMechine(void)
{
	memset(&mCurTime,0,sizeof(mCurTime));
	mTimeSpeed =10;
	mIsRunning = false;
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
void TimeMechine::start(GameTime starttime)
{
	mCurTime = starttime;
}
void TimeMechine::stop()
{
}
void TimeMechine::pause()
{
	if(mIsRunning)
	{
		mIsRunning = false;
		Director::getInstance()->getScheduler()->unscheduleUpdate(this);
	}
}
void TimeMechine::resume()
{
	if(!mIsRunning)
	{
		mIsRunning = true;
		Director::getInstance()->getScheduler()->scheduleUpdate(
			this,-1,false);
		mCurFrames = 0;
	}
}


void TimeMechine::removeTimeChangeListener(ITimeChangeListener* listener)
{
	mListenersTobeMoved.push_back(listener);
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
			if(!tobeMoved(*it))
			{
				(*it)->onTimeChange(mCurTime);
			}
		}
		moveListeners();
	}
}


bool TimeMechine::tobeMoved(ITimeChangeListener* listener)
{
	auto it = mListenersTobeMoved.begin();
	for(; mListenersTobeMoved.end() != it;it++)
	{
		if(listener == (*it))
		{
			return true;
		}
	}
	return false;
}
void TimeMechine::moveListeners()
{
	auto i = mListenersTobeMoved.begin();
	for(;mListenersTobeMoved.end()!=i;i++)
	{
		auto it = mAllListeners.begin();
		for (; mAllListeners.end()!=it; it++)
		{
			if((*i) == (*it))
			{
				mAllListeners.erase(it);
				break;
			}
		}
	}
	mListenersTobeMoved.clear();
}