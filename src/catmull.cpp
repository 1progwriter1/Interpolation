#include "catmull.hpp"
#include "color.hpp"
#include "point.hpp"
#include <cassert>
#include <cstddef>
#include <cstdlib>


const int POINT_RADIUS = 3;


CatmullRom::CatmullRom( size_t init_size)
    :   points_( init_size)
{

}

void CatmullRom::addPoint( Point point)
{
    base_points_.push_back( point);
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
    return base_points_;
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


    Point m0 = (base_points_[ind + 2] - base_points_[ind + 0]) / 2;
    Point m1 = (base_points_[ind + 3] - base_points_[ind + 1]) / 2;

    return  h00 * base_points_[ind + 1] + h10 * m0 +
            h01 * base_points_[ind + 2] + h11 * m1;
}


WindowPoint createPoint( CatmullRom &cat, double t)
{
    size_t ind = size_t( t);
    assert( ind < cat.getPoints().size() - 3 );

    Point point = cat.interpolation( t);

    WindowPoint w_point;
    w_point.x = float( point.x_);
    w_point.y = float( point.y_);
    w_point.is_found = true;

    return w_point;
}


WindowPoint &CatmullRom::operator[]( double t)
{
    return points_[size_t( t * 1 / T_STEP)];
}


void CatmullRom::updateWindow( sf::RenderWindow &window, double t)
{
    size_t cur_ind = size_t( t * 1 / T_STEP);
    assert( cur_ind < points_.size() );

    sf::CircleShape circe( POINT_RADIUS);
    circe.setPosition( points_[cur_ind].x, points_[cur_ind].y);
    circe.setFillColor( ( Color( sf::Color::Yellow) * ( t - size_t( t))).getColor());

    window.draw( circe);
    window.display();
}
