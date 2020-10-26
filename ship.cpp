#include <iostream>
#include <SDL2\SDL.h>
#include <gl\gl.h>
#include "Ship.hpp"
void Ship::Render()
    {
		glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
			glVertex2f(0.0, 16.0);//A
			glVertex2f(-2.0, 12.0);//P
			glVertex2f( -4.0,  10.0);//B
			glVertex2f( -4.0, 2.0);//D
			glVertex2f( -12.0, -2.0);//E
			glVertex2f(-8.0, -4.0);//F
			glVertex2f(-4.0, -4.0);//G
			glVertex2f(-4.0, -8.0);//H
			glVertex2f(-8.0, -14.0);//I
			glVertex2f(-4.0, -14.0);//R
			glVertex2f(-2.0, -12.0);//S
			glVertex2f(0.0, -14.0);//T
			glVertex2f(2.0, -12.0);//V
			glVertex2f(4.0, -14.0);//U
            glVertex2f(8.0, -14.0);//J
			glVertex2f(4.0, -8.0);//K
			glVertex2f(4.0, -4.0);//L
			glVertex2f(8.0, -4.0);//M
			glVertex2f(12.0, -2.0);//N
			glVertex2f(4.0, 2.0);//O
			glVertex2f( 4.0, 10.0);//C
			glVertex2f(2.0, 12.0);//Q
		glEnd();

		SDL_GL_SwapWindow(m_mainWindow);
     
    }