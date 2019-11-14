#ifndef OUR_EXCEPTIONS_HPP
# define OUR_EXCEPTIONS_HPP

#include <iostream>
#include <string>
#include <exception>

/*
** this will hold all of our exception classses ,
** -	none of the exceptions will throw scalars
** -	they will all inherete from std::exception
*/

/*
** You can probably template this but i don't think it would actually be less code
** also not sure if i should move these into a namespace
*/

extern unsigned int	line_number;

class ex_FileOpen: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_FileOpen(std::string const & ref);
};

class ex_NoExitInstruction: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_NoExitInstruction();
};

class ex_Overflow: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_Overflow();
};

class ex_Underflow: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_Underflow();
};
class ex_BadByZero: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_BadByZero();
};
class ex_AssertIsFalse: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_AssertIsFalse();
};
class ex_MissingValues: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_MissingValues();
};
class ex_UnknownInstruction: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_UnknownInstruction();
};
class ex_BadPopInstruction: public std::exception
{
	private:
		std::string		error_str;
	public:
		const char *what() const throw();
		ex_BadPopInstruction();
};
#endif
