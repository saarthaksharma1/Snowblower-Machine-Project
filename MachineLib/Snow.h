/**
 * @file Snow.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOW_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOW_H

#include <wx/gdicmn.h>
#include <wx/graphics.h>
#include <memory>
#include "Component.h"
#include "RotationSink.h"

class SnowBlower;
/**
 * Snow class
 */
class Snow
{
private:
    /// The location of the snow
    wxPoint2DDouble mLocation;

    /// The velocity of the snow
    wxPoint2DDouble mVelocity;

    ///Is the snow yellow
    bool mYellow;



public:
    /// Constructor
    Snow( wxPoint2DDouble location, wxPoint2DDouble velocity);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Set the location of the snow
     * @param location
     */
    void SetLocation(wxPoint2DDouble location) {mLocation = location;}
    /**
        * Set the velocity of the snow
     * @param velocity
     */
    void SetVelocity(wxPoint2DDouble velocity) {mVelocity = velocity;}
    void Update(double time);
    /**
     * Get the location of the snow
     * @return  The location of the snow
     */
    wxPoint2DDouble GetLocation() const {return mLocation;}



};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOW_H
