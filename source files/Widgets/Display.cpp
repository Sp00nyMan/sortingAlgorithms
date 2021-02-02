#include <iostream>
#include "../../header files/Widgets/Display.h"
#include "../../header files/Constants.h"

Display::Display(const sf::String& string, float x, float y, float length) //�������� ����� ������ ���������� � ����� (x, y) ������ lenght � ������� string
	:x(x), y(y)
{
	float thickness = length / 3;

	/////////////�������� ������
	try
	{
		font.loadFromFile(defaultFont);
		text.setFont(font);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}

	text.setCharacterSize(length / 3.5);
	text.setString(string);
	text.setFillColor(buttonColor);
	//������������� � ��������������� ������ � ����������� �� ����� �������
	if (text.getGlobalBounds().width >= length)
	{
		text.setCharacterSize(text.getCharacterSize() * length / text.getGlobalBounds().width);
	}
	const float offsetY = (thickness - 2.0f * text.getCharacterSize() + text.getGlobalBounds().height) / 2.0f;
	const float offsetX = (length - text.getGlobalBounds().width) / 2.0f;
	text.setPosition(x + offsetX, y + offsetY);

	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(length, thickness));
	shape.setFillColor(sf::Color::Transparent);
}

void Display::draw(sf::RenderWindow& window) const //��������� ������� �� ���� window
{
	window.draw(shape);
	window.draw(text);
}

std::string Display::update(const sf::String& newText) //�������� ����� �� �������
{
	if (text.getString() != newText)
	{
		text.setString(newText);
	}
	return text.getString();
}
