/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"
#include "TreeDrawable.h"

/**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();

    std::shared_ptr<CPicture> Create();

	/// Get the first tree drawable
	/// \return The first tree drawable
	CTreeDrawable* GetTreeDrawable1() 
	{ 
		return (mTreeDrawable1 == nullptr) ? nullptr : mTreeDrawable1.get(); 
	}

	/// Get the second tree drawable
	/// \return The second tree drawable
	CTreeDrawable* GetTreeDrawable2() 
	{ 
		return (mTreeDrawable2 == nullptr) ? nullptr : mTreeDrawable2.get(); 
	}

private:
	/// The first tree drawable
	std::shared_ptr<CTreeDrawable> mTreeDrawable1 = nullptr;
	/// The second tree drawable
	std::shared_ptr<CTreeDrawable> mTreeDrawable2 = nullptr;
};

