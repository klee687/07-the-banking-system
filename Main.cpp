//#include "Maintenance.hpp"
#include "Create_Customer.hpp"
#include "Customer.hpp"
#include "Account.hpp"
#include "Manager.hpp"
#include "Bank.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
	Create_Customer CC;
	Customer customer;
	Account account;		
void input(){
	std::string id;
	std::cout << "User's ID : \n" << std::endl;
	std::cin >> id;
	std::string id_input = id+".txt";
	std::ifstream ifile(id_input);
	if (ifile) {
		std::cout << "This ID exists \n" << std::endl;
		CC.create_customer(id_input);		
	}
	else{
		std::cout << "There is an issue with the file name, or the customer does not exist" << std::endl; //cute error message   ->>>>>>>>>>>> CUZ IM SYO FUCKING KAWAII! :3
	}
} //input closing 


int main(){
			std::cout << "------------------ATM------------------" std::endl;
			st						

} // main closing


