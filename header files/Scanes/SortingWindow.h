#pragma once
#include "Scene.h"

class SortingWindow : public Scene
{
	Button backButton;
	Lines lines;
public:
	SortingWindow(unsigned arraySize);
	void run(sf::RenderWindow& window, SortingMethod* currentSorting, bool fast);
	void draw(sf::RenderWindow& window) override;
	static BUTTON_PURPOSE getButtonEvent(sf::RenderWindow& window, Button& backButton);

	bool update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize) override;
};

