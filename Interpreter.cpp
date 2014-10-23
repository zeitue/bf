/*
 * Interpreter.cpp
 *
 *  Created on: 2014-10-18
 *      Author: zeitue
 */

#include "Interpreter.hpp"
namespace bf {

Interpreter::Interpreter(std::string filename, int cell_size) {
	pc = 0;
	ret = 0;
	index = 0;
	std::ifstream file(filename.c_str());
	if (!file) {
		if (filename == "")
			std::cout << "No file to open" << std::endl;
		else
			std::cout << "Failed to open \"" << filename << "\"" << std::endl;
		exit(0);
	} else {
		slurp(file);
		program = new char[cell_size]();
	}
	file.close();
}

Interpreter::~Interpreter() {
	delete[] program;
}
void Interpreter::slurp(std::ifstream& in) {
	std::stringstream sstr;
	sstr << in.rdbuf();
	code = sstr.str();

}

void Interpreter::inc_pointer() {
	++pc;
}

void Interpreter::dec_pointer() {
	--pc;
}

void Interpreter::inc_value() {
	++program[pc];
}

void Interpreter::dec_value() {
	--program[pc];
}

void Interpreter::output() {
	std::cout << program[pc];
}

void Interpreter::input() {
	program[pc] = getchar();
}

void Interpreter::forward() {
	int balance = 1;
	if (program[pc] == '\0') {
		do {
			index++;
			if (code[index] == '[')
				balance++;
			else if (code[index] == ']')
				balance--;
		} while (balance != 0);

	}
}

void Interpreter::backward() {
	int balance = 0;
	do {
		if (code[index] == '[')
			balance++;
		else if (code[index] == ']')
			balance--;
		index--;
	} while (balance != 0);
}

void Interpreter::eval() {
	for (index = 0; index < (int) code.length(); index++) {
		switch (code[index]) {
		case '<':
			dec_pointer();
			break;
		case '>':
			inc_pointer();
			break;
		case '+':
			inc_value();
			break;
		case '-':
			dec_value();
			break;
		case ',':
			input();
			break;
		case '.':
			output();
			break;
		case '[':
			forward();
			break;
		case ']':
			backward();
			break;
		}
	}
}

}
