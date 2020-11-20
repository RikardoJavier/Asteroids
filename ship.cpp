#include "Ship.hpp"
#include "App.hpp"
#include "Physics.hpp"
#include "Vector2.hpp"

#include <gl\GL.h>
// STL
#include <iostream>
#include <cmath>

namespace Engine
{

    Ship::Ship(App *parent)
        : m_position(Math::Vector2::Origin), m_velocity(Math::Vector2::Origin), m_angle(0.0f), m_rotation(250.0f), m_mass(1.0f), m_parent(parent) // TODO: RR: Contemplate using a component based design approach
    {
        std::cout << "Construction of ship\n";
        ChangeShip();
    }

    Ship::Ship(App *parent, float _x, float _y)
        : m_position(_x, _y), m_velocity(Math::Vector2::Origin), m_angle(0.0f), m_rotation(250.0f), m_mass(1.0f), m_parent(parent)
    {
        std::cout << "Construction of ship\n";
    }

    Ship::~Ship()
    {
        std::cout << "Destruction of ship\n";
    }

    void Ship::MoveUp()
    {
        ApplyImpulse(Math::Vector2(THRUST));
    }

    void Ship::RotateLeft(float deltaTime)
    {
        m_angle += m_rotation * deltaTime;
    }

    void Ship::RotateRight(float deltaTime)
    {
        m_angle -= m_rotation * deltaTime;
    }

    void Ship::ApplyDrag(Math::Vector2 force)
    {
        m_velocity.x *= force.x;
        m_velocity.y *= force.y;
    }

    void Ship::ApplyImpulse(Math::Vector2 impulse)
    {
        if (m_mass > 0)
        {
            m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
            m_velocity.y += (impulse.y / m_mass) * sinf((m_angle + ANGLE_OFFSET) * (Engine::Math::Vector2::PI / 180));
        }
    }

    void Ship::Update(float deltaTime)
    {
        // Calculate speed
        float speed =
            std::fabs(m_velocity.Length());

        // Cap speed
        if (speed > MAX_VELOCITY)
        {
            m_velocity.x = (m_velocity.x / speed) * MAX_VELOCITY;
            m_velocity.y = (m_velocity.y / speed) * MAX_VELOCITY;
        }

        // Set new state
        m_currentSpeed = speed;
        m_position.x += m_velocity.x * deltaTime;
        m_position.y += m_velocity.y * deltaTime;

        // Applies drag
        ApplyDrag(Math::Vector2(DRAG_FORCE)); //this need to go to Asteroids.

        // Calculations for wrap around
        float halfWidth = m_parent->GetWidth() / 2.0f;
        float halfHeight = m_parent->GetHeight() / 2.0f;

        float worldMinX = -halfWidth;
        float worldMaxX = halfWidth;

        float worldMinY = -halfHeight;
        float worldMaxY = halfHeight;

        m_position.x = Engine::wrap(m_position.x, worldMinX, worldMaxX);
        m_position.y = Engine::wrap(m_position.y, worldMinY, worldMaxY);
    }

    void Ship::ChangeShip()
    {
        m_NewShip2 = ++m_NewShip2 %2;
        m_points.clear();
        switch (m_NewShip2)
        {
        case 1:
            m_points.push_back(Math::Vector2(0.0f, 16.0f));  //A
            m_points.push_back(Math::Vector2(-2.0f, 12.0f)); //P
            m_points.push_back(Math::Vector2(-4.0, 10.0));   //B
            m_points.push_back(Math::Vector2(-4.0, 2.0));    //D
            m_points.push_back(Math::Vector2(-12.0, -2.0));  //E
            m_points.push_back(Math::Vector2(-8.0, -4.0));   //F
            m_points.push_back(Math::Vector2(-4.0, -4.0));   //G
            m_points.push_back(Math::Vector2(-4.0, -8.0));   //h
            m_points.push_back(Math::Vector2(-8.0, -14.0));  //I
            m_points.push_back(Math::Vector2(-4.0, -14.0));  //R
            m_points.push_back(Math::Vector2(-2.0, -12.0));  //S
            m_points.push_back(Math::Vector2(0.0, -14.0));   //T
            m_points.push_back(Math::Vector2(2.0, -12.0));   //V
            m_points.push_back(Math::Vector2(4.0, -14.0));   //U
            m_points.push_back(Math::Vector2(8.0, -14.0));   //J
            m_points.push_back(Math::Vector2(4.0, -8.0));    //K
            m_points.push_back(Math::Vector2(4.0, -4.0));    //L
            m_points.push_back(Math::Vector2(8.0, -4.0));    //M
            m_points.push_back(Math::Vector2(12.0, -2.0));   //N
            m_points.push_back(Math::Vector2(4.0, 2.0));     //O
            m_points.push_back(Math::Vector2(4.0, 10.0));    //C
            m_points.push_back(Math::Vector2(2.0, 12.0));    //Q
            break;
        default:
            m_points.push_back(Math::Vector2(0.0f, 20.0f));
            m_points.push_back(Math::Vector2(12.0f, -10.0f));
            m_points.push_back(Math::Vector2(6.0f, -4.0f));
            m_points.push_back(Math::Vector2(-6.0f, -4.0f));
            m_points.push_back(Math::Vector2(-12.0f, -10.0f));

            break;
        }
     } //Switch.

        void Ship::Render()
        {
            glLoadIdentity();
            glTranslatef(m_position.x, m_position.y, 0.0);
            glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
            glBegin(GL_LINE_LOOP);
            std::vector<Math::Vector2>::iterator it = m_points.begin();
            for (; it != m_points.end(); ++it)
            {
                glVertex2f((*it).x, (*it).y);
            }
            glEnd();
        }
            void Ship::Restart()
    {
        glLoadIdentity();
        m_position.x = 0.0f;
        m_position.y = 0.0f;
        m_velocity.x = 0.0f;
        m_velocity.y = 0.0f;
        m_angle = 0.0f;

        glTranslatef(m_position.x, m_position.y, 0.0);

        glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
    }
    } // namespace Engine