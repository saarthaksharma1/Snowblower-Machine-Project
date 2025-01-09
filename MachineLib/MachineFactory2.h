/**
 * @file MachineFactory2.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H
#include <memory>
#include <string>
#include <wx/colour.h>

class Machine;
class Shape;

/**
 * MachineFactory2 class for the machine
 */
class MachineFactory2
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;

    /// Path to the images directory
    std::wstring mImagesDir;

    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColor color);

public:
    MachineFactory2(std::wstring resourcesDir);
    std::shared_ptr<Machine> Create();

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINEFACTORY2_H
