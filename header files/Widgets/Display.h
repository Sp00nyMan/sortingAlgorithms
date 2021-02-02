#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Display
{
	float x;
	float y;

	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;
public:
	Display()
		:x(0), y(0) {}
	Display(const sf::String& string, float x = 0, float y = 0, float length = 40);
	void draw(sf::RenderWindow& window) const;
	std::string update(const sf::String& newText);
	float X() const { return this->x; }
	float Lenght() const { return shape.getSize().x; }
};

