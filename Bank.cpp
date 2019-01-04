

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Bank.hpp"
#include "Account.hpp"
#include "Customer.hpp"

Bank::Bank(std::string ID): ID(ID) {}

void Bank::summary(Customer customer, Account account){
	std::cout << "ID:		" << customer.get_ID() << std::endl;
	std::cout << "Name:		" << customer.get_name() << std::endl;
	
	if (account.get_account_name_C() == "chequing") std::cout <<"Chequing:	" << account.get_chequing_balance() << std::endl;
	if (account.get_account_name_S() == "saving") std::cout <<  "Saving:		" << account.get_saving_balance() <<std::endl;	
}





