/**
 * @file Machine.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "Machine.h"
#include "Component.h"

/**
 * Adds a component to the machine
 * @param component The component to add
 */
void Machine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetMachine(this);
}
/**
 * Draws the machine
 * @param graphics The graphics context to draw to
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto component : mComponents)
    {
        component->Draw(graphics);
    }
}
/**
 * Sets the time for the machine
 * @param time The time to set
 */
void Machine::SetTime(double time)
{
    for(auto component : mComponents)
    {
        component->SetTime(time);
    }

}
/**
 * Resets the machine
 */
void Machine::Reset()
{
    for(auto component : mComponents)
    {
        component->Reset();
    }
}
/**
 * Sets the flag for the machine
 * @param flag The flag to set
 */
void Machine::SetFlag(int flag)
{
    mFlag = flag;
}
/**
 * Updates the machine
 * @param time The time to update to
 */
void Machine::Update(double time)
{
    for(auto component : mComponents)
    {
        component->Update(time);
    }
}



