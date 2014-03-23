#pragma once
#include "../DataModel/BaseModel.h"
#include <vector>

class ITimeChangeListener
{
public :
	ITimeChangeListener()
	{
	}
	virtual ~ITimeChangeListener()
	{
	}

	virtual void onTimeChange(GameTime curtime) = 0;
	virtual void onTimeFly(long dayPassed, GameTime curtime) = 0;
};

class TimeMechine 
{
private:
	TimeMechine(void);
	~TimeMechine(void);
public:
	static TimeMechine* getInstance();
public:
	void start(GameTime starttime);
	void stop();
	void pause();
	void resume();
	void addTimeChangeListener(ITimeChangeListener* listener)
	{
		mAllListeners.push_back(listener);
	}

	void removeTimeChangeListener(ITimeChangeListener* listener);
	void setSpeed(int framesPerHour)
	{
		mTimeSpeed = framesPerHour;
	}

	void timeFly(long days);
public:
	void update(float dt);
private:
	void moveListeners();
	bool tobeMoved(ITimeChangeListener* listener);
private:
	GameTime mCurTime;
	int mTimeSpeed;
	int mCurFrames;
	bool mIsRunning;
	std::vector<ITimeChangeListener*> mAllListeners;
	std::vector<ITimeChangeListener*> mListenersTobeMoved;
};

