#include <iostream>
#include <SDL2\SDL.h>
#include <GL\gl.h>
#include "Ship.hpp"
#include "Vector2.hpp"
namespace Engine
{
	namespace Math
	{
		inline float wrap (float x, float min, float max)
		{
			if (x<min) return max - (min - x);// si la nave sale del ancho, regresa al valor min y se le resta a X, para colocarse en su nueva posicion.
			if (x>max) return min - (x- max);
			return x;
		}
		Ship::Ship() //Constructor de la nave
			: m_position(Math::Vector2::Origin)
		{
			std::cout<<"Construyendo la nave";
		}
		Ship::Ship(float _x, float _y)
			: m_position(_x, _y)
		{
		}
		Ship::~Ship() //Destructor
		{
			std::cout<<"Construyendo la nave";
		}
		void Ship::Move(float _x, float _y)
		{
			float x = m_position.x + _x;
			float y = m_position.y + _y;
			float width = 1136.0f;
			float heigth = 640.0f;
			//Ancho
			float min_width = -width/ 2.0f;
			float max_width = width/2.0f;
			//altura
			float min_heigth = -heigth/ 2.0f;
			float max_heigth = heigth/ 2.0f;

			m_position.x = wrap(x,min_width,max_width);
			m_position.y = wrap(y,min_heigth,max_heigth);

		}
		void Ship::Render()
		{
			glLoadIdentity();
			glTranslatef(m_position.x, m_position.y, 0.0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(0.0, 16.0);	 //A
			glVertex2f(-2.0, 12.0);	 //P
			glVertex2f(-4.0, 10.0);	 //B
			glVertex2f(-4.0, 2.0);	 //D
			glVertex2f(-12.0, -2.0); //E
			glVertex2f(-8.0, -4.0);	 //F
			glVertex2f(-4.0, -4.0);	 //G
			glVertex2f(-4.0, -8.0);	 //H
			glVertex2f(-8.0, -14.0); //I
			glVertex2f(-4.0, -14.0); //R
			glVertex2f(-2.0, -12.0); //S
			glVertex2f(0.0, -14.0);	 //T
			glVertex2f(2.0, -12.0);	 //V
			glVertex2f(4.0, -14.0);	 //U
			glVertex2f(8.0, -14.0);	 //J
			glVertex2f(4.0, -8.0);	 //K
			glVertex2f(4.0, -4.0);	 //L
			glVertex2f(8.0, -4.0);	 //M
			glVertex2f(12.0, -2.0);	 //N
			glVertex2f(4.0, 2.0);	 //O
			glVertex2f(4.0, 10.0);	 //C
			glVertex2f(2.0, 12.0);	 //Q
			glEnd();
		}
	} // namespace Math
} // namespace Engine