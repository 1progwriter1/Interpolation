#include "point.hpp"
#include <cmath>
#include <cassert>

Point operator+( const Point &fst, const Point &snd)
{
    return Point( fst.x_ + snd.x_, fst.y_ + snd.y_);
}


Point operator*( const Point &fst, const Point &snd)
{
    return Point( fst.x_ * snd.x_, fst.y_ * snd.y_);
}


Point operator*( const Point &pt, const double cf)
{
    return Point( pt.x_ * cf, pt.y_ * cf);
}


Point operator*( const double cf, const Point &pt)
{
    return Point( pt.x_ * cf, pt.y_ * cf);
}


Point operator/( const Point &pt, const double cf)
{
    assert( fabs( cf) > 1e-9 );

    return Point( pt.x_ / cf, pt.y_ / cf);
}


Point operator-( const Point &fst, const Point &snd)
{
    return Point( fst.x_ - snd.x_, fst.y_ - snd.y_);
}
