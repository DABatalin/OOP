#include <iostream>
#include <string>
#include "time_converter.h"

std::string time_converter(unsigned int hour, unsigned int minute, std::string period) {
    if ((hour > 12) or (minute > 59) or ((period != "am") and (period != "pm"))) {
		return "ERROR: Wrong input data\n";
    }
    
    if (hour == 12) {
        if (period == "pm") {
            hour = 0;
        }
    } else if (period == "am") {
        hour += 12;
    }

    char buffer[5];
    snprintf(buffer, sizeof(buffer), "%02d%02d", hour, minute);

    return std::string(buffer);
}