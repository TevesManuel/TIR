#ifndef SNAPSHOT_HPP
#define SNAPSHOT_HPP

class Snapshot
{
    public:
        unsigned long pulseTime;
        unsigned long atTime;
        Snapshot(unsigned long pulseTime, unsigned long atTime);
        Snapshot();
};

#include <Snapshot.ipp>

#endif