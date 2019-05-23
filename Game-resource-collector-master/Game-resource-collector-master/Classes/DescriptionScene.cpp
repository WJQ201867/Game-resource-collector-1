#include "DescriptionScene.h"
#include "OperationScene.h"


USING_NS_CC;

Scene* Description::createScene()
{
	return Description::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in OperationScene.cpp\n");
}

bool Description::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto background = Sprite::create("helpscene2.jpg");
	if (background == nullptr)
	{
		problemLoading("'helpscene2.jpg'");
	}
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background);
	//返回主菜单按钮
	auto back_button = MenuItemImage::create("return_to_main_menu1.jpg",
		"return_to_main_menu2.jpg",
		CC_CALLBACK_1(Description::BackButtonCallback, this));
	back_button->setPosition(Vec2(240, 80));

	Menu * help_menu = Menu::create(back_button, NULL);

	help_menu->setPosition(Vec2::ZERO);

	this->addChild(help_menu);
	return true;
}
//返回主菜单
void Description::BackButtonCallback(Ref * pSender)
{
	Director::getInstance()->popToRootScene();
}