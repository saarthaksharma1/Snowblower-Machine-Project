/**
 * @file SnowBlower.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H

#include "Component.h"
#include "RotationSink.h"
#include <random>
#include <list>
#include <memory>
#include "Snow.h"
#include "RotationSource.h"

class RotationSink;
class RotationSource;
/**
 * SnowBlower class
 */
class SnowBlower : public Component
{
private:

    /// Random number generator
    std::mt19937 mRandom;

    /// The sink
    RotationSink mSink;


    /// List of snow
    std::list<std::shared_ptr<Snow>> mSnow;

    /// the rotation
    double mRotation = 0;



public:
    ///Constructor
    SnowBlower(std::wstring imageDir);

    SnowBlower(const SnowBlower & ) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const SnowBlower &) = delete;
    /// Draws the snow blower
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /// Generates a random number
    double Random(double fmValue, double toValue);
    /**
     * Creates snow particles based on the snow blower's rotation.
     * @param rotation The rotation angle of the snow blower which influences the direction of snow particle emission.
     */

    RotationSink* GetSink() {return &mSink;}
    /**
     * Sets the rotation
     * @param rotation
     */
    void SetRotation(double rotation) override;


    //void SetRotation(double rotation) override {Component::SetRotation(rotation);}

    /// Makes snow
    void MakeSnow(double rotation);

    /// Updates the snow blower
     void Update(double time) override;
     void Reset() override;



};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOWBLOWER_H
