/**
 * \file TreeFruit.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "FruitTree.h"
#include "TreeFruit.h"

using namespace std;
using namespace Gdiplus;

/// Scale size for fruits in the basket
const float BasketFruitScale = 0.10f;

/**
 * Constructor
 * \param tree The tree this fruit is a part of
 * \param level The level or depth of the fruit in the tree
 */
CTreeFruit::CTreeFruit(CFruitTree* tree, int level) :
	CPartImage(tree, level, tree->GetFruitImage().get())
{
}

/**
 * Destructor
 */
CTreeFruit::~CTreeFruit()
{
}

/**
* Set the position of the fruit in the basket
*
* This position is relative to the basket, so
* it will be added to the basket location passed
* to DrawInBasket when we draw it
* \param x X position in pixels
* \param y Y position in pixels
*/
void CTreeFruit::SetBasketPosition(int x, int y)
{
	mBasketLocation = Point((INT)x, (INT)y);
}

/**
* Draw the fruit in the basket
* \param graphics The graphics object to draw on
* \param x X location of the basket
* \param y Y location of the basket
*/
void CTreeFruit::DrawInBasket(Gdiplus::Graphics* graphics, int x, int y)
{
	float xPos = (float)x + (float)mBasketLocation.X;
	float yPos = (float)y + (float)mBasketLocation.Y;
	auto state = graphics->Save();
	graphics->TranslateTransform(xPos, yPos);
	graphics->ScaleTransform(BasketFruitScale, BasketFruitScale);
	graphics->DrawImage(GetFruitTree()->GetFruitImage().get(),
		-(int)GetFruitTree()->GetFruitImage()->GetWidth() / 2,
		-(int)GetFruitTree()->GetFruitImage()->GetHeight() / 2,
		GetFruitTree()->GetFruitImage()->GetWidth(),
		GetFruitTree()->GetFruitImage()->GetHeight());
	graphics->Restore(state);
}

/// Grows the tree part based on the current conditions
void CTreeFruit::Grow()
{
	if (!mHarvested) CPartImage::Grow();
	else SetAge(GetAge() + 1);
}

/// Draws the tree part
/// \param graphics The graphics context
/// \param parentLocation The point location of the parent part
/// \param parentAngle The angle of the parent
void CTreeFruit::Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle)
{
	if (!mHarvested) CPartImage::Draw(graphics, parentLocation, parentAngle);
}
