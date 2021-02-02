#pragma once
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Constants.h"
static const float STEP = 255.0f / WIDTH;
class Line
{
	sf::RectangleShape shape;
	float x;
	float lenght;
	float thickness;
	sf::Color color;
	static float getGradientR(float lenght);
	static float getGradientG(float lenght);
	static float getGradientB(float lenght);
public:
	Line(float x, float lenght, float thickness);
	Line(const Line& other);
	Line(Line&& other) noexcept;
	void draw(sf::RenderWindow& window) const;
	void moveTo(float newX);
	void swap(Line& other) noexcept;
	void swap(Line& other, sf::Color newColor) noexcept;
	void repaint(float r, float g, float b);
	void repaint(sf::Color newColor);
	float Lenght() const { return this->lenght; }
	float X() const { return this->x; }
	sf::Color Color() const { return this->color; }
	Line& operator=(Line other);
	bool operator<(const Line& other) const;
	bool operator>(const Line& other) const;
	bool operator<=(const Line& other) const;

	void setThickness(float newT);
};