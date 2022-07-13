#pragma once
#include "back_ground.h"
class cookie
{
public:
	cookie() = default;
	cookie(const std::string& cookie_location);
	cookie(const cookie& other);
	~cookie();

	void rotate_cookie(const sf::Time& delta_time);
	void draw_cookie(sf::RenderWindow& win);
private:
	sf::Texture* m_cookie_texture = new sf::Texture;
	sf::Sprite* m_cookie_sprite = new sf::Sprite;
};

