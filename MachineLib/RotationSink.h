/**
 * @file RotationSink.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H

#include "Component.h"
class RotationSource;
/**
 * RotationSink class for the machine
 */
class RotationSink
{
private:
    /// The component
    Component* mComponent;
    /// The source
    RotationSource* mSource;
      /// The speed
    double mSpeed = 1.0;
    /// The rotation
    double mRotation = 0;

public:
    /// Default constructor
    RotationSink(Component* comp);
    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;
    /// Assignment operator (disabled)
    void operator=(const RotationSink &) = delete;

    /**
     * Sets the rotation
     * @param rotate
     */
    void SetRotation(double rotate);

    /**
     * Sets the source
     * @param source
     */
    void SetSource(RotationSource* source) { mSource = source; }

    /**
     * Sets the component
     * @param component
     */
    void SetComponent(Component* component) { mComponent = component; }

    /**
     * Gets the rotation
     * @return  The rotation
     */
    double GetRotation() { return mRotation; }

    /**
     * Sets the speed
     * @param speed
     */
    void SetSpeed(double speed) { mSpeed = speed; }





};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSINK_H
