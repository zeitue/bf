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

#ifdef OPTIMIZED
void Interpreter::optimize() {
	std::stack<int> brackets;
	int open_bracket = -1;
	for (int i = 0; i < (int) code.length(); i++) {
		if (code[i] == '[')
			brackets.push(i - 1);
		else if (code[i] == ']') {
			open_bracket = brackets.top();
			brackets.pop();
			jump_back[i] = open_bracket;
			jump_forward[open_bracket + 1] = i;
		}
	}
}
#endif

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
#ifdef OPTIMIZED
	if (program[pc] == '\0')
		index = jump_forward[index];
#else
	int balance = 1;
	if (program[pc] == '\0') {
		do {
			index++;
			if (code[index] == '[')
			balance++;
			else if (code[index] == ']')
			balance--;
		}while (balance != 0);
	}
#endif
}

void Interpreter::backward() {
#ifdef OPTIMIZED
	index = jump_back[index];
#else
	int balance = 0;
	do {
		if (code[index] == '[')
		balance++;
		else if (code[index] == ']')
		balance--;
		index--;
	}while (balance != 0);
#endif
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
