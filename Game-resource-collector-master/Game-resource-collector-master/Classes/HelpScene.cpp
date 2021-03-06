#include "HelloWorldScene.h"
#include "HelpScene.h"
#include "OperationScene.h"

USING_NS_CC;

Scene* Help::createScene()
{
	return Help::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Help::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//////////添加自己的代码
	auto background = Sprite::create("helpscene1.jpg");
	if (background == nullptr)
	{
		problemLoading("'helpscene1.jpg'");
	}
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background);
	//返回按钮
	auto back_button = MenuItemImage::create("back_button2.jpg",
		"back_button3.png",
		CC_CALLBACK_1(Help::BackButtonCallback, this));
	back_button->setPosition(Vec2(50, 80));
	//前进按钮
	auto forward_button = MenuItemImage::create("forward_button1.jpg",
		"back_button3.png",
		CC_CALLBACK_1(Help::menuItemOperationCallback, this));
	forward_button->setPosition(Vec2(430,80));

	Menu * help_menu = Menu::create(back_button,forward_button, NULL);

	help_menu->setPosition(Vec2::ZERO);

	this->addChild(help_menu);


	return true;
}
void Help::BackButtonCallback(Ref * pSender)
{
	Director::getInstance()->popScene();
}

void Help::menuItemOperationCallback(Ref* pSender)
{
	auto operation_scene = Operation::createScene();
	auto dong_operation_scene = TransitionSlideInL::create(0.5f, operation_scene);
	Director::getInstance()->pushScene(dong_operation_scene);
}
