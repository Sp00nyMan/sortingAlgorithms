#pragma once
#include "SortingMethod.h"
class Selection : public SortingMethod
{
public:
	Selection(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};

