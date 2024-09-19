#include "catmull.hpp"
#include "color.hpp"
#include "point.hpp"
#include <cassert>
#include <cstddef>
#include <cstdlib>

const int POINT_RADIUS = 3;

void CatmullRom::addPoint( Point point)
{
    points_.push_back( point);
}


void CatmullRom::addManyPoints( size_t num_of_points, const int scr_w, const int scr_h)
{
    addPoint( Point( rand() % scr_w, rand() % scr_h));
    for ( size_t i = 1; i < num_of_points; i++ )
    {
        addPoint( Point( rand() % scr_w, rand() % scr_h));
    }
}


const std::vector<Point> &CatmullRom::getPoints() const
{
    return points_;
}

Point CatmullRom::interpolation( double t)
{
    size_t ind = size_t( t);
    t -= ind;

    double t2   = t  * t,
           t3   = t2 * t,
           t3_2 = t3 * 2,
           t2_3 = t2 * 3;

    double h00 =  t3_2 - t2_3 + 1;
    double h10 =  t3   - t2 * 2 + t;
    double h01 = -t3_2 + t2_3;
    double h11 =  t3   - t2;


    Point m0 = (points_[ind + 2] - points_[ind + 0]) / 2;
    Point m1 = (points_[ind + 3] - points_[ind + 1]) / 2;

    return  h00 * points_[ind + 1] + h10 * m0 +
            h01 * points_[ind + 2] + h11 * m1;
}


sf::CircleShape createCircle( CatmullRom &cat, double t)
{
    size_t ind = size_t( t);
    assert( ind < cat.getPoints().size() - 3 );

    sf::CircleShape circle( POINT_RADIUS);
    Point point = cat.interpolation( t);
    circle.setPosition( float( point.x_), float( point.y_));
    circle.setFillColor( (Color( sf::Color::Yellow) * (t - ind)).getColor());

    return circle;;
}
