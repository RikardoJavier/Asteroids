#include <iostream>
namespace Engine
{
    namespace Math
    {
        struct Vector2
        {
            //Static
            static Vector2 Origin;
            //Static

            //Constructor
            Vector2();
            Vector2(float, float);
            Vector2(float);
            //Cosntructor

            //Funciones
            float Length() const;
            float SquaredLeth() const;
            float Normalize();

            //Cnstructor
            float x;
            float y;
            float length;
        };
    } // namespace Math
} // namespace Engine