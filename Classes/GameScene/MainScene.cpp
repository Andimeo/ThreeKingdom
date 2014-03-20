#include "MainScene.h"
#include "CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocostudio;
using namespace cocos2d::ui;

MainScene::~MainScene()
{
}

MainScene::MainScene()
{
	TimeMechine::getInstance()->addTimeChangeListener(this);
}

bool MainScene::init()
{
	if(!Scene::init())
	{
		return false;
	}
	//���ص����ļ�����ʼ�����ڵ�
	Node *pNode = SceneReader::getInstance()->createNodeWithSceneFile("publish/FightScene.json"); 

	//ͨ��tag��ȡ��Ƶ���
	 ComAudio*  pAudio =(ComAudio* ) pNode->getComponent("CCBackgroundAudio"); 
	//������Ƶ
	pAudio->playBackgroundMusic(pAudio->getFile(), pAudio->isLoop()); 

	//�����ڵ���ӵ��³���
	this->addChild(pNode, 0, 1); 
	TimeMechine::getInstance()->resume();
	return true;
}

void MainScene::menuStartCallback( cocos2d::Ref* pSender )
{
}

void MainScene::onTimeChange( GameTime curtime )
{
	auto pNode = this->getChildByTag(1);

	if(curtime.day % 2 ==0)
	{
		//��ȡcomrender���
		ComRender *pHeroRender = (ComRender*)(pNode->getChildByTag(10005)->getComponent( "hero")); 
		//ת��Ϊarmature
		Armature *pHero= (Armature *)(pHeroRender->getNode()); 
		if(pHero->getAnimation()->getCurrentMovementID() != "attack")
		{
			pHero->getAnimation()->play("attack"); 
		}
	}

	ComRender* pTitle =(ComRender*) pNode->getChildByTag(10046)->getComponent("title");
	Text* year = (Text*)pTitle->getNode()->getChildByTag(12);
	Text* month = (Text*)pTitle->getNode()->getChildByTag(13);
	Text* day = (Text*)pTitle->getNode()->getChildByTag(14);

	char buf[16] ;

	sprintf(buf,"%d",curtime.year);
	year->setText(buf);

	sprintf(buf,"%d",curtime.month);
	month->setText(buf);

	sprintf(buf,"%d",curtime.day);
	day->setText(buf);
}

