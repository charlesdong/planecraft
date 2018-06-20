#ifndef MATHUTIL_H_
#define MATHUTIL_H_

#include "glm.h"

template <typename T>
inline bool isBetween(const T & v, const T & x, const T & y) { return v >= x && v <= y; }

#endif