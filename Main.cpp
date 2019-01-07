//#include "Maintenance.hpp"
#include "Create_Customer.hpp"
#include "Customer.hpp"
#include "Account.hpp"
#include "Manager.hpp"
#include "Open_Account.hpp"
#include "Bank.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
	Customer customer;
	Account account;
	Create_Customer CC;	
/*
void login(){
	std::string id, pwd;
	//std::string id_input = id+".txt";
	//std::ifstream ifile(id_input);

	std::cout << "------------------ATM------------------" << std::endl;
	std::cout << "Insert your ID and password" << std::endl;
	std::cout << "ID :	" <<std::endl;
	std::cin >> id;

	std::string id_input = id+".txt";
	std::ifstream ifile(id_input);
	CC.create_customer(id_input);
	std::cout << account.get_saving_balance() << std::endl;
	std::cout << customer.get_password() << std::endl;
	if (!ifile){
		std::cout << "Invalid ID." << std::endl;
		login();
	}
	
	CC.create_customer(id_input);
	std::cout << "Password :	" << std::endl;
	std::cin >> pwd;
	std::cout << customer.get_password() << std::endl;
	if (customer.get_password()) != pwd){
		std::cout << "wrong password. Try again." << std::endl;	
		login();
	}
	
	

}		
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

*/
int main(){

	std::string id;
	std::cout << "------------------ATM------------------" << std::endl;
	std::cout << "Insert your ID and password" << std::endl;
	std::cout << "ID :	" <<std::endl;
	std::cin >> id;
	std::string id_input = id+".txt";
	CC.create_customer(id_input);		
} // main closing






















