#include "color.hpp"

Color::Color( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    :   color_( sf::Color( red, green, blue, alpha))
{

}


Color::Color( sf::Color init_color)
    :   color_( init_color)
{

}


Color operator*( const Color &cl, double cf)
{
    const sf::Color &old = cl.getColor();

    uint8_t r = uint8_t( std::min( uint64_t( old.r * cf), uint64_t( 255)));
    uint8_t g = uint8_t( std::min( uint64_t( old.g * cf), uint64_t( 255)));
    uint8_t b = uint8_t( std::min( uint64_t( old.b * cf), uint64_t( 255)));

    return Color( r, g, b, old.a);
}


Color operator*( double cf, const Color &cl)
{
    return cl * cf;
}


const sf::Color &Color::getColor() const
{
    return color_;
}
