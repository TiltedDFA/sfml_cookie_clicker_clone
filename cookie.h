#pragma once
#include "back_ground.h"
#define COOKIE_RAD 210
class cookie
{
public:
	cookie() = default;
	cookie(const std::string& cookie_location);
	
	const sf::Sprite& get_sprite()const;
	void rotate_cookie(const sf::Time& delta_time);
	void draw_cookie(sf::RenderWindow& win);
	bool check_collision(const sf::Vector2i& mouse_pos)const;
private:
	sf::Texture m_cookie_texture;
	sf::Sprite m_cookie_sprite;
};

