/**
 * @file Snow.cpp
 * @author Saarthak Sharma
 */
#include "pch.h"
#include "Snow.h"
#include "SnowBlower.h"

/// Gravity in pixels per second per second
const float Gravity = 15;
/// Probability of a snow particle being a yellow snow
const double YellowSnowProbability = 0.1;

/**
 * Constructs a Snow object with initial location and velocity.
 * @param location The initial location of the snowflake as a wxPoint2DDouble.
 * @param velocity The initial velocity of the snowflake as a wxPoint2DDouble.
 */

/// Random number generator for the yellow snow probability
std::mt19937 gen( std::random_device{}());
///Gets the distribution of the yellow snow probability
std::bernoulli_distribution dist(YellowSnowProbability);

/**
 * Constructs a Snow object with initial location and velocity and a random yellow snow probability.
 * @param location The initial location of the snowflake as a wxPoint2DDouble.
 * @param velocity The initial velocity of the snowflake as a wxPoint2DDouble.
 */
Snow::Snow( wxPoint2DDouble location, wxPoint2DDouble velocity) : mLocation(location), mVelocity(velocity),
                                                                  mYellow(dist(gen))
{
}

/**
 * Draws the snowflake on the provided graphics context.
 * @param graphics Shared pointer to a wxGraphicsContext used for drawing the snowflake.
 */
void Snow::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    wxColour snowColor;
    if (mYellow) {
        snowColor = *wxYELLOW;
    }
    else {
        snowColor = *wxWHITE;
    }
    wxBrush brush(snowColor);
    graphics->SetBrush(brush);
    graphics->SetPen(wxPen(snowColor));
    graphics->DrawRectangle((int)mLocation.m_x, (int)mLocation.m_y, 2, 2);
}

/**
 * Updates the position of the snowflake based on its velocity and the influence of gravity.
 * @param time The time elapsed since the last update, used to calculate the new position.
 */
void Snow::Update(double time)
{
    mVelocity = wxPoint2DDouble(mVelocity.m_x, mVelocity.m_y + Gravity * time);
    mLocation = wxPoint2DDouble(mLocation.m_x + mVelocity.m_x * time, mLocation.m_y + mVelocity.m_y * time);
}

