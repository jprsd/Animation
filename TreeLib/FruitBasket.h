/**
 * \file FruitBasket.h
 *
 * \author Jaideep Prasad
 *
 * Class for the actual fruit basket
 */

#pragma once

#include <memory>
#include "Basket.h"
#include "PseudoRandom.h"

/**
 * Class for the actual fruit basket
 */
class CFruitBasket : public CBasket
{
public:
	CFruitBasket();
	virtual ~CFruitBasket();

	/** \brief Copy constructor disabled */
	CFruitBasket(const CFruitBasket&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CFruitBasket&) = delete;

	virtual void SetBasketLocation(int x, int y) override;

	virtual void DrawBasket(Gdiplus::Graphics* graphics) override;

	virtual void AddToBasket(std::vector < std::shared_ptr<CFruit>> fruit) override;

	virtual void EmptyBasket() override;

private:
	/// The basket location on screen
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	/// The list of fruits in the basket
	std::vector<std::shared_ptr<CFruit>> mFruits;
	/// The image for the back of the basket
	std::shared_ptr<Gdiplus::Bitmap> mBasketImageBack;
	/// The image for the front of the basket
	std::shared_ptr<Gdiplus::Bitmap> mBasketImageFront;
	/// Random number generator for the basket
	CPseudoRandom mRandom;
};

