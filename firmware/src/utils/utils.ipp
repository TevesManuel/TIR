#include <utils/utils.hpp>


template <typename T>
T TUtils::elapsedTime(T t0, T t1)
{
    if( t0 < t1 )
        return t1 - t0;
    else
        return t0 - t1;
}

#include <Arduino.h>

template <typename T>
T TUtils::elapsed(T t)
{
    return micros() - t;
}