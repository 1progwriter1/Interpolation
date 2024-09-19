#ifndef CATMULL_ROM_FUNCTIONS
#define CATMULL_ROM_FUNCTIONS

#include <cstddef>
#include <vector>
#include <SFML/Graphics.hpp>
#include "point.hpp"

class Catmull
{
    std::vector<Point> points_;
public:
    Catmull() = default;
    ~Catmull() = default;

    void addPoint( Point);
    void addManyPoints( size_t num_of_points, const int scr_w, const int scr_h);

    const std::vector<Point> &getPoints() const;

    Point interpolation( double t);
};

sf::CircleShape createCircle( Catmull &cat, double t);

#endif // CATMULL_ROM_FUNCTIONS
