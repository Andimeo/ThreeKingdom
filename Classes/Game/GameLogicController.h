#pragma once

#include <list>
#include <thread>
#include <mutex>
#include <errno.h>
#include "DataModel\GameEventBase.h"

class GameLogicController
{
public:
	GameLogicController(void);
	~GameLogicController(void);

	static GameLogicController* getInstance();
	void addGameEvent(GameEventBase* event);

public:
	void init();

private:
	std::list< GameEventBase* > mGameEvents;

private:
	void eventHandleThreadRunable();

};

