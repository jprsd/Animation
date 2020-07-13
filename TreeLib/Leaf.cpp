/**
 * \file Leaf.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "FruitTree.h"
#include "Leaf.h"

/**
 * Constructor
 * \param tree The tree this leaf is a part of
 * \param level The level or depth of this leaf
 */
CLeaf::CLeaf(CFruitTree* tree, int level) : 
	CPartImage(tree, level, tree->GetLeafImage().get())
{
}

/**
 * Destructor
 */
CLeaf::~CLeaf()
{
}
