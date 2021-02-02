#pragma once
#include "Button.h"
#include "Display.h"

class ValueChanger
{
	int value;
	int minValue;
	int maxValue;

	Display* display;
	Button* bigMinus;
	Button* Minus;
	Button* Plus;
	Button* bigPlus;
public:
	ValueChanger();
	ValueChanger(float x, float y, int currentValue, int minValue = 1, int maxValue = 1200);
	void draw(sf::RenderWindow& window) const;
	int update(sf::Vector2f mousePos, bool mousePressed);
	void setMaxValue(int maxV);
	~ValueChanger();
};

