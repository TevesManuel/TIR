#include<Snapshot.hpp>
#include<Arduino.h>

Snapshot::Snapshot(unsigned long pulseTime, unsigned long atTime)
{
    this->pulseTime = pulseTime;
    this->atTime    = atTime;
}
Snapshot::Snapshot()
{
    this->pulseTime = 0;
    this->atTime    = 0;
}