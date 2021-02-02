#pragma once
#include "SFML/Graphics.hpp"
#include "../Sortings/SortingMethod.h"

class Scene
{
	virtual bool update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};
