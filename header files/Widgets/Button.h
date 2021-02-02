#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


enum class BUTTON_PURPOSE
{
	EXIT = -1,
	MAIN = 0,
	START = 1,
	SETTINGS = 2,
	nothing = -99,
	doSomething = 99
};

class Button
{
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;

	sf::Color shapeColor;
	sf::Color shapeColorOnHover;
	sf::Color textColor;
	sf::Color textColorOnHover;

	float x;
	float y;
	float lenght;
	float thickness;
	BUTTON_PURPOSE purpose;

	bool isMouseHoverAbove;

public:
	Button(float x, float y, float length, sf::String string, BUTTON_PURPOSE purpose, float height = 0);

	Button();
	Button(const Button& other);
	Button(Button&& other) noexcept;
	Button& operator=(const Button& other);
	Button& operator=(Button&& other) noexcept;

	void setShapeColor(sf::Color def, sf::Color onHover);
	void setTextColor(sf::Color def, sf::Color onHover);
	void draw(sf::RenderWindow& window) const;
	void setLenght(float newLenght);

	float X() const { return this->x; }
	float Y() const { return this->y; }
	float Lenght() const { return this->lenght; }

	BUTTON_PURPOSE update(sf::Vector2f mousePos, bool mousePressed);
};

