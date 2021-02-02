#include <iostream>
#include "../../header files/Scanes/MainWindow.h"
#include "../../header files/Scanes/SortingWindow.h"
#include "../../header files/Scanes/SettingsWindow.h"

MainWindow::MainWindow(unsigned width, unsigned height) // Создание интерфейса главного меню на окне программы
{
	float lenght = width / 3.2;
	float xPos = (width - lenght) / 2.0f;
	const int buttonCount = 3;
	buttons.push_back(new Button(xPos, height / (buttonCount * 2), lenght, "START", BUTTON_PURPOSE::START)); // Начало сортировки
	buttons.push_back(new Button(xPos, buttons[0]->Y() + lenght / 2 + height / 20, lenght, "SETTINGS", BUTTON_PURPOSE::SETTINGS)); // Окно настроек
	buttons.push_back(new Button(xPos, buttons[1]->Y() + lenght / 2 + height / 20, lenght, "EXIT", BUTTON_PURPOSE::EXIT)); // Выход из программы
	for (size_t i = 0; i < buttonCount; i++) // Коррекция длинны кнопок в зависимости от ширины окна
	{
		buttons[i]->setLenght(width / 2.286);
	}
}

bool MainWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
{
	window.setTitle("MAIN MENU"); // Заголовок окна программы
	draw(window);
	//////////////// Обработка пользовательских действий
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) // Нажат крестик
		{
			window.close();
			return window.isOpen();
		}
		if (event.type == sf::Event::MouseButtonPressed) // Нажата ЛКМ
			mousePressed = true;
	}

	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //Получение координат мыши относительно окна программы
	BUTTON_PURPOSE buttonEvent = BUTTON_PURPOSE::nothing;
	for (int i = 0; i < buttons.size(); i++)
	{
		buttonEvent = buttons[i]->update(mousePos, mousePressed); // Обработка наведения на кнопку и нажатия на нёё
		if (buttonEvent != BUTTON_PURPOSE::nothing)
			break;
	}
	switch (buttonEvent)
	{
	case BUTTON_PURPOSE::EXIT: // Если нажата кнопка "Exit" закрыть окно
		window.close();
		break;
	case BUTTON_PURPOSE::START: // Если нажата кнопка "Start"
		SortingWindow(currentArraySize).run(window, currentSorting, fast); //Создание окна сортировки и начало выбранной сортировки currentSorting размера currentArraySize в режиме fast
		break;
	case BUTTON_PURPOSE::SETTINGS: // Если нажата кнопка "Settings"
		SettingsWindow settings(currentArraySize, fast, currentSorting); // Создание окна настроек
		while (settings.update(window, currentSorting, fast, currentArraySize)); //Обновление параметров currentSorting, fast, currentArraySize внутри окна настроек
		break;
	}
	return window.isOpen(); //Возвращает true, если окно открыто
}

void MainWindow::draw(sf::RenderWindow& window) //Отрисовка элементов главного меню
{
	window.clear(bgColor); //Очистка окна
	for (int i = 0; i < buttons.size(); i++) // отрисовка кнопок
	{
		buttons[i]->draw(window);
	}
	window.display(); //Вывод обновлённого окна
}

MainWindow::~MainWindow()
{
	for (int i = 0; i < buttons.size(); i++) //Удаление указателей на кнопки
	{
		delete buttons[i];
	}
	buttons.clear();
}
