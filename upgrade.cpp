#include "upgrade.h"
template <int starting_price, double c_inc_amount, double p_scaling>
upgrade<starting_price, c_inc_amount, p_scaling>::upgrade(const std::string& texture_path,const sf::Vector2f& sprite_pos)
{
	if(!m_ugrade_texture.loadFromFile(texture_path))
	{
		throw std::exception("FAIL TO LOAD UPGRADE TEXTURE");
	}
	m_ugrade_sprite.setPosition(sprite_pos);
}

template <int starting_price, double c_inc_amount, double p_scaling>
long long int& upgrade<starting_price, c_inc_amount, p_scaling>::get_price()
{
	return m_price;
}

template <int starting_price, double c_inc_amount, double p_scaling>
void upgrade<starting_price, c_inc_amount, p_scaling>::update_price()
{
	m_price += m_price_scaling * m_amount_purchased;
}

template <int starting_price, double c_inc_amount, double p_scaling>
double upgrade<starting_price, c_inc_amount, p_scaling>::get_increase_amount()
{
	return m_cookie_increase*m_amount_purchased;
}
