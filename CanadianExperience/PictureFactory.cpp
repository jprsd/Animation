/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "TreeDrawable.h"
#include "BasketDrawable.h"
#include "TreeFactory.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);

	// Add two trees and a basket to the background
	CTreeFactory treeFactory; 
	auto basket = treeFactory.CreateBasket();
	auto basketDrawable = make_shared<CBasketDrawable>(L"Basket", basket);
	basketDrawable->SetPosition(Point(600, 500));

	auto tree1 = treeFactory.CreateTree();
	auto treeDrawable1 = make_shared<CTreeDrawable>(L"Tree One", tree1, basketDrawable.get());
	treeDrawable1->SetPosition(Point(700, 500));
	mTreeDrawable1 = treeDrawable1;

	auto tree2 = treeFactory.CreateTree();
	auto treeDrawable2 = make_shared<CTreeDrawable>(L"Tree Two", tree2, basketDrawable.get());
	treeDrawable2->SetPosition(Point(850, 500));
	mTreeDrawable2 = treeDrawable2;

	background->AddDrawable(basketDrawable);
	background->AddDrawable(treeDrawable1);
	background->AddDrawable(treeDrawable2);

    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);

    return picture;
}
