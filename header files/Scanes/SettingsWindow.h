#pragma once
#include "Scene.h"

#include "../Sortings/Bubble.h"
#include "../Widgets/RadioButtons.h"
#include "../Widgets/ValueChanger.h"
#include "../Sortings/Shaker.h"
#include "../Sortings/Shell.h"
#include "../Sortings/Selection.h"
#include "../Sortings/Insertion.h"
#include "../Sortings/Heap.h"
#include "../Sortings/Hoar.h"
#include "../Sortings/Merge.h"

const std::vector<SortingMethod*> avalibleSortings{
													new Bubble(0),
													new Insertion(1),
													new Selection(2),
													new Shell(3),
													new Shaker(4),
													new Heap(5),
													new Hoar(6),
													new Merge(7),
};
	
class SettingsWindow : public Scene
{
	Button* backButton;
	RadioButtons sortings;
	CheckBox* fast;
	ValueChanger arraySizeChanger;
public:


	SettingsWindow(int currentArraySize, bool isFast, SortingMethod* currentSorting, unsigned width = WIDTH, unsigned height = HEIGHT);
	void draw(sf::RenderWindow& window) override;
	bool update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize) override;
	~SettingsWindow();
};
