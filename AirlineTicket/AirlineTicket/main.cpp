#include <iostream>
#include "AirlineTicket.h"

int main() {
	AirlineTicket Max;
	Max.setNumberofmiles(920);
	std::cout << Max.calculatePrice();
}