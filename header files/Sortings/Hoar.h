#pragma once
#include "RecursiveSorting.h"

class Hoar : public RecursiveSorting
{
public:
	Hoar(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
private:
	void realUpdate(Lines& lines, size_t left, size_t right, sf::RenderWindow& window, Button& backButton) override;
};

