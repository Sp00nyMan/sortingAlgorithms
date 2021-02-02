#pragma once
#include <chrono>
#include <string>
#include "../Lines.h"
#include "../Widgets/Button.h"


class SortingMethod
{
	std::chrono::time_point<std::chrono::system_clock> startTime;

public:
	bool isSortingDone;
	unsigned index;
	std::string name;
	virtual Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0; //Отрисовка после каждой перестановки
	virtual Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0; //Отрисовка после каждого прохода по массиву

	unsigned timeElapsed() const { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - this->startTime).count(); }; //Вернуть время с начала сортировки в миллисекундах
	void setStartTime() { this->startTime = std::chrono::system_clock::now(); }; //Сохранить время начала сортировки
	static void draw(sf::RenderWindow& window, Lines& lines, Button& backButton); //Отрисовка линий lines и кнопки backButton на окне window
};
