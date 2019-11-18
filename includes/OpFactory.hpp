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
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

	//depending on enum use one of these, must use array for enum values
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;
};
	typedef IOperand const * (OpFactory::*(std::string const &) const);
#endif
