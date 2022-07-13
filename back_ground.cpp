#include "back_ground.h"
back_ground::back_ground(const std::string& bground_location)
{
	m_bground_texture->loadFromFile(bground_location);
	m_bground_sprite->setTexture(*m_bground_texture);
	m_bground_sprite->setPosition({ 0,0 });
}
back_ground::back_ground(const back_ground& other)
{
	this->m_bground_texture = new sf::Texture();
	this->m_bground_texture = other.m_bground_texture;
	this->m_bground_sprite = new sf::Sprite();
	this->m_bground_sprite = other.m_bground_sprite;	
}
back_ground::~back_ground()
{
	delete m_bground_texture;
	delete m_bground_sprite;
}

void back_ground::draw_bground(sf::RenderWindow& win) const
{
	win.draw(*m_bground_sprite);
}
