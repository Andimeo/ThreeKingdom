#include "MainScene.h"
#include "MessageDialog.h"


MainScene::~MainScene()
{
	TimeMachine::getInstance()->removeTimeChangeListener(this);
}

MainScene::MainScene()
{
	TimeMachine::getInstance()->addTimeChangeListener(this);
}

bool MainScene::init()
{
	if(!Scene::init())
	{
		return false;
	}
	//���ص����ļ�����ʼ�����ڵ�
	Node *pNode = SceneReader::getInstance()->createNodeWithSceneFile("publish/MainScene.json"); 

	//ͨ��tag��ȡ��Ƶ���
	 ComAudio*  pAudio =(ComAudio* ) pNode->getComponent("CCBackgroundAudio"); 
	//������Ƶ
	pAudio->playBackgroundMusic(pAudio->getFile(), pAudio->isLoop()); 

	ComRender* comrender = (ComRender*)pNode->getChildByTag(10028)->getComponent("Menu");
	Button* pBtn = (Button*)comrender->getNode()->getChildByTag(53);
	pBtn->addTouchEventListener(this,toucheventselector(MainScene::menuStartCallback));

	ComRender* maprender = (ComRender*)pNode->getChildByTag(10026)->getComponent("Map");

	//�����ڵ���ӵ��³���
	this->addChild(pNode, 0, 1); 
	return true;
}

void MainScene::menuStartCallback( cocos2d::Ref* object ,TouchEventType type )
{
	if(TouchEventType::TOUCH_EVENT_ENDED == type)
	{
		Button* btn = (Button*)object;
		btn->setVisible(false);
		TimeMachine::getInstance()->resume();
	}
}

void MainScene::onTimeChange( GameTime curtime )
{
	auto pNode = this->getChildByTag(1);

	if(curtime.day % 10 ==0)
	{
		TimeMachine::getInstance()->pause();
		ComRender* comrender = (ComRender*)pNode->getChildByTag(10028)->getComponent("Menu");
		Button* pBtn = (Button*)comrender->getNode()->getChildByTag(53);
		pBtn->setVisible(true);
		pBtn->addTouchEventListener(this,toucheventselector(MainScene::menuStartCallback));
	}
	if(curtime.day % 2 ==0)
	{
		MessageDialog::getInstance()->hide();
	}
	else
	{
		MessageDialog::getInstance()->show();
	}
	ComRender* pTitle =(ComRender*) pNode->getChildByTag(10028)->getComponent("Menu");
	Text* year = (Text*)pTitle->getNode()->getChildByTag(46);
	Text* month = (Text*)pTitle->getNode()->getChildByTag(48);
	Text* day = (Text*)pTitle->getNode()->getChildByTag(50);

	char buf[16] ;

	sprintf(buf,"%d",curtime.year);
	year->setText(buf);

	sprintf(buf,"%d",curtime.month);
	month->setText(buf);

	sprintf(buf,"%d",curtime.day);
	day->setText(buf);
}

