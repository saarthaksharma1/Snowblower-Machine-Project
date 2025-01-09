/**
 * @file PictureFactory.h
 * @author Charles Owen
 *
 * A factory class that builds our picture.
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;
class MachineDrawable;
/**
 * A factory class that builds our picture.
 */

class PictureFactory {
private:
    std::shared_ptr<MachineDrawable> mMachine1;
    std::shared_ptr<MachineDrawable> mMachine2;

public:
    std::shared_ptr<Picture> Create(std::wstring resourcesDir);

    std::shared_ptr<MachineDrawable> GetMachine1() { return mMachine1; }
    std::shared_ptr<MachineDrawable> GetMachine2() { return mMachine2; }
};

#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
