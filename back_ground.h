#pragma once
#include <SFML/Graphics.hpp>

class back_ground
{
public:
	back_ground() = default;
	back_ground(const std::string& bground_location);


	const sf::Sprite& get_sprite()const;
	void draw_bground(sf::RenderWindow& win)const;
private:
	sf::Texture m_bground_texture;
	sf::Sprite m_bground_sprite;
};

