#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include "../header files/Scanes/MainWindow.h"
#include "../header files/Constants.h"
#include "../header files/Sortings/Bubble.h"
#include <Windows.h>


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); //�������� �������
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NOTHING"); //�������� ���� ���������
	window.setPosition(sf::Vector2i(window.getPosition().x, window.getPosition().y - 50)); //���� ��������� �� 50 �������� ����� (��������)
	//��������� ������ ���������� (��� ����������� � ���� ����)
	try
	{
		sf::Image icon;
		if (!icon.loadFromFile("resources/icon256.png"))
			throw 1;
		window.setIcon(256, 256, icon.getPixelsPtr());
	}
	catch (...)
	{
		std::cout << "Icon loading trouble" << std::endl;
	}

	MainWindow Main(WIDTH, HEIGHT); // �������� �������� ����

	///////////////////// ��������� ���������
	bool doFastSorting = false;  // ������� ����� ��������� ����������
	int arraySize = 500; // ������ ������� ��� ����������
	SortingMethod* currentSorting = new Bubble(0); // ��� ����������
	/////////////////////

	while (Main.update(window, currentSorting, doFastSorting, arraySize)); // ���� ������� ���� ��������� ���������� ������
}
