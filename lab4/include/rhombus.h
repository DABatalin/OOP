#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <string>
#include <iostream>
#include <vector>

#include "figure.h"
#include "methods.h"


template <typename T>
class Rhombus : public Figure<T>
{
public:
	unsigned int n = 4; // Количество вершин 
	std::vector<std::pair<T, T>> points;

	// Constructors
	Rhombus();
	Rhombus(std::vector<std::pair<T, T>>& _points);
	Rhombus(const Rhombus&);
	Rhombus(Rhombus&& other);
    virtual ~Rhombus();


	// Standard operators
	bool operator==(const Rhombus<T> &other) const;
	Rhombus& operator=(const Rhombus<T> &other);
	Rhombus& operator=(Rhombus<T> &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const; //override;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Rhombus<T>& p)
{
	os << "Точки: " << std::endl;
    for (int i = 0; i != p.points.size(); ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << p.points[i].first << ", "
           << "y" << " = " << p.points[i].second << "];" << std::endl;
    }
    return os;
}

template <typename T>
inline std::istream& operator>>(std::istream& is, Rhombus<T>& p)
{
    std::vector<std::pair<T, T>> v(4);

    for (int i = 0; i < 4; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Rhombus(v);

    return is;
}

template <typename T>
Rhombus<T>::Rhombus()
{
	points.resize(n);
}

template <typename T>
Rhombus<T>::Rhombus(std::vector<std::pair<T, T>>& _points) {
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
Rhombus<T>::Rhombus(const Rhombus& other) {
    points = other.points;
}

template <typename T>
Rhombus<T>::Rhombus(Rhombus&& other) {
    points = std::move(other.points);
}


template <typename T>
Rhombus<T>::~Rhombus() {}


template <typename T>
bool Rhombus<T>::operator==(const Rhombus<T> &other) const
{
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = 0; j < n; j++) {
			if (other.points[i] != points[j]) {
				check += 1;
			}
		}
		if (check == n - 1) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator=(const Rhombus<T> &other) 
{
	points = other.points;

	return *this;
}

template <typename T>
Rhombus<T>& Rhombus<T>::operator=(Rhombus<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}

template <typename T>
Rhombus<T>::operator double() const {
    return (double)figures::get_area<Rhombus<T>, T>(*this);
}
#endif