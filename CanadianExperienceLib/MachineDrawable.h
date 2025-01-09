/**
 * @file MachineDrawable.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H

#include <machine-api.h>
#include "Drawable.h"
/**
 * Drawable class for the machine
 */
class MachineDrawable :  public Drawable
{
private:
    ///start frame
    int mStartFrame;

    ///start time
    double mStartTime = 0.0;

    /// Machine
    std::shared_ptr<IMachineSystem> mMachine;

    /// the timeline
    Timeline* mTimeline;

    /// Position of the machine
    wxPoint2DDouble mPosition;

public:
    /// Default constructor (disabled)
    MachineDrawable() = delete;
    // Copy constructor (disabled)
    MachineDrawable(const MachineDrawable &) = delete;

    /// Assignment operator
    void operator=(const MachineDrawable &) = delete;
    /// Constructor
    MachineDrawable(const std::wstring &name, const std::wstring resourcesDir, int machineNum);

    /// Draw the machine
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /// Hit test
    bool HitTest(wxPoint pos) override;

    /**
     * sets the position
     * @param pos
     */
    void SetPosition(wxPoint pos);

    /**
     * Gets the timeline
     * @param timeline
     */
    void GetTimeline(Timeline* timeline);

    /**
     * Sets the timeline
     * @param timeline
     */
    void SetTimeline(Timeline* timeline);

    /**
     * Sets the machine number
     * @param machineNum
     */
    void SetMachineNumber(int machineNum){ mMachine->SetMachineNumber(machineNum); }

    /**
     * Gets the machine number
     */
    int GetMachineNumber() { return mMachine->GetMachineNumber(); }
//    void StartTime(double startTime);
//    int GetStartTime() const { return mStartTime; }
//    int GetStartFrame() const { return mStartFrame; }
    /**
     * Sets the start frame
     * @return mStartFrame
     */
    void SetStartFrame(int startFrame) { mStartFrame = startFrame; }

    /**
     * Gets the start time
     * @return mStartTime
     */
    int GetStart() {return mStartFrame;}

    /**
     * Gets the start time
     * @return mStartTime
     */
    void SetStart(int start) {mStartFrame = start;}

    /**
     * Sets the start time
     * @param startTime
     */
    void SetStartTime(int startTime) { mStartTime = startTime; }
    int ShowDialogBox(wxWindow *window);





};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
