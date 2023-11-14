#ifndef HEXAGON_H
#define HEXAGON_H
#include <string>
#include <iostream>
#include <vector>

#include "figure.h"
#include "methods.h"


template <typename T>
class Hexagon : public Figure<T>
{
public:
	unsigned int n = 6; // Количество вершин 
	std::vector<std::pair<T, T>> points;

	// Constructors
	Hexagon();
	Hexagon(std::vector<std::pair<T, T>>& _points);
	Hexagon(const Hexagon&);
	Hexagon(Hexagon&& other);
    virtual ~Hexagon();


	// Standard operators
	bool operator==(const Hexagon<T> &other) const;
	Hexagon& operator=(const Hexagon<T> &other);
	Hexagon& operator=(Hexagon<T> &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const; //override;

};

// template <typename T>
// inline std::ostream& operator<<(std::ostream& os, const Hexagon<T>& p)
// {
// 	os << "Точки: " << std::endl;
//     for (int i = 0; i != p.points.size(); ++i) {
//         os << "Точка " << i + 1 << ": "<< "[x" << " = " << p.points[i].first << ", "
//            << "y" << " = " << p.points[i].second << "];" << std::endl;
//     }
//     return os;
// }

template <typename T>
inline std::istream& operator>>(std::istream& is, Hexagon<T>& p)
{
    std::vector<std::pair<T, T>> v(6);

    for (int i = 0; i < 6; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Hexagon(v);

    return is;
}

template <typename T>
Hexagon<T>::Hexagon()
{
	points.resize(n);
}

template <typename T>
Hexagon<T>::Hexagon(std::vector<std::pair<T, T>>& _points) {
	std::cout << "Vector constructor init" << std::endl;
	// Points amount check
	if (_points.size() != n) 
	{
		throw std::invalid_argument("Wrong amount of points");
	}

	// Push points to _points
	for (int i = 0; i < n; i++)
	{
		points.push_back(_points[i]);
	}
}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon& other) {
    points = other.points;
}

template <typename T>
Hexagon<T>::Hexagon(Hexagon&& other) {
    points = std::move(other.points);
}


template <typename T>
Hexagon<T>::~Hexagon() {}


template <typename T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const
{
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = 0; j < n; j++) {
			if (other.points[i] != points[j]) {
				check += 1;
			}
		}
		if (check == 5) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T> &other) 
{
	points = other.points;

	return *this;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}

template <typename T>
Hexagon<T>::operator double() const {
    return (double)figures::get_area<Hexagon<T>, T>(*this);
}
#endif