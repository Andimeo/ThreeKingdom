#pragma once
#include "cocos2d.h"
USING_NS_CC;

class MessageDialog : public Layer
{
public :
	static MessageDialog* getInstance();
	static void destroy();
	void show();
	void hide();
protected:
	MessageDialog();
	~MessageDialog();
	CREATE_FUNC(MessageDialog)
private:
	virtual bool init();
};