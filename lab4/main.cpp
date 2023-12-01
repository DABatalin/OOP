#include <iostream>
#include <string>
#include <vector>

#include "hexagon.h"
#include "methods.h"
#include "pentagon.h"
#include "rhombus.h"
#include "array.h"


int main() {
	std::vector<std::pair<double, double>> hex_vector{{2, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 3}, {3, 2}};
	std::vector<std::pair<double, double>> hex_vector2{{3, 1}, {1, 2}, {1, 3}, {3, 4}, {5, 3}, {5, 2}};
	std::vector<std::pair<double, double>> pent_vector{{2, 1}, {1, 2}, {2, 3}, {3, 3}, {4, 2}};
	Hexagon<double> hex(hex_vector);
	Hexagon<double> hex2(hex_vector2);
	Pentagon<double> pent(pent_vector);
	std::cout << pent << std::endl;

	Hexagon<double> hex3;
	std::pair<double, double> pair;
	std::pair<double, double> pair2;
	pair.first = 0;
	pair.second = 0;
	pair2.first = 0;
	pair2.second = 0;
	double area = figures::get_area<Hexagon<double>, double>(hex);
	pair2 = figures::get_middle_point<Hexagon<double>, double>(hex);

	std::cout << "Area: " << area << std::endl << pair2.first << " " << pair2.second << std::endl;

	std::shared_ptr<Hexagon<double>> sp_hex = std::make_shared<Hexagon<double>>(hex);
	std::shared_ptr<Hexagon<double>> sp_hex2 = std::make_shared<Hexagon<double>>(hex2);

	Array<Hexagon<double>> array{{sp_hex, sp_hex2}};
	std::cout <<  *(array[0]) << std::endl;

	std::cout << array.total_area() << std::endl;
}