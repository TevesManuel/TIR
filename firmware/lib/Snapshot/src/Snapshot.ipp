#include<Snapshot.hpp>

Snapshot::Snapshot(int pulseTime, unsigned long atTime)
{
    this->pulseTime = pulseTime;
    this->atTime    = atTime;
}
Snapshot::Snapshot()
{
    this->pulseTime = 0;
    this->atTime    = 0;
}