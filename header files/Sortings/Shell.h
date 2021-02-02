#pragma once
#include "SortingMethod.h"

class Shell : public SortingMethod
{
public:
	Shell(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};
