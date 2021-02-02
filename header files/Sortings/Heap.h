#pragma once
#include "SortingMethod.h"
class Heap : public SortingMethod
{
public:
	Heap(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};