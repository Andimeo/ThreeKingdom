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
	addChild(GUIReader::getInstance()->widgetFromJsonFile("ui/CommonDilog.json"));
	return true;
}

MessageDialog::MessageDialog()
{
	Facade::getInstance().registerMediator(this);
}

MessageDialog::~MessageDialog()
{
	Facade::getInstance().removeMediator(MESSAGE_NAME);
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

void MessageDialog::handleNotification( INotification const& notification )
{
	DialogData* data = (DialogData*)notification.getBody();
	if(data->mIsShow)
	{
		show();
	}
	else
	{
		hide();
	}
}

IMediator::NotificationNames MessageDialog::listNotificationInterests( void ) const
{
	typedef std::list<NotificationNames::element_type::type> list_t;
	list_t namelist;
	namelist.push_back(MESSAGE_NAME);
	typedef StdContainerAggregate<list_t> result_t;
	return NotificationNames(new result_t(namelist));
}

inline std::string const& MessageDialog::getMediatorName( void ) const
{
	return MESSAGE_NAME;
}

