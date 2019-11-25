#include <stack>
#include <iostream>
#include <string>
#include <deque>
#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "command_prototypes.hpp"

/*
 * this is to test the stack_interface_commands
 */

int		main(void)
{
	try {
	std::deque<const IOperand *>		q;
	OpFactory fac;

	//basic push print pop
	std::cout << "\n\n-------------\n Push print assert\n";
	stack_interface_command__push(q, eint_8t, fac, std::string("42"));
	stack_interface_command__print(q, eint_8t, fac, std::string());
	stack_interface_command__push(q, eint_8t, fac, std::string("40"));
	stack_interface_command__print(q, eint_8t, fac, std::string());
	std::cout << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__add(q, eint_8t, fac, std::string());
	stack_interface_command__print(q, eint_8t, fac, std::string());
	std::cout << std::endl;
	stack_interface_command__push(q, eint_16t, fac, std::string("512"));
	stack_interface_command__print(q, eint_8t, fac, std::string());
	stack_interface_command__add(q, eint_8t, fac, std::string());
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	// print on non char value
	stack_interface_command__print(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	std::deque<const IOperand *>		q;
	OpFactory fac;

	//more testing for dump
	std::cout << "\n\n-------------\n Dump\n";
	stack_interface_command__push(q, eint_8t, fac, std::string("42"));
	std::cout << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	std::cout << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	//testing precision stuff
	std::cout << "\n\n-------------\n Precision\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	const IOperand * j = fac.createOperand(edouble, std::string("42.071111111111111111"));
	std::cout << j->getPrecision() << std::endl;
	stack_interface_command__push(q, eint_16t, fac, std::string("512"));
	stack_interface_command__push(q, eint_32t, fac, std::string("513"));
	stack_interface_command__push(q, efloat, fac, std::string("24"));
	stack_interface_command__push(q, edouble, fac, std::string("62"));
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__add(q, eint_8t, fac, std::string());
	stack_interface_command__add(q, eint_8t, fac, std::string());
	stack_interface_command__add(q, eint_8t, fac, std::string());
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__pop(q, eint_8t, fac, std::string());
	std::cout << "empty stack :: " << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	//pop on empty stack exception
	stack_interface_command__pop(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	//add sub mul
	std::cout << "\n\n-------------\n Add Sub Mul";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, eint_16t, fac, std::string("512"));
	stack_interface_command__push(q, eint_32t, fac, std::string("256"));
	stack_interface_command__push(q, efloat, fac, std::string("128"));
	stack_interface_command__push(q, edouble, fac, std::string("64"));
	std::cout << "before ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__mul(q, eint_8t, fac, std::string());
	stack_interface_command__sub(q, eint_8t, fac, std::string());
	stack_interface_command__mul(q, eint_8t, fac, std::string());
	std::cout << "after ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// div
	std::cout << "\n\n-------------\n Div\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, edouble, fac, std::string("0"));
	stack_interface_command__push(q, eint_16t, fac, std::string("512"));
	stack_interface_command__push(q, eint_32t, fac, std::string("512"));
	stack_interface_command__push(q, efloat, fac, std::string("512"));
	stack_interface_command__push(q, edouble, fac, std::string("512"));
	std::cout << "before ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__div(q, eint_8t, fac, std::string());
	stack_interface_command__div(q, eint_8t, fac, std::string());
	stack_interface_command__div(q, eint_8t, fac, std::string());
	std::cout << "after ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	std::cout << "div by 0 except\n";
	stack_interface_command__div(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// mod
	std::cout << "\n\n-------------\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, edouble, fac, std::string("0"));
	stack_interface_command__push(q, eint_16t, fac, std::string("512"));
	stack_interface_command__push(q, eint_32t, fac, std::string("512"));
	stack_interface_command__push(q, efloat, fac, std::string("512"));
	stack_interface_command__push(q, edouble, fac, std::string("512"));
	std::cout << "before ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__mod(q, eint_8t, fac, std::string());
	stack_interface_command__mod(q, eint_8t, fac, std::string());
	stack_interface_command__mod(q, eint_8t, fac, std::string());
	std::cout << "after ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	std::cout << "mod by 0\n";
	stack_interface_command__mod(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// overflow
	std::cout << "\n\n-------------\n Overflow\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, eint_8t, fac, std::string("129"));
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// underflow
	std::cout << "\n\n-------------\n Underflow\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, eint_8t, fac, std::string("-129"));
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// missing values except
	std::cout << "\n\n-------------\n Missing values except\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__push(q, edouble, fac, std::string("0"));
	std::cout << "before ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	stack_interface_command__mod(q, eint_8t, fac, std::string());
	// the rest wont run
	std::cout << "after ops" << std::endl;
	stack_interface_command__dump(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	try {
	// exit
	std::cout << "\n\n-------------\n Exit\n";
	std::deque<const IOperand *>		q;
	OpFactory fac;

	stack_interface_command__exit(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	return (0);
}
