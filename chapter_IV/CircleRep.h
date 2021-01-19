#ifndef circle_rep_h
#define circle_rep_h

#include "Point.h"
#include "PointRep.h"

struct Circle {
    const struct Point* point;
    int radius;
};

#endif // circle_rep_h