#include <iostream>
#include "../../header files/Widgets/ValueChanger.h"
#include "../../header files/Constants.h"

ValueChanger::ValueChanger()
	:value(200), minValue(1), maxValue(1200)
{
}

ValueChanger::ValueChanger(float x, float y, int currentValue, int minValue, int maxValue)
	: value(currentValue), minValue(minValue), maxValue(maxValue)
{
	if (currentValue > maxValue)
		value = maxValue;
	if (currentValue < minValue)
		value = minValue;
	const float buttonsLenght = WIDTH / 16;
	const float distBetweenElements = buttonsLenght / 10;
	const float displayLenght = WIDTH / 10;
	const float buttonHeight = displayLenght / 3;
	bigMinus = new Button(x, y, buttonsLenght, "-100", BUTTON_PURPOSE::doSomething, buttonHeight); //Кнопка "-100"

	Minus = new Button(x + bigMinus->Lenght() + distBetweenElements, y, buttonsLenght, "-20", BUTTON_PURPOSE::doSomething, buttonHeight); //Кнопка "-20"

	display = new Display(std::to_string(value), Minus->X() + Minus->Lenght() + distBetweenElements, y, displayLenght); //Дисплей для отображение текущего значения

	Plus = new Button(display->X() + display->Lenght() + distBetweenElements, y, buttonsLenght, "+20", BUTTON_PURPOSE::doSomething, buttonHeight); //Кнопка "+100"

	bigPlus = new Button(Plus->X() + Plus->Lenght() + distBetweenElements, y, buttonsLenght, "+100", BUTTON_PURPOSE::doSomething, buttonHeight);//Кнопка "+20"
}

void ValueChanger::draw(sf::RenderWindow& window) const //Отрисовка на окне window
{
	bigMinus->draw(window);
	Minus->draw(window);
	display->draw(window);
	Plus->draw(window);
	bigPlus->draw(window);
}

int ValueChanger::update(sf::Vector2f mousePos, bool mousePressed)
{
	if (value > maxValue)
		value = maxValue;
	if (bigMinus->update(mousePos, mousePressed) == BUTTON_PURPOSE::doSomething && value >= minValue + 100) //Если нажата кнопка "-100" и это не приведёт к выходу за пределы допустимых значений
	{
		value -= 100; //Уменьшаем значение на 100
	}
	if (Minus->update(mousePos, mousePressed) == BUTTON_PURPOSE::doSomething && value >= minValue + 20) //Если нажата кнопка "-20" и это не приведёт к выходу за пределы допустимых значений
	{
		value -= 20; //Уменьшаем значение на 20
	}
	if (Plus->update(mousePos, mousePressed) == BUTTON_PURPOSE::doSomething && value <= maxValue - 20) //Если нажата кнопка "+20" и это не приведёт к выходу за пределы допустимых значений
	{
		value += 20;//Увеличиваем значение на 20
	}
	if (bigPlus->update(mousePos, mousePressed) == BUTTON_PURPOSE::doSomething && value <= maxValue - 100) //Если нажата кнопка "+100" и это не приведёт к выходу за пределы допустимых значений
		value += 100; //Увеличиваем значение на 100

	display->update(std::to_string(value)); //Обновление значения на дисплее
	return value;
}

void ValueChanger::setMaxValue(int maxV)
{
	if (maxV >= minValue)
		maxValue = maxV;
	else
	{
		throw std::exception("Max value can't be less than min value");
	}
}

ValueChanger::~ValueChanger()
{
	delete bigMinus;
	bigMinus = nullptr;
	delete Minus;
	Minus = nullptr;
	delete Plus;
	Plus = nullptr;
	delete bigPlus;
	bigPlus = nullptr;
	delete display;
	display = nullptr;
}
