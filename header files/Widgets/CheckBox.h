#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Constants.h"

class CheckBox
{
	sf::RectangleShape shape;
	const sf::Color color = sf::Color::Transparent;
	const sf::Color colorChecked = buttonColor;
	bool checked;
	sf::Text title;
	sf::Font font;
	float x;
	float y;
public:
	const static auto size = 40;

	CheckBox(float x, float y, std::string text, bool isChecked);
	void check();
	bool update(sf::Vector2f mousePos, bool mouseClicked);
	void draw(sf::RenderWindow& window);

	bool Checked() const { return this->checked; }
	float X() const { return x; }
	float Y() const { return y; }
};
