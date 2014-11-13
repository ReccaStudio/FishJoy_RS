#include "ChooseTableView.h"
#include "Gameconfig.h"
#include "SceneFactory.h"
USING_NS_CC;
#include "GUI\CCEditBox\CCEditBox.h"
USING_NS_CC_EXT;

ChooseTableView * ChooseTableView::s_pChooseTableView = nullptr;


ChooseTableView * ChooseTableView::getInstance()
{
	if (s_pChooseTableView==nullptr||s_pChooseTableView==NULL)
	{

		s_pChooseTableView = ChooseTableView::create();
		s_pChooseTableView->retain();
	}

	return s_pChooseTableView;
	
}


// on "init" you need to initialize your instance
bool ChooseTableView::init()
{
    //////////////////////////////
    // 1. super init first
	if ( !Scene::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(ChooseTableView::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::create("Choose games", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    

	//MessageBox("消息内容","我是惊蛰");


	Scale9Sprite * q  = Scale9Sprite::create("green_edit.png");
	EditBox * p = EditBox::create(Size(400,50), q);
	this->addChild(p);
	p->setPosition(Vec2(visibleSize.width/3,visibleSize.height*2/3));

	TableView * table = TableView::create(this,Size(300,300));
	this->addChild(table);
	table->setDirection(ScrollView::Direction::VERTICAL);
	table->setPosition(Vec2(visibleSize.width*2/3,visibleSize.height/3));
	table->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	table->setDelegate(this);

    return true;
}


void ChooseTableView::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


/**
    * cell height for a given table.
    *
    * @param table table to hold the instances of Class
    * @return cell size
    */
Size ChooseTableView::cellSizeForTable(TableView *table) 
{
	return Size(300,50);
};
/**
    * a cell instance at a given index
    *
    * @param idx index to search for a cell
    * @return cell found at idx
    */
TableViewCell* ChooseTableView::tableCellAtIndex(TableView *table, ssize_t idx)
{
	TableViewCell* p= table->dequeueCell();
	if (p==nullptr||p==NULL)
	{

		p = TableViewCell::create();
		auto temp = Scale9Sprite::create("green_edit.png");
		temp->setAnchorPoint(Vec2(0,0));
		temp->setContentSize(Size(table->getContentSize().width,table->getContentSize().height/this->numberOfCellsInTableView(table)-2));
		p->addChild(temp);

		auto label = Label::create("", "Arial", 24);
		label->setPosition(cellSizeForTable(table).width/2,cellSizeForTable(table).height/2);
		p->addChild(label,0,100);
	}

	
	if (idx>=0&&idx<6)
	{
		auto TextCell = static_cast<Label*>(p->getChildByTag(100));
		TextCell->setString(GameConfig::SceneNames[idx]);
	}
	
	
	return p;
}

    /* Returns number of cells in a given table view.
    *
    * @return number of cells
    */
ssize_t ChooseTableView::numberOfCellsInTableView(TableView *table)
{
	return 6;
}

void ChooseTableView::tableCellTouched(cocos2d::extension::TableView* table,cocos2d::extension:: TableViewCell* cell)
{
	Director * pDirector = Director::getInstance();
	pDirector->replaceScene(SceneFactory::create(GameConfig::SceneIndex(cell->getIdx())));
}