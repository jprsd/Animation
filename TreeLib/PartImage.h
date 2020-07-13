/**
 * \file PartImage.h
 *
 * \author Jaideep Prasad
 *
 * Class for tree parts that are images
 */

#pragma once

#include <memory>
#include "TreePart.h"

/**
 * Class for tree parts that are images
 */
class CPartImage : public CTreePart
{
public:
	virtual ~CPartImage();
	/** \brief Default constructor disabled */
	CPartImage() = delete;
	/** \brief Copy constructor disabled */
	CPartImage(const CPartImage&) = delete;

	virtual void Grow() override;
	virtual void Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle) override;
	
protected:
	CPartImage(CFruitTree* tree, int level, Gdiplus::Bitmap* image);

private:
	/// The image associated with this part
	Gdiplus::Bitmap* mImage;
	/// The size scale for this part
	double mScale = 0.05;
};

