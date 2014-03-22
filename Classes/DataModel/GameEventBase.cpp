#include "GameEventBase.h"


GameEventBase::GameEventBase(void)
{
}


GameEventBase::~GameEventBase(void)
{
}

GameEventHistory::GameEventHistory(void){
	mType = ENUM_GAME_EVENT_TYPE::HISTORY_EVENT;
}

GameEventHistory::~GameEventHistory(void){
}
