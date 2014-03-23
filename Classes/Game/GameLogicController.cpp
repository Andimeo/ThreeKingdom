#include "GameLogicController.h"
#include "HistoryEventLogicController.h"
#include "cocos2d.h"
#include <condition_variable>
#include "CCDirector.h"

USING_NS_CC;

static GameLogicController* s_GameLogicController = nullptr;
static std::mutex s_EventMutex;
static std::mutex s_SleepThreadMutex;
static std::condition_variable s_sleepConditionVariable;
GameLogicController::GameLogicController(void)
{
	init();
}


GameLogicController::~GameLogicController(void)
{
	s_sleepConditionVariable.notify_all();
}

GameLogicController* GameLogicController::getInstance(){
	
	if (nullptr == s_GameLogicController){
		s_GameLogicController = new GameLogicController();
	}

	return s_GameLogicController;
}

void GameLogicController::addGameEvent(GameEventBase* event){
	s_SleepThreadMutex.lock();
	
	std::list<GameEventBase*>::iterator eventIterator = mGameEvents.begin();
	for (; eventIterator != mGameEvents.end(); eventIterator++){
		if ((*eventIterator)->mTime > event->mTime){
			break;
		}
	}
	mGameEvents.insert(eventIterator, event);
	
	s_SleepThreadMutex.unlock();

	s_sleepConditionVariable.notify_one();
}

void GameLogicController::init(){
	 auto t = std::thread(CC_CALLBACK_0(GameLogicController::eventHandleThreadRunable, this));
     t.detach();
}

void GameLogicController::eventHandleThreadRunable(){
	while (true){
		GameEventBase* curEvent = nullptr;
		
		s_EventMutex.lock();
		while (!mGameEvents.empty()){
			curEvent = *(mGameEvents.begin());
			mGameEvents.pop_front();

			if (nullptr != curEvent){
				//TODO: Handle this event
				if (ENUM_GAME_EVENT_TYPE::HISTORY_EVENT == curEvent->mType){
					auto scheduler = Director::getInstance()->getScheduler();
					scheduler->performFunctionInCocosThread(
						CC_CALLBACK_0(HistoryEventLogicController::handleHistoryEvent, 
						HistoryEventLogicController::getInstance(), curEvent));
				}
			}
		}
		s_EventMutex.unlock();
		
		// Wait Until Next Event Come
		std::unique_lock<std::mutex> lk(s_SleepThreadMutex);
		s_sleepConditionVariable.wait(lk);
	}
}