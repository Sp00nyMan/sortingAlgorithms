#include <iostream>
#include "../../header files/Widgets/CheckBox.h"
#include "../../header files/Constants.h"


CheckBox::CheckBox(float x, float y, std::string text, bool isChecked) //Создание чек-бокса в точке (x, y) с текстом string.  
	:checked(isChecked), x(x), y(y)
{
	/////////////Загрузка шрифта
	try
	{
		font.loadFromFile(defaultFont); //Proxima-Nove extrabold
		title.setFont(font);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}
	////////////
	
	title.setCharacterSize(size / 3.5 * 5);
	title.setString(text);
	title.setFillColor(colorChecked);
	title.setPosition(x + size * 1.5, y - title.getGlobalBounds().height / 2.2);

	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(size, size));
	shape.setOutlineColor(colorChecked);
	shape.setOutlineThickness(3);
	shape.setFillColor(color);
}

void CheckBox::check() //Отметить чек-бокс
{
	this->checked = !this->checked;
}

bool CheckBox::update(sf::Vector2f mousePos, bool mouseClicked)
{
	if (shape.getGlobalBounds().contains(mousePos)) //Если курсор находится внутри чек-бокса
	{
		if (mouseClicked)// и ЛКМ нажата
			check(); //Отметить чек-бокс
	}
	return Checked(); //Возврщает текущее состояние чек-бокса
}

void CheckBox::draw(sf::RenderWindow& window) //Отрисовка чек-бокса на окне window
{
	if (Checked())
	{
		shape.setFillColor(colorChecked);
	}
	else
	{
		shape.setFillColor(color);
	}
	window.draw(shape);
	window.draw(title);
}
