/**
 * \file Branch.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "Branch.h"
#include "FruitTree.h"
#include "Leaf.h"
#include "TreeFruit.h"

using namespace std;
using namespace Gdiplus;

/// Rate for branch growth
const double GrowthRate = 0.30;
/// Height limit before the branch can spawn children
const double SpawnHeight = 5.75;
/// Multiplier for how the wind speed affects angle
const double WindSpeedMultiplier = 0.0005;

/**
 * Constructor
 * \param tree The tree this branch is a part of
 * \param level The level or depth of the branch in the tree
 */
CBranch::CBranch(CFruitTree* tree, int level) : CTreePart(tree, level)
{
}

/**
 * Destructor
 */
CBranch::~CBranch()
{
}

/**
 * Adds a child tree part to the branch
 * \param child The child tree part
 */
void CBranch::AddChild(std::shared_ptr<CTreePart> child)
{
	if (mFirstChild == nullptr) 
	{
		mFirstChild = child;
	}
	else if (mSecondChild == nullptr)
	{
		mSecondChild = child;
	}
	else
	{
		throw "Exceeding two children.";
	}
}

/**
 * Grows the branch based on the current conditions
 */
void CBranch::Grow()
{
	double delta = 1.0 / 30;
	double growRate = pow((1.0 + GrowthRate), delta);

	mHeight *= growRate;
	mWidth *= growRate;

	SetAge(GetAge() + 1);

	if (mHeight >= SpawnHeight && mFirstChild == nullptr && mSecondChild == nullptr)
	{
		if (GetLevel() > 6 && GetFruitTree()->GetRandomGenerator()->Random(0.0, 1.0) < 0.7)
		{
			auto leaf = make_shared<CLeaf>(GetFruitTree(), GetLevel() + 1);
			leaf->SetAngle(GetFruitTree()->GetRandomGenerator()->Random(-3.1415, 3.1415));
			leaf->SetParent(this);
			AddChild(leaf);
		}
		else if (GetLevel() < 10)
		{
			auto limb = make_shared<CBranch>(GetFruitTree(), GetLevel() + 1);
			limb->SetAngle(GetFruitTree()->GetRandomGenerator()->Random(-0.5, 0.5));
			limb->SetParent(this);
			AddChild(limb);
		}

		if (GetLevel() > 8 && GetFruitTree()->GetRandomGenerator()->Random(0.0, 1.0) < 0.1)
		{
			auto fruit = make_shared<CTreeFruit>(GetFruitTree(), GetLevel() + 1);
			fruit->SetAngle(GetFruitTree()->GetRandomGenerator()->Random(-3 * 3.14159 / 4, -3.14159 / 4) - GetAngle());
			fruit->SetParent(this);
			AddChild(fruit);
			GetFruitTree()->AddFruit(fruit);
		}
		else if (GetLevel() < 10)
		{
			auto limb = make_shared<CBranch>(GetFruitTree(), GetLevel() + 1);
			limb->SetAngle(GetFruitTree()->GetRandomGenerator()->Random(-0.4, 0.4));
			limb->SetParent(this);
			AddChild(limb);
		}
	}

	if (mFirstChild != nullptr) mFirstChild->Grow();
	if (mSecondChild != nullptr) mSecondChild->Grow();
}

/**
 * Draws the branch
 * \param graphics The graphics contect
 * \param parentLocation The location of the parent tree part
 * \param parentAngle The angle of the parent tree part
 */
void CBranch::Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle)
{
	double angle = parentAngle + GetAngle();

	double offset = GetFruitTree()->GetWindSpeed() * WindSpeedMultiplier;
	if(sin(angle) < 0) angle += offset;
	else angle -= offset;

	double dx = cos(angle) * mHeight;
	double dy = sin(angle) * mHeight;

	double x = (double)parentLocation.X + (double)GetLocation().X;
	double y = (double)parentLocation.Y + (double)GetLocation().Y;

	Pen pen(Color(139, 69, 19), (REAL)mWidth);
	pen.SetEndCap(LineCapRound);
	graphics->DrawLine(&pen, (REAL)x, (REAL)y,
		(REAL)(x + dx), (REAL)(y + dy));

	PointF location((REAL)(x + dx), (REAL)(y + dy));

	if (mFirstChild != nullptr) mFirstChild->Draw(graphics, location, angle);
	if (mSecondChild != nullptr) mSecondChild->Draw(graphics, location, angle);
}
