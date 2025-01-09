/**
 * @file MachineSystem.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_SYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_SYSTEM_H

#include "IMachineSystem.h"
class Machine;
class MachineCFactory;
/**
 * MachineSystem class for the machine
 */
class MachineSystem : public IMachineSystem
{
public:

    MachineSystem(std::wstring resourcesDir);
    /**
     * Sets the location of machine system
     * @param location
     */
    void SetLocation(wxPoint location) override;
    /**
     * Sets the machine
     * @param machine
     *
     */
    void SetMachine(std::shared_ptr<Machine> machine) { mMachine = machine; }
    /**
     * Gets the location of the machine
     */
    wxPoint GetLocation() override;
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Sets the frame rate for machine
     * @param frame
     */
    void SetMachineFrame(int frame) override;
    /**
     * Sets the frame rate
     * @param rate
     */
    void SetFrameRate(double rate) override;
    /**
     * Sets the machine number
     * @param machine
     */
    void SetMachineNumber(int machine) override;
    /**
     * Gets the number for the machine
     */
    int GetMachineNumber() override;
    /**
     * Gets the time for the machine
     */
    double GetMachineTime() override;
    /**
     * Sets the flags
     * @param flag
     */
    void SetFlag(int flag) override;

private:

    /// Location of the machine
    wxPoint mLocation;

    /// Machine
    std::shared_ptr<Machine> mMachine;

    /// Machine number
    int mMachineNumber = 0;

    /// Resources directory
    std::wstring mResourcesDir;

    /// Time
    double mTime;

    ///  Current Frame
    int currentFrame;

    /// Frame Rate
    double mFrameRate;

    double mFrame;





};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H