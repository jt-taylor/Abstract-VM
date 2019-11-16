#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "lexertk.hpp"
#include "our_exceptions.hpp"

static void	read_from_cin_to_vector(std::vector<std::string> & v)
{
	std::string tmp;
	while (std::getline(std::cin, tmp))
		v.push_back(tmp);
	auto t = v.end();
	if (t->compare(0, 2, ";;") != 0)
		throw (ex_NoExitInstruction());
}

static void	read_file_in_to_vector(std::string file_path, std::vector<std::string> & v)
{
	std::ifstream	in(file_path.c_str());
	std::string		tmp;

	if (!in)
		throw (ex_FileOpen(file_path));

	while (std::getline(in,tmp))
	{
		if (tmp.size() > 0)
			v.push_back(tmp);
	}
	in.close();
	return ;
}

static int	do_the_vm(std::vector<std::string> & v)
{
	lexertk::generator	gen;
	auto iter = v.begin();
	while (iter != v.end())
	{
		std::cout << *iter << std::endl;
		if (!gen.process(iter->c_str()))
		{
			std::cout << "Lexer parser error" << std::endl;
			throw (ex_UnknownInstruction(*iter));
		}
		else
		{
			//lexertk::helper::dump(gen);
			//std::cout << "\n";
			;
		}
		if (iter->at(0) == ';')
		{
			line_number++;
			iter++;
			continue ;
		}
		if (0)//check valid command *i
			break;
		line_number++;
		iter++;
	}
	//if (strcmp(iter->c_str(),";;") != 0)
	//	throw (ex_NoExitInstruction());
	return (0);
}

int			main(int ac, char **argv)
{
	std::vector<std::string>	v;
	try {
	if (ac == 1)
		//read from cin
		read_from_cin_to_vector(v);
	else if (ac == 2)
		//read from file;
		read_file_in_to_vector(std::string(argv[1]), v);
	else
		//too many parameters
		std::cout << "Too many arguments" << std::endl;
	// do the vm
	do_the_vm(v);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	} catch (...) {
		;
	}
	return (0);
}
