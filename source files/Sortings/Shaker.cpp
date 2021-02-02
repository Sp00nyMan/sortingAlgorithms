#include "../../header files/Sortings/Shaker.h"
#include "../../header files/Scanes/SortingWindow.h"

Shaker::Shaker(unsigned index)
{
	this->index = index;
	this->name = "SHAKER";
}

Lines Shaker::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	size_t m = lines.Size();
	for (unsigned i = 0; i < m;)
	{
		for (unsigned j = i + 1; j < m; j++)
		{
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;

			if (lines[j] < lines[j - 1])
			{
				lines.swap(j, j - 1);
				draw(window, lines, backButton);
				lines.resetColor();
			}
		}
		m--;
		for (unsigned k = m - 1; k > i; k--)
		{
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
				return lines;

			if (lines[k] < lines[k - 1])
			{
				lines.swap(k, k - 1);
				draw(window, lines, backButton);
				lines.resetColor();
			}
		}
		i++;
	}
	this->isSortingDone = true;
	return lines;
}

Lines Shaker::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = false;
	size_t m = lines.Size();
	for (unsigned i = 0; i < m;)
	{
		BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
			return lines;

		for (unsigned j = i + 1; j < m; j++)
			if (lines[j] < lines[j - 1])
				lines.swap(j, j - 1);

		m--;
		for (unsigned k = m - 1; k > i; k--)
			if (lines[k] < lines[k - 1])
				lines.swap(k, k - 1);
		lines.resetColor();
		draw(window, lines, backButton);
		i++;
	}
	this->isSortingDone = true;
	return lines;
}
