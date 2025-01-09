/**
 * @file MachineCFactory.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "MachineCFactory.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
//#include "Motor.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
MachineCFactory::MachineCFactory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}



/**
 * Factory method to create machine #1
 * @return
 */
std::shared_ptr<Machine> MachineCFactory::Create()
{
    // The machine itself
    auto machine = std::make_shared<Machine>(1);

    //
    // The base
    //
    const int BaseWidth = 325;  // Width of the base
    const int BaseHeight = 40;  // Height of the base

    auto base = std::make_shared<Shape>();

    base->Rectangle(int(-BaseWidth/2), 0, BaseWidth, BaseHeight);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);


    // The motor
    //
    const int MotorX = 20;	// Motor X location

    auto motor =  std::make_shared<Motor>(mImagesDir);
    motor->SetPosition(MotorX, -38);
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);



    return machine;
}
