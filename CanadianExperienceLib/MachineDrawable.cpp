/**
 * @file MachineDrawable.cpp
 * @author Saarthak Sharma
 */
#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"


/**
 * Constructor
 * @param name The name of the drawable
 * @param resourcesDir The resources directory
 * @param machineNum The machine number
 */
MachineDrawable::MachineDrawable(const std::wstring &name, const std::wstring resourcesDir, int machineNum) :
        Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    mMachine = factory.CreateMachineSystem();
//    mMachine = machine;
    mMachine->SetMachineNumber(machineNum);

}
/**
 * Draws the machine
 * @param graphics
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->SetFrameRate(mTimeline->GetFrameRate());
    mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
    double frameRate = mTimeline->GetFrameRate();
    double currFrame = mTimeline->GetCurrentFrame();
    if (currFrame >= mStartFrame)
    {
      mMachine->SetFrameRate(currFrame - mStartFrame);

    }
    else
    {
        mMachine->SetMachineFrame(0);
    }
    double scale = 0.75f;
    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachine->SetLocation(wxPoint(0, 0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}


/**
 *  Hits test for the machine
 * @param pos
 * @return
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}
/**
 * Sets the timeline for the machine
 * @param timeline
 */
void MachineDrawable::SetTimeline(Timeline* timeline)
{
    mTimeline = timeline;
    Drawable::SetTimeline(timeline);
}
/**
 * Gets the timeline for the machine
 * @param timeline
 */
void MachineDrawable::GetTimeline(Timeline *timeline)
{
    mTimeline = timeline;
}
/**
 * Sets the start frame for the machine
 * @param pos
 */
void MachineDrawable::SetPosition(wxPoint pos)
{
    mPlacedPosition = pos;
}
/**
 * Shows the dialog box for the machine
 * @param window
 */
int MachineDrawable::ShowDialogBox(wxWindow *window)
{
    MachineDialog dialog(window, mMachine);
    return dialog.ShowModal();
}
