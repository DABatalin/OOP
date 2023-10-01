#include <iostream>
#include "three.h"


int main(){
	Three three(-1);
	size_t size1 = three.getSize();
	three.print(std::cout) << std::endl << "SIZE IS: " << size1 << std::endl;
}