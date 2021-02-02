#include <iostream>
#include "../../header files/Scanes/MainWindow.h"
#include "../../header files/Scanes/SortingWindow.h"
#include "../../header files/Scanes/SettingsWindow.h"

MainWindow::MainWindow(unsigned width, unsigned height) // �������� ���������� �������� ���� �� ���� ���������
{
	float lenght = width / 3.2;
	float xPos = (width - lenght) / 2.0f;
	const int buttonCount = 3;
	buttons.push_back(new Button(xPos, height / (buttonCount * 2), lenght, "START", BUTTON_PURPOSE::START)); // ������ ����������
	buttons.push_back(new Button(xPos, buttons[0]->Y() + lenght / 2 + height / 20, lenght, "SETTINGS", BUTTON_PURPOSE::SETTINGS)); // ���� ��������
	buttons.push_back(new Button(xPos, buttons[1]->Y() + lenght / 2 + height / 20, lenght, "EXIT", BUTTON_PURPOSE::EXIT)); // ����� �� ���������
	for (size_t i = 0; i < buttonCount; i++) // ��������� ������ ������ � ����������� �� ������ ����
	{
		buttons[i]->setLenght(width / 2.286);
	}
}

bool MainWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
{
	window.setTitle("MAIN MENU"); // ��������� ���� ���������
	draw(window);
	//////////////// ��������� ���������������� ��������
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) // ����� �������
		{
			window.close();
			return window.isOpen();
		}
		if (event.type == sf::Event::MouseButtonPressed) // ������ ���
			mousePressed = true;
	}

	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //��������� ��������� ���� ������������ ���� ���������
	BUTTON_PURPOSE buttonEvent = BUTTON_PURPOSE::nothing;
	for (int i = 0; i < buttons.size(); i++)
	{
		buttonEvent = buttons[i]->update(mousePos, mousePressed); // ��������� ��������� �� ������ � ������� �� �
		if (buttonEvent != BUTTON_PURPOSE::nothing)
			break;
	}
	switch (buttonEvent)
	{
	case BUTTON_PURPOSE::EXIT: // ���� ������ ������ "Exit" ������� ����
		window.close();
		break;
	case BUTTON_PURPOSE::START: // ���� ������ ������ "Start"
		SortingWindow(currentArraySize).run(window, currentSorting, fast); //�������� ���� ���������� � ������ ��������� ���������� currentSorting ������� currentArraySize � ������ fast
		break;
	case BUTTON_PURPOSE::SETTINGS: // ���� ������ ������ "Settings"
		SettingsWindow settings(currentArraySize, fast, currentSorting); // �������� ���� ��������
		while (settings.update(window, currentSorting, fast, currentArraySize)); //���������� ���������� currentSorting, fast, currentArraySize ������ ���� ��������
		break;
	}
	return window.isOpen(); //���������� true, ���� ���� �������
}

void MainWindow::draw(sf::RenderWindow& window) //��������� ��������� �������� ����
{
	window.clear(bgColor); //������� ����
	for (int i = 0; i < buttons.size(); i++) // ��������� ������
	{
		buttons[i]->draw(window);
	}
	window.display(); //����� ����������� ����
}

MainWindow::~MainWindow()
{
	for (int i = 0; i < buttons.size(); i++) //�������� ���������� �� ������
	{
		delete buttons[i];
	}
	buttons.clear();
}
