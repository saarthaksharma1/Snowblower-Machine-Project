/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"


/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 550));
    picture->AddActor(harold);

    //Machine 1 Factory added
    auto machine1 = std::make_shared<Actor>(L"Machine1");
    auto machineDrawable1 = std::make_shared<MachineDrawable>(L"Machine1", resourcesDir, 1);
    machine1->SetPosition(wxPoint(800, 500));

    mMachine1 = machineDrawable1;
    machine1->AddDrawable(machineDrawable1);
    machine1->SetRoot(machineDrawable1);

    machineDrawable1->SetStart(0);
    picture->AddActor(machine1);
    picture->SetMachine1(machineDrawable1);

    //Machine 2 Factory added
    auto machine2 = std::make_shared<Actor>(L"Machine2");
    auto machineDrawable2 = std::make_shared<MachineDrawable>(L"Machine2", resourcesDir, 2);
    machine2->SetPosition(wxPoint(150, 300));

    mMachine2 = machineDrawable2;
    machine2->AddDrawable(machineDrawable2);
    machine2->SetRoot(machineDrawable2);

    machineDrawable2->SetStart(200);

    picture->AddActor(machine2);
    picture->SetMachine2(machineDrawable2);



    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    return picture;
}

