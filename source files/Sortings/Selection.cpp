#include "../../header files/Sortings/Selection.h"
#include "../../header files/Scanes/SortingWindow.h"

Selection::Selection(unsigned index)
{
	this->index = index;
	this->name = "SELECTION";
}

Lines Selection::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	for (int i = 0; i < lines.Size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < lines.Size(); j++)
		{
			lines[min].repaint(255, 255, 255);
			draw(window, lines, backButton);
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;
			if (lines[min] > lines[j])
			{
				min = j;
				lines.resetColor();
			}
		}
		lines.swap(i, min);
	}
	lines.resetColor();
	draw(window, lines, backButton);
	this->isSortingDone = true;
	return lines;
}

Lines Selection::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	for (int i = 0; i < lines.Size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < lines.Size(); j++)
		{
			lines[min].repaint(255, 255, 255);
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;
			if (lines[min] >lines[j])
				min = j;
		}
		lines.swap(i, min);
		draw(window, lines, backButton);
		lines.resetColor();
	}
	this->isSortingDone = true;
	return lines;
}
