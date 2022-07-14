#pragma once
#include "cookie.h"
template<int starting_price,double c_inc_amount,double p_scaling>
class upgrade
{
public:
	upgrade() = default;
	upgrade(const upgrade& other) = delete;
	upgrade(const std::string& n_texture_path, const std::string& a_texture_path, const float& sprite_pos_x, const float& sprite_pos_y)
	//the n_texture is the normal texture while the a_texture is the alternate texture which is to be displayed when the texture is blacked out
	{
		if (!m_ugrade_texture.loadFromFile(n_texture_path))
		{
			EXCEPTIONN("FAIL TO LOAD UPGRADE TEXTURE");
		}
		if (!m_upgrade_bout_texture.loadFromFile(a_texture_path))
		{
			EXCEPTIONN("FAIL TO LOAD UPGRADE TEXTURE");
		}
		if(!m_font.loadFromFile(FONT_PATH))
		{
			EXCEPTIONN("FAIL TO LOAD FONT");			
		}
		m_ugrade_sprite.setTexture(m_ugrade_texture);
		m_ugrade_sprite.setPosition({ sprite_pos_x,sprite_pos_y });
		m_ugrade_sprite.setScale(0.75f, 0.75f);
		m_display_price_text.setFont(m_font);
		m_display_price_text.setString("$" + std::to_string(m_price));
		m_display_price_text.setCharacterSize(30);
		m_display_price_text.setPosition(m_ugrade_sprite.getPosition().x, m_ugrade_sprite.getPosition().y);
		m_display_price_text.setFillColor(sf::Color::Blue);
	}
	[[nodiscard]] long long int& get_price()
	{
		return m_price;
	}
	void update_price()
	{
		m_price += m_price_scaling * m_amount_purchased;
		m_display_price_text.setString("$" + std::to_string(m_price));
	}
	[[nodiscard]] double get_increase_amount()
	{
		return m_cookie_increase * m_amount_purchased;
	}
	void display_sprite(const double& cookie_amount, sf::RenderWindow& window)
	{
		if(cookie_amount >= m_price)
		{
			m_ugrade_sprite.setTexture(m_ugrade_texture);
			window.draw(m_ugrade_sprite);
			window.draw(m_display_price_text);
		}
		else
		{
			m_ugrade_sprite.setTexture(m_upgrade_bout_texture);
			window.draw(m_ugrade_sprite);
			window.draw(m_display_price_text);
		}
	}
	const sf::Text& get_text()
	{
		return m_display_price_text;
	}
	void handle_click(const sf::Vector2i& mouse_position, double& cookie_amount,double& passive_amount)
	{
		const sf::Vector2i temp(m_ugrade_sprite.getPosition());
		if(mouse_position.x >= temp.x &&
			mouse_position.x <= temp.x + 112.50f &&
			mouse_position.y >= temp.y &&
			mouse_position.y <= temp.y + 112.50f)
			//checks if the mouse positon is over the sprite
		{
			if (cookie_amount >= m_price)
			{
				cookie_amount -= m_price;
				++m_amount_purchased;
				passive_amount += m_cookie_increase;
				update_price();
			}
		}
	}
private:
	long long int m_price = starting_price;
	const double m_cookie_increase = c_inc_amount;
	const double m_price_scaling = p_scaling;
	long long int m_amount_purchased = 0;
	sf::Texture m_upgrade_bout_texture;
	sf::Texture m_ugrade_texture;
	sf::Sprite m_ugrade_sprite;
	sf::Font m_font;
	sf::Text m_display_price_text;
};

