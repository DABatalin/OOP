#include <iostream>
#include <string>
#include <vector>

#include "hexagon.h"
// #include "pentagon.h"
// #include "rhombus.h"
#include "array.h"


int main(){
	std::vector<std::pair<double, double>> hex_vector{{2, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 3}, {3, 2}};
	Hexagon<double> hex(hex_vector);
	Hexagon<double> hex2(hex_vector);

	std::cout << hex << std::endl;
	std::cout << (double)hex << std::endl;

	std::shared_ptr<Hexagon<double>> sp_hex = std::make_shared<Hexagon<double>>(hex);
	std::shared_ptr<Figure<double>> sp_hex2 = std::make_shared<Hexagon<double>>(hex2);

	Array<Figure<double>> array{{sp_hex, sp_hex2}};
	array.printFigures();
	std::cout << array.total_area() << std::endl;


}