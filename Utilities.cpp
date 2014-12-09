/*
 * Utilities.cpp
 *
 *  Created on: 2014-10-18
 *      Author: zeitue
 */
#include "Utilities.hpp"
#include "Interpreter.hpp"

namespace bf {

void help(std::string name) {
	std::cout << "Usage: " << name << " [-h] [options] filename.bf";
	std::cout << std::endl << std::endl << "Options:" << std::endl;
	std::cout << "\t-c<number>\tSpecify number of cells [30000]" << std::endl;
	std::cout << "\t-v\t\tPrint version and exit" << std::endl;
	std::cout << "\t-h\t\tDisplay this help and exit" << std::endl;
}

void version() {
	std::cout << "bf: a Brainf*ck interpreter\tversion 0.0.1" << std::endl;
}

void interprete(std::string name, int cell_size) {
	Interpreter i(name, cell_size);
	i.eval();
}

void interprete(std::string name) {
	Interpreter i(name);
#ifdef OPTIMIZED
	i.optimize();
#endif
	i.eval();
}

}
