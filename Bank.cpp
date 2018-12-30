/**

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

These includes should be in the Bank.hpp!!

**/
#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank(){}

Account Bank::openFile(){

	std::ifstream file;
	std::string file_name = "text.txt";
	std::string token;
	std::vector<std::string> info;

	file.open(file_name.c_str());

	while(file >> token){
		//std::cout<<token<<std::endl;
		info.push_back(token);
	}

	



}





