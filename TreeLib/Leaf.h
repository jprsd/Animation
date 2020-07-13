/**
 * \file Leaf.h
 *
 * \author Jaideep Prasad
 *
 * Class for the tree leaf
 */

#pragma once

#include "PartImage.h"

/**
 * Class for the tree leaf
 */
class CLeaf : public CPartImage
{
public:
	CLeaf(CFruitTree* tree, int level);
	virtual ~CLeaf();

	/** \brief Default constructor disabled */
	CLeaf() = delete;
	/** \brief Copy constructor disabled */
	CLeaf(const CLeaf&) = delete;

private:

};

