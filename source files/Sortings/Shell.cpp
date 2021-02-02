#include <iostream>
#include "../../header files/Sortings/Shell.h"
#include "../../header files/Scanes/SortingWindow.h"

Shell::Shell(unsigned index)
{
	this->index = index;
	this->name = "SHELL";
}

Lines Shell::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	unsigned j;
	for (unsigned step = lines.Size() / 2; step > 0; step /= 2)
		for (unsigned i = step; i < lines.Size(); i++)
		{
			const BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;

			Line temp((lines[i]));
			for (j = i; j >= step; j -= step)
				if (temp < lines[j - step])
					lines.swap(j, j - step);
				else
					break;
			draw(window, lines, backButton);
			lines.resetColor();
		}
	this->isSortingDone = true;
	return lines;
}
Lines Shell::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	std::cout << "BORING" << std::endl;
	this->isSortingDone = false;
	unsigned j;
	for (unsigned step = lines.Size() / 2; step > 0; step /= 2)
	{
		for (unsigned i = step; i < lines.Size(); i++)
		{
			const BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;

			Line temp((lines[i]));
			for (j = i; j >= step; j -= step)
				if (temp < lines[j - step])
					lines.swap(j, j - step);
				else
					break;	
		}
		lines.resetColor();
		draw(window, lines, backButton);
	}
	this->isSortingDone = true;
	return lines;
}
