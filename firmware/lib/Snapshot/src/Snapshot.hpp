#ifndef SNAPSHOT_HPP
#define SNAPSHOT_HPP

class Snapshot
{
    public:
        int pulseTime;
        unsigned long atTime;
        Snapshot(int pulseTime, unsigned long atTime);
        Snapshot();
};

#include <Snapshot.ipp>

#endif