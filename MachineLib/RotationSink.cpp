/**
 * @file RotationSink.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "RotationSink.h"
#include "RotationSource.h"


/**
 * Constructor
 * @param comp The component to rotate
 */
RotationSink::RotationSink(Component *comp)
{
    mComponent = comp;
    mRotation = 0;
}
/**
 * Set the rotation of the component
 * @param rotate The rotation to set
 */
void RotationSink::SetRotation(double rotate)
{
    mRotation = rotate;
    mComponent->SetRotation(mRotation);

}
