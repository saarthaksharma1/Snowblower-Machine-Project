/**
 * @file RotationSource.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include "Machine.h"
#include "Component.h"
#include "Shape.h"

/**
 * Constructor
 */
RotationSource::RotationSource()
{

}
/**
 * Add a sink
 * @param sink
 */
void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);
    sink->SetSource(this);
}
/**
 * Set the rotation
 * @param rotation
 */
void RotationSource::SetRotation(double rotation)
{

    for(auto sink : mSinks)
    {
        sink->SetRotation(rotation);
    }
}





