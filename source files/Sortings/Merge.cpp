#include "../../header files/Sortings/Merge.h"
#include "../../header files/Scanes/SortingWindow.h"

void Merge::merge(Lines& lines, size_t left, size_t middle, size_t right, sf::RenderWindow& window, Button& backButton) const
{
	if (returnFromRecursion)
		return;
	size_t i, j, k;
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	Lines L(n1), R(n2);

	for (i = 0; i < n1; i++)
		L[i] = lines[left + i];
	for (j = 0; j < n2; j++)
		R[j] = lines[middle + 1 + j];

	i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			lines.swap(k, L[i]);
			i++;
		}
		else
		{
			lines.swap(k, R[j]);
			j++;
		}
		k++;
		draw(window, lines, backButton);
		lines.resetColor();
	}

	for (; i < n1; i++, k++)
	{
		lines.swap(k, L[i]);
		draw(window, lines, backButton);
		lines.resetColor();

	}

	for (; j < n2; j++, k++)
	{
		lines.swap(k, R[j]);
		draw(window, lines, backButton);
		lines.resetColor();

	}
}

Merge::Merge(unsigned index)
{
	name = "MERGE";
	this->index = index;
}

Lines Merge::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	this->isSortingDone = true;
	this->returnFromRecursion = false;
	realUpdate(lines, 0, lines.Size() - 1, window, backButton);
	return lines;
}

void Merge::realUpdate(Lines& lines, size_t left, size_t right, sf::RenderWindow& window, Button& backButton)
{
	if (returnFromRecursion)
		return;
	BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
	if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
	{
		this->isSortingDone = false;
		this->returnFromRecursion = true;
		return;
	}
	if (left < right && !returnFromRecursion)
	{
		size_t middle = left + (right - left) / 2;

		realUpdate(lines, left, middle, window, backButton);
		realUpdate(lines, middle + 1, right, window, backButton);
		merge(lines, left, middle, right, window, backButton);
	}
}

Lines Merge::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	return update(lines, window, backButton);
}
