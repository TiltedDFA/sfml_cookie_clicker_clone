#include "cookie.h"

cookie::cookie(const std::string& cookie_location)
{
	if (!m_cookie_texture.loadFromFile(cookie_location))
	{
		EXCEPTIONN("FAILED TO LOAD COOKIE TEXTURE");
	}
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
bool cookie::check_collision(const sf::Vector2i& mouse_pos) const
{
	const sf::Vector2f converted_pos(mouse_pos);
	const sf::Vector2f cookie_pos = m_cookie_sprite.getPosition();
	if(converted_pos.x <= cookie_pos.x + COOKIE_RAD &&
		converted_pos.x >= cookie_pos.x - COOKIE_RAD &&
		converted_pos.y <= cookie_pos.y + COOKIE_RAD &&
		converted_pos.y >= cookie_pos.y - COOKIE_RAD)
	{
		return true;
	}
	return false;
}

