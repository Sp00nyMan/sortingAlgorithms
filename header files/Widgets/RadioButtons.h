#pragma once
#include <vector>
#include "CheckBox.h"

class RadioButtons
{
	std::vector<CheckBox*> buttons;
	unsigned current;
public:
	RadioButtons();
	void push_back(CheckBox* newButton);
	void push_back(const std::string& string, bool checked);

	unsigned Size() const { return buttons.size(); }
	void setCurrent(unsigned index);

	void draw(sf::RenderWindow& window);
	unsigned update(sf::Vector2f mousePos, bool mousePressed);
	~RadioButtons();
};

