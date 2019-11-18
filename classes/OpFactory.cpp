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

IOperand const * (OpFactory::*(OpFactory::ftable[5]))(std::string const &) const =
{
	&OpFactory::createInt8,
	&OpFactory::createInt16,
	&OpFactory::createInt32,
	&OpFactory::createFloat,
	&OpFactory::createDouble
};

// create ----------------------------------------------------------------------
IOperand const * OpFactory::createOperand( eOperandType type, std::string const & ref)
{
	IOperand const * ret = 0;
	try {
		if (type >= 5)
			;
		//	throw out of jumptable index
		ret = (this->*ftable[type])(ref);
	} catch (std::exception & e) {
	std::cerr << e.what();
	throw;
	} catch (...) {
	std::cerr << "unknow exception in create operand" << std::endl;
	throw;
	}
	return ret;
}
