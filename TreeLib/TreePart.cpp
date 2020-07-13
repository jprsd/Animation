/**
 * \file TreePart.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "TreePart.h"
#include "FruitTree.h"

/**
 * Destructor
 */
CTreePart::~CTreePart()
{
}

/**
 * Constructor
 * \param tree The tree this part is a part of
 * \param level The level or depth of this part in the tree
 */
CTreePart::CTreePart(CFruitTree* tree, int level)
{
	mFruitTree = tree;
	mLevel = level;
}
