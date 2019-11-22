#include <stack>
#include <iostream>
#include <string>
#include <deque>
#include "IOperand.hpp"
#include "OpFactory.hpp"


int		main(void)
{
	try {
	std::deque<const IOperand *>		q;

	OpFactory fac;
	const IOperand * i = fac.createOperand(eint_8t, std::string("42"));
	q.push_front(i);
	std::cout << (q.front())->toString() << std::endl;
	const IOperand * j = fac.createOperand(edouble, std::string("42.071111111111111111"));
	q.push_front(j);
	const IOperand * n1 = q.front();
	const IOperand * n2 = q.front();
	const IOperand * ret = *n1 + *n2;
	q.push_front(ret);
	std::cout << (q.front())->toString() << std::endl;
	//deque overloads the [] operator so you can iterate with an int if you want
	std::cout << "Iterate throgh stack" << std::endl;
	for (auto i = q.cbegin();i != q.cend();i++)
		std::cout << (*i)->toString() << std::endl;
	std::cout << "------------------------------" << std::endl;
	n1 = fac.createOperand(eint_8t, "33");
	std::cout << n1->toString() << std::endl;
	std::cout << "------------------------------" << std::endl;
	q.pop_front();
	q.pop_front();
	q.pop_front();
	const IOperand * dblz = fac.createOperand(edouble, "1.0");
	const IOperand * dbla = fac.createOperand(edouble, "0.0");
	q.push_front(dbla);
	n1 = q.front();
	q.push_front(dblz);
	n2 = q.front();
	std::cout << "testing div by zero" << std::endl;
	ret = *n1 / *n2;
	ret = *n1 - *n2;
	q.push_front(ret);
	for (auto i = q.cbegin();i != q.cend();i++)
		std::cout << (*i)->toString() << std::endl;
	std::cout << "------------------------------" << std::endl;
	q.push_front(ret);
	} catch (std::exception & e) {
		std::cout << "\nhere" << std::endl;
		std::cout << e.what() << std::endl;
	} catch (...) {
		std::cout << "Unknow exception raised" << std::endl;
	}
}
