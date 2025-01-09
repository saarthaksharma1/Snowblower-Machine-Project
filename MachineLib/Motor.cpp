/**
 * @file Motor.cpp
 * @author Saarthak Sharma
 *
 */

#include "pch.h"
#include "Motor.h"
#include "Machine.h"
#include "Component.h"
#include "Shape.h"
#include "RotationSource.h"
#include "RotationSink.h"

/**
 * Sets the time for the motor and updates the rotation accordingly.
 * @param time The current time, which influences the motor's rotation.
 */
void Motor::SetTime(double time)
{
    mRotation = time;
    mMotorPolygon.SetRotation(mRotation * mSpeed);
    mMotorShaft.SetRotation(mRotation * mSpeed);
    mSource.SetRotation(mRotation * mSpeed);
}

/**
 * Draws the motor and its components on the provided graphics context.
 * @param graphics Shared pointer to a wxGraphicsContext used for drawing the motor.
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mRotation = GetTime() * mSpeed;
    mMotorPolygon.DrawPolygon(graphics, mPosition.x - 20, mPosition.y - 38);

    mMotorShaft.SetRotation(mRotation);
    mMotorShaft.DrawPolygon(graphics, mPosition.x + 20, mPosition.y - 80);
    mSource.SetRotation(mRotation);
}

/**
 * Constructs the Motor object with specified image directory for loading visual assets.
 * @param imageDir The directory path where motor images are stored.
 */
Motor::Motor(std::wstring imageDir)
{
    mMotorPolygon.Rectangle(0, 0, 80, 80);
    mMotorPolygon.SetImage(imageDir + L"/motor3.png");
    mMotorShaft.Circle(10);
    mMotorShaft.SetImage(imageDir + L"/shaft.png");
}

/**
 * Sets the size of the motor's visual components.
 * @param x Width of the motor polygon.
 * @param y Height of the motor polygon.
 */
void Motor::Size(int x, int y)
{
    mMotorPolygon.Rectangle(0, 0, x, y);
    mMotorShaft.Circle(29);  // Example value, adjust as needed
}
