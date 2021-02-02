#include <iostream>
#include "../../header files/Scanes/SettingsWindow.h"

SettingsWindow::SettingsWindow(int currentArraySize, bool isFast, SortingMethod* currentSorting, unsigned width, unsigned height) // �������� ���������� �������� ���� �� ���� ���������
	:arraySizeChanger(width / 3.2, height/ 1.48, currentArraySize, 20, isFast ? 1200 : 500)
{
	backButton = new Button(width / 2.91, height / 1.3333, width / 3.2, "BACK", BUTTON_PURPOSE::MAIN); //�������� ������ �������� � ������� ����
	fast = new CheckBox(500, 30, "FAST", isFast); //�������� ���-����� ��� ������ ������� ����������
	for (size_t i = 0; i < avalibleSortings.size(); i++) //�������� ���-������ ��� ������� ���� ���������� �� ���������� i * (height / 40 + CheckBox::size) ���� �� �����
	{
		sortings.push_back(new CheckBox(width / 53.33, height / 26.667  + i * (height / 40 + CheckBox::size), avalibleSortings[i]->name, false));
	}
	sortings.setCurrent(currentSorting->index); //���-���� ��� ���������� ������ ���������� ����������
}

void SettingsWindow::draw(sf::RenderWindow& window) //��������� ��������� ���� ��������
{
	backButton->draw(window);
	fast->draw(window);
	sortings.draw(window);
	arraySizeChanger.draw(window);
}

bool SettingsWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
//���������� ���������� currentSorting, fast, currentArraySize � ����������� �� �������� ������������
{
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event)) //��������� ���������������� ��������
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			mousePressed = true;
			break;
		}
	}

	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //��������� ��������� ���� ������������ ����
	if (backButton->update(mousePos, mousePressed) == BUTTON_PURPOSE::MAIN) //���� ������ ������ "�����" ����� ��������� � ������� ����
		return false;
	currentArraySize = arraySizeChanger.update(mousePos, mousePressed); //���������� ����������� �������

	if (mousePressed)
	{
		fast = this->fast->update(mousePos, mousePressed); //����� ������ ����������
		if (fast) //���� ������ ��������� ����� ����������, �� ��������� ������������ ������ ������� �� 500
			arraySizeChanger.setMaxValue(1200);
		else
			arraySizeChanger.setMaxValue(500);
		const unsigned chosenSort = sortings.update(mousePos, mousePressed); //����� ���� ����������
		if (chosenSort != currentSorting->index)
		{
			currentSorting = avalibleSortings[chosenSort];
		}
	}
	window.clear(bgColor);
	draw(window);
	window.display();
	return true;
}

SettingsWindow::~SettingsWindow()
{
	delete backButton;
	delete fast;
	backButton = nullptr;
	fast = nullptr;
}
