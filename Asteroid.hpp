#pragma once

#ifndef ASTEROID_HPP
#define ASTEROID_HPP

// Asteroids
#include "Vector2.hpp"
#include "GameObject.hpp"


namespace Engine
{
    class App;
<<<<<<< HEAD
    class Asteroid : public GameObject
    {
    public:
        /* ==========================
            * ENUMERATIONS
            * ==========================*/
        struct AsteroidSize
        {
            enum Size
            {
                BIG = 0,
                MEDIUM = 1,
                SMALL = 2
            };
        };
        /* ==========================
            * PUBLIC FUNCTIONS
            * ==========================*/
        Asteroid(AsteroidSize::Size size, App *parent);
        void Update(float deltaTime);
        inline AsteroidSize::Size GetSize() { return m_size; }

    private:
        /* ==========================
            * MEMBERS
            * ==========================*/
        App *m_parent;
        AsteroidSize::Size m_size;
=======
    class Asteroid
    {
        public:
            Asteroid(App* parent);
            void Update(float deltaTime);
            void Render();
            
        private:
            
        /* ==========================
        * PRIVATE FUNCTIONS
        * ==========================*/
         std::vector<Engine::Math::Vector2> m_points;
         void ApplyImpulse(Engine::Math::Vector2 impulse);
         /* ==========================
        * PRIVATE MEMBERS
        * ==========================*/
        float m_angle;
        float m_mass;
        float m_rotation;
         Engine::Math::Vector2 m_position;
        Engine::Math::Vector2 m_velocity;
        App* m_parent; 

>>>>>>> Development
    };
} // namespace Engine

#endif