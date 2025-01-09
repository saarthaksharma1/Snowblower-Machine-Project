/**
 * @file Machine.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#include <memory>
#include "Component.h"
#include <vector>
#include <wx/graphics.h>
class Component;
class MachineSystem;
/**
 * Machine class for the machine
 */
class Machine
{
private:
    /// Machine number
    int mMachineNumber;
    ///Components
    std::vector<std::shared_ptr<Component>> mComponents;
    ///Time
    double mTime = 0;
    ///Flag
    int mFlag = 1;


public:
    /**
     * Constructor
     * @param machineNumber The machine number to set
     */
    Machine(int machineNumber) : mMachineNumber(machineNumber) {}
    /**
     * Gets the machine number
     */
    int GetMachineNumber() { return mMachineNumber; }
    /**
     * Adds a component to the machine
     * @param component The component to add
     */
    void AddComponent(std::shared_ptr<Component> component);
    /**
     * Draws the machine
     * @param graphics The graphics context to draw to
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Sets the time
     * @param time
     */
    void SetTime(double time);
    /**
     * Gets the time
     */
    double GetTime() { return mTime; }
    //should take a double, redraw after a certain period of time and update every component
    //virtual void Update(double T) override;
    /**
     * Resets the machine
     */
    void Reset();

    /**
     * Updates the machine
     * @param time The time to update to
     */
    void Update(double time);

    /**
     * Sets the flag for the machine
     * @param flag The flag to set
     */
    void SetFlag(int flag);



};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
