#include "Create_Customer.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


Create_Customer::Create_Customer(){}

void Create_Customer::create_customer(std::string file_name){
	Account account;
	Bank bank(customer.get_ID());
	Customer customer;
	std::ifstream file;
	std::vector<std::string> temp_vector;
	std::string token;
			
	int vector_size;
	file.open(file_name.c_str());
	while(file >> token){
		temp_vector.push_back(token);
	}

	vector_size = temp_vector.size(); 

	if(vector_size == 5){

		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		account.set_account_name_C("chequing");
		account.set_account_name_S("saving");
		account.set_chequing_balance(atof(temp_vector[2].c_str()));
		account.set_saving_balance(atof(temp_vector[3].c_str()));
		setup(account, customer);		
	}
	else if(vector_size == 4){
		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		if (temp_vector[3] == "C"){
			account.set_account_name_C("chequing");
			account.set_chequing_balance(atof(temp_vector[2].c_str()));
			setup(account, customer);
		}else if(temp_vector[3] == "S"){
			account.set_account_name_S("saving");
			account.set_saving_balance(atof(temp_vector[2].c_str()));
			setup(account, customer);
		}
		
	}
	else std::cout << "invalid. vector size overflow\n" << std::endl;

	bank.summary(customer,account);	
	Transaction money;
	money.transaction(account, temp_vector, file_name);
}


//Now lets add the account to customer's Account vector !
void Create_Customer::setup(Account account, Customer customer){
	account.set_customer(&customer);
	customer.add_account(account);
}
