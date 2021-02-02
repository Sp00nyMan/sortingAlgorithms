#include "../header files/Lines.h"

Lines::Lines() //Создание пустого массива линий
{
	lines.clear();
	arraySize = 0;
	distanceBetweenLines = WIDTH;
	lineThickness = WIDTH;
}

void Lines::push_back(const Line& line) //Добавление новой линии в массив
{
	arraySize++;
	lines.push_back(line);
}

Lines::Lines(unsigned arraySize, bool smooth)//Создание массива линий размером arraySize. Параметр smooth отвечает за сглаживание генерации. 
											//Если он равен false, то линии генерируются случайной длинны. 
											//Иначе, линии генерируются с определённым шагом и расставляются в случайном порядке на окне
{
	this->arraySize = arraySize;
	this->lineThickness = WIDTH / float(arraySize);
	this->distanceBetweenLines = lineThickness * lineThickness / WIDTH;
	this->lineThickness -= this->distanceBetweenLines;
	if (!smooth)
	{
		const unsigned seed = time(nullptr); //Записываем seed генератора псевдослучайных чисел
		srand(seed);
		//Генерируем массив линий толщины lineThickness случайной длинны в пределах высоты окна через каждые (lineThickness + distanceBetweenLines) пикселей 
		for (int i = 0; i < arraySize; i++)
		{
			this->lines.emplace_back(float(i) * (lineThickness + distanceBetweenLines), float(rand() % HEIGHT), lineThickness);
		}
	}
	else
	{
		float step = float(HEIGHT) / arraySize; //Разница между длиннами соседних линий в отсортированном массиве
		//Создание массива длин в пределах высоты окна с шагом step для предотвращения повторений
		std::vector<float> randLenghts;
		for (size_t i = 0; i < arraySize; i++)
		{
			randLenghts.push_back(HEIGHT - step * i);
		}
		unsigned randElem;
		for (int i = 0; i < arraySize; i++)
		{
			randElem = rand() % (arraySize - i); //Выбирается случайный элемент из массива длин
			this->lines.emplace_back(float(i) * (lineThickness + distanceBetweenLines), randLenghts[randElem], lineThickness); //Создание объекта линии
			randLenghts.erase(randLenghts.begin() + randElem); //Удаление использованной длинны из массива для предотвращения повторений
		}
	}
}

void Lines::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < arraySize; i++) //Отрисовка на окне window всех линий массива
	{
		lines[i].draw(window);
	}
}

void Lines::swap(unsigned indexOfFirst, unsigned indexOfSecond) //Поменять местами indexOfFirst и indexOfSecond линии в массиве 
{
	try
	{
		lines[indexOfFirst].swap(lines[indexOfSecond]); //Поменять местами координаты линий и перекрасить в зелёный
	}
	catch (...)
	{
		throw;
	}

	const Line temp = lines[indexOfFirst]; //Поменять местами объекты линий в массиве 
	lines[indexOfFirst] = lines[indexOfSecond];
	lines[indexOfSecond] = temp;
}

void Lines::swap(unsigned indexOfFirst, Line other) //Поменять местами indexOfFirst и линию other
{
	try
	{
		lines[indexOfFirst].swap(other); //Поменять местами координаты линий
	}
	catch (...)
	{
		throw;
	}

	lines[indexOfFirst] = other; //Присвоить объекту indexOfFirst массива все характеристики линии other
}

void Lines::swap(unsigned indexOfFirst, unsigned indexOfSecond, sf::Color newColor) //Поменять местами indexOfFirst и indexOfSecond линии в массиве и перекрасить их в цвет newColor
{
	lines[indexOfFirst].swap(lines[indexOfSecond], newColor);

	const Line temp = lines[indexOfFirst];
	lines[indexOfFirst] = lines[indexOfSecond];
	lines[indexOfSecond] = temp;
}

void Lines::resetColor() //Вернуть всем линиям их изначальные цвета
{
	for (int i = 0; i < arraySize; i++)
	{
		lines[i].repaint(lines[i].Color());
	}
}

Line& Lines::operator[](size_t index)
{
	if (index < 0 || index >= lines.size())
	{
		std::string msg = "Index" + std::to_string(index) + " is out of range";
		throw std::exception(msg.c_str());
	}
	return lines[index];
}

