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

