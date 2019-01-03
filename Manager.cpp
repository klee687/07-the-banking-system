#include "Customer.hpp"
#include "Account.hpp"
#include "Manager.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <vector>
#include <fstream>

Manager::Manager(std::string ID) : ID(ID) {}



void Manager::add_account(Account account){
	//isteam -> writing new account
}


void Manager::open_acc(std::vector<std::string> temp_vector, Account account, std::string file_name){	
	std::string c_deposit;
	std::string s_deposit;
	int answr;
	std::cout << "Account Open" << std::endl;
		std::cout << "[1] chequing account\n[2] saving account \n[3] both" << std::endl;
		std::cin >> answr;
		if (answr == 1){
			if (account.get_chequing_balance() != 0){
				std::cout << "you already have a chequing account." << std::endl;
			}
			
			else{
		label_1:	std::cout << "How much do you want to deposit in youe Chequing account?" << std::endl;
				std::cin >> c_deposit;
				if (atof(c_deposit.c_str()) <= 0) {
					std::cout << "it should be more than $0. Please try again!" << std::endl;
					goto label_1;
				}
				account.set_chequing_balance(atof(c_deposit.c_str()));
				account.set_account_name("chequing");
				temp_vector.insert(temp_vector.begin() + 2, c_deposit);
				temp_vector.insert(temp_vector.begin() + 4, "CS");
				
				std::ofstream output_file(file_name);
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end() -1, output_iterator);		
			}

		}else if (answr == 2){
			if (account.get_saving_balance() != 0){
				std::cout << "you already have a saving account." << std::endl;
			}else{
		label_2:	std::cout << "How much do you want to deposit in youe Saving account?" << std::endl;
				std::cin >> s_deposit;
				if (atof(s_deposit.c_str()) <= 0) {
					std::cout << "it should be more than $0. Please try again!" << std::endl;
					goto label_2;
				}
				account.set_saving_balance(atof(s_deposit.c_str()));
				account.set_account_name("saving");
				temp_vector.insert(temp_vector.begin() + 3, s_deposit);
				temp_vector.insert(temp_vector.begin() + 4, "CS");	
				std::ofstream output_file(file_name);
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end()-1, output_iterator);
			}
		}else if (answr ==3){
			if (account.get_chequing_balance() != 0 || account.get_saving_balance() != 0){
				std::cout << "Both" << std::endl;
			}
		}else{
			std::cout << "wrong input" << std::endl; 
		}
}
