#include "../../header files/Sortings/Insertion.h"
#include "../../header files/Scanes/SortingWindow.h"

Insertion::Insertion(unsigned index)
{
	this->index = index;
	this->name = "INSERTION";
	this->isSortingDone = false;
}

Lines Insertion::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	for (int i = 1; i < lines.Size(); i++)
		for (int j = i; j > 0; j--)
		{
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;

			if (lines[j - 1] > lines[j])
				lines.swap(j - 1, j);

			draw(window, lines, backButton);
			lines.resetColor();
		}
	this->isSortingDone = true;
	return lines;
}

Lines Insertion::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	for (int i = 1; i < lines.Size(); i++)
	{
		BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
			return lines;

		for (int j = i; j > 0; j--)
			if (lines[j - 1] > lines[j])
				lines.swap(j - 1, j);
		lines.resetColor();
		draw(window, lines, backButton);
	}
	this->isSortingDone = true;
	return lines;
}
