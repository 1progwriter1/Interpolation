#ifndef CATMULL_ROM_FUNCTIONS
#define CATMULL_ROM_FUNCTIONS

#include <cstddef>
#include <vector>
#include <SFML/Graphics.hpp>
#include "point.hpp"

const double T_STEP = 0.001;

class CatmullRom
{
    std::vector<WindowPoint> points_;
    std::vector<Point> base_points_;
public:
    CatmullRom( size_t init_size);
    ~CatmullRom() = default;

    void addPoint( Point point);
    void addManyPoints( size_t num_of_points, const int scr_w, const int scr_h);

    const std::vector<Point> &getPoints() const;
    Point interpolation( double t);
    void updateWindow( sf::RenderWindow &window, double t);
    WindowPoint &operator[]( double t);
};

WindowPoint createPoint( CatmullRom &cat, double t);

#endif // CATMULL_ROM_FUNCTIONS
