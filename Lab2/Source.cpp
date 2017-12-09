#include <iostream>
#include "P5dot10.h"
#include "P6dot6.h"
#include "P7dot7.h"

int main() {

	std::cout << "P5.10: " << std::endl;
	P5dot10::run();

	std::cout << std::endl << std::endl;

	std::cout << "P6.6: " << std::endl;
	P6dot6::run();

	//std::cout << std::endl << std::endl;

	//std::cout << "P7.7: " << std::endl;
	//P7dot7::run();

	return 0;
}