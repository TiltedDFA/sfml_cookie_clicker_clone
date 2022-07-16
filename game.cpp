#include "game.h"
game::game()
{
    m_cookie_amount = 0;
    m_click_cookie_rate = 1;
    m_passive_cookie_rate = 0;
    if (!m_font.loadFromFile(FONT_PATH))
    {
        throw std::exception("FAIL TO LOAD FONT");	    
    }
    m_cookie_display_text.setFont(m_font);
	m_cookie_display_text.setCharacterSize(50);	
    m_cookie_display_text.setOutlineColor(sf::Color::Black);
    m_cookie_display_text.setOutlineThickness(3);
    m_cookie_display_text.setPosition(100, 50);
    m_cookie_display_text.setString("Cookie amount: " + h_fun::double_to_string_2_dp(m_cookie_amount));
    m_passive_cookies_text.setFont(m_font);
    m_passive_cookies_text.setCharacterSize(50);  
    m_passive_cookies_text.setOutlineColor(sf::Color::Black);
    m_passive_cookies_text.setOutlineThickness(3);
    m_passive_cookies_text.setPosition(100, 100);
    m_passive_cookies_text.setString("Cookies per second: " + h_fun::double_to_string_2_dp(m_passive_cookie_rate));
}
game::~game()
{
    delete m_cookie;
    delete m_back_ground;
}


void game::update_text()
{
    m_cookie_display_text.setString("Cookie amount: " + h_fun::double_to_string_2_dp(m_cookie_amount));
    m_passive_cookies_text.setString("Cookies per second: " + h_fun::double_to_string_2_dp(m_passive_cookie_rate));
}
void game::update_cookie_amount()
{
    m_cookie_amount += m_click_cookie_rate;
}
void game::tick_update_cookie_timer(sf::Clock& clock)
{
	if(clock.getElapsedTime().asSeconds() >= 1.0f)
	{
        clock.restart();
        m_cookie_amount += m_passive_cookie_rate;
	}
}


void game::run()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Cookie Clicker");
    window.setFramerateLimit(60);
    sf::Clock delta_clock;
    sf::Clock cookie_rate_timer;
   
    while (window.isOpen())
    {
        sf::Event event{};
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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    m_mouse_pos = sf::Mouse::getPosition(window);
					if(m_cookie->check_collision(m_mouse_pos))
					{
                        update_cookie_amount();
					}
                    clicker_upgrade.handle_click(m_mouse_pos, m_cookie_amount, m_passive_cookie_rate);
                    granny_upgrade.handle_click(m_mouse_pos, m_cookie_amount, m_passive_cookie_rate);
                    farm_upgrade.handle_click(m_mouse_pos, m_cookie_amount, m_passive_cookie_rate);
                    update_text();
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
        tick_update_cookie_timer(cookie_rate_timer);
        update_text();
        clicker_upgrade.display_sprite(m_cookie_amount, window);
        granny_upgrade.display_sprite(m_cookie_amount, window);
        farm_upgrade.display_sprite(m_cookie_amount, window);
        window.draw(m_cookie_display_text);
        window.draw(m_passive_cookies_text);
        
        window.display();
    }
}