#pragma once
#include "SortingMethod.h"

class RecursiveSorting : public SortingMethod
{
	virtual void realUpdate(Lines& lines, size_t left, size_t right, sf::RenderWindow& window, Button& backButton) = 0; //Рекурсивная сортировка массива lines в пределах left-right
public:
	bool returnFromRecursion;
	virtual Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0;
	virtual Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0;
};