#pragma once
#include "RecursiveSorting.h"

class Merge : public RecursiveSorting
{
	void merge(Lines& lines, size_t left, size_t middle, size_t right, sf::RenderWindow& window, Button& backButton) const;
	void realUpdate(Lines& lines, size_t left, size_t right, sf::RenderWindow& window, Button& backButton) override;
public:
	Merge(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};

