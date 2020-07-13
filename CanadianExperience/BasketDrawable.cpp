/**
 * \file BasketDrawable.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "BasketDrawable.h"

/**
 * Constructor
 * \param name The name of the basket drawable
 * \param basket The actual basket
 */
CBasketDrawable::CBasketDrawable(const std::wstring& name, std::shared_ptr<CBasket> basket) : CDrawable(name)
{
	mBasket = basket;
}

/**
 * Destructor
 */
CBasketDrawable::~CBasketDrawable()
{
}

/**
 * Draws the basket
 * \param graphics The graphics context
 */
void CBasketDrawable::Draw(Gdiplus::Graphics* graphics)
{
	auto state = graphics->Save();
	graphics->TranslateTransform((float)GetPosition().X, (float)GetPosition().Y);
	mBasket->SetBasketLocation(0, 0);
	mBasket->DrawBasket(graphics);
	graphics->Restore(state);
}
