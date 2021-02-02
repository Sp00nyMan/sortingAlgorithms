#include "../../header files/Sortings/SortingMethod.h"
#include "../../header files/Lines.h"
#include <Windows.h>
#include "../../header files/Widgets/Button.h"

void SortingMethod::draw(sf::RenderWindow& window, Lines& lines, Button& backButton)
{
	window.clear();
	lines.draw(window);
	backButton.draw(window);
	window.display();
	Sleep(10 / lines.Size());
}