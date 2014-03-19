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

	virtual void OnTimeChange(GameTime curtime) = 0;
};

class TimeMechine 
{
private:
	TimeMechine(void);
	~TimeMechine(void);
public:
	static TimeMechine* getInstance();
public:
	void Start(GameTime starttime);
	void Stop();
	void Pause();
	void Resume();
	void AddTimeChangeListener(ITimeChangeListener* listener)
	{
		mAllListeners.push_back(listener);
	}

	void RemoveTimeChangeListener(ITimeChangeListener* listener);
	void SetSpeed(int framesPerHour)
	{
		mTimeSpeed = framesPerHour;
	}
public:
	void update(float dt);
private:
	GameTime mCurTime;
	int mTimeSpeed;
	int mCurFrames;
	std::vector<ITimeChangeListener*> mAllListeners;
};

