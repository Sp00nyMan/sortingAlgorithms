#include "../header files/Line.h"
////////��������� ����� � ����������� �� ����� �����
float Line::getGradientR(float lenght)
{
	return lenght * STEP;
}
float Line::getGradientG(float lenght)
{
	return abs(float(255) / 2 - lenght * STEP);
}
float Line::getGradientB(float lenght)
{
	return 255 - lenght * STEP;
}
///////////

Line::Line(float x, float lenght, float thickness) //�������� ����� ����� lenght � ������� thickness � ������� � ����� (x, HEIGHT)
	:x(x), lenght(lenght), thickness(thickness), color(getGradientR(lenght), getGradientG(lenght), getGradientB(lenght))
{
	shape.setFillColor(color);
	shape.setPosition(x, HEIGHT);
	shape.setSize(sf::Vector2f(thickness + 1, -lenght));
}

Line::Line(const Line& other) //�������� ����� ����� other
	:x(other.x), lenght(other.lenght), thickness(other.thickness), color(other.color)
{
	this->shape.setFillColor(other.shape.getFillColor());
	this->shape.setPosition(x, HEIGHT);
	this->shape.setSize(sf::Vector2f(other.thickness, -other.lenght));
}

Line::Line(Line&& other) noexcept
	:x(other.x), lenght(other.lenght), thickness(other.thickness), color(other.color)
{
	this->shape.setFillColor(other.color);
	this->shape.setPosition(x, HEIGHT);
	this->shape.setSize(sf::Vector2f(other.thickness, -other.lenght));
	other.x = 0;
	other.lenght = 0;
	other.thickness = 0;
}

void Line::draw(sf::RenderWindow& window) const //��������� ����� �� ���� window
{
	window.draw(shape);
}

void Line::moveTo(float newX) //����������� ����� � ����� (newX, HEIGHT)
{
	x = newX;
	shape.setPosition(sf::Vector2f(x, HEIGHT));
}

void Line::swap(Line& other) noexcept //�������� ���������� ������ ����� � ����� other ������� � ����������� �� � ������ ����
{
	float buffer = x;
	moveTo(other.X());
	other.moveTo(buffer);

	//Repainting
	repaint(0, 255, 0);
	other.repaint(0, 255, 0);
}

void Line::swap(Line& other, sf::Color newColor) noexcept //�������� ���������� ������ ����� � ����� other ������� � ����������� �� � ���� newColor
{
	float buffer = x;
	moveTo(other.X());
	other.moveTo(buffer);

	//Repainting
	repaint(newColor);
	other.repaint(newColor);
}

void Line::repaint(float r, float g, float b) //����������� �����
{
	shape.setFillColor(sf::Color(r, g, b));
}

void Line::repaint(sf::Color newColor) //����������� �����
{
	shape.setFillColor(newColor);
}

Line& Line::operator=(Line other) //���������� ����� � ����� other
{
	x = other.x;
	lenght = other.lenght;
	thickness = other.thickness;
	shape = sf::RectangleShape(other.shape);
	this->color = other.color;
	return *this;
}

bool Line::operator<(const Line& other) const
{
	return lenght < other.lenght;
}

bool Line::operator>(const Line& other) const
{
	return lenght > other.lenght;
}

bool Line::operator<=(const Line& other) const
{
	return lenght <= other.lenght;
}

void Line::setThickness(float newT) //�������� ������� �����
{
	this->thickness = newT;
	shape.setSize(sf::Vector2f(newT, -lenght));
}
