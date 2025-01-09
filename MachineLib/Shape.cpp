/**
 * @file Shape.cpp
 * @author Saarthak Sharma
 */

#include "pch.h"
#include "Shape.h"
#include "Machine.h"
#include "Component.h"

/**
 * Constructor
 */
Shape::Shape() : mSink(this)
{

}
/**
 * Set the position of the shape
 * @param x The x position
 * @param y The y position
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    DrawPolygon(graphics, mPosition.x, mPosition.y);
}
