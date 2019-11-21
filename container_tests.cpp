#include <stack>
#include <iostream>
#include <string>
#include <deque>
#include "IOperand.hpp"
#include "OpFactory.hpp"


int		main(void)
{
	std::deque<const IOperand *>		q;

	OpFactory fac;
	const IOperand * i = fac.createOperand(eint_8t, std::string("42"));
	q.push_front(i);
	std::cout << (q.front())->toString();
}
