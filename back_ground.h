#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "helper_functions.h"
#define COOKIE_PATH "assets/images/cookie.png"
#define BGROUND_PATH "assets/images/back_ground.png"
#define FONT_PATH "assets/fonts/OETZTYP_.TTF"
#define COOKIE_RAD 210
#ifdef _DEBUG
#define EXCEPTIONN(x) throw std::exception(x)
#else 
#define EXCEPTIONN(x)
#endif

#define CLICKER_UPGRADE_PATH "assets/images/clicker_upgrade.png"
#define CLICKER_UPGRADE_ALT_PATH "assets/images/clicker_upgrade_alt.png"
#define GRANNY_UPGRADE_PATH "assets/images/granny_upgrade.png"
#define GRANNY_UPGRADE_ALT_PATH "assets/images/granny_upgrade_alt.png"


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

