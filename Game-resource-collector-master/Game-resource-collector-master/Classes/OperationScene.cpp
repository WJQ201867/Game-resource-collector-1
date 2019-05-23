#include "OperationScene.h"
#include "HelpScene.h"
#include"DescriptionScene.h"

USING_NS_CC;

Scene* Operation::createScene()
{
	return Operation::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelpScene.cpp\n");
}
bool Operation::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto sprite = Sprite::create("descriptionscene1.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'descriptionscene1.jpg'");
	}
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite);
	
	auto mAnimation = Animation::create();//操作界面动画
	for (int i = 1;i < 4;i++)
	{
		char nameSize[100] = { 0 };
		sprintf(nameSize, "descriptionscene%d.jpg", i);
		mAnimation->addSpriteFrameWithFile(nameSize);
	}
	  mAnimation->setDelayPerUnit(2.00f);//播放速度
	  mAnimation->setRestoreOriginalFrame(false);//不重复循环
	  auto mAnimate = Animate::create(mAnimation);
	  sprite->runAction(mAnimate);

	auto back_button = MenuItemImage::create("back_button2.jpg",
		"back_button3.png",
		CC_CALLBACK_1(Operation::BackButtonCallback, this));
	back_button->setPosition(Vec2(50, 80));


	
	auto forward_button = MenuItemImage::create("forward_button1.jpg",
		"back_button3.png",
		CC_CALLBACK_1(Operation::menuItemDescriptionCallback, this));
	forward_button->setPosition(Vec2(430, 80));

	Menu * help_menu = Menu::create(back_button,forward_button, NULL);

	help_menu->setPosition(Vec2::ZERO);

	this->addChild(help_menu);
	return true;
}
void Operation::BackButtonCallback(Ref * pSender)
{
	Director::getInstance()->popScene();
}



void Operation::menuItemDescriptionCallback(Ref* pSender)
{
	auto description_scene = Description::createScene();
	auto dong_description_scene = TransitionSlideInL::create(0.5f, description_scene);
	Director::getInstance()->pushScene(dong_description_scene);
}