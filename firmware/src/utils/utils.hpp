#ifndef UTILS_HPP
#define UTILS_HPP
namespace TUtils
{
    template <typename T>
    T elapsedTime(T t0, T t1);
    template <typename T>
    T elapsed(T t0);
}

#include <utils/utils.ipp>

#endif