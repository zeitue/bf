/*
 * Interpreter.hpp
 *
 *  Created on: 2014-10-18
 *      Author: zeitue
 */

#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
namespace bf {

class Interpreter {
private:
	std::string code;
	char* program;
	int pc;
	int ret;
	int index;
	void slurp(std::ifstream&);
public:
	Interpreter(std::string = "", int = 30000);
	~Interpreter();
	void inc_pointer();
	void dec_pointer();
	void inc_value();
	void dec_value();
	void output();
	void input();
	void forward();
	void backward();
	void eval();
};

}
#endif /* INTERPRETER_HPP_ */
