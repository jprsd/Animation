/**
 * \file TreeDrawable.h
 *
 * \author Jaideep Prasad
 *
 * Encapsulation adapter drawable class for Trees
 */

#pragma once

#include "Drawable.h"
#include "Tree.h"
#include "BasketDrawable.h"

/**
 * Encapsulation adapter drawable class for Trees
 */
class CTreeDrawable : public CDrawable
{
public:
	CTreeDrawable(const std::wstring& name, std::shared_ptr<CTree> tree, CBasketDrawable* basket);
	virtual ~CTreeDrawable();

	/** \brief Default constructor disabled */
	CTreeDrawable() = delete;
	/** \brief Copy constructor disabled */
	CTreeDrawable(const CTreeDrawable&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeDrawable&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/** Test to see if we have been clicked on by the mouse
	 * \param pos Position to test
	 * \return False always for this drawable */
	virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	/// Set the seed of the tree
	/// \param seed The new seed of the tree
	void SetSeed(int seed) { mTree->SetSeed(seed); }

	/// Get the seed of the tree
	/// \return The seed of the tree
	int GetSeed() const { return mTree->GetSeed(); }

	/// Set the start frame
	/// \param frame The frame number
	void SetStartFrame(int frame) { mStartFrame = frame; }

	/// Gets the start frame
	/// \return The start frame
	int GetStartFrame() const { return mStartFrame; }

	/// Set the harvest frame
	/// \param frame The frame number
	void SetHarvestFrame(int frame) { mHarvestFrame = frame; }

	/// Gets the harvest frame
	/// \return The harvest frame
	int GetHarvestFrame() const { return mHarvestFrame; }

	void Harvest();
	void ShowDialogBox();

private:
	void SetTreeFrame(int frame);
	/// The tree
	std::shared_ptr<CTree> mTree;
	/// The basket for the tree
	CBasketDrawable* mBasket;
	/// The frame at which the tree is planted
	int mStartFrame = -1;
	/// The frame at which the tree is harvested
	int mHarvestFrame = -1;
};

