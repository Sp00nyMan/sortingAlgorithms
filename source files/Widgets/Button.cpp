#include <iostream>
#include "../../header files/Widgets/Button.h"
#include "../../header files/Constants.h"

Button::Button(float x, float y, float length, sf::String string, BUTTON_PURPOSE purpose, float height) //�������� ������ � ����� (x,y) ������ lenght � ������� height � ������� string �� ��� � ����������� purpose
	:x(x), y(y), lenght(length), thickness(length / 2), purpose(purpose), isMouseHoverAbove(false)
{
	if (height != 0)
	{
		this->thickness = height;
	}
	try
	{
		font.loadFromFile(defaultFont); //Proxima-Nova extrabold
		text.setFont(font);
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
		system("pause");
	}
	text.setCharacterSize(length / textScale);
	text.setString(string);

	textColor = buttonTextColor;
	textColorOnHover = buttonTextColorOnHover;
	text.setFillColor(textColor);

	const float offsetY = (thickness - 2.0f * text.getCharacterSize() + text.getGlobalBounds().height) / 2.0f;
	const float offsetX = (length - text.getGlobalBounds().width) / 2.0f;

	text.setPosition(x + offsetX, y + offsetY);

	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(length, thickness));

	shapeColor = buttonColor;
	shapeColorOnHover = buttonColorOnHover;
	shape.setFillColor(shapeColor);
}

Button::Button()
	:x(0), y(0), lenght(0), thickness(0), purpose(BUTTON_PURPOSE::nothing), isMouseHoverAbove(false)
{
}

Button::Button(const Button& other)
	: shape(other.shape), text(other.text), font(other.font), x(other.x), y(other.y), lenght(other.lenght), thickness(other.thickness), purpose(other.purpose), isMouseHoverAbove(other.isMouseHoverAbove)
{
}

Button::Button(Button&& other) noexcept
	:shape(std::move(other.shape)), text(std::move(other.text)), font(other.font), x(other.x), y(other.y), lenght(other.lenght), thickness(other.thickness), purpose(other.purpose), isMouseHoverAbove(other.isMouseHoverAbove)
{
	other.x = 0;
	other.y = 0;
	other.lenght = 0;
	other.thickness = 0;
	other.purpose = BUTTON_PURPOSE::nothing;

}

Button& Button::operator=(const Button& other)
{
	shape = other.shape;
	text = other.text;
	font = other.font;
	x = other.x;
	y = other.y;
	lenght = other.lenght;
	thickness = other.thickness;
	purpose = other.purpose;
	isMouseHoverAbove = other.isMouseHoverAbove;
	return *this;
}

Button& Button::operator=(Button&& other) noexcept
{
	shape = std::move(other.shape);
	text = std::move(other.text);
	font = other.font;
	x = other.x;
	other.x = 0;
	y = other.y;
	other.y = 0;
	lenght = other.lenght;
	other.lenght = 0;
	thickness = other.thickness;
	other.thickness = 0;
	purpose = other.purpose;
	other.purpose = BUTTON_PURPOSE::nothing;
	isMouseHoverAbove = other.isMouseHoverAbove;
	other.isMouseHoverAbove = false;
	return *this;
}

void Button::setShapeColor(sf::Color def, sf::Color onHover) //��������� ����� ������
{
	shapeColor = def;
	shapeColorOnHover = onHover;
}

void Button::setTextColor(sf::Color def, sf::Color onHover) //��������� ����� ������ �� ������
{
	textColor = def;
	textColorOnHover = onHover;
}

void Button::draw(sf::RenderWindow& window) const //��������� ������ �� ���� window
{
	window.draw(shape);
	window.draw(text);
}

void Button::setLenght(float newLenght) //�������� ����� ������
{
	if (newLenght >= 0)
	{
		shape.setPosition(x - (newLenght - lenght) / 2, y);
		shape.setSize(sf::Vector2f(newLenght, thickness));
		this->lenght = newLenght;
	}
}

BUTTON_PURPOSE Button::update(sf::Vector2f mousePos, bool mousePressed) //��������� ���������� ���� ������������ ���� � ���� ������� ��� 
{
	if (shape.getGlobalBounds().contains(mousePos)) //���� ������ ��������� ��� �������
	{
		if (mousePressed) //���� ������ ������
		{
			return purpose; //������� � ����������
		}
		if (!isMouseHoverAbove) //� ����� ��� �� ���� �����������
		{
			isMouseHoverAbove = true;

			shape.setFillColor(shapeColorOnHover); //����������� ������ ��� ���������
			text.setFillColor(textColorOnHover);
		}
	}
	else
		if (isMouseHoverAbove) //���� ������ �� ��������� ��� ������� � ����� ��� �� ���� �����������
		{
			isMouseHoverAbove = false; 
			shape.setFillColor(shapeColor); //����������� ������
			text.setFillColor(textColor);
		}
	return BUTTON_PURPOSE::nothing; //���� ������ �� ������
}