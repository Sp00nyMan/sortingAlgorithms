#include <iostream>
#include "../../header files/Sortings/Hoar.h"
#include "../../header files/Scanes/SortingWindow.h"

Hoar::Hoar(unsigned index)
{
	this->index = index;
	this->name = "QUICKSORT";
}

Lines Hoar::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = true;
	this->returnFromRecursion = false;
	realUpdate(lines, 0, lines.Size() - 1, window, backButton);
	return lines;
}

void Hoar::realUpdate(Lines& lines, size_t left, size_t right, sf::RenderWindow& window, Button& backButton)
{
	if (right- left < 1 || returnFromRecursion)
		return;
	int leftMarker = left;
	int rightMarker = right;
	const int buf = std::round((leftMarker + rightMarker) / 2.0f);
	Line pivit = lines[buf];
	while (true)
	{
		const BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
		{
			this->isSortingDone = false;
			this->returnFromRecursion = true;
			return;
		}

		for (; leftMarker <= right && pivit > lines[leftMarker]; leftMarker++);
		for (; rightMarker >= left && pivit < lines[rightMarker]; rightMarker--);
		if (leftMarker <= rightMarker)
		{
			lines.swap(leftMarker, rightMarker);
			leftMarker++;
			rightMarker--;
		}
		else
		{
			draw(window, lines, backButton);
			lines.resetColor();
			break;
		}
		draw(window, lines, backButton);
		lines.resetColor();
	}

	if (leftMarker < right)
		realUpdate(lines, leftMarker, right, window, backButton);
	if (rightMarker > left)
		realUpdate(lines, left, rightMarker, window, backButton);
}

Lines Hoar::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	return update(lines, window, backButton);
}
