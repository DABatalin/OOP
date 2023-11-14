#ifndef PENTAGON_H
#define PENTAGON_H
#include <string>
#include <iostream>
#include <vector>

#include "figure.h"


class Pentagon : public Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Pentagon& p);
	friend std::istream& operator>>(std::istream& is, Pentagon& p);
public:
	// Constructors
	Pentagon();
	Pentagon(std::vector<std::pair<double, double>>& points);
    virtual ~Pentagon();


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
	bool operator==(const Pentagon &other) const;
	Pentagon& operator=(const Pentagon &other);
	Pentagon& operator=(Pentagon &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;

private:
	std::vector<std::pair<double, double>> _points;
	std::pair<double, double> _middle_point;
	double _area = 0;
	unsigned int n = 5; // Количество вершин 
};

inline std::ostream& operator<<(std::ostream& os, const Pentagon& p)
{
    std::vector<std::pair<double, double>> points = p.get_points();
	os << "Точки: " << std::endl;
    for (int i = 0; i != 5; ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << points[i].first << ", "
           << "y" << " = " << points[i].second << "];" << std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Pentagon& p)
{
    std::vector<std::pair<double, double>> v(5);

    for (int i = 0; i < 5; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Pentagon(v);

    return is;
}
#endif