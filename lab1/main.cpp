#include <iostream>
#include <string>
#include "time_converter.h"


int main() {
    int hour, minute;
    std::string period, result;

    std::cout << "Enter the hour (1-12): ";
    std::cin >> hour;

    std::cout << "Enter the minute (0-59): ";
    std::cin >> minute;

    std::cout << "Enter 'am' or 'pm': ";
    std::cin >> period;

    result = time_converter(hour, minute, period);

    std::cout << "Result: " << result << std::endl;
}
