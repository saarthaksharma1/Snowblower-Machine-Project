/**
 * @file MachineFactory2.cpp
 * @author Saarthak Sharma
 */


#include "pch.h"
#include "MachineFactory2.h"
#include "MachineFactory1.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "SnowBlower.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";


/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
MachineFactory2::MachineFactory2(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}

std::shared_ptr<Machine> MachineFactory2::Create()
{
    // The machine itself
    auto machine = std::make_shared<Machine>(1);

//    const int BackgroundWidth = 500;
//    const int BackgroundHeight = 350;

    const int BaseWidth = 325;  // Width of the base
    const int BaseHeight = 40;  // Height of the base

    const int MotorX = 20;	// Motor X location
    const int Post1X = -70;	// Post X location
    const int Post2X = 80;	// Second post X location

    int Post1Height = 120;
    int Post2Height = 200;

    //
    // The base
    //
    auto base = std::make_shared<Shape>();

    base->Rectangle(int(-BaseWidth/2), 0, BaseWidth, BaseHeight);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);

    //
    // The motor
    //
    auto motor =  std::make_shared<Motor>(mImagesDir);
    motor->SetPosition(MotorX-38, -38);
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    //
    // The snow blower
    //
    auto blower =  std::make_shared<SnowBlower>(mImagesDir + L"/blowerR.png");
    machine->AddComponent(blower);
    blower->SetPosition(Post2X, -150);
    blower->SetRotation(0.15);
    machine->AddComponent(blower);

    //
    // Post to hold the first pulley
    // Must be added before the motor pulley so it draws behind the belt
    //
    auto post1 = CreatePost(Post2X, -40, 20, Post1Height, wxColor(10, 10, 10));
    machine->AddComponent(post1);

    //
    // Post to hold the second pully
    //
    auto post2 = CreatePost(Post1X, -40, 20, Post2Height, wxColor(10, 10, 10));
    machine->AddComponent(post2);

    //
    // The pulley driven by the motor
    // Radius=15pixels
    //
    auto pulley1 = std::make_shared<Pulley>(15);
    pulley1->SetImage(mImagesDir + L"/pulley2.png");
    pulley1->SetPosition(MotorX, -78);
    pulley1->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley1);

    // This is how I make a connection from a source to a sink.
    // This is the case where they are driven at the same speed.
    motor->GetSource()->AddSink(pulley1->GetSink());

    //
    // The pulley on the snow blower. Driven by the motor pulley.
    // Radius=40pixels
    //
    auto pulley2 = std::make_shared<Pulley>(40);
    pulley2->SetImage(mImagesDir + L"/pulley.png");
    pulley2->SetPosition(Post2X, post1->GetY() - Post1Height + 10);
    pulley2->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley2);
    motor->GetSource()->AddSink(pulley2->GetSink());

    pulley2->GetSource()->AddSink(blower->GetSink());

    // This is how I make a connection from a pully
    // to another pully using a belt.
    pulley1->Drive(pulley2);

    //
    // Pulley directly driven by that pulley
    // Radius=15px
    //
    auto pulley3 = std::make_shared<Pulley>(15);
    pulley3->SetImage(mImagesDir + L"/pulley2.png");
    pulley3->SetPosition(pulley2->GetPosition().x, pulley2->GetPosition().y);
    machine->AddComponent(pulley3);

    pulley2->GetSource()->AddSink(pulley3->GetSink());



    //
    // Pully on the second post
    //
    auto pulley4 = std::make_shared<Pulley>(40);
    pulley4->SetImage(mImagesDir + L"/pulley.png");
    pulley4->SetPosition(Post1X, post2->GetY() - Post2Height + 10);
    pulley4->SetPhase(0.1);	// Rotate it a little bit
    machine->AddComponent(pulley4);

    pulley3->Drive(pulley4);
    //motor->GetSource()->AddSink(pulley3->GetSink());


    //
    // The flag
    //
    auto flag = std::make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(pulley4->GetPosition().x, pulley4->GetPosition().y);
    machine->AddComponent(flag);

    //motor->GetSource()->AddSink(flag->GetSink());
    //motor->GetSource()->AddSink(pulley4->GetSink());

    pulley4->GetSource()->AddSink(flag->GetSink());

    return machine;

}
/**
* Create a shape to use as a post to hold pulleys.
*
* I create several posts. This function just makes it easier to do.
*
* \param x X position of bottom center of post in pixels
* \param y Y position of bottom of post in pixels
* \param wid Post width in pixels
* \param hit Post height in pixels
* \param color Color to apply to the post
* \return Shape object
*/
std::shared_ptr<Shape> MachineFactory2::CreatePost(int x, int y, int wid, int hit, wxColor color)
{
    auto post = std::make_shared<Shape>();
    post->Rectangle(-wid/2, 0, wid, hit);
    post->SetColor(color);
    post->SetPosition(x, y);

    return post;
}