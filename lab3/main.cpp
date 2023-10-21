#include <iostream>
#include <string>
#include <vector>


#include "hexagon.h"
#include "pentagon.h"
#include "rhombus.h"


int main(){
	// Hexagon hex;
	// std::cin >> hex;
	// Pentagon pent;
	// std::cin >> pent;
	Rhombus rh;
	std::cin >> rh;


	// std::cout << "Площадь: " << hex.get_area() << std::endl;
	// std::cout << "Центральная точка: " << hex.get_middle_point().first << " " << hex.get_middle_point().second << std::endl;
	// std::cout << hex << std::endl;

	// std::cout << "Площадь: " << pent.get_area() << std::endl;
	// std::cout << "Центральная точка: " << pent.get_middle_point().first << " " << pent.get_middle_point().second << std::endl;
	// std::cout << pent << std::endl;

	std::cout << "Площадь: " << rh.get_area() << std::endl;
	std::cout << "Центральная точка: " << rh.get_middle_point().first << " " << rh.get_middle_point().second << std::endl;
	std::cout << rh << std::endl;
}