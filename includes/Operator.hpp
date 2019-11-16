#ifndef OPERATOR_HPP
# define OPERATOR_HPP
# include "OpFactory.hpp"
# include "IOperand.hpp"
# include "our_exceptions.hpp"
# include <string>
# include <limits.h>

template <class T>
class Operand:public IOperand
{
	public:
	Operand();
	Operand(T v);
	Operand(Operand const & ref);
	Operand & operator=( Operand const & ref );
	~Operand();

}
#endif
