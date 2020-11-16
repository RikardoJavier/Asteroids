#pragma once
#ifndef Ship_HPP_
#define Ship_HPP_
#include "Vector2.hpp"
namespace Engine
{
      class Ship
      {
      public:
            //Constructor.
            Ship();
            Ship(float, float);
            ~Ship();
            //Public Funcion.
            void Move(float x, float y);
            
            void Render();

      private:
            //members.
            Engine::Math::Vector2 m_position;
      };
} // namespace Engine

#endif