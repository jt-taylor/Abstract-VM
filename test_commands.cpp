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
	stack_interface_command__push(q, eint_8t, fac, std::string("42"));
	stack_interface_command__print(q, eint_8t, fac, std::string());
	stack_interface_command__pop(q, eint_8t, fac, std::string());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
	}
	return (0);
}
