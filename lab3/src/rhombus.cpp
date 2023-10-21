#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

#include "rhombus.h"

Rhombus::Rhombus() : _area(0)
{
	_points.resize(n);
	_middle_point.first = 0;
	_middle_point.second = 0;
}


Rhombus::Rhombus(std::vector<std::pair<double, double>> &points)
{
	std::cout << "Vector constructor init" << std::endl;
	// Points amount check
	if (points.size() != n) 
	{
		throw std::invalid_argument("Wrong amount of points");
	}
	

	// Push points to _points and find middle point
	for (int i = 0; i < n; i++)
	{
		_points.push_back(points[i]);
		_middle_point.first += _points.back().first / n;
		_middle_point.second += _points.back().second / n;
	}

	double side1 = std::sqrt(std::pow(_points[0].first - _points[1].first, 2) + std::pow(_points[0].second - _points[1].second, 2));
	double side2 = std::sqrt(std::pow(_points[1].first - _points[2].first, 2) + std::pow(_points[1].second - _points[2].second, 2));
	double side3 = std::sqrt(std::pow(_points[2].first - _points[3].first, 2) + std::pow(_points[2].second - _points[3].second, 2));
	double side4 = std::sqrt(std::pow(_points[3].first - _points[0].first, 2) + std::pow(_points[3].second - _points[0].second, 2));
	
	if (!(is_equal(side1, side2))) {
		throw std::invalid_argument("Its not a rhombus");
	}
	if (!(is_equal(side2, side3))) {
		throw std::invalid_argument("Its not a rhombus");
	}
	if (!(is_equal(side3, side4))) {
		throw std::invalid_argument("Its not a rhombus");
	}
	std::vector<std::pair<double, double>> points2;
	std::pair<double, double> para; para.first = 0; para.second = 0;

	points2.push_back(para);
	for (int i = 0; i < n; i++) {
		points2.push_back(_points[i]);
	}

    // for (std::pair<double, double> point : points2) {
    //     std::cout << point.first << " " << point.second << std::endl;
    // }

	double s = 0, m = 0;
	for (int i = 1; i <= n - 1; i++)
		s += points2[i].first * points2[i + 1].second;

	s += points2[n].first * points2[1].second;
	for (int i = 1; i <= n - 1; i++)
		m -= points2[i].second * points2[i + 1].first;
	m -= points2[n].second * points2[1].first;

	_area = 0.5 * abs(s + m);
}

Rhombus::~Rhombus() {}

bool Rhombus::operator==(const Rhombus &other) const
{
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = 0; j < n; j++) {
			if (other._points[i] != _points[j]) {
				check += 1;
			}
		}
		if (check == 3) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

Rhombus& Rhombus::operator=(const Rhombus &other) 
{
	_points = other.get_points();
	_middle_point = other.get_middle_point();
	_area = other.get_area();

	return *this;
}

Rhombus& Rhombus::operator=(Rhombus &&other) 
{
   	_points = std::move(other._points);
    _middle_point = std::move(other._middle_point);
    _area = std::move(other._area);

    return *this;
}

Rhombus::operator double() const {
    return get_area();
}


