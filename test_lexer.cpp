#include "lexertk.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
//static void	read_file_in_to_vector(std::string file_path, std::vector<std::string> & v)
//{
//	std::ifstream	in(file_path.c_str());
//	std::string		tmp;
//
//	if (!in)
//		throw (ex_FileOpen(file_path));
//
//	while (std::getline(in,tmp))
//	{
//		if (tmp.size() > 0)
//			v.push_back(tmp);
//	}
//	in.close();
//	return ;
//}

int		main(void)
{
	//std::vector<std::string> test;
	//read_file_in_to_vector("./test_in.txt", v);
	std::string	tmp;
	std::string	ins;
	std::ifstream in("./test_in.txt");

	lexertk::generator gen;
	while (std::getline(in,tmp))
	{
		if (!gen.process(tmp))
			std::cout << "fail\n";
		else
		{
			lexertk::helper::dump(gen);
			std::cout << std::endl;
		}
	}
//	for (auto i = v.begin();i != v.end();i++)
//	{
//		if (*i.front() == ';')
//			continue ;
//		gen
//	}
	return 0;
}
