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
//	static IOperand const * (* arr[5](std::string const & ref)) = {
	static IOperand const * arr[5] = {
				arr[0] = &OpFactory::createInt8,
				0,
				0,
				0,
				0
				//this->createInt16,
				//this->createInt32,
				//this->createFloat,
				//this->createDouble
			};
	IOperand const * ret = 0;
	try {
		if (type >= sizeof(arr))
			;
		//	throw out of jumptable index
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
