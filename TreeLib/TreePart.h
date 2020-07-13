/**
 * \file TreePart.h
 *
 * \author Jaideep Prasad
 *
 * Class that represents a part of a fruit tree
 */

#pragma once

class CFruitTree;
class CBranch;

/**
 * Class that represents a part of a fruit tree
 */
class CTreePart
{
public:
	virtual ~CTreePart();

	/** \brief Default constructor disabled */
	CTreePart() = delete;
	/** \brief Copy constructor disabled */
	CTreePart(const CTreePart&) = delete;

	/**
	 * Set tree part level
	 * \param level The level
	 */
	void SetLevel(int level) { mLevel = level; }

	/**
	 * Get tree part level
	 * \return The level
	 */
	int GetLevel() const { return mLevel; }

	/**
	 * Set tree part angle
	 * \param angle The angle
	 */
	void SetAngle(double angle) { mAngle = angle; }

	/**
	 * Get tree part angle
	 * \return The angle
	 */
	double GetAngle() const { return mAngle; }

	/**
	 * Set tree part location
	 * \param location The location
	 */
	void SetLocation(Gdiplus::PointF location) { mLocation = location; }

	/**
	 * Get tree part location
	 * \return The location
	 */
	Gdiplus::PointF GetLocation() const { return mLocation; }

	/**
	 * Set tree part age
	 * \param age The age
	 */
	void SetAge(int age) { mAge = age; }

	/**
	 * Get tree part age
	 * \return The age
	 */
	int GetAge() const { return mAge; }

	/**
	 * Get tree that this part is a part of
	 * \return The tree
	 */
	CFruitTree* GetFruitTree() { return mFruitTree; }

	/// Grows the tree part based on the current conditions
	virtual void Grow() = 0;

	/**
	 * Set the parent of this branch
	 * \param parent The parent
	 */
	void SetParent(CBranch* parent) { mParent = parent; }

	/**
	 * Get the parent of this branch
	 * \return The parent
	 */
	CBranch* GetParent() { return mParent; }

	/// Draws the tree part
	/// \param graphics The graphics context
	/// \param parentLocation The point location of the parent part
	/// \param parentAngle The angle of the parent
	virtual void Draw(Gdiplus::Graphics* graphics, Gdiplus::PointF parentLocation, double parentAngle) = 0;

protected:
	CTreePart(CFruitTree* tree, int level);

private:
	/// The level or depth of the tree part in the tree
	int mLevel = 1;
	/// The angle of the tree part
	double mAngle = -3.14159 / 2;
	/// The location of the tree part
	Gdiplus::PointF mLocation = Gdiplus::PointF(0, 0);
	/// The age of the tree part in frames
	int mAge = 0;
	/// The tree this part is a part of
	CFruitTree* mFruitTree;
	/// The parent branch of this part
	CBranch* mParent = nullptr;
};

