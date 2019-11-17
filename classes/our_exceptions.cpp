#include "our_exceptions.hpp"

unsigned int line_number = 1;

// FileOpen --------------------------------------------------------------------
ex_FileOpen::ex_FileOpen(std::string const & ref)
{
	this->error_str = "Error opening <" + ref + " >";
}
const char*	ex_FileOpen::what() const _NOEXCEPT
{
	return (this->error_str.c_str());
}
ex_FileOpen::~ex_FileOpen() _NOEXCEPT {};
// NoExitInstruction -----------------------------------------------------------
ex_NoExitInstruction::ex_NoExitInstruction()
{
	this->error_str = "Missing exit < ;; > instruction";
}
const char*	ex_NoExitInstruction::what() const throw()
{
	return (this->error_str.c_str());
}
ex_NoExitInstruction::~ex_NoExitInstruction() _NOEXCEPT {};
//Overflow
//Underflow
//BadByZero
//AssertIsFalse
//MissingValues
//UnknownInstruction
ex_UnknownInstruction::ex_UnknownInstruction()
{
	this->error_str = "Unknown instruction < ?? > instruction";
}
ex_UnknownInstruction::ex_UnknownInstruction(const std::string & str)
{
	this->error_str = "Unknown instruction < " + str + " > instruction";
}
const char*	ex_UnknownInstruction::what() const throw()
{
	return (this->error_str.c_str());
}
ex_UnknownInstruction::~ex_UnknownInstruction() _NOEXCEPT {};
//BadPopInstruction
