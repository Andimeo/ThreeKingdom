#include "TimeMachine.h"
#include "cocos2d.h"

USING_NS_CC;

static TimeMachine* s_TimeMachine = NULL;
TimeMachine::TimeMachine(void)
{
	memset(&mCurTime,0,sizeof(mCurTime));
	mTimeSpeed =10;
	mIsRunning = false;
}


TimeMachine::~TimeMachine(void)
{
}

TimeMachine* TimeMachine::getInstance()
{
	if(NULL == s_TimeMachine)
	{
		s_TimeMachine = new TimeMachine();
	}
	return s_TimeMachine;
}
void TimeMachine::start(GameTime starttime)
{
	mCurTime = starttime;
}
void TimeMachine::stop()
{
}
void TimeMachine::pause()
{
	if(mIsRunning)
	{
		mIsRunning = false;
		Director::getInstance()->getScheduler()->unscheduleUpdate(this);
	}
}
void TimeMachine::resume()
{
	if(!mIsRunning)
	{
		mIsRunning = true;
		Director::getInstance()->getScheduler()->scheduleUpdate(
			this,-1,false);
		mCurFrames = 0;
	}
}


void TimeMachine::removeTimeChangeListener(ITimeChangeListener* listener)
{
	mListenersTobeMoved.push_back(listener);
}

void TimeMachine::update(float dt)
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


bool TimeMachine::tobeMoved(ITimeChangeListener* listener)
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
void TimeMachine::moveListeners()
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