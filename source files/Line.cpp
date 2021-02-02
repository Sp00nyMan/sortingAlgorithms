#include "../header files/Line.h"
////////Получение цвета в зависимости от длины линии
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

Line::Line(float x, float lenght, float thickness) //Создание линии длины lenght и толщины thickness с началом в точке (x, HEIGHT)
	:x(x), lenght(lenght), thickness(thickness), color(getGradientR(lenght), getGradientG(lenght), getGradientB(lenght))
{
	shape.setFillColor(color);
	shape.setPosition(x, HEIGHT);
	shape.setSize(sf::Vector2f(thickness + 1, -lenght));
}

Line::Line(const Line& other) //Создание копии линии other
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

void Line::draw(sf::RenderWindow& window) const //Отрисовка линии на окне window
{
	window.draw(shape);
}

void Line::moveTo(float newX) //Передвинуть линии в точку (newX, HEIGHT)
{
	x = newX;
	shape.setPosition(sf::Vector2f(x, HEIGHT));
}

void Line::swap(Line& other) noexcept //Поменять координаты данной линии и линии other местами и перекрасить их в зелёный цвет
{
	float buffer = x;
	moveTo(other.X());
	other.moveTo(buffer);

	//Repainting
	repaint(0, 255, 0);
	other.repaint(0, 255, 0);
}

void Line::swap(Line& other, sf::Color newColor) noexcept //Поменять координаты данной линии и линии other местами и перекрасить их в цвет newColor
{
	float buffer = x;
	moveTo(other.X());
	other.moveTo(buffer);

	//Repainting
	repaint(newColor);
	other.repaint(newColor);
}

void Line::repaint(float r, float g, float b) //Перекрасить линию
{
	shape.setFillColor(sf::Color(r, g, b));
}

void Line::repaint(sf::Color newColor) //Перекрасить линию
{
	shape.setFillColor(newColor);
}

Line& Line::operator=(Line other) //Приравнять линию к линии other
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

void Line::setThickness(float newT) //Изменить толщину линии
{
	this->thickness = newT;
	shape.setSize(sf::Vector2f(newT, -lenght));
}
