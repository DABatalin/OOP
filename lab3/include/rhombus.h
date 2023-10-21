#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#include "figure.h"


class Rhombus : public Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Rhombus& p);
	friend std::istream& operator>>(std::istream& is, Rhombus& p);
public:
	// Constructors
	Rhombus();
	Rhombus(std::vector<std::pair<double, double>>& points);
    virtual ~Rhombus();


	// Getters
	std::vector<std::pair<double, double>> get_points() const {
		return _points;
	}

	std::pair<double, double> get_middle_point() const override {
		return _middle_point;
	}

	double get_area() const override {
		return _area;
	}

	// Standard operators
	bool operator==(const Rhombus &other) const;
	Rhombus& operator=(const Rhombus &other);
	Rhombus& operator=(Rhombus &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;

private:
	std::vector<std::pair<double, double>> _points;
	std::pair<double, double> _middle_point;
	double _area = 0;
	unsigned int n = 4; // Количество вершин 

	bool is_equal(double x, double y) {
    	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
	}
};

inline std::ostream& operator<<(std::ostream& os, const Rhombus& p)
{
    std::vector<std::pair<double, double>> points = p.get_points();
	os << "Точки: " << std::endl;
    for (int i = 0; i != 4; ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << points[i].first << ", "
           << "y" << " = " << points[i].second << "];" << std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Rhombus& p)
{
    std::vector<std::pair<double, double>> v(4);

    for (int i = 0; i < 4; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Rhombus(v);

    return is;
}
#endif