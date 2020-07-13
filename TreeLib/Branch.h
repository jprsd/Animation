/**
 * \file Branch.h
 *
 * \author Jaideep Prasad
 *
 * Tree branch class
 */

#pragma once

#include<memory>
#include "TreePart.h"

/**
 * Class for the tree branch
 */
class CBranch : public CTreePart
{
public:
	CBranch(CFruitTree* tree, int level);
	virtual ~CBranch();

	/** \brief Default constructor disabled */
	CBranch() = delete;
	/** \brief Copy constructor disabled */
	CBranch(const CBranch&) = delete;

	void AddChild(std::shared_ptr<CTreePart> child);

	virtual void Grow() override;
	virtual void Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle) override;

private:
	/// The width of the branch
	double mWidth = 1;
	/// The height of the branch
	double mHeight = 5;
	/// The first child of the branch
	std::shared_ptr<CTreePart> mFirstChild = nullptr;
	/// The second child of the branch
	std::shared_ptr<CTreePart> mSecondChild = nullptr;
};

