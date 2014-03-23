#pragma once
#include "cocos2d.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include <string>

USING_NS_CC;

class MessageDialog : public Layer
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
};