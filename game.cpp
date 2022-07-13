#include "game.h"
game::game()
{
    m_cookie = cookie(cookie_file);
    m_back_ground = back_ground(bground_file);
}

void game::run()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Cookie Clicker");
    window.setFramerateLimit(60);
    sf::Clock delta_clock;
    while (window.isOpen())
    {
        window.clear();
       // m_back_ground.draw_bground(window);
        m_cookie.draw_cookie(window);
        m_cookie.rotate_cookie(delta_clock.restart());
        window.display();
    }
}