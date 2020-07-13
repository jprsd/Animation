/**
 * \file FruitTree.h
 *
 * \author Jaideep Prasad
 *
 * Actual fruit tree class to be used in place of the standin tree
 */

#pragma once

#include<memory>
#include "PseudoRandom.h"
#include "Tree.h"
#include "Branch.h"
#include "TreeFruit.h"

/**
 * Actual fruit tree class to be used in place of the standin tree
 */
class CFruitTree : public CTree
{
public:
	CFruitTree();
	virtual ~CFruitTree();

	/** \brief Copy constructor disabled */
	CFruitTree(const CFruitTree&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CFruitTree&) = delete;

	virtual void SetRootLocation(int x, int y) override;

	virtual void DrawTree(Gdiplus::Graphics* graphics) override;

	virtual void SetTreeFrame(int frame) override;

	virtual void SetWindSpeed(double speed) override;

	/// Gets the wind speed
	/// \return The wind speed
	double GetWindSpeed() const { return mWindSpeed; }

	virtual void SetSeed(int seed) override;

	virtual int GetSeed() override;

	virtual std::vector<std::shared_ptr<CFruit>> Harvest() override;

	/// Gets the random generator for this tree
	/// \return The random generator
	CPseudoRandom* GetRandomGenerator() { return &mRandom; }

	/// Gets the leaf image used for this tree
	/// \return The leaf image
	std::shared_ptr<Gdiplus::Bitmap> GetLeafImage() { return mLeafImage; }

	/// Gets the fruit image used for this tree
	/// \return The fruit image
	std::shared_ptr<Gdiplus::Bitmap> GetFruitImage() { return mFruitImage; }

	/// Updates the list of fruits of this tree
	/// \param fruit The newly added fruit
	void AddFruit(std::shared_ptr<CTreeFruit> fruit) { mFruits.push_back(fruit); }


private:
	void BuildTree();
	void Reset();
	/// The current frame for the tree
	int mCurrentFrame = 0;
	/// The location of the tree root
	Gdiplus::PointF mRootLocation = Gdiplus::PointF(0, 0);
	/// The wind speed
	double mWindSpeed = 0;
	/// The random seed for the tree
	int mSeed = 1235;
	/// The root limb of the tree
	CBranch mRoot;
	/// The fruits of this tree
	std::vector<std::shared_ptr<CTreeFruit>> mFruits;
	/// Random number generator
	CPseudoRandom mRandom;
	/// The leaf image this tree will use
	std::shared_ptr<Gdiplus::Bitmap> mLeafImage;
	/// The fruit image this tree will use
	std::shared_ptr<Gdiplus::Bitmap> mFruitImage;
};

