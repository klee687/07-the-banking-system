#include "Create_Manager.hpp"
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>

Create_Manager::Create_Manager(){}

void Create_Manager::create_manager(std::string file_name, Manager manager){
	std::ifstream file;
	std::vector<std::string> vectr;
	std::string token, pwd; 
	file.open(file_name.c_str());
	while (file >> token) {
		vectr.push_back(token);	
	}

	manager.set_ID(vectr[0]);
	manager.set_password(vectr[1]);
	manager.add_manager(manager);
	std::cout << manager.get_ID() << std::endl;	
	std::cout << manager.get_password() << std::endl;
}
