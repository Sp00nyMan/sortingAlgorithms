#pragma once
#include "SortingMethod.h"
class Shaker : public SortingMethod
{
public:
	Shaker(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};
