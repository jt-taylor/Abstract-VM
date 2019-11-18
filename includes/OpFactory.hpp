#ifndef OPFACTORY_HPP
# define OPFACTORY_HPP
# include "IOperand.hpp"
# include "Operator.hpp"

class OpFactory{
	public:
	OpFactory();
	OpFactory(OpFactory const & ref);
	OpFactory & operator=( OpFactory const & ref );
	virtual ~OpFactory();

	//must use factory method for creation
	IOperand const * createOperand( eOperandType type, std::string const & value );
	static IOperand const *(OpFactory::*ftable[5])(std::string const &) const;

	//depending on enum use one of these, must use array for enum values
	private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};
#endif
