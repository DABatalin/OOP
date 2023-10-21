#ifndef HEXAGON_H
#define HEXAGON_H
#include <string>
#include <iostream>
#include <vector>

#include "figure.h"


class Hexagon : public Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Hexagon& p);
	friend std::istream& operator>>(std::istream& is, Hexagon& p);
public:
	// Constructors
	Hexagon();
	Hexagon(std::vector<std::pair<double, double>>& points);
    virtual ~Hexagon();


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
	bool operator==(const Hexagon &other) const;
	Hexagon& operator=(const Hexagon &other);
	Hexagon& operator=(Hexagon &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;

private:
	std::vector<std::pair<double, double>> _points;
	std::pair<double, double> _middle_point;
	double _area = 0;
	unsigned int n = 6; // Количество вершин 
};

inline std::ostream& operator<<(std::ostream& os, const Hexagon& p)
{
    std::vector<std::pair<double, double>> points = p.get_points();
	os << "Точки: " << std::endl;
    for (int i = 0; i != 6; ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << points[i].first << ", "
           << "y" << " = " << points[i].second << "];" << std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Hexagon& p)
{
    std::vector<std::pair<double, double>> v(6);

    for (int i = 0; i < 6; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Hexagon(v);

    return is;
}
#endif