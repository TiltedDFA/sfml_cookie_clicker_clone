#include "back_ground.h"
back_ground::back_ground(const std::string& bground_location)
{
	m_bground_texture.loadFromFile(bground_location);
	m_bground_sprite.setTexture(m_bground_texture);
	m_bground_sprite.setPosition({ 0,0 });
}
const sf::Sprite& back_ground::get_sprite() const
{
	return m_bground_sprite;
}

void back_ground::draw_bground(sf::RenderWindow& win) const
{
	win.draw(m_bground_sprite);
}
