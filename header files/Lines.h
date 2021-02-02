#pragma once
#include "Line.h"

class Lines
{
	std::vector<Line> lines;
	unsigned arraySize;
	float distanceBetweenLines;
	float lineThickness;
public:
	Lines();
	Lines(unsigned arraySize, bool smooth = true);
	void draw(sf::RenderWindow& window) const;
	void swap(unsigned indexOfFirst, unsigned indexOfSecond);
	void swap(unsigned indexOfFirst, Line other);
	void swap(unsigned indexOfFirst, unsigned indexOfSecond, sf::Color newColor);
	unsigned Size() const { return this->arraySize; }
	void push_back(const Line& line);
	void resetColor();
	Line& operator[](size_t index);

	~Lines() = default;
};


