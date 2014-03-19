#include "MainScene.h"

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
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MainScene::menuStartCallback, this));

	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));


	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
	mTimeLabel = LabelTTF::create("Hello World", "Arial", 24);

	// position the label on the center of the screen
	mTimeLabel->setPosition(Point(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - mTimeLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(mTimeLabel, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite,0);
}

void MainScene::menuStartCallback( cocos2d::Ref* pSender )
{
	TimeMechine::getInstance()->resume();
}

void MainScene::onTimeChange( GameTime curtime )
{
	char timestr[32];
	sprintf(timestr,"%dY%dM%dD",curtime.year,curtime.month,curtime.day);
	mTimeLabel->setString(timestr);
}

