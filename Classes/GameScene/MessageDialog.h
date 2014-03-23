#pragma once
#include "cocos2d.h"
#include "CocosMVC.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include <string>

USING_NS_CC;

class DialogData : public Ref
{
private:
	DialogData(){}
public:
	std::string mMessage;
	bool mIsShow;
	bool init(){return true;}
	CREATE_FUNC(DialogData)
};

class MessageDialog : public Layer , public CocosMediator
{
public :
	static const std::string MESSAGE_NAME;

	static MessageDialog* getInstance();
	static void destroy();

	void show();
	void hide();
	void setContent(std::string content);
private:
	ui::Widget* mWidget;
protected:
	MessageDialog();
	~MessageDialog();
	CREATE_FUNC(MessageDialog)
private:
	virtual bool init();

	virtual std::string const& getMediatorName(void) const;

	virtual IMediator::NotificationNames listNotificationInterests(void) const;

    virtual void handleNotification(INotification const& notification);

};