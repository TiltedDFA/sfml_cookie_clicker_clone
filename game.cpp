#include "game.h"

game::~game()
{
    delete m_cookie;
    delete m_back_ground;
}


void game::run()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Cookie Clicker");
    window.setFramerateLimit(60);
    sf::Clock delta_clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear();
        window.draw(m_back_ground->get_sprite());
        window.draw(m_cookie->get_sprite());
        m_cookie->rotate_cookie(delta_clock.restart());
        window.display();
    }
}