#include "../../header files/Scanes/SortingWindow.h"

SortingWindow::SortingWindow(unsigned arraySize) // �������� ������ �������� � ������� ���� � ������� �����
	:backButton(0, 0, 100, "BACK", BUTTON_PURPOSE::MAIN), lines(arraySize, true) {}

void SortingWindow::run(sf::RenderWindow& window, SortingMethod* currentSortingMethod, bool fast) 
{
	window.setTitle("Sorting in progress..."); //
	currentSortingMethod->setStartTime();
	if (fast) //����� ������ ��� ���������� ������� ����� � ����������� �� ���������� ������
		currentSortingMethod->fastUpdate(lines, window, backButton); //������ ���������� �������� �������� ������ SortigMethod � 
																	//������ �������������� ������� fastUpdate � Update ��� ���� ������� ����������
	else
		currentSortingMethod->update(lines, window, backButton);
	window.setTitle("SORTING IS DONE!");
	while (currentSortingMethod->isSortingDone) //���� ���������� ���������
	{
		const BUTTON_PURPOSE buttonEvent = getButtonEvent(window, backButton); //��������� ���������������� �������� (������� ������ "�����" ��� �������� ��������� �� �������)
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN) //���� �����-���� �� ����������������� ������ ������, ����� �� �������
			return;
		draw(window); //��������� ���������
	}
}
void SortingWindow::draw(sf::RenderWindow& window)
{
	window.clear(); //������� ����
	lines.draw(window);//��������� ���� �����
	backButton.draw(window); //��������� ������ "�����"
	window.display(); //����� �� �����
}

bool SortingWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
{
	return false;
}

BUTTON_PURPOSE SortingWindow::getButtonEvent(sf::RenderWindow& window, Button& backButton) //�������� ���������������� ��������
{
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) //������� ���� ��� ������� �� �������
		{
			window.close();
			return BUTTON_PURPOSE::EXIT;
		}
		if (event.type == sf::Event::MouseButtonPressed) //������ ���
			mousePressed = true;
	}
	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //��������� ��������� ���� ������������ ������ �������� ���� ���� ���������
	return backButton.update(mousePos, mousePressed); //���������� BUTTON_PURPOSE::MAIN ��� ������� �� ������ � BUTTON_PURPOSE::nothing, ���� ������ �� ������
}
