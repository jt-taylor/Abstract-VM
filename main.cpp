#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "lexertk.hpp"
#include "our_exceptions.hpp"
#include "command_prototypes.hpp"
#include "IOperand.hpp"
#include "OpFactory.hpp"


static void	read_from_cin_to_vector(std::vector<std::string> & v)
{
	std::string tmp;
	while (std::getline(std::cin, tmp))
		v.push_back(tmp);
	auto t = v.end();
	//if (t->compare(0, 2, ";;") == 0)
	if (v.empty())
		throw (ex_NoExitInstruction());
	if (t->find(std::string(";;"), 0) != std::string::npos)
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
	// command list
	std::string			arr_comp[] =
	{
		"push",
		"pop",
		"dump",
		"assert",
		"add",
		"sub",
		"mul",
		"div",
		"mod",
		"print",
		"exit"
	};
	// type list
	std::string		arr_type[] =
	{
		"int8",
		"int16",
		"int32",
		"float",
		"double"
	};
	int				found_exit = 0;
	int				i = 0;
	int				j = 0;
	lexertk::generator	gen;
	auto iter = v.begin();
	std::deque<const IOperand *>	q;
	OpFactory fac;

	// parse line by line
	while (iter != v.end())
	{
		//std::cout << "Input string < " <<  *iter << " >" + std::endl;
		if (!gen.process(iter->c_str()))
		{
			std::cout << "Lexer parser error" << std::endl;
			throw (ex_UnknownInstruction(*iter));
		}
		//ignore comments
		if (iter->at(0) == ';' && !found_exit)
		{
			line_number++;
			iter++;
			continue ;
		}
		else
		{
			lexertk::token t = gen[0];
			for (i = 0; i < 12;i++)
			{
				if (arr_comp[i].compare(t.value) == 0)
					break;
			}
			switch (i)
			{
				// instruction push  -> check data type and value
				case 1: {
							for (j = 0; j < 5;j++)
							{
								if (arr_comp[i].compare(t.to_str(t.type)) == 0)
									break;
							}
							t = gen[3];
							if (j > 4)
								throw (ex_UnknownInstruction());
							else
								stack_interface_command__push(q, static_cast<eOperandType>(j),
										fac, std::string(t.value));
						}
				//pop
				case 2: {
					stack_interface_command__pop(q, eint_8t, fac, std::string());}
				// dump
				case 3: {
					stack_interface_command__dump(q, eint_8t, fac, std::string());}
				// assert
				case 4: {
							for (j = 0; j < 5;j++)
							{
								if (arr_comp[i].compare(t.value) == 0)
									break;
							}
							t = gen[3];
							if (j > 4)
								throw (ex_UnknownInstruction());
							else
								stack_interface_command__assert(q, static_cast<eOperandType>(j),
										fac, std::string(t.value));
						}
				// add
				case 5: {
					stack_interface_command__add(q, eint_8t, fac, std::string());}
				// sub
				case 6: {
					stack_interface_command__sub(q, eint_8t, fac, std::string());}
				// mul
				case 7: {
					stack_interface_command__mul(q, eint_8t, fac, std::string());}
				// div
				case 8: {
					stack_interface_command__div(q, eint_8t, fac, std::string());}
				// mod
				case 9: {
					stack_interface_command__mod(q, eint_8t, fac, std::string());}
				// print
				case 10: {
					stack_interface_command__print(q, eint_8t, fac, std::string());}
				// exit
				case 11: {
					stack_interface_command__exit(q, eint_8t, fac, std::string());}
			}
			if (i > 11)
				throw (ex_UnknownInstruction());
		}
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
