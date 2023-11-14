#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include <vector>

// Будем считать, что вершины фигуры подаются на вход по или против часовой стрелки
template <class T>
class Figure
{
	template <class T_>
	friend std::ostream& operator<<(std::ostream& os, const Figure<T_>& p);
	template <class T_>
	friend std::ostream& operator>>(std::istream& is, Figure<T_>& p);

public:
	std::vector<std::pair<T, T>> points;
    virtual ~Figure() = default;

	// = 0 говорит, что фукнция чисто виртуальная и в каждом 
	// унаследованном классе она должна быть реализована

	virtual explicit operator double() const = 0;

};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Figure<T>& p)
{
	os << "Точки: " << std::endl;
    for (int i = 0; i != p.points.size(); ++i) {
        os << "Точка " << i + 1 << ": "<< "[x" << " = " << p.points[i].first << ", "
           << "y" << " = " << p.points[i].second << "];" << std::endl;
    }
    return os;
}

#endif