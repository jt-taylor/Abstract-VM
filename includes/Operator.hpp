#ifndef OPERATOR_HPP
# define OPERATOR_HPP
# include "OpFactory.hpp"
# include "IOperand.hpp"
# include "our_exceptions.hpp"
# include <string>
# include <iostream>
# include <limits.h>

template <typename T>
class Operand:public IOperand
{
	public:
	Operand();
	Operand(T v);
	Operand(Operand const & ref);
	Operand & operator=( Operand const & ref );
	Operand(std::string & ref);
	Operand(const std::string & ref, eOperandType n);
//	Operand<T>(std::string & ref);
	Operand(std::string const & ref);
	~Operand();

	int		getPrecision(void) const;
	eOperandType	getType(void) const;
	std::string const & toString(void) const;

	IOperand const * operator + (IOperand const & ref) const;
	IOperand const * operator - (IOperand const & ref) const;
	IOperand const * operator / (IOperand const & ref) const;
	IOperand const * operator * (IOperand const & ref) const;
	IOperand const * operator % (IOperand const & ref) const;

	std::string		peek(void);
	private:
	std::string		value;
	T				data;
};

// Operator.cpp
	template<class T>
	Operand<T>::Operand(){
		this->value = std::to_string(static_cast<T>(0));
	}
	template<class T>
	Operand<T>::Operand(Operand<T> const & ref){
		*this = ref;
	}
	template<class T>
	Operand<T>::Operand(std::string & ref){
		this->value = ref;
	}
	template<class T>
	Operand<T>::Operand(std::string const & ref){
		this->value = ref;
	}
	template<class T>
	Operand<T>::Operand(std::string const & ref, eOperandType n){
		if (n)
			;
		this->value = ref;
		this->data = static_cast<T>(stod(ref));
	}
	template<class T>
	Operand<T>::Operand(T val){
		this->value = std::to_string(val);
	}
	template<class T>
	Operand<T> & Operand<T>::operator=(Operand<T> const & ref ){
		this->value = ref.peek();
	}
	template<class T>
	Operand<T>::~Operand(){
	}

//peek -------------------------------------------------------------------------
	template<class T>
	std::string const & Operand<T>::toString(void) const
	{
		return (this->value);
	}
	template<class T>
	std::string Operand<T>::peek(void)
	{
		return (this->value);
	}
// getPrecision && getType -----------------------------------------------------
//		enum eOperandType {int_8t, int_16t, int_32t, float, double };
template<>
int		Operand<int8_t>::getPrecision(void) const
{return (eint_8t);}
template<>
eOperandType Operand<int8_t>::getType(void) const
{return eint_8t;}

template<>
int		Operand<int16_t>::getPrecision(void) const
{return (eint_16t);}
template<>
eOperandType Operand<int16_t>::getType(void) const
{return eint_16t;}

template<>
int		Operand<int32_t>::getPrecision(void) const
{return (eint_32t);}
template<>
eOperandType Operand<int32_t>::getType(void) const
{return eint_32t;}

template<>
int		Operand<float>::getPrecision(void) const
{return (efloat);}
template<>
eOperandType Operand<float>::getType(void) const
{return efloat;}

template<>
int		Operand<double>::getPrecision(void) const
{return (edouble);}
template<>
eOperandType Operand<double>::getType(void) const
{return edouble;}

// logical checks --------------------------------------------------------------
//mode == 1 -> add ;; mode == 2 -> mul ;; mode == 0 ->err(?)
template <class T>
void		over_under_flow_check(T a, T b, int mode)
{
	if (mode == 1)
	{
		T sum = a + b;
		if ((a < 0) || (b < 0)) {
			if (sum > a)
				throw ex_Underflow(); }
		else
			if (sum < a)
				throw ex_Overflow();
	}
	else if (mode == 2)
	{
		T prod = a * b;
		if ((a < 0) ^ (b < 0)) {
			if (prod > a)
				throw ex_Underflow(); }
		else if (prod < a)
			throw ex_Overflow();
	}
	return ;
}

// Operators -------------------------------------------------------------------
template <class T>
IOperand const * Operand<T>::operator + (IOperand const & ref) const
{
	if (this->getPrecision() < ref.getPrecision())
		return (ref + *this);
	try {
		T n1 = static_cast<T>(stod(this->value));
		T n2 = static_cast<T>(stod(ref.toString()));
		over_under_flow_check(n1, n2, 1);
		//OperandFactory * factory = OperandFactory();
		//IOperand const * ret_val = factory->createOperand(this->getType), std::to_string(static_cast<T>(stod(this->value)));
		//return ret_val;
	} catch (std::exception & e) {
		std::cout << e.what();
	} catch (...) {
		std::cout << "missing exception in \'+\'" << std::endl;
		throw;
	}
	return (0);
}
#endif
