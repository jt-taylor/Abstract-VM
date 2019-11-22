#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "our_exceptions.hpp"
#include <string>
#include <iostream>

//should i throw these into their own class >?

// push pop dump ---------------------------------------------------------------
void		stack_interface_command__push(std::deque<IOperand *> & ref, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		const IOperand n = fac.createOperand(type, value);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__pop(std::deque<IOperand *> & ref, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		if (q.empty())
			throw (ex_BadPopInstruction());
		const IOperand * tmp = q.front();
		q.pop_front();
		delete (tmp);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::enl;
		throw;
	}
}

void		stack_interface_command__dump(std::deque<IOperand *> & ref, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		for (auto i = q.front();i != q.end();i++)
			std::cout << (*i)->toString() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::enl;
		throw;
	}
}

void		stack_interface_command__dump(std::deque<IOperand *> & ref, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		const IOperand * tmp = q.front();
		if (value.compare(tmp->toString()) != 0)
			throw (ex_AssertIsFalse());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::enl;
		throw;
	}
}

// operations ------------------------------------------------------------------
void		stack_interface_command__add(std::deque<IOperand *> & ref, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValue());
		const IOperand * tmp1 = q.front();
			q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::enl;
		throw;
	}
}
