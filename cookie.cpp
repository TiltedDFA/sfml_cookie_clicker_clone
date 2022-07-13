#include "cookie.h"

cookie::cookie(const std::string& cookie_location)
{
	m_cookie_texture.loadFromFile(cookie_location);
	m_cookie_sprite.setTexture(m_cookie_texture);
	m_cookie_sprite.setPosition(500.0f, 500.0f);
	m_cookie_sprite.setOrigin(300, 300);
	m_cookie_sprite.setRotation(0);
}

const sf::Sprite& cookie::get_sprite() const
{
	return m_cookie_sprite;
}
void cookie::rotate_cookie(const sf::Time& delta_time)
{
	m_cookie_sprite.rotate(delta_time.asSeconds() * 50);
}
void cookie::draw_cookie(sf::RenderWindow& win)
{
	win.draw(m_cookie_sprite);
}

