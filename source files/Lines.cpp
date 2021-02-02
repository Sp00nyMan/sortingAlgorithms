#include "../header files/Lines.h"

Lines::Lines() //�������� ������� ������� �����
{
	lines.clear();
	arraySize = 0;
	distanceBetweenLines = WIDTH;
	lineThickness = WIDTH;
}

void Lines::push_back(const Line& line) //���������� ����� ����� � ������
{
	arraySize++;
	lines.push_back(line);
}

Lines::Lines(unsigned arraySize, bool smooth)//�������� ������� ����� �������� arraySize. �������� smooth �������� �� ����������� ���������. 
											//���� �� ����� false, �� ����� ������������ ��������� ������. 
											//�����, ����� ������������ � ����������� ����� � ������������� � ��������� ������� �� ����
{
	this->arraySize = arraySize;
	this->lineThickness = WIDTH / float(arraySize);
	this->distanceBetweenLines = lineThickness * lineThickness / WIDTH;
	this->lineThickness -= this->distanceBetweenLines;
	if (!smooth)
	{
		const unsigned seed = time(nullptr); //���������� seed ���������� ��������������� �����
		srand(seed);
		//���������� ������ ����� ������� lineThickness ��������� ������ � �������� ������ ���� ����� ������ (lineThickness + distanceBetweenLines) �������� 
		for (int i = 0; i < arraySize; i++)
		{
			this->lines.emplace_back(float(i) * (lineThickness + distanceBetweenLines), float(rand() % HEIGHT), lineThickness);
		}
	}
	else
	{
		float step = float(HEIGHT) / arraySize; //������� ����� �������� �������� ����� � ��������������� �������
		//�������� ������� ���� � �������� ������ ���� � ����� step ��� �������������� ����������
		std::vector<float> randLenghts;
		for (size_t i = 0; i < arraySize; i++)
		{
			randLenghts.push_back(HEIGHT - step * i);
		}
		unsigned randElem;
		for (int i = 0; i < arraySize; i++)
		{
			randElem = rand() % (arraySize - i); //���������� ��������� ������� �� ������� ����
			this->lines.emplace_back(float(i) * (lineThickness + distanceBetweenLines), randLenghts[randElem], lineThickness); //�������� ������� �����
			randLenghts.erase(randLenghts.begin() + randElem); //�������� �������������� ������ �� ������� ��� �������������� ����������
		}
	}
}

void Lines::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < arraySize; i++) //��������� �� ���� window ���� ����� �������
	{
		lines[i].draw(window);
	}
}

void Lines::swap(unsigned indexOfFirst, unsigned indexOfSecond) //�������� ������� indexOfFirst � indexOfSecond ����� � ������� 
{
	try
	{
		lines[indexOfFirst].swap(lines[indexOfSecond]); //�������� ������� ���������� ����� � ����������� � ������
	}
	catch (...)
	{
		throw;
	}

	const Line temp = lines[indexOfFirst]; //�������� ������� ������� ����� � ������� 
	lines[indexOfFirst] = lines[indexOfSecond];
	lines[indexOfSecond] = temp;
}

void Lines::swap(unsigned indexOfFirst, Line other) //�������� ������� indexOfFirst � ����� other
{
	try
	{
		lines[indexOfFirst].swap(other); //�������� ������� ���������� �����
	}
	catch (...)
	{
		throw;
	}

	lines[indexOfFirst] = other; //��������� ������� indexOfFirst ������� ��� �������������� ����� other
}

void Lines::swap(unsigned indexOfFirst, unsigned indexOfSecond, sf::Color newColor) //�������� ������� indexOfFirst � indexOfSecond ����� � ������� � ����������� �� � ���� newColor
{
	lines[indexOfFirst].swap(lines[indexOfSecond], newColor);

	const Line temp = lines[indexOfFirst];
	lines[indexOfFirst] = lines[indexOfSecond];
	lines[indexOfSecond] = temp;
}

void Lines::resetColor() //������� ���� ������ �� ����������� �����
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

