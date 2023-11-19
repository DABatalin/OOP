#include <memory>

#include "figure.h"


template <class T>
class Array 
{
    typedef std::vector<std::shared_ptr<T>> array;
public:
	// constructors
    Array();
    Array(const array& figures) : _figures(figures) {}
	// methods

    // void printFigures();
    void delete_figure(int i);
    double total_area();

    std::shared_ptr<T> operator[](int i);

private:
    array _figures;
};

template <class T>
Array<T>::Array() {}

template <class T>
void Array<T>::delete_figure(int i)
{
    if (i >= this->_figures.size())
        throw std::invalid_argument("Out of range");

    this->_figures.erase(this->_figures.begin() + i);
}


template <class T>
double Array<T>::total_area() 
{
    double res = 0;
    for (int i = 0; i < this->_figures.size(); ++i) {
        res += double(*(this->_figures[i]));
    }

    return res;
}

template <class T>
std::shared_ptr<T> Array<T>::operator[](int i) 
{
    if (i >= this->_figures.size())
        throw std::invalid_argument("The array index is out of range");

    return this->_figures[i];
}