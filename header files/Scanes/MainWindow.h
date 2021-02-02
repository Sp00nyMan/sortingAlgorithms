#pragma once
#include "Scene.h"

class MainWindow : public Scene
{
	std::vector<Button*> buttons;
public:
	MainWindow(unsigned width, unsigned height);
	bool update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize) override;
	void draw(sf::RenderWindow& window) override;
	~MainWindow();
};
