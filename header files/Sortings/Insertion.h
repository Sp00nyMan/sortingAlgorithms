#pragma once
#include "SortingMethod.h"
class Insertion :	public SortingMethod
{
public:
	Insertion(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};

