#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "our_exceptions.hpp"
#include <string>
#include <iostream>
#include <deque> // for std::deque<>
#include <stdlib.h> //for atoi

//should i throw these into their own class >?
//so because it's isgnificantly faster to yank and paste the function base
//than writing them from scratch we have to silence the unused variable functions
//you can use the lagacy c style (void)var cast , or not give the variable a name in the
//prototype like my_func(int /*no name*/, ...)
//or c++17 has [[maybe unused]]
//but i went with the gcc atribute option --> __attribute__((unused))var

// push pop dump ---------------------------------------------------------------
void		stack_interface_command__push(std::deque<const IOperand *> & q, eOperandType type, OpFactory & fac, std::string value)
{
	try {
		const IOperand * n = fac.createOperand(type, value);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknow exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__pop(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused)) std::string value)
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
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__dump(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		for (auto i = q.begin();i != q.end();i++)
			std::cout << (*i)->toString() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

// assert print exit

void		stack_interface_command__assert(std::deque<const IOperand *> & q, eOperandType type, __attribute__((unused))OpFactory & fac, std::string value)
{
	try {
	//	const IOperand * tmp = fac.createOperand(type, value);
		if ((q.front())->getType() != type)
			throw (ex_AssertIsFalse());
		if (value.compare((q.front())->toString()) != 0)
			throw (ex_AssertIsFalse());
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__print(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if ((q.front())->getType() != type)
			throw (ex_AssertIsFalse());
		std::cout << static_cast<char>((atoi(((q.front())->toString()).c_str())));
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__exit(__attribute__((unused)) std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused)) std::string value)
{
	try {
		exit(0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

// operations ------------------------------------------------------------------
void		stack_interface_command__add(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValues());
		const IOperand * tmp1 = q.front();
		q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
		const IOperand * n = *tmp1 + *tmp2;
		delete (tmp1);
		delete (tmp2);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__sub(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValues());
		const IOperand * tmp1 = q.front();
		q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
		const IOperand * n = *tmp1 - *tmp2;
		delete (tmp1);
		delete (tmp2);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__mul(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValues());
		const IOperand * tmp1 = q.front();
		q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
		const IOperand * n = *tmp1 * *tmp2;
		delete (tmp1);
		delete (tmp2);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__div(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValues());
		const IOperand * tmp1 = q.front();
		q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
		const IOperand * n = *tmp1 / *tmp2;
		delete (tmp1);
		delete (tmp2);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}

void		stack_interface_command__mod(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value)
{
	try {
		if (q.size() < 2)
			throw (ex_MissingValues());
		const IOperand * tmp1 = q.front();
		q.pop_front();
		const IOperand * tmp2 = q.front();
		q.pop_front();
		const IOperand * n = *tmp1 % *tmp2;
		delete (tmp1);
		delete (tmp2);
		q.push_front(n);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw;
	} catch (...) {
		std::cout << "unknowe exception" << std::endl;
		throw;
	}
}
