#include "OpFactory.hpp"

OpFactory::Opfactory(){}
OpFactory::Opfactory(const OpFactory & ref){
	static_cast<void>(ref);
}
OpFactory & OpFactory::Opfactory(const OpFactory & ref){
	static_cast<void>(ref);
	return (*this);
}
OpFactory::~Opfactory(){}
// create with factory method ---------------------------------------------------
IOperand const * OpFactory::createInt8(std::string const & ref) const
{return new Operand<int8_t>(ref);}
IOperand const * OpFactory::createInt16(std::string const & ref) const
{return new Operand<int16_t>(ref);}
IOperand const * OpFactory::createInt32(std::string const & ref) const
{return new Operand<int32_t>(ref);}
IOperand const * OpFactory::createFloat(std::string const & ref) const
{return new Operand<float>(ref);}
IOperand const * OpFactory::createDouble(std::string const & ref) const
{return new Operand<double>(ref);}

// create ----------------------------------------------------------------------
IOperand const * OpFactory::createOperand( eOperandType type, std::string const & ref) const
{
	//array of function pointers
	static (IOperand const *)(* arr[](std::string const & ref) = {
				&createInt8,
				&createInt16,
				&createInt32,
				&createFloat,
				&createDouble
			};
	IOperand const * ret = 0;
	try {
		arr[type](ref);
	}

}
