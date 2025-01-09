/**
 * @file MachineSystem.cpp
 * @author Saarthak Sharma

 */

#include "pch.h"
#include "Machine.h"
#include "MachineStandin.h"
#include "MachineSystem.h"
#include "MachineFactory1.h"
#include "MachineFactory2.h"
#include "Shape.h"
#include "Motor.h"
using namespace std;

/**
 * Constructs the MachineSystem object.
 * @param resourcesDir Path to the directory containing resource files for the machine.
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
}

/**
 * Sets the location where the machine will be drawn.
 * @param location A wxPoint object specifying the new location of the machine.
 */
void MachineSystem::SetLocation(wxPoint location)
{
    mLocation = location;
}

/**
 * Retrieves the current location of the machine.
 * @return Current location of the machine as a wxPoint object.
 */
wxPoint MachineSystem::GetLocation()
{
    return mLocation;
}

/**
 * Draws the machine on the provided graphics context.
 * @param graphics Shared pointer to a wxGraphicsContext for drawing the machine.
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);

    mMachine->Draw(graphics);

    graphics->PopState();
}

/**
 * Sets the current time for the machine based on the frame number.
 * @param frame The frame number used to calculate the current time.
 */
void MachineSystem::SetMachineFrame(int frame)
{
    mTime = frame / mFrameRate;
    mMachine->SetTime(mTime);

    if (frame < mFrame)
    {
        // Reset();
        mFrame = frame;
    }

    while (mFrame < frame) {
        // Advance one frame
        mFrame++;
        mMachine->Update(1.0 / mFrameRate);
    }
}

/**
 * Sets the frame rate used to calculate the machine's time from frame numbers.
 * @param rate The new frame rate for time calculation.
 */
void MachineSystem::SetFrameRate(double rate)
{
    mFrameRate = rate;
}

/**
 * Sets the machine number and loads the corresponding machine configuration.
 * @param machine The machine number (1 or 2) which determines the factory used for creation.
 */
void MachineSystem::SetMachineNumber(int machine)
{
    mMachineNumber = machine;
    if(machine == 1)
    {
        MachineFactory1 factory(mResourcesDir);
        auto machine = factory.Create();
        mMachine = machine;
    }
    else
    {
        MachineFactory2 factory(mResourcesDir);
        auto machine = factory.Create();
        mMachine = machine;
    }
}

/**
 * Gets the current machine number.
 * @return Current machine number indicating which factory configuration is in use.
 */
int MachineSystem::GetMachineNumber()
{
    return mMachineNumber;
}

/**
 * Gets the current time for the machine.
 * @return Current time of the machine.
 */
double MachineSystem::GetMachineTime()
{
    return mTime;
}

/**
 * Sets a flag on the machine.
 * @param flag The flag value to set on the machine.
 */
void MachineSystem::SetFlag(int flag)
{
    mMachine->SetFlag(flag);
}
