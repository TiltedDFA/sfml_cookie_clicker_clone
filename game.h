#pragma once
#include "upgrade.h"

class game
{
public:
	game();
	~game();
	void update_text();
	void update_cookie_amount();
	void tick_update_cookie_timer(sf::Clock& clock);
	void run();
private:
	back_ground* m_back_ground = new back_ground(BGROUND_PATH);
	cookie* m_cookie = new cookie(COOKIE_PATH);
	sf::Vector2i m_mouse_pos{};
	double m_cookie_amount;
	long long int m_click_cookie_rate;
	double m_passive_cookie_rate;
	sf::String m_cookie_display_string;
	sf::Text m_cookie_display_text;
	sf::Font m_font;
	upgrade<10, 0.1, 1.6> clicker_upgrade{ CLICKER_UPGRADE_PATH,CLICKER_UPGRADE_ALT_PATH,887.5f,100.0f };//112.5f = size
};

