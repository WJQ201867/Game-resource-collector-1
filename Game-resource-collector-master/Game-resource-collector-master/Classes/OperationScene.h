#ifndef __Operation_SCENE_H__
#define __Operation_SCENE_H__

#include "cocos2d.h"


class Operation : public cocos2d::Scene
{
public:
	
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void BackButtonCallback(cocos2d::Ref* sPender);
	void menuItemDescriptionCallback(cocos2d::Ref* pSender);




	//void menuItem2Callback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Operation);
};


#endif // __Setting_SCENE_H__