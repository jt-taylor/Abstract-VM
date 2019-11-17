#include "OpFactory.hpp"

OpFactory::OpFactory(){}
OpFactory::OpFactory(const OpFactory & ref){
	static_cast<void>(ref);
}
OpFactory & OpFactory::operator = (const OpFactory & ref){
	static_cast<void>(ref);
	return (*this);
}
OpFactory::~OpFactory(){}
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
	static IOperand const * (arr[](std::string const & ref)) = {
				&OpFactory::createInt8,
				&OpFactory::createInt16,
				&OpFactory::createInt32,
				&OpFactory::createFloat,
				&OpFactory::createDouble
			};
	IOperand const * ret = 0;
	try {
		ret = arr[type](ref);
	} catch (std::exception & e) {
	std::cerr << e.what();
	throw;
	} catch (...) {
	std::cerr << "unknow exception in create operand" << std::endl;
	throw;
	}
	return ret;
}
