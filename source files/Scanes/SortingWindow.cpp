#include "../../header files/Scanes/SortingWindow.h"

SortingWindow::SortingWindow(unsigned arraySize) // Создание кнопки возврата в главное меню и массива линий
	:backButton(0, 0, 100, "BACK", BUTTON_PURPOSE::MAIN), lines(arraySize, true) {}

void SortingWindow::run(sf::RenderWindow& window, SortingMethod* currentSortingMethod, bool fast) 
{
	window.setTitle("Sorting in progress..."); //
	currentSortingMethod->setStartTime();
	if (fast) //Вызов метода для сортировки массива линий в зависимости от выбранного режима
		currentSortingMethod->fastUpdate(lines, window, backButton); //Каждая сортировка является дочерней классу SortigMethod и 
																	//должна переопределять функции fastUpdate и Update Для двух режимов сортировки
	else
		currentSortingMethod->update(lines, window, backButton);
	window.setTitle("SORTING IS DONE!");
	while (currentSortingMethod->isSortingDone) //Если сортировка завершена
	{
		const BUTTON_PURPOSE buttonEvent = getButtonEvent(window, backButton); //Обработка пользовательских действий (нажатия кнопки "назад" или закрытия программы на крестик)
		if (buttonEvent == BUTTON_PURPOSE::EXIT || buttonEvent == BUTTON_PURPOSE::MAIN) //Если какая-либо из вышеперечисленных кнопок нажата, выйти из функции
			return;
		draw(window); //Отрисовка элементов
	}
}
void SortingWindow::draw(sf::RenderWindow& window)
{
	window.clear(); //Очистка окна
	lines.draw(window);//Отрисовка всех линий
	backButton.draw(window); //Отрисовка кнопки "Назад"
	window.display(); //Вывод на экран
}

bool SortingWindow::update(sf::RenderWindow& window, SortingMethod*& currentSorting, bool& fast, int& currentArraySize)
{
	return false;
}

BUTTON_PURPOSE SortingWindow::getButtonEvent(sf::RenderWindow& window, Button& backButton) //Обрабока пользовательских действий
{
	sf::Event event{};
	bool mousePressed = false;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) //Закрыть окно при нажатии на крестик
		{
			window.close();
			return BUTTON_PURPOSE::EXIT;
		}
		if (event.type == sf::Event::MouseButtonPressed) //Нажата ЛКМ
			mousePressed = true;
	}
	const sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); //Получение координат мыши относительно левого верхнего угла окна программы
	return backButton.update(mousePos, mousePressed); //Возвращает BUTTON_PURPOSE::MAIN при нажатии на кнопку и BUTTON_PURPOSE::nothing, если ничего не нажато
}
