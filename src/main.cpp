#include "../../MyLibraries/headers/systemdata.h"
#include "catmull.hpp"
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>


const int HEIGHT = 900;
const int WIDTH = 1600;
const size_t POINTS_C = 20;


int main()
{
    sf::RenderWindow window( sf::VideoMode( WIDTH, HEIGHT), "hello");

    srand( (unsigned int)time( NULL));

    CatmullRom cat( size_t( 1 / T_STEP * (POINTS_C - 3)));
    cat.addManyPoints( POINTS_C, WIDTH, HEIGHT);

    double t = 0.000f;
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

        if ( !cat[t].is_found )
        {
            cat[t] = createPoint( cat, t);
            cat.updateWindow( window, t);
        }

        t += T_STEP;
        if ( size_t( t) >= POINTS_C - 3 )
        {
            t = 0;
        }

        sf::sleep( sf::microseconds( 500));
    }

    return SUCCESS;
}
