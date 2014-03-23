#include "Command.h"


BaseCommand::BaseCommand()
{
	autorelease();
}

bool TimeCommand::init()
{
	this->retain();
	return true;
}

void TimeCommand::onTimeChange( GameTime curtime )
{
	if(curtime > mCommandtime)
	{
		run();
		TimeMachine::getInstance()->removeTimeChangeListener(this);
		release();
	}
}

void TimeCommand::start()
{
	TimeMachine::getInstance()->addTimeChangeListener(this);
}

bool InstantCommand::init()
{
	return true;
}

void InstantCommand::start()
{
	run();
}


