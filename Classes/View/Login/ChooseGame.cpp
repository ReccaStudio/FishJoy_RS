#include "ChooseGame.h"

#include "cocos/ui/UIImageView.h"
#include "cocos/ui/UIText.h"

USING_NS_CC;
using namespace cocos2d::ui;

ChooseGame * ChooseGame::s_pChooseGame = nullptr;

ChooseGame::ChooseGame():Layer()
{
}

ChooseGame::~ChooseGame()
{
}

ChooseGame * ChooseGame::getInstance()
{
	if (s_pChooseGame==nullptr || s_pChooseGame == NULL)
	{
		s_pChooseGame = ChooseGame::create();

	}
	return s_pChooseGame;
}


bool ChooseGame::init()
{

	if (Layer::init())
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		// Create the page view
		PageView * pageView = PageView::create();
		pageView->setContentSize(Size(visibleSize.width/2, visibleSize.height/3*2));

		pageView->setPosition(Vec2(visibleSize.width/2, visibleSize.height*2));
        
		pageView->removeAllPages();
        
		int pageCount = 4;
		for (int i = 0; i < pageCount; ++i)
		{
			Layout* layout = Layout::create();
			layout->setContentSize(Size(240.0f, 130.0f));
            
			ImageView* imageView = ImageView::create("scrollviewbg.png");
			imageView->setScale9Enabled(true);
			imageView->setContentSize(Size(240, 130));
			imageView->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
			layout->addChild(imageView);
            
			Text* label = Text::create(StringUtils::format("page %d",(i+1)), "fonts/Marker Felt.ttf", 30);
			label->setColor(Color3B(192, 192, 192));
			label->setPosition(Vec2(layout->getContentSize().width / 2.0f, layout->getContentSize().height / 2.0f));
			layout->addChild(label);
            
			pageView->insertPage(layout,i);
		}
        
		pageView->removePageAtIndex(0);
		pageView->scrollToPage(pageCount-2);
        
		pageView->addEventListener(CC_CALLBACK_2(ChooseGame::pageViewEvent, this));
        
		this->addChild(pageView);
        
		return true;

	}



		return false;

}

ChooseGame * ChooseGame::create()
{
	ChooseGame * pRet = new ChooseGame();
	if (!pRet ||  !pRet->init())
	{	
		delete pRet;
		pRet = NULL;
	}
	return pRet;
}

void ChooseGame::pageViewEvent(Ref* pSender, PageView::EventType type)
{
#ifdef DEBUG
	CCLOG("----------------------jingz--------------");
#endif
}


