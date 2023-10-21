#include "figure.h"

class Array 
{
public:
	// constructors
    Array();
    Array(int size);
    virtual ~Array();

	// methods
    void delete_figure(int i);
    void replace_figure(int i, Figure* figure);
    double average_area();

	// operators
    Figure* operator[](int i) const;
private:
    Figure** _figures;
    int _size;
};