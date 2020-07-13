/**
 * \file FruitTree.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include <string>
#include "FruitTree.h"

using namespace std;
using namespace Gdiplus;

/// Image file name for the leaf
const wstring LeafImageName = L"images/leaf3.png";
/// Image file name for the fruit
const wstring FruitImageName = L"images/orange.png";

/// Constructor
CFruitTree::CFruitTree() : mRoot(this, 1)
{
	Reset();

	mLeafImage = shared_ptr<Bitmap>(Bitmap::FromFile(LeafImageName.c_str()));
	if (mLeafImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += LeafImageName;
		AfxMessageBox(msg.c_str());
	}

	mFruitImage = shared_ptr<Bitmap>(Bitmap::FromFile(FruitImageName.c_str()));
	if (mFruitImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += FruitImageName;
		AfxMessageBox(msg.c_str());
	}
}

/// Destructor
CFruitTree::~CFruitTree()
{
}

/**
 * Set the position for the root of the tree
 * \param x X location (pixels)
 * \param y Y location (pixels)
 */
void CFruitTree::SetRootLocation(int x, int y)
{
	mRootLocation.X = (REAL) x;
	mRootLocation.Y = (REAL) y;
	mRoot.SetLocation(mRootLocation);
}

/**
 * Draw the tree at the currently specified location
 * \param graphics GDI+ Graphics object
 */
void CFruitTree::DrawTree(Gdiplus::Graphics* graphics)
{
	mRoot.Draw(graphics, PointF(0, 0), 0);
}

/**
 * Set the current tree frame
 * \param frame Frame number
 */
void CFruitTree::SetTreeFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		BuildTree();
	}
}

/**
 * Set  the wind speed
 * \param speed Wind speed in miles per hour
 */
void CFruitTree::SetWindSpeed(double speed)
{
	mWindSpeed = speed;
	int currentFrame = mCurrentFrame;

	bool harvested = false;
	if (mFruits.size() == 0) harvested = true;

	Reset();
	SetTreeFrame(currentFrame);

	if (harvested)
	{
		for (auto fruit : mFruits)
		{
			fruit->Harvest();
		}
		mFruits.clear();
	}
}

/**
 * Set the tree seed
 * \param seed An integer number. Each number makes a different tree
 */
void CFruitTree::SetSeed(int seed)
{
	mSeed = seed;
	mRandom.Seed(mSeed);
}

/**
 * Get the current tree seed
 * \return Tree seed integer
 */
int CFruitTree::GetSeed()
{
	return mSeed;
}

/**
 * Harvest all of the fruit
 * \return Vector of objects of type CFruit
 */
std::vector<std::shared_ptr<CFruit>> CFruitTree::Harvest()
{
	std::vector<std::shared_ptr<CFruit>> fruits;
	for (auto fruit : mFruits)
	{
		fruit->Harvest();
		fruits.push_back(fruit);
	}
	mFruits.clear();
	return fruits;
}

/// Builds the tree based on the current conditions
void CFruitTree::BuildTree()
{
	mRoot.Grow();
}

/// Resets the tree root and random number generator
void CFruitTree::Reset()
{
	mCurrentFrame = 0;
	mRoot = CBranch(this, 1);
	SetRootLocation((int)mRootLocation.X, (int)mRootLocation.Y);
	mRandom.Reset();
	mFruits.clear();
}
