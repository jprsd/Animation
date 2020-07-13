/**
 * \file FruitBasket.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include <string>
#include "FruitBasket.h"
#include "TreeFruit.h"

using namespace std;
using namespace Gdiplus;

/// The image of the entire basket
const wstring BasketBackImage = L"images/basket.png";

/// The image for the front only of the basket
const wstring BasketFrontImage = L"images/basket-front.png";

/**
 * Constructor
 */
CFruitBasket::CFruitBasket()
{
	mBasketImageBack = shared_ptr<Bitmap>(Bitmap::FromFile(BasketBackImage.c_str()));
	if (mBasketImageBack->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += BasketBackImage;
		AfxMessageBox(msg.c_str());
	}

	mBasketImageFront = shared_ptr<Bitmap>(Bitmap::FromFile(BasketFrontImage.c_str()));
	if (mBasketImageFront->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += BasketFrontImage;
		AfxMessageBox(msg.c_str());
	}

	mRandom.Seed((int)time(nullptr));
}

/**
 * Destructor
 */
CFruitBasket::~CFruitBasket()
{
}

/**
 * Set the position for the basket.
 * \param x X location (pixels)
 * \param y Y location (pixels)
 */
void CFruitBasket::SetBasketLocation(int x, int y)
{
	mLocation = Point((INT)x, (INT)y);
}

/**
 * Draw the basket at the currently specified location
 * \param graphics GDI+ Graphics object
 */
void CFruitBasket::DrawBasket(Gdiplus::Graphics* graphics)
{
	float width = (float)mBasketImageBack->GetWidth();
	float height = (float)mBasketImageBack->GetHeight();

	auto state = graphics->Save();
	graphics->TranslateTransform((float)mLocation.X, (float)mLocation.Y);
	graphics->DrawImage(mBasketImageBack.get(), -width / 2, -height, width, height);
	graphics->Restore(state);

	for (auto fruit : mFruits)
	{
		fruit->DrawInBasket(graphics, (int)mLocation.X, (int)mLocation.Y);
	}

	width = (float)mBasketImageFront->GetWidth();
	height = (float)mBasketImageFront->GetHeight();

	state = graphics->Save();
	graphics->TranslateTransform((float)mLocation.X, (float)mLocation.Y);
	graphics->DrawImage(mBasketImageFront.get(), -width / 2, -height, width, height);
	graphics->Restore(state);
}

/**
 * Add fruit to the basket
 * \param fruit Vector of fruit objects
 */
void CFruitBasket::AddToBasket(std::vector<std::shared_ptr<CFruit>> fruit)
{
	int width = (int)mBasketImageBack->GetWidth();
	int height = (int)mBasketImageBack->GetHeight();

	for (auto harvestedFruit : fruit)
	{
		int x = (int)mRandom.Random(-width / 3.0, width / 3.0);
		int y = (int)mRandom.Random(-height / 1.5, -height / 4.0);
		harvestedFruit->SetBasketPosition(x, y);
		mFruits.push_back(harvestedFruit);
	}
}

/**
 * Empty all fruit from the basket
 */
void CFruitBasket::EmptyBasket()
{
	mFruits.clear();
}
