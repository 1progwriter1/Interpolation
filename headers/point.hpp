#ifndef POINT_FUNCTIONS
#define POINT_FUNCTIONS


struct WindowPoint
{
    float x = 0;
    float y = 0;
    bool is_found = false;
};


class Point
{
public:
    double x_;
    double y_;

    Point( double init_x, double init_y)
        :   x_( init_x), y_( init_y)
    {};
    ~Point() = default;
};

Point operator+( const Point &fst, const Point &snd);
Point operator*( const Point &fst, const Point &snd);
Point operator*( const Point &pt, const double cf);
Point operator*( const double cf, const Point &pt);
Point operator/( const Point &pt, const double cf);
Point operator-( const Point &fst, const Point &snd);

#endif // POINT_FUNCTIONS
