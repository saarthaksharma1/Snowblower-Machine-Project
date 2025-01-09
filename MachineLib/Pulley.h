/**
 * @file Pulley.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
class RotationSource;
class RotationSink;
#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"
/**
 * Pulley class for the machine
 */
class Pulley : public Component
{
private:
    /// The rotation
    double mRotation = 0.0;
    /// the ratio
    double mRatio= 1.0;

    /// the sink
    RotationSink mSink;

    /// the source
    RotationSource mSource;

    /// the speed
    double mSpeed = 1.0;

    /// the time
    double mTime = 0.0;

    /// the other pulley
    std::shared_ptr<Pulley> mBeltConnectedPulley;

    /// the radius
    double mRadius;



public:

/// Constructor
    Pulley(double radius);

    /// Copy constructor (disabled)
    Pulley(const Pulley &) = delete;

    /// Assignment operator
    void operator=(const Pulley &) = delete;


/**
 * Draws the pulley on the provided graphics context.
 * @param graphics
 */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
//    void SetRadius(double radius) {mRadius = radius;}
    /**
     * Gets the radius of the pulley
     * @return The radius of the pulley
     */
    double GetRadius() {return this->Radius();}

    /**
     * Drives the other pulley
     * @param pulley
     */
    void Drive(std::shared_ptr<Pulley> pulley); //drive the pulley

    void SinkUpdate(std::shared_ptr<RotationSink> sink); //update the sink
    /**
     * Sets the rotation for the pulley
     * @param rotation
     */
    void SetRotation(double rotation) override;
    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSink* GetSink() {return &mSink;}
    /**
     * Get a pointer to the source object
     * @return  Pointer to RotationSource object
     */
    RotationSource* GetSource() {return &mSource;}
    /**
     * Sets the speed of the pulley's visual components.
     * @param pulley
     *
     */
    void SetConnectedPulley(std::shared_ptr<Pulley> pulley) {mBeltConnectedPulley = pulley;}







};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
