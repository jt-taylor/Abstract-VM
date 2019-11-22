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
ex_Overflow::ex_Overflow()
{
	this->error_str = "Missing exit < ;; > instruction";
}
const char*	ex_Overflow::what() const throw()
{
	return (this->error_str.c_str());
}
ex_Overflow::~ex_Overflow() _NOEXCEPT {};
//Underflow
ex_Underflow::ex_Underflow()
{
	this->error_str = "Missing exit < ;; > instruction";
}
const char*	ex_Underflow::what() const throw()
{
	return (this->error_str.c_str());
}
ex_Underflow::~ex_Underflow() _NOEXCEPT {};
//BadByZero
ex_BadByZero::ex_BadByZero()
{
	this->error_str = "( / || % ) by zero";
}
const char*	ex_BadByZero::what() const throw()
{
	return (this->error_str.c_str());
}
ex_BadByZero::~ex_BadByZero() _NOEXCEPT {};
//AssertIsFalse
ex_AssertIsFalse::ex_AssertIsFalse()
{
	this->error_str = "Assert is false";
}
const char*	ex_AssertIsFalse::what() const throw()
{
	return (this->error_str.c_str());
}
ex_AssertIsFalse::~ex_AssertIsFalse() _NOEXCEPT {};
//MissingValues
ex_MissingValues::ex_MissingValues()
{
	this->error_str = "Missing Values";
}
const char*	ex_MissingValues::what() const throw()
{
	return (this->error_str.c_str());
}
ex_MissingValues::~ex_MissingValues() _NOEXCEPT {};
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
ex_BadPopInstruction::ex_BadPopInstruction()
{
	this->error_str = "Pop on empty stack instruction";
}
ex_BadPopInstruction::ex_BadPopInstruction(const std::string & str)
{
	this->error_str = "Pop on empty stack instruction";
}
const char*	ex_BadPopInstruction::what() const throw()
{
	return (this->error_str.c_str());
}
ex_BadPopInstruction::~ex_BadPopInstruction() _NOEXCEPT {};
