#pragma once
#include "cookie.h"
template<int starting_price,double c_inc_amount,double p_scaling>
class upgrade
{
public:
	upgrade() = default;
	upgrade(const std::string& texture_path, const sf::Vector2f& sprite_pos);
	upgrade(const upgrade& other) = delete;

	[[nodiscard]] long long int& get_price();
	void update_price();

	[[nodiscard]] double get_increase_amount();

private:
	long long int m_price = starting_price;
	const double m_cookie_increase = c_inc_amount;
	const double m_price_scaling = p_scaling;
	long long int m_amount_purchased = 0;
	sf::Texture m_ugrade_texture;
	sf::Sprite m_ugrade_sprite;
};

