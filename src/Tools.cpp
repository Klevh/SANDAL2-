#include "Tools.hpp"



// ---------------------------------------------------------
// SANDAL2::Color
SANDAL2::Color::Color(int r, int g, int b, int a)
    :r(r)
    ,g(g)
    ,b(b)
    ,a(a)
{}
SANDAL2::Color::Color(int color[4])
    :r(color[0])
    ,g(color[1])
    ,b(color[2])
    ,a(color[3])
{}
// ---------------------------------------------------------



// ---------------------------------------------------------
// SANDAL2::Point
SANDAL2::Point::Point(float x, float y)
    :x(x)
    ,y(y)
{}
// ---------------------------------------------------------



// ---------------------------------------------------------
// SANDAL2::OperationFailure
SANDAL2::OperationFailure::OperationFailure(const char * message)
    :message_(message)
{}

const char * SANDAL2::OperationFailure::what() const throw() {
    return message_.c_str();
}
// ---------------------------------------------------------
