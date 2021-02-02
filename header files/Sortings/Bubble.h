#pragma once
#include "../Lines.h"
#include "../../header files/Widgets/Button.h"
#include "SortingMethod.h"

class Bubble : public SortingMethod
{
public:
	Bubble(unsigned index);
	Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
	Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) override;
};
