/**
 * @file Motor.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTOR_H

#include "Component.h"
#include "Polygon.h"
#include "Machine.h"
#include "RotationSource.h"
#include "RotationSink.h"
#include <memory>
#include <string>
#include <wx/graphics.h>

/**
 * Motor class for the machine
 */
class Motor : public Component
{
private:
    /// The time
    double mTime;
    /// The current speed of the motor
    double mSpeed = 1.0;
    /// The current rotation of the motor
    double mRotation = 0.0;
    /// The polygon representing the motor
    cse335::Polygon mMotorPolygon;

    ///The motor shaft
    cse335::Polygon mMotorShaft;

    /// The flag
    cse335::Polygon mFlag;


    /// The position of the motor
    wxPoint mPosition = wxPoint(0,0);
    /// Rotation source for this component
    RotationSource mSource;


public:
    /**
     * Constructor
     * @param imageDir
     */
    Motor(std::wstring imageDir);
    /**
     * Sets the time for the motor and updates the rotation accordingly.
     * @param time The current time, which influences the motor's rotation.
     */
    void SetTime(double time);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     * Sets the speed of the motor's visual components.
     * @param speed The speed of the motor.
     */
    void SetSpeed(double speed) {mSpeed = speed;}
    /** Get a pointer to the source object
    * @return Pointer to RotationSource object
      */

    RotationSource *GetSource() { return &mSource; }
    /**
     * Sets the size of the motor's visual components.
     * @param x Width of the motor polygon.
     * @param y Height of the motor polygon.
     */
    void Size(int x, int y);







};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
