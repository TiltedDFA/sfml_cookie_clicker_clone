#include "cookie.h"

cookie::cookie(const std::string& cookie_location)
{
	m_cookie_texture->loadFromFile(cookie_location);
	m_cookie_sprite->setTexture(*m_cookie_texture);
	m_cookie_sprite->setPosition(400.0f, 400.0f);
	m_cookie_sprite->setRotation(0);
}
cookie::cookie(const cookie& other)
{
	this->m_cookie_texture = new sf::Texture();
	this->m_cookie_texture = other.m_cookie_texture;
	this->m_cookie_sprite = new sf::Sprite();
	this->m_cookie_sprite = other.m_cookie_sprite;
}
cookie::~cookie()
{
	delete m_cookie_texture;
	delete m_cookie_sprite;
}

void cookie::rotate_cookie(const sf::Time& delta_time)
{
	m_cookie_sprite->rotate(delta_time.asSeconds());//same a rotating it 1 degree * delta time
}
void cookie::draw_cookie(sf::RenderWindow& win)
{
	win.draw(*m_cookie_sprite);
}

