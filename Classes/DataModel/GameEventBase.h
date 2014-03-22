#pragma once
#include <string>
typedef enum _GAME_EVENT_TYPE
{
	HISTORY_EVENT = 0,
}ENUM_GAME_EVENT_TYPE;


class GameEventBase
{
public:
	GameEventBase(void);
	virtual ~GameEventBase(void);
	ENUM_GAME_EVENT_TYPE mType;
	long mTime;	// Event Time
};

class GameEventHistory : public GameEventBase{
public:
	GameEventHistory(void);
	virtual ~GameEventHistory(void);
public:
	std::string mTips;
};

