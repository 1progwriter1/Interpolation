#include "../MyLibraries/headers/systemdata.h"
#include "catmull.hpp"
#include "point.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>


const int HEIGHT = 900;
const int WIDTH = 1600;
const int POINT_RADIUS = 10;
const size_t POINTS_C = 4;

int main()
{
    sf::RenderWindow window( sf::VideoMode( WIDTH, HEIGHT), "hello");

    srand( (unsigned int)time( NULL));

    Catmull cat;
    cat.addManyPoints( POINTS_C, WIDTH, HEIGHT);

    // cat.addPoint( Point( 100, 100));
    // cat.addPoint( Point( 1500, 100));
    // cat.addPoint( Point( 100, 1000));
    // cat.addPoint( Point( 100, 100));

    for ( auto i : cat.getPoints() )
    {
        printf( "%f %f\n", i.x_, i.y_);
    }

    double t = 0.001f;
    window.clear( sf::Color::Black);
    while ( window.isOpen() )
    {
        sf::Event event;
        while ( window.pollEvent( event) )
        {
            if ( event.type == sf::Event::Closed )
            {
                window.close();
            }
        }

        Point next_point = cat.interpolation( t);
        Point next = cat.getPoints()[size_t( t)];
        sf::CircleShape circle = createCircle( cat, t);
        circle.setPosition( sf::Vector2f( float( next_point.x_), float( next_point.y_)));

        t += 0.001f;
        if ( size_t( t) >= POINTS_C - 3 )
        {
            t = 0;
        }

        sf::sleep( sf::microseconds( 1000));
        sf::CircleShape n( POINT_RADIUS);
        n.setFillColor( sf::Color::Red);
        n.setPosition( next.x_, next.y_);
        window.draw( circle);
        window.draw( n);
        window.display();
    }

    return SUCCESS;
}
