/**
 * \file TreeFruit.h
 *
 * \author Jaideep Prasad
 *
 * Class for the tree fruit
 */

#pragma once

#include "Fruit.h"
#include "PartImage.h"


/**
 * Class for the tree fruit
 */
class CTreeFruit : public CFruit, public CPartImage
{
public:
	CTreeFruit(CFruitTree* tree, int level);
	virtual ~CTreeFruit();

	/** \brief Default constructor disabled */
	CTreeFruit() = delete;
	/** \brief Copy constructor disabled */
	CTreeFruit(const CTreeFruit&) = delete;

	/// Designates the fruit as being harvested
	void Harvest() { mHarvested = true; }

	virtual void SetBasketPosition(int x, int y) override;
	virtual void DrawInBasket(Gdiplus::Graphics* graphics, int x, int y) override;

	virtual void Grow() override;
	virtual void Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle) override;

private:
	/// Tracks if the fruit has been harvested
	bool mHarvested = false;
	/// The location of the fruit in the basket if after it is harvested
	Gdiplus::Point mBasketLocation = Gdiplus::Point(0, 0);
};

