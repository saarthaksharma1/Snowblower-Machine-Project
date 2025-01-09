/**
 * @file SnowBlower.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "SnowBlower.h"
/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;
/// Width of the snow blower in pixels
const int SnowBlowerWidth = 120;

/// Height of the snow blower in pixels
const int SnowBlowerHeight = 174;

/// Y offset to the center of the snow blower in pixels
const int SnowBlowerCenterOffset = 60;



/**
 * Constructor for SnowBlower class.
 * @param imageDir Directory containing the images used for the snow blower.
 */
SnowBlower::SnowBlower(std::wstring imageDir) :mSink(this)
{
    std::random_device rd;	// Generates a random seed
    mRandom.seed(rd());		// Seed the random number generator
    Rectangle(-SnowBlowerWidth/2, SnowBlowerCenterOffset, SnowBlowerWidth, SnowBlowerHeight);
    SetImage(imageDir);
}

/**
 * Generate a uniform distribution random number from fmValue to toValue
 * \param fmValue Minimum value to generate
 * \param toValue Maximum value to generate
 * \return Random number
 */
double SnowBlower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

/**
 * Draws the snow blower and its snow particles.
 * @param graphics Shared pointer to a wxGraphicsContext used for drawing the snow blower and snow.
 */
void SnowBlower::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // Draw the snow blower
    for (auto &snow : mSnow)
    {
        snow->Draw(graphics);
    }
    Component::Draw(graphics);


}
/**
 * Creates snow particles based on the snow blower's rotation.
 * @param rotation The rotation angle of the snow blower which influences the direction of snow particle emission.
 */
void SnowBlower::MakeSnow(double rotation )
{
    // Compute how much snow to generate for this amount of rotation.
    auto num = 15;
    for (int i = 0; i < num; i++)
    {
        // GetRotation gets the rotation of the snow machine.
        // This code computes a vector to the emitting end of the
        // snow machine. The random value means that position is over
        // the entire end of the machine, not just a single point.
        auto angle = GetRotation() * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        auto dx = sin(angle);
        auto dy = -cos(angle);


        auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
        auto dx1 = sin(angle1);
        auto dy1 = -cos(angle1);

        double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
        double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);

        wxPoint2DDouble snowPosition((float)(GetPosition().x+dx * offset), (float)(GetPosition().y+dy * offset));
        wxPoint2DDouble snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));
        // Create a snowflake
        auto snow = std::make_shared<Snow>( snowPosition, snowVelocity);

        mSnow.push_back(snow);
    }

}

/**
 * Updates all snow particles managed by the snow blower.
 * @param time The time elapsed since the last update, used to update each snow particle's position.
 */
void SnowBlower::Update(double time)
{
    for(auto snow : mSnow)
    {
        snow->Update(time);
    }
}
/**
 * Sets the rotation for the snow blower and generates snow based on the new rotation.
 * @param rotation The new rotation angle for the snow blower.
 */
void SnowBlower::SetRotation(double rotation)
{
    MakeSnow(rotation);
    Component::SetRotation(rotation);
}
/**
 * Resets the snow blower by clearing all generated snow particles.

 */
void SnowBlower::Reset()
{
    mSnow.clear();
    Component::Reset();
}