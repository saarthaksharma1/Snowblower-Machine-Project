/**
 * @file Pulley.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "Pulley.h"
#include "Machine.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "Component.h"
#include <wx/graphics.h>
#include <cmath>


/// Maximum amount to rock the belt
const double BeltRockAmount = 0.01;

/// How quickly to rock the belt in radians per second
/// This is divided by the length to get the actual rate
const double BeltRockBaseRate = M_PI * 1000;

/**
 * Constructor
 * @param radius The radius of the pulley
 */

Pulley::Pulley(double radius) :mSink(this)
{
    Circle(radius);

}
/**
 * Draw the pulley
 * @param graphics The graphics context to draw to
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    // Draw the belts
    // for you to figure out
    if (mBeltConnectedPulley != nullptr)
    {
        wxPoint endpoint1 = Component::GetPosition();
        wxPoint endpoint2 = mBeltConnectedPulley->GetPosition();

        double radius1 = this->GetRadius() - 3;
        double radius2 = mBeltConnectedPulley->GetRadius() - 3;

        double theta = atan2(endpoint2.y - endpoint1.y, endpoint2.x - endpoint1.x);
        double distance = sqrt(pow(endpoint2.x - endpoint1.x, 2) + pow(endpoint2.y - endpoint1.y, 2));

        double phi = asin((radius2 - radius1) / distance);
        double beta1 = theta + phi + (M_PI / 2);
        double beta2 = theta - phi - (M_PI / 2);
        wxPoint point1(endpoint1.x + radius1 * cos(beta1), endpoint1.y + radius1 * sin(beta1));
        wxPoint point2(endpoint2.x + radius2 * cos(beta1), endpoint2.y + radius2 * sin(beta1));

        //Gets the belts to flap
        //Had to learn how to use MoveToPoint and AddCurveToPoint from the wxWidgets website
        //to get the belts to flap by drawing
        double currentTime = wxGetLocalTimeMillis().GetValue() / 1000.0;
        double flap = BeltRockAmount * sin(currentTime * BeltRockBaseRate / distance);

        double controlDistance = distance * 0.1;
        wxPoint control1(point1.x + controlDistance, point1.y + flap);
        wxPoint control2(point2.x - controlDistance, point2.y + flap);

        wxGraphicsPath path = graphics->CreatePath();
        path.MoveToPoint(point1);
        path.AddCurveToPoint(control1, control2, point2);
        graphics->SetPen(*wxBLACK_PEN);
        graphics->StrokePath(path);

        wxPoint point3(endpoint1.x + radius1 * cos(beta2), endpoint1.y + radius1 * sin(beta2));
        wxPoint point4(endpoint2.x + radius2 * cos(beta2), endpoint2.y + radius2 * sin(beta2));
        wxPoint control3(point3.x + controlDistance, point3.y - flap);
        wxPoint control4(point4.x - controlDistance, point4.y - flap);

        path = graphics->CreatePath();
        path.MoveToPoint(point3);
        path.AddCurveToPoint(control3, control4, point4);
        graphics->StrokePath(path);
    }

    Component::Draw(graphics);
}
/**
 * Set the rotation for this component
 * @param rotation Relative number of turns to set.
 */
void Pulley::SetRotation(double rotation)
{
    // Upcall to ensure the polygon rotation gets set
    // for you to figure out

    Component::SetRotation(rotation);
    // Set the rotation for any source
    // for you to figure out
    mSource.SetRotation(rotation);

    if (mBeltConnectedPulley != nullptr)
    {
        // Set the rotation for any pulley we
        // are connected to by a belt.
        // for you to figure out
        //adjusts the speed for each pulley based on the rotation

        auto speed = Radius() / mBeltConnectedPulley->Radius();
        mBeltConnectedPulley->SetRotation(speed * rotation);

    }

}
/**
 * Set the drive for the other pulley
 * @param pulley
 */
void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    SetConnectedPulley(pulley);
    double speed = Radius() / pulley->Radius();
    pulley->SetRotation(speed * GetRotation());


}

/**
 * Updates the sink
 * @param sink

 */
void Pulley::SinkUpdate(std::shared_ptr<RotationSink> sink)
{
    // Set the rotation for any sink
    // for you to figure out
    sink->SetRotation(GetRotation());
}