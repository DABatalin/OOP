#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include <vector>

// Будем считать, что вершины фигуры подаются на вход по или против часовой стрелки
class Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Figure& p);
	friend std::ostream& operator>>(std::istream& is, Figure& p);

protected:
	// Конструктор базового класса Figure сделан protected, чтобы его нельзя было вызвать извне класса.
	Figure() {}
public:
	
    virtual ~Figure() = default;

	// = 0 говорит, что фукнция чисто виртуальная и в каждом унаследованном классе она должна
	// быть реализована
	virtual std::pair<double, double> get_middle_point() const = 0;

    virtual double get_area() const = 0;

	virtual explicit operator double() const = 0;

private:
	std::vector<std::pair<double, double>> _points;
	std::pair<double, double> _middle_point;
	double _area = 0.0;
	unsigned int n = 0; // количество вершин 
};
#endif