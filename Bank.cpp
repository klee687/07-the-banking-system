

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Bank.hpp"
#include "Account.hpp"
#include "Customer.hpp"

Bank::Bank(std::string ID): ID(ID) {}

void Bank::summary(Customer customer, Account account, int v_size){
	customer.print_summary();
	if (account.get_chequing_balance() != 0.000000){
			std::cout << "Chequing: " << account.get_chequing_balance() << std::endl;
	}
	
	if (account.get_saving_balance() != 0.000000){
			std::cout << "Saving: " << account.get_saving_balance() << std::endl;
	}
}





