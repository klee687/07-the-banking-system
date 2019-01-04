//#include "Customer.hpp"
//#include "Account.hpp"
#include "Manager.hpp"
#include "Create_Customer.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


Create_Customer::Create_Customer(){}


//create customer object
void Create_Customer::create_customer(std::string file_name){
	Account account;
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

	//Check if size is 3 or 4. If it's 3, then they only made a checking account, if it's 4, then they made a saving accouunt too. Thankfully we have structure in our text file, so we know index 0: ID, index 1:name, index 2:checking, index 3: saving (optional)

	if(vector_size == 5){

		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		account.set_account_name_C("chequing"); // look at how ive implemented set_account_name in the Account class, so u dont get confused by this
		account.set_account_name_S("saving");
		account.set_chequing_balance(atof(temp_vector[2].c_str())); //THe value of the text file is 100, but it;'s a string. So we need to convert it to a double
		account.set_saving_balance(atof(temp_vector[3].c_str()));
		setup(account, customer);		
	}
	else if(vector_size == 4){
		customer.set_ID(temp_vector[0]);
		customer.set_name(temp_vector[1]);

		if (temp_vector[3] == "C"){
			account.set_account_name_C("chequing");
			account.set_chequing_balance(atof(temp_vector[2].c_str()));
			account.set_customer(&customer); 
			customer.add_account(account);				
		}else if(temp_vector[3] == "S"){
			account.set_account_name_S("saving");
			account.set_saving_balance(atof(temp_vector[2].c_str()));
			setup(account, customer);
		}
		
	}
	else std::cout << "invalid. vector size overflow\n" << std::endl;

	Bank bank(customer.get_ID());
	bank.summary(customer,account);	
}


void Create_Customer::setup(Account account, Customer customer){ //Now lets add the account to customer's Account vector !
	account.set_customer(&customer);
	customer.add_account(account);
}
