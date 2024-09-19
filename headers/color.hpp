#ifndef COLOR_FUNCTIONS
#define COLOR_FUNCTIONS

#include <SFML/Graphics.hpp>
#include <_types/_uint8_t.h>

class Color
{
    sf::Color color_;

public:
    Color( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
    Color( sf::Color init_color);
    ~Color() {};
    const sf::Color &getColor() const;
};

Color operator*( const Color &cl, double cf);
Color operator*( double cf, const Color &cl);

#endif //  COLOR_FUNCTIONS
