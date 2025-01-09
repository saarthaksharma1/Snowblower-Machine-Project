/**
 * @file Component.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

#include "Polygon.h"
#include <memory>

class Machine;
/**
 * Component class for the machine
 */
class Component : public cse335::Polygon
{
private:
    /// Position of the component
    wxPoint mPosition = wxPoint(0,0);
    /// Time
    double mTime;
    /// Image
    wxBitmap mImage;
    /// Rotation
    double mRotation = 0;
    /// Machine
    Machine* mMachine = nullptr;
public:
    /**
     * Sets the machine
     * @param machine
     */
    virtual void SetMachine(Machine*machine);

    /**
     * Draws the component on the provided graphics context.
     * @param graphics
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Gets the position
     * @return mPosition
     */
    wxPoint GetPosition() {return mPosition;}
    /**
     * Sets the position
     * @param time
     */
    virtual void SetPosition(int x, int y){ mPosition = wxPoint(x,y);}
    /**
     * Sets the time
     * @param time
     */
    void SetTime(double time) { mTime = time; }
    /**
     * Gets time
     * @return mTime
     */
    double GetTime() { return mTime; }
    /**
     * Resets the component
     */
    virtual void Reset() {}
    /**
     * Updates the component
     * @param time
     */
    virtual void Update(double time) {}
    //void SetRotation(double rotation) {mRotation = rotation;}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
