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
	virtual Lines update(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0; //��������� ����� ������ ������������
	virtual Lines fastUpdate(Lines& lines, sf::RenderWindow& window, Button& backButton) = 0; //��������� ����� ������� ������� �� �������

	unsigned timeElapsed() const { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - this->startTime).count(); }; //������� ����� � ������ ���������� � �������������
	void setStartTime() { this->startTime = std::chrono::system_clock::now(); }; //��������� ����� ������ ����������
	static void draw(sf::RenderWindow& window, Lines& lines, Button& backButton); //��������� ����� lines � ������ backButton �� ���� window
};
