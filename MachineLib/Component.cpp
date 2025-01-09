/**
 * @file Component.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "Component.h"

/**
 * Draws the component on the provided graphics context.
 * @param graphics
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DrawPolygon(graphics, mPosition.x, mPosition.y);
}

/**
 * Sets the machine associated with this component.
 * @param machine Pointer to the Machine object this component will be part of.
 */
void Component::SetMachine(Machine* machine)
{
    mMachine = machine;
}
