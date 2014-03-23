#include "MessageDialog.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio;
using namespace cocos2d::ui;

static MessageDialog* s_MessageDialog = NULL;
const std::string MessageDialog::MESSAGE_NAME = "MessageDialog";
bool MessageDialog::init()
{
	if(!Layer::init())
	{
		return false;
	}
	mWidget = GUIReader::getInstance()->widgetFromJsonFile("ui/CommonDilog.json");
	addChild(mWidget);
	return true;
}

MessageDialog::MessageDialog()
{ }

MessageDialog::~MessageDialog()
{ }

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

void MessageDialog::setContent(std::string content){
	Widget* contentWidget = mWidget->getChildByName("dialog")->getChildByName("message");
	Text* message = dynamic_cast<Text*> (contentWidget);
	if (nullptr != message){
		message->setText(content);
	}
}
