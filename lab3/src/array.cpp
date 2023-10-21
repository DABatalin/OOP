#include "array.h"

Array::Array() 
{
    _size = 100;
    _figures = new Figure*[_size];

    for (int i = 0; i != _size; ++i)
        _figures[i] = nullptr;
}

Array::Array(int size) 
{
    _size = size;
    _figures = new Figure*[_size];

    for (int i = 0; i != _size; ++i)
        _figures[i] = nullptr;
}

Array::~Array() 
{
    _size = 0;
    delete[] _figures;
    _figures = nullptr;
}

Figure* Array::operator[](int i) const
{
    if (i >= _size)
        throw std::invalid_argument("Out of range");

    return _figures[i];
}

void Array::delete_figure(int i)
{
    if (i >= _size)
        throw std::invalid_argument("Out of range");

    delete _figures[i];
    _figures[i] = nullptr;
}

void Array::replace_figure(int i, Figure* figure)
{
    if (i >= _size)
        throw std::invalid_argument("Out of range");

    delete _figures[i];
    _figures[i] = figure;
}

double Array::average_area() 
{
    double res = 0.0;
    for (int i = 0; i != _size; ++i) {
        if (_figures[i] != nullptr)
            res += (double)*_figures[i];
    }

    return res;
}