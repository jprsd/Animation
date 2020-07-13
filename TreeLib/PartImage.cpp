/**
 * \file PartImage.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "PartImage.h"
#include "FruitTree.h"

/// Rate image size growth
const double GrowthRate = 0.40;
/// Max size scale for the image
const double MaxScale = 0.3;
/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;
/// Multiplier for how the wind speed affects angle
const double WindSpeedMultiplier = 0.001;

/**
 * Destructor
 */
CPartImage::~CPartImage()
{
}

/// Grows the tree part based on the current conditions
void CPartImage::Grow()
{
	double delta = 1.0 / 30;
	double growRate = pow((1.0 + GrowthRate), delta);

	mScale *= growRate;
	
	if (mScale > MaxScale) mScale = MaxScale;

	SetAge(GetAge() + 1);
}

/// Draws the tree part
/// \param graphics The graphics context
/// \param parentLocation The point location of the parent part
/// \param parentAngle The angle of the parent
void CPartImage::Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle)
{
	float x = (float)parentLocation.X + (float)GetLocation().X;
	float y = (float)parentLocation.Y + (float)GetLocation().Y;
	double angle = parentAngle + GetAngle();

	double offset = GetFruitTree()->GetWindSpeed() * WindSpeedMultiplier;
	if (sin(angle) < 0) angle += offset;
	else angle -= offset;

	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(angle * RtoD));
	graphics->ScaleTransform((float)mScale, (float)mScale);
	graphics->DrawImage(mImage, -(int)mImage->GetWidth() / 2,
		-(int)mImage->GetHeight(),
		mImage->GetWidth(), mImage->GetHeight());
	graphics->Restore(state);
}

/**
 * Constructor
 * \param tree The tree this image part is a part of
 * \param level The level or depth of this part in the tree
 * \param image The image associated with this part
 */
CPartImage::CPartImage(CFruitTree* tree, int level, Gdiplus::Bitmap* image) :
	CTreePart(tree, level)
{
	mImage = image;
}
