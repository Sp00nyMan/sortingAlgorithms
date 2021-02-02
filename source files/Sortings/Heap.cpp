#include "../../header files/Scanes/SortingWindow.h"
#include "../../header files/Sortings/Heap.h"

Heap::Heap(unsigned index)
{
	this->name = "HEAP";
	this->index = index;
	this->isSortingDone = false;
}

Lines Heap::update(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	size_t offset = 0;
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i < lines.Size(); i++)
		{
			BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
			if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
			{
				this->isSortingDone = false;
				return lines;
			}

			if (i * 2 + 2 + offset < lines.Size())
			{
				if (lines[i + offset] > lines[i * 2 + 1 + offset] || lines[i + offset] > lines[i * 2 + 2 + offset])
					if (lines[i * 2 + 1 + offset] < lines[i * 2 + 2 + offset])
					{
						lines.swap(i + offset, i * 2 + 1 + offset);
						draw(window, lines, backButton);
						lines.resetColor();

						flag = true;
					}
					else if (lines[i * 2 + 2 + offset] < lines[i * 2 + 1 + offset])
					{
						lines.swap(i + offset, i * 2 + 2 + offset);
						draw(window, lines, backButton);
						lines.resetColor();

						flag = true;
					}

				if (lines[i * 2 + 2 + offset] < lines[i * 2 + 1 + offset])
				{
					lines.swap(i * 2 + 1 + offset, i * 2 + 2 + offset);
					draw(window, lines, backButton);
					lines.resetColor();

					flag = true;
				}
			}
			else if (i * 2 + 1 + offset < lines.Size())
				if (lines[i + offset] > lines[i * 2 + 1 + offset])
				{
					lines.swap(i + offset, i * 2 + 1 + offset);
					draw(window, lines, backButton);
					lines.resetColor();

					flag = true;
				}

		}
		if (!flag)
			++offset;
	} while (offset + 2 < lines.Size());
	this->isSortingDone = true;
	return lines;
}

Lines Heap::fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton)
{
	size_t offset = 0;
	bool flag, isFirstIterration = true;
	do
	{
		BUTTON_PURPOSE buttonEvent = SortingWindow::getButtonEvent(window, backButton);
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN)
			return lines;
		lines.resetColor();
		draw(window, lines, backButton);

		flag = false;
		for (int i = 0; i < lines.Size(); i++)
		{
			if (i * 2 + 2 + offset < lines.Size())
			{
				if (lines[i + offset] > lines[i * 2 + 1 + offset] || lines[i + offset] > lines[i * 2 + 2 + offset])
					if (lines[i * 2 + 1 + offset] < lines[i * 2 + 2 + offset])
					{
						lines.swap(i + offset, i * 2 + 1 + offset);
						flag = true;
					}
					else if (lines[i * 2 + 2 + offset] < lines[i * 2 + 1 + offset])
					{
						lines.swap(i + offset, i * 2 + 2 + offset);
						flag = true;
					}

				if (lines[i * 2 + 2 + offset] < lines[i * 2 + 1 + offset])
				{
					lines.swap(i * 2 + 1 + offset, i * 2 + 2 + offset);
					flag = true;
				}
			}
			else if (i * 2 + 1 + offset < lines.Size())
				if (lines[i + offset] > lines[i * 2 + 1 + offset])
				{
					lines.swap(i + offset, i * 2 + 1 + offset);
					flag = true;
				}

			if (isFirstIterration)
			{
				lines.resetColor();
				draw(window, lines, backButton);
			}

		}
		if (!flag)
			++offset; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
		isFirstIterration = false;
	} while (offset + 2 < lines.Size());
	this->isSortingDone = true;
	return lines;
}
