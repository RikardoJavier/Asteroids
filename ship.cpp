#include "Ship.hpp"
#include "App.hpp"
//#include "Physics.hpp"
#include "Vector2.hpp"

#include <gl\GL.h>

//STL
#include <iostream>
#include <cmath>
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Physics.hpp"

namespace Engine
{

	Ship::Ship(App *parent)
		: GameObject(1.0f, RADIUS, 0.0f, 250.0f), m_parent(parent) // TODO: RR: Contemplate using a component based design approach
	{
		std::cout << "Construction of ship\n";
		ChangeShip();
	}

	Ship::Ship(App *parent, float _x, float _y)
		: GameObject(1.0f, RADIUS, 0.0f, 250.0f), m_parent(parent)
	{
		m_position = Math::Vector2(_x, _y);
		std::cout << "Construction of ship\n";
		ChangeShip();
	}

	Ship::~Ship()
	{
		std::cout << "Destruction of ship\n";
	}

	void Ship::MoveUp()
	{
		ApplyImpulse(Math::Vector2(THRUST), m_angle + ANGLE_OFFSET);
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
		ApplyDrag(Math::Vector2(DRAG_FORCE));

		GameObject::Update(m_parent, deltaTime);
	}
 void Ship::ChangeShip()
    {
		
        m_NewShip2 = ++m_NewShip2 %2;
        m_points.clear();
        
        switch (m_NewShip2)
        {
        case 1:
		glBegin(GL_POLYGON);
            glColor3f (0.0, 1.0, 0.0);
            glVertex3f (0.25, 0.25, 0.0);
            glVertex3f (0.75, 0.25, 0.0);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.75, 0.75, 0.0);
            glVertex3f (0.25, 0.75, 0.0);
            glBegin(GL_LINE_LOOP);
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
		glBegin(GL_POLYGON);
            glColor3f (0.0, 1.0, 0.0);
            glVertex3f (0.25, 0.25, 0.0);
            glVertex3f (0.75, 0.25, 0.0);
            glColor3f (1.0, 0.0, 0.0);
            glVertex3f (0.75, 0.75, 0.0);
            glVertex3f (0.25, 0.75, 0.0);
            glBegin(GL_LINE_LOOP);
            m_points.push_back(Math::Vector2(0.0f, 20.0f));
            m_points.push_back(Math::Vector2(12.0f, -10.0f));
            m_points.push_back(Math::Vector2(6.0f, -4.0f));
            m_points.push_back(Math::Vector2(-6.0f, -4.0f));
            m_points.push_back(Math::Vector2(-12.0f, -10.0f));

            break;
        }
     } //Switch.
	
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
		glEnd();
	}

	Bullet *Ship::Shoot()
	{
		float shootingAngle = m_angle + ANGLE_OFFSET;
		float bulletPx = m_points[0].x * cosf(shootingAngle * (Engine::Math::Vector2::PI / 180));
		float bulletPy = m_points[0].y * sinf(shootingAngle * (Engine::Math::Vector2::PI / 180));

		Bullet *bullet = new Bullet(m_parent);
		bullet->Teleport(m_position.x + bulletPx, m_position.y + bulletPy);
		bullet->ApplyImpulse(Math::Vector2(m_currentSpeed + BULLET_SPEED), shootingAngle);

		return bullet;
	}

} // namespace Engine