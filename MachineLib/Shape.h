/**
 * @file Shape.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

/**
 * Shape class for the machine
 */
class Shape : public Component
{
private:
    /// Position of the shape
    wxPoint mPosition = wxPoint(0, 0);
    /// The sink
    RotationSink mSink;



public:
    /// Default constructor
    Shape();

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;
    ///draws the shape
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Gets the sink
     * @return  The sink
     */
    RotationSink* GetSink() { return &mSink; }

    /**
     * Sets the position of the shape
     * @param x
     * @param y
     */
    void SetPosition(int x, int y) { mPosition = wxPoint(x, y); }
    /**
     * Gets the y position
     * @return  The y position
     */

    int GetY() { return mPosition.y; }




};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
