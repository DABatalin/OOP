#include <iostream>
#include <string>
#include <vector>

#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"
#include "array.h"


int main(){
	// Hexagon hex;
	// std::cin >> hex;
	// Pentagon pent;
	// std::cin >> pent;
	Rhombus rh;
	Rhombus rh1;
	std::cin >> rh;
	std::cin >> rh1;

	// std::cout << "Площадь: " << hex.get_area() << std::endl;
	// std::cout << "Центральная точка: " << hex.get_middle_point().first << " " << hex.get_middle_point().second << std::endl;
	// std::cout << hex << std::endl;

	// std::cout << "Площадь: " << pent.get_area() << std::endl;
	// std::cout << "Центральная точка: " << pent.get_middle_point().first << " " << pent.get_middle_point().second << std::endl;
	// std::cout << pent << std::endl;

	std::cout << "Площадь: " << rh.get_area() << std::endl;
	std::cout << "Центральная точка: " << rh.get_middle_point().first << " " << rh.get_middle_point().second << std::endl;
	std::cout << rh << std::endl;

	Array arr[4];
	arr->replace_figure(0, &rh);
	arr->replace_figure(1, &rh1);

	std::cout << "Средняя площадь: " << arr->average_area() << std::endl;

}