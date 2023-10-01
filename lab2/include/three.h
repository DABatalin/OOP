#pragma once

#include <string>
#include <iostream>

#define MAX_LEN 1000

class Three
{ 
public:
    Three();
    Three(const size_t &n);
    Three(const std::initializer_list<unsigned char> &t);
    Three(const std::string &t);
    Three(const Three& other);
    Three(Three&& other) noexcept;

    Three operator+(const Three& other);
    Three operator-(const Three& other);
    bool operator==(const Three& other);
    bool operator!=(const Three& other);
    bool operator>(const Three& other);
    bool operator<(const Three& other);

    int getSize();
    unsigned char* getThreeArray();

    std::ostream& print(std::ostream& os);
    virtual ~Three() noexcept;
private:
    bool validator(const std::string &t);
    void reverseArray(unsigned char* t, size_t length);
    unsigned char* decimalToThree(const size_t &n);
    size_t threeToDecimal(unsigned char* t, size_t length);
    size_t sizeOfCArray(unsigned char* t);
private:
    size_t _size;
    unsigned char *_three;
};
