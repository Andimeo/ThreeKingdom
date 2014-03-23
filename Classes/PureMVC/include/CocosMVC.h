#pragma once

#include "PureMVC.hpp"
using namespace PureMVC;
using namespace PureMVC::Interfaces;
using namespace PureMVC::Patterns;

class CocosMediator : public IMediator
{
	static const std::string MultitonKey;
protected:
	virtual void const* getViewComponent(void) const 
	{
		return NULL;
	}

	virtual void setViewComponent(void const* view_component){}

	virtual void onRegister(void){}

	virtual void onRemove(void){}
	
	virtual void sendNotification(std::string const& notification_name, void const* body = NULL, std::string const& type = "")
	{
		Facade::getInstance().sendNotification(notification_name,body,type);
	}

    virtual void initializeNotifier(std::string const& key){}

    virtual std::string const& getMultitonKey(void) const
	{
		return MultitonKey;
	}
};