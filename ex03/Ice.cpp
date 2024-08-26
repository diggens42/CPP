#include "Ice.hpp"
#include <iostream>

// Default constructor
Ice::Ice() {
	std::cout << "Default constructor called" << std::endl;
	// Initialization code
}

// Copy constructor
Ice::Ice(const Ice &other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy initialization code
}

// Copy assignment operator
Ice& Ice::operator=(const Ice &other) {
	// self-assignment check
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		// Copy assignment code
	}
	return *this;
}

// Destructor
Ice::~Ice() {
	std::cout << "Destructor called" << std::endl;
	// Cleanup code
}
