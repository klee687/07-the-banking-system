#include "Create_Customer.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


Create_Customer::Create_Customer(){}

void Create_Customer::create_customer(std::string file_name){
	Transaction money;
	Account account;
	Bank bank(customer.get_ID());
	Customer customer;
	std::ifstream file;
	std::vector<std::string> temp_vector;
	std::string token, pwd;
			
	int vector_size;
	file.open(file_name.c_str());
	while(file >> token){
		temp_vector.push_back(token);
	}

	vector_size = temp_vector.size(); 

	if(vector_size == 6){

		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		account.set_account_name_C("chequing");
		account.set_account_name_S("saving");
		account.set_chequing_balance(atof(temp_vector[2].c_str()));
		account.set_saving_balance(atof(temp_vector[3].c_str()));
		customer.set_password(temp_vector[4]);
		setup(account, customer);		
	}
	else if(vector_size == 5){
		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		if (temp_vector[4] == "C"){
			account.set_account_name_C("chequing");
			account.set_chequing_balance(atof(temp_vector[2].c_str()));
			setup(account, customer);
		}else if(temp_vector[4] == "S"){
			account.set_account_name_S("saving");
			account.set_saving_balance(atof(temp_vector[2].c_str()));
			customer.set_password(temp_vector[3]);
			setup(account, customer);
		}
		
	}
	else {
		std::cout << "Invalid" << std::endl;
		return;
	}
	
	password(customer, file_name, temp_vector);
	bank.summary(customer,account);
	money.transaction(account, temp_vector, file_name);
}


//Now lets add the account to customer's Account vector !
void Create_Customer::setup(Account account, Customer customer){
	account.set_customer(&customer);
	customer.add_account(account);
}


void Create_Customer::password(Customer customer, std::string file_name, std::vector<std::string> temp_vector){
	std::string pwd;
	std::cout << "Password :  " << std::endl;
	std::cin >> pwd;
	if (customer.get_password() != pwd){
		std::cout << "wrong pwd" << std::endl;
		create_customer(file_name);
	}
	else{
		std::cout << "Correct Password" << std::endl;
	}
}
