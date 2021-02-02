#include "../../header files/Sortings/Bubble.h"
#include "../../header files/Scanes/SortingWindow.h"

Bubble::Bubble(unsigned index)
{
	this->index = index;
	name = "BUBBLE";
}

Lines Bubble::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	for (int i = 0; i < lines.Size(); i++)
		for (int j = 0; j < lines.Size() - i - 1; j++)
		{
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;
			if (lines[j] > lines[j + 1])
				lines.swap(j, j + 1);
			draw(window, lines, backButton);
			lines.resetColor();
		}
	this->isSortingDone = true;
	return lines;
}

Lines Bubble::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	for (int i = 0; i < lines.Size(); i++)
	{
		const BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
			return lines;
		for (int j = 0; j < lines.Size() - i - 1; j++)
			if (lines[j] > lines[j + 1])
				lines.swap(j, j + 1);
		lines.resetColor();
		draw(window, lines, backButton);
	}
	this->isSortingDone = true;
	return lines;
}