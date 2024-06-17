#ifndef UTILS_HPP
#define UTILS_HPP

#define between(value, min, max) (value >= min && value <= max)


namespace TUtils
{
    template <typename T>
    T elapsedTime(T t0, T t1);
    template <typename T>
    T elapsed(T t0);
}

#include <utils/utils.ipp>

#endif