#ifndef PENTAGON_H
#define PENTAGON_H
#include <string>
#include <iostream>
#include <vector>

#include "figure.h"
#include "methods.h"


template <typename T>
class Pentagon : public Figure<T>
{
public:
	unsigned int n = 5; // Количество вершин 
	std::vector<std::pair<T, T>> points;

	// Constructors
	Pentagon();
	Pentagon(std::vector<std::pair<T, T>>& _points);
	Pentagon(const Pentagon&);
	Pentagon(Pentagon&& other);
    virtual ~Pentagon();


	// Standard operators
	bool operator==(const Pentagon<T> &other) const;
	Pentagon& operator=(const Pentagon<T> &other);
	Pentagon& operator=(Pentagon<T> &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const; //override;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Pentagon<T>& p)
{
	os << "Точки: " << std::endl;
    for (int i = 0; i != p.points.size(); ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << p.points[i].first << ", "
           << "y" << " = " << p.points[i].second << "];" << std::endl;
    }
    return os;
}

template <typename T>
inline std::istream& operator>>(std::istream& is, Pentagon<T>& p)
{
    std::vector<std::pair<T, T>> v(5);

    for (int i = 0; i < 5; ++i) {
		std::cout << "Введите x и y " << i + 1 << " точки: ";
        is >> v[i].first >> v[i].second;
    }
    p = Pentagon(v);

    return is;
}

template <typename T>
Pentagon<T>::Pentagon()
{
	points.resize(n);
}

template <typename T>
Pentagon<T>::Pentagon(std::vector<std::pair<T, T>>& _points) {
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
Pentagon<T>::Pentagon(const Pentagon& other) {
    points = other.points;
}

template <typename T>
Pentagon<T>::Pentagon(Pentagon&& other) {
    points = std::move(other.points);
}


template <typename T>
Pentagon<T>::~Pentagon() {}


template <typename T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) const
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
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T> &other) 
{
	points = other.points;

	return *this;
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}

template <typename T>
Pentagon<T>::operator double() const {
    return (double)figures::get_area<Pentagon<T>, T>(*this);
}
#endif