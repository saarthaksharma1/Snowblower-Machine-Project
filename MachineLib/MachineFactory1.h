/**
 * @file MachineFactory1.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY1_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY1_H

#include <memory>
#include <string>

class Machine;
class Shape;

/**
 * MachineFactory1 class for the machine
 */
class MachineFactory1
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColor color);

public:
    MachineFactory1(std::wstring resourcesDir);
    std::shared_ptr<Machine> Create();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY1_H
