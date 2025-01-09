/**
 * @file RotationSource.h
 * @author Saarthak Sharma
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H

class RotationSink;
/**
 * RotationSource class for the machine
 */
class RotationSource
{
private:
    /// the sinks
    std::vector<RotationSink*> mSinks;



public:
    /// Default constructor
    RotationSource();
    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

    void AddSink(RotationSink* sink);

    /**
     * Set the sink
     * @param sink
     */
    void SetSink(RotationSink* sink);


    /**
     * Set the rotation
     * @param rotation
     */
    void SetRotation(double rotation);









};

#endif //CANADIANEXPERIENCE_MACHINELIB_ROTATIONSOURCE_H
