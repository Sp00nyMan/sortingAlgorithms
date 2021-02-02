#include "SFML/Graphics/RenderWindow.hpp"
#include <iostream>
#include "../header files/Scanes/MainWindow.h"
#include "../header files/Constants.h"
#include "../header files/Sortings/Bubble.h"
#include <Windows.h>


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Сокрытие консоли
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NOTHING"); //Создаётся окно программы
	window.setPosition(sf::Vector2i(window.getPosition().x, window.getPosition().y - 50)); //Окно смещается на 50 пикселей влево (эстетика)
	//Подгрузка иконки приложения (для отображения в углу окна)
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

	MainWindow Main(WIDTH, HEIGHT); // Создание главного меню

	///////////////////// Стартовые параметры
	bool doFastSorting = false;  // Быстрый режим отрисовки сортировки
	int arraySize = 500; // Размер массива для сортировки
	SortingMethod* currentSorting = new Bubble(0); // Вид сортировки
	/////////////////////

	while (Main.update(window, currentSorting, doFastSorting, arraySize)); // Пока открыто окно программа продолжает работу
}
