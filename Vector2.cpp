#include "Vector2.hpp"
#include <cmath>

namespace Math
{
    Vector2 Vector2::Origin = Vector2();

    Vector2::Vector2() : x(0.0f),
                         y(0.0f),
                         length(0.0f)
    {
    }
    Vector2::Vector2(float _x, float _y) : x(_x),
                                           y(_y),
                                           length(0.0f)
    {
        length();
    }
    Vector2::Vector2(float _uniform) : x(_uniform),
                                       y(_uniform),
                                       length(0.0f)
    {
        length = length();
    }
    float Vector2::Length() const
    {
        return std::sqrt(x * x + y * y);
    }

    float Vector2::SquaredLeth() const
    {
        return (x * x + y * y);
    }

    float Vector2::Narmalize()
    {
        //Calculete Length
        length = Length();

        float inverscale = 1.0f / length;

        x *= 1 / inverscale;
        y *= 1 / inverscale;
    }
} // namespace Math