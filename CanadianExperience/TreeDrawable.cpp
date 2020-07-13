/**
 * \file TreeDrawable.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "TreeDrawable.h"
#include "Timeline.h"
#include "TreeSeedDlg.h"

/// Used for scaling the drawn tree to an appropriate size
const double Scale = 2.0;


/**
 * Constructor
 * \param name The name of this drawable tree
 * \param tree The actual tree
 * \param basket The basket associated with this tree
 */
CTreeDrawable::CTreeDrawable(const std::wstring& name, std::shared_ptr<CTree> tree, CBasketDrawable* basket) : CDrawable(name)
{
	mTree = tree;
	mBasket = basket;
}

/**
 * Destructor
 */
CTreeDrawable::~CTreeDrawable()
{
}

/** 
 * Draw the drawable
 * \param graphics Graphics object to draw on 
 */
void CTreeDrawable::Draw(Gdiplus::Graphics* graphics)
{
	SetTreeFrame(CDrawable::GetAngleChannel()->GetTimeline()->GetCurrentFrame());
	auto state = graphics->Save();
	graphics->TranslateTransform((float)GetPosition().X, (float)GetPosition().Y);
	graphics->ScaleTransform((float)Scale, (float)Scale);
	mTree->SetRootLocation(0, 0);
	mTree->DrawTree(graphics);
	graphics->Restore(state);
}

/**
 * Harvests the fruits from the tree
 */
void CTreeDrawable::Harvest()
{
	auto fruits = mTree->Harvest();
	mBasket->AddToBasket(fruits);
}

/**
 * Shows the tree seed dialog box
 */
void CTreeDrawable::ShowDialogBox()
{
	CTreeSeedDlg dlg(mTree);
	if (dlg.DoModal() == IDOK) {
		SetTreeFrame(mStartFrame);
		SetTreeFrame(CDrawable::GetAngleChannel()->GetTimeline()->GetCurrentFrame());
	}
}

/**
 * Sets the tree frame for growing conditions
 * \param frame The frame number
 */
void CTreeDrawable::SetTreeFrame(int frame)
{
	int actualFrame = frame - mStartFrame;
	if (mStartFrame < 0 || actualFrame < 0) mTree->SetTreeFrame(0);
	else mTree->SetTreeFrame(actualFrame);

	if (mHarvestFrame >= 0 && frame == mHarvestFrame) Harvest();
	else if (frame < mHarvestFrame) mBasket->EmptyBasket();
}

