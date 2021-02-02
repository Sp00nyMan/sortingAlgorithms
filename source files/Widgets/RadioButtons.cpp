#include <SFML/Window/Event.hpp>
#include <iostream>
#include <cassert>
#include "../../header files/Widgets/RadioButtons.h"

RadioButtons::RadioButtons()
	:current(0)
{
}

void RadioButtons::push_back(CheckBox* newButton) //Добавить новый чек-бокс
{
	buttons.push_back(newButton);
}

void RadioButtons::push_back(const std::string& string, bool checked) //Создать новый чек-бокс
{
	this->buttons.push_back(new CheckBox(buttons[Size()]->X(), buttons[Size()]->Y() + 2 * CheckBox::size, string, checked));
}

void RadioButtons::setCurrent(unsigned index) //Отметить чек-бокс index
{
	if (index >= buttons.size() || index < 0)
	{
		const std::string msg = "Index " + std::to_string(index) + " is out of range";
		throw std::exception(msg.c_str());
	}
	current = index;
	buttons[current]->check();
}

void RadioButtons::draw(sf::RenderWindow& window) //Отрисовка всех чек-боксов на окне window 
{
	for (unsigned i = 0; i < Size(); i++)
	{
		buttons[i]->draw(window);
	}
}

unsigned RadioButtons::update(sf::Vector2f mousePos, bool mousePressed)
{
	for (unsigned int i = 0; i < Size(); i++)
	{
		if (i != current && buttons[i]->update(mousePos, mousePressed)) //Если пользователем отмечен чек-бокс и он не был отмечен ранее 
		{
			buttons[current]->check(); //Снимаем отметку с ранее отмеченного чек-бокса
			current = i;
			return current;
		}
	}
	return current;
}

RadioButtons::~RadioButtons()
{
	for (size_t i = 0; i < this->buttons.size(); i++)
	{
		delete buttons[i];
	}
	buttons.clear();
}

