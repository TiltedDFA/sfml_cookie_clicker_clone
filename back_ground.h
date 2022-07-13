#pragma once
#include <SFML/Graphics.hpp>

class back_ground
{
public:
	back_ground() = default;
	back_ground(const std::string& bground_location);
	back_ground(const back_ground& other);
	~back_ground();

	void draw_bground(sf::RenderWindow& win)const;
private:
	sf::Texture* m_bground_texture = new sf::Texture();
	sf::Sprite* m_bground_sprite = new sf::Sprite();
};

