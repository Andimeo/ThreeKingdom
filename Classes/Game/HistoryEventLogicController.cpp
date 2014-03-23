#include "HistoryEventLogicController.h"
#include "cocos2d.h"
#include "CCDirector.h"
#include "GameLogicController.h"
#include "GameScene/MessageDialog.h"

USING_NS_CC;
static HistoryEventLogicController* s_HistoryEventLogicController = nullptr;

HistoryEventLogicController::HistoryEventLogicController(void)
{
}


HistoryEventLogicController::~HistoryEventLogicController(void)
{
}

void HistoryEventLogicController::onTimeChange(GameTime curtime){

}

void HistoryEventLogicController::onTimeFly(long dayPassed, GameTime curtime){
	long curLongTime = GameTime::toLong(curtime);

	while (mLastEventIterator != mAllHistory.end()){
		if ((*mLastEventIterator)->mTime > curLongTime){
			// Not yet!
			return;
		}else if ((*mLastEventIterator)->mTime < curLongTime - dayPassed){
			mLastEventIterator++;
		}else{
			GameLogicController::getInstance()->addGameEvent(*mLastEventIterator);
			mLastEventIterator++;
		}
	}
}

HistoryEventLogicController* HistoryEventLogicController::getInstance(){
	if (nullptr == s_HistoryEventLogicController){
		s_HistoryEventLogicController = new HistoryEventLogicController();
	}
	return s_HistoryEventLogicController;
}

void HistoryEventLogicController::initHistory(){
	GameTime startTime;
	startTime.year = 190;
	startTime.month = 1;
	startTime.day = 3;
	startTime.hour = 0;
	static GameEventHistory startEvent;
	startEvent.mTime = GameTime::toLong(startTime);
	startEvent.mTips = "Three Kingdom Start!";
	mAllHistory.push_back(&startEvent);

	GameTime JieyiTime;
	JieyiTime.year = 190;
	JieyiTime.month = 1;
	JieyiTime.day = 5;
	static GameEventHistory jieyiEvent;
	jieyiEvent.mTips = "Liu Guan Zhang Are Gays!";
	jieyiEvent.mTime = GameTime::toLong(JieyiTime);
	mAllHistory.push_back(&jieyiEvent);

	GameTime dongzhuodied;
	dongzhuodied.year = 190;
	dongzhuodied.month = 1;
	dongzhuodied.day = 7;
	static GameEventHistory dongzhuodiedEvent;
	dongzhuodiedEvent.mTips = "DongZhuo dead!";
	dongzhuodiedEvent.mTime = GameTime::toLong(dongzhuodied);
	mAllHistory.push_back(&dongzhuodiedEvent);

	mLastEventIterator = mAllHistory.begin();

	TimeMachine::getInstance()->addTimeChangeListener(this);
}

void HistoryEventLogicController::handleHistoryEvent(GameEventBase* event){
	// TODO
	GameEventHistory* historyEvent = dynamic_cast<GameEventHistory*>(event);
	if (historyEvent != nullptr){
		MessageDialog::getInstance()->setContent(historyEvent->mTips);
	}
	MessageDialog::getInstance()->show();
}