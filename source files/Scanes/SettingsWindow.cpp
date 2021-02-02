#include <iostream>
#include "../../header files/Scanes/SettingsWindow.h"

SettingsWindow::SettingsWindow(int currentArraySize, bool isFast, SortingMethod* currentSorting, unsigned width, unsigned height) // Создание интерфейса главного меню на окне программы
	:arraySizeChanger(width / 3.2, height/ 1.48, currentArraySize, 20, isFast ? 1200 : 500)
{
	backButton = new Button(width / 2.91, height / 1.3333, width / 3.2, "BACK", BUTTON_PURPOSE::MAIN); //Создание кнопки возврата в главное меню
	fast = new CheckBox(500, 30, "FAST", isFast); //Создание чек-бокса для режима быстрой сортировки
	for (size_t i = 0; i < avalibleSortings.size(); i++) //Создание чек-боксов для каждого вида сортировки на расстоянии i * (height / 40 + CheckBox::size) друг от друга
	{
		sortings.push_back(new CheckBox(width / 53.33, height / 26.667  + i * (height / 40 + CheckBox::size), avalibleSortings[i]->name, false));
	}
	sortings.setCurrent(currentSorting->index); //Чек-бокс для выбранного метода сортировки отмечается
}

void SettingsWindow::draw(sf::RenderWindow& window) //Отрисовка элементов окна настроек
{
	backButton->draw(window);
	fast->draw(window);
	sortings.draw(window);
	arraySizeChanger.draw(window);
}

bool SettingsWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
//Обновление параметров currentSorting, fast, currentArraySize в зависимости от действий пользователя
{
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event)) //Обработка пользовательских действий
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

	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //Получение координат мыши относительно окна
	if (backButton->update(mousePos, mousePressed) == BUTTON_PURPOSE::MAIN) //Если нажата кнопка "Назад" выйти вернуться в главное меню
		return false;
	currentArraySize = arraySizeChanger.update(mousePos, mousePressed); //Обновление размерности массива

	if (mousePressed)
	{
		fast = this->fast->update(mousePos, mousePressed); //Выбор режима сортировки
		if (fast) //Если выбран медленный режим сортировки, то ограничим максимальный размер массива до 500
			arraySizeChanger.setMaxValue(1200);
		else
			arraySizeChanger.setMaxValue(500);
		const unsigned chosenSort = sortings.update(mousePos, mousePressed); //Выбор вида сортировки
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
