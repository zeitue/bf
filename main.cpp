/*
 * main.cpp
 *
 *  Created on: 2014-10-18
 *      Author: zeitue
 */

#include "Interpreter.hpp"
#include "Utilities.hpp"

int main(int argc, char* argv[]) {
	if (argc >= 2) {
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'c':
				if (argc == 4)
					bf::interprete(std::string(argv[3]), atoi(argv[2]));
				else
					std::cout << "Not enough arguments for option -c"
							<< std::endl;
				break;
			case 'h':
				bf::help(argv[0]);
				break;
			case 'v':
				bf::version();
				break;
			default:
				std::cout << "Invalid option" << std::endl;
			}
		} else {
			bf::interprete(std::string(argv[1]));
		}
	} else {
		bf::help(argv[0]);
	}
	return 0;
}

