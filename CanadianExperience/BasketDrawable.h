/**
 * \file BasketDrawable.h
 *
 * \author Jaideep Prasad
 *
 * Encapsulation adapter drawable class for Baskets
 */

#pragma once

#include "Drawable.h"
#include "Basket.h"

/**
 * Encapsulation adapter drawable class for Baskets
 */
class CBasketDrawable : public CDrawable
{
public:
	CBasketDrawable(const std::wstring& name, std::shared_ptr<CBasket> basket);
	virtual ~CBasketDrawable();

	/** \brief Default constructor disabled */
	CBasketDrawable() = delete;
	/** \brief Copy constructor disabled */
	CBasketDrawable(const CBasketDrawable&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBasketDrawable&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/** Test to see if we have been clicked on by the mouse
	 * \param pos Position to test
	 * \return False always for this drawable */
	virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	/// Adds harvested fruits to the basket
	/// \param fruit The harvested fruits
	void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit) { mBasket->AddToBasket(fruit); }

	/// Empties the fruits from the basket
	void EmptyBasket() { mBasket->EmptyBasket(); }

private:
	/// The actual basket for this drawable
	std::shared_ptr<CBasket> mBasket;
};

