#include "MessageDialog.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio;
using namespace cocos2d::ui;

static MessageDialog* s_MessageDialog = NULL;
bool MessageDialog::init()
{
	if(!Layer::init())
	{
		return false;
	}
	addChild(GUIReader::getInstance()->widgetFromJsonFile("ui/CommonDilog.json"));
	return true;
}

MessageDialog::MessageDialog()
{

}

MessageDialog::~MessageDialog()
{

}

MessageDialog* MessageDialog::getInstance()
{
	if(NULL == s_MessageDialog)
	{
		s_MessageDialog = create();
		s_MessageDialog->retain();
	}
	return s_MessageDialog;
}

void MessageDialog::destroy()
{
	if(NULL!=s_MessageDialog)
	{
		s_MessageDialog->release();
	}
}

void MessageDialog::show()
{
	hide();
	Director::getInstance()->getRunningScene()->addChild(this);
}

void MessageDialog::hide()
{
	if (this->getParent()!= NULL)
	{
		this->getParent()->removeChild(this);
	}
}

