#include <iostream>
#include "../../header files/Widgets/CheckBox.h"
#include "../../header files/Constants.h"


CheckBox::CheckBox(float x, float y, std::string text, bool isChecked) //�������� ���-����� � ����� (x, y) � ������� string.  
	:checked(isChecked), x(x), y(y)
{
	/////////////�������� ������
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

void CheckBox::check() //�������� ���-����
{
	this->checked = !this->checked;
}

bool CheckBox::update(sf::Vector2f mousePos, bool mouseClicked)
{
	if (shape.getGlobalBounds().contains(mousePos)) //���� ������ ��������� ������ ���-�����
	{
		if (mouseClicked)// � ��� ������
			check(); //�������� ���-����
	}
	return Checked(); //��������� ������� ��������� ���-�����
}

void CheckBox::draw(sf::RenderWindow& window) //��������� ���-����� �� ���� window
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
