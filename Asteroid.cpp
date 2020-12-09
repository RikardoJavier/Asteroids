#include "Asteroid.hpp"
<<<<<<< HEAD
#include "App.hpp"
#include <iostream>
#include <vector>
=======
#include "Vector2.hpp"
//#include "Physics.hpp"
#include "App.hpp"
#include <gl\GL.h>
#include <cmath>
>>>>>>> Development
#include <cstdlib>
#include <cmath>

namespace Engine
{
    inline float randInRange(float min, float max)
    {
        return min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
    }

    const size_t NUM_POINTS = 16;
    const float MIN_SIZE = 25.0f;
    const float MAX_SIZE = 45.0f;

<<<<<<< HEAD
    Asteroid::Asteroid(AsteroidSize::Size size, App *parent)
        : GameObject(1.0f, 1.0f, 0.0f, 120.0f), m_parent(parent), m_size(size)
=======
    inline float randInRange(float min, float max)
    {
        return min + (max - min) * (rand() /static_cast<float>(RAND_MAX));
    }
      
 float wrap2(float x, float min, float max)
    {
        if (x < min)
            return max - (min - x);
        if (x > max)
            return min + (x - max);
        return x;
    }

    Asteroid::Asteroid(App* parent)
    :m_mass(1.0f),
    m_angle(0.0f),
    m_rotation(120),
    m_parent(parent) // TODO: RR: Contemplate using a component based design approach
>>>>>>> Development
    {
        float sizeFactor = (int)m_size + 1;
        float min = MIN_SIZE / sizeFactor;
        float max = MAX_SIZE / sizeFactor;

        for (size_t idx = 0; idx < NUM_POINTS; ++idx)
        {
            const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * Engine::Math::Vector2::PI;
<<<<<<< HEAD
            const float randDist = min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
=======
            const float randDist = randInRange(min,max);//min + (max - min) * (rand() / static_cast<float>(RAND_MAX));

>>>>>>> Development
            m_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist,
                                                     cosf(radians) * randDist));
        }
<<<<<<< HEAD

        m_radius = (min + max) * 0.5f;

        float x = randInRange(-150.0f, 150.0f);
        float y = randInRange(-150.0f, 150.0f);
        
        ApplyImpulse(Engine::Math::Vector2(x, y), m_rotation);
    }

    void Asteroid::Update(float deltaTime)
    {
        m_angle += m_rotation * deltaTime;
        GameObject::Update(m_parent, deltaTime);
=======

        float x = randInRange(-150.0f , 150.0f);
        float y = randInRange(-150.0f , 150.0f);
        m_position = Engine::Math::Vector2(x,y);
        ApplyImpulse(Engine::Math::Vector2(x,y));

    }
    void Asteroid::ApplyImpulse(Engine::Math::Vector2 impulse)
    {
        if(m_mass>0)
        {
            m_velocity.x += (impulse.x / m_mass) * cosf((m_rotation) * (Engine::Math::Vector2::PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((m_rotation) * (Engine::Math::Vector2::PI / 180));
        }
    }

    void Asteroid::Update(float deltaTime)
    {
        m_angle += m_rotation * deltaTime;

        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

         // Calculations for wrap around
        float halfWidth = m_parent->GetWidth() / 2.0f;
        float halfHeight = m_parent->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = wrap2(m_position.x, worldMinX, worldMaxX);
        m_position.y = wrap2(m_position.y, worldMinY, worldMaxY);
    }

    void Asteroid::Render()
    {
        int i=0;
        float sizeFactor = 1;
        float min = MIN_SIZE / sizeFactor;
        float max = MAX_SIZE / sizeFactor;
        float x = randInRange(-100.0f , 150.0f);
        float y = randInRange(-40.0f , 150.0f);
        
         glLoadIdentity();
        glTranslatef(m_position.x, m_position.y, 0.f);
        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
        std::vector<Engine::Math::Vector2>::iterator it = m_points.begin();
        for (; it != m_points.end(); ++it)
        {
            glVertex2f((*it).x, (*it).y);
        }
        glEnd();
        do
        {
            
              for(size_t idx = 0; idx < NUM_POINTS; ++idx)
            {
                
                const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * Engine::Math::Vector2::PI;
                const float randDist = randInRange(min,max);//min + (max - min) * (rand() / static_cast<float>(RAND_MAX));

                 m_points.push_back(Engine::Math::Vector2(sinf(radians) * randDist,
                                                         cosf(radians) * randDist)); 
                                                         
            }
           
            i++;
        } while (i<1);
>>>>>>> Development
    }
} // namespace Engine