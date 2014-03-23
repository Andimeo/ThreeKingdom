#pragma once
#include "TimeMachine.h"
#include "DataModel/GameEventBase.h"
#include <list>
#include <string>
class HistoryEventLogicController : public ITimeChangeListener
{
public:
	HistoryEventLogicController(void);
	~HistoryEventLogicController(void);

	virtual void onTimeFly(long timePassed, GameTime curtime);
	virtual void onTimeChange(GameTime curtime);

	static HistoryEventLogicController* getInstance();
	void handleHistoryEvent(GameEventBase* event);
private:
	std::list<GameEventHistory*> mAllHistory;	// This would be not change after initial
	std::list<GameEventHistory*> mTriggeredEventList;

	std::list<GameEventHistory*>::iterator mLastEventIterator;
public:
	void initHistory();
};

