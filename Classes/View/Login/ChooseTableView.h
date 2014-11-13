#ifndef __ChooseTableView_SCENE_H__
#define __ChooseTableView_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class ChooseTableView : public cocos2d::Scene,public cocos2d::extension::TableViewDataSource,public cocos2d::extension::TableViewDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static ChooseTableView * getInstance();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
    virtual cocos2d::Size cellSizeForTable(cocos2d::extension::TableView *table);
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    /**
     * Returns number of cells in a given table view.
     *
     * @return number of cells
     */
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);


	/**
     * Delegate to respond touch event
     *
     * @param table table contains the given cell
     * @param cell  cell that is touched
     * @js NA
     * @lua NA
     */
    virtual void tableCellTouched(cocos2d::extension::TableView* table,cocos2d::extension:: TableViewCell* cell);

    /**
     * Delegate to respond a table cell press event.
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     * @js NA
     * @lua NA
     */
    virtual void tableCellHighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell){};

    /**
     * Delegate to respond a table cell release event
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     * @js NA
     * @lua NA
     */
    virtual void tableCellUnhighlight(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell){};

    /**
     * Delegate called when the cell is about to be recycled. Immediately
     * after this call the cell will be removed from the scene graph and
     * recycled.
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     * @js NA
     * @lua NA
     */
    virtual void tableCellWillRecycle(cocos2d::extension::TableView* table,cocos2d::extension:: TableViewCell* cell){};

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view) {};
    /**
     * @js NA
     * @lua NA
     */
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view) {};
    
    // implement the "static create()" method manually
protected:
	CREATE_FUNC(ChooseTableView);

private:
	static ChooseTableView *s_pChooseTableView;
};

#endif // __ChooseTableView_SCENE_H__
