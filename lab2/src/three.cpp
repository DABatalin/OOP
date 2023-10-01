#include <string>
#include <cstdint>
#include <cstring>
#include <cmath>
#include "three.h"


Three::Three() : _size(0), _three{nullptr}
{
    std::cout << "Default constructor" << std::endl;
}

Three::Three(const size_t &n)
{   
    std::cout << "Fill constructor" << std::endl;
    _three = decimalToThree(n);
    _size = sizeOfCArray(_three);
}

Three::Three(const std::initializer_list<unsigned char> &t)
{
    std::cout << "Initializer list constructor" << std::endl;
    _three = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _three[i++] = c;
    _size = t.size();
    reverseArray(_three, _size);
    const std::string str = std::string(reinterpret_cast<const char*>(_three), _size);
    if (!validator(str)) {
        throw std::invalid_argument("wrong symblos in constructor strings");
    }
}

Three::Three(const std::string &t)
{
    std::cout << "Copy string constructor" << std::endl;
    _three = new unsigned char[t.size()];
    _size  = t.size();
    for(size_t i{0};i<_size;++i) _three[i] = t[i];
    reverseArray(_three, _size);
    if (!validator(t)) {
        throw std::invalid_argument("wrong symblos in constructor strings");
    }

}

Three::Three(const Three &other)
{
    std::cout << "Copy constructor" << std::endl;
    _size  = other._size;
    _three = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _three[i] = other._three[i];
}

Three::Three(Three &&other) noexcept
{
    std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _three = other._three;

    other._size = 0;
    other._three = nullptr;
}


Three Three::operator+(const Three& other) {
    Three temp;
    size_t first_three = threeToDecimal(this->_three, this->_size);
    size_t second_three =  threeToDecimal(other._three, other._size);

    size_t sum = first_three + second_three;

    temp._three = decimalToThree(sum);
    temp._size = sizeOfCArray(temp._three);

    return temp;
}

Three Three::operator-(const Three& other) {
    Three temp;
    size_t first_three = threeToDecimal(this->_three, this->_size);
    size_t second_three =  threeToDecimal(other._three, other._size);

    size_t sum = first_three - second_three;

    temp._three = decimalToThree(sum);
    temp._size = sizeOfCArray(temp._three);

    return temp;
}

bool Three::operator==(const Three& other) {
    if (this->_size == other._size) {
        for (int i{0}; i < this->_size; i++) {
            if (this->_three[i] != other._three[i])
                return false;
        }
        return true;
    }
    return false;
}

bool Three::operator!=(const Three& other) {
    if (this->_size == other._size) {
        for (int i{0}; i < this->_size; i++) {
            if (this->_three[i] != other._three[i])
                return true;
        }
        return false;
    }
    return true;
}

bool Three::operator>(const Three& other) {
    size_t first_three = threeToDecimal(this->_three, this->_size);
    size_t second_three =  threeToDecimal(other._three, other._size);

    return first_three > second_three;
}

bool Three::operator<(const Three& other) {
    size_t first_three = threeToDecimal(this->_three, this->_size);
    size_t second_three =  threeToDecimal(other._three, other._size);

    return first_three < second_three;
}

int Three::getSize() {
    return this->_size;
}

unsigned char* Three::getThreeArray() {
    return this->_three;
}


std::ostream &Three::print(std::ostream &os)
{
    for (long int i = _size; i >= 0; i--) {
        os << _three[i];
    }
    return os;
}

Three::~Three() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _three;
        _three = nullptr;
    }
}


bool Three::validator(const std::string &t) {
    for (int i{0}; i < t.length(); i++) {
        char a = t[i];
        if (!((t[i] == '0') or (t[i] == '1') or (t[i] == '2')))
            return false;
    }
    return true;
}

void Three::reverseArray(unsigned char* t, size_t length) {
    if (length <= 1) {
        return;
    }

    unsigned char* start = t;
    unsigned char* end = t + length - 1;

    while (start < end) {
        unsigned char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

unsigned char* Three::decimalToThree(const size_t &n) {
    unsigned char * three;
    size_t size = 0;
    if (n == 0) {
        three = new unsigned char[1];
        three[0] = '0';
        size = 1;
        three[size] = '\0';
    }
    else {
        size_t check_size = n;
        while (check_size > 0) {
            size_t remainder = check_size % 3;
            check_size /= 3;
            size += 1;
        }
        three = new unsigned char[size];
        three[size] = '\0';
        size_t not_const_n = n;
        
        size_t counter = 0;
        while (not_const_n > 0) {
            size_t remainder = not_const_n % 3;
            three[counter] = char(remainder + 48);
            counter += 1;
            not_const_n /= 3;
        }
    }
    return three;
}

size_t Three::threeToDecimal(unsigned char* t, size_t length) {
    unsigned int decimalNumber = 0;

    for (int i = 0; i < length; ++i) {
        long long t_i = t[i] - '0';
        decimalNumber += t_i * std::pow(3, i);
    }

    return decimalNumber;
}

size_t Three::sizeOfCArray(unsigned char* t) {
    size_t i = 0;
    while (t[i] != '\0') {
        // std::cout << "INDEX: " << i << "\t" << "Three[i]: " << t[i] << "\n";
        i++;
    }
    return i;
}