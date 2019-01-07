#include "Customer.hpp"
#include "Create_Manager.hpp"
#include "Account.hpp"
#include "Open_Account.hpp"
#include "Transaction.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <vector>
#include <fstream>

Open_Account::Open_Account(){}

void Open_Account::open_acc(std::vector<std::string> temp_vector, Account account, std::string file_name){
	Manager m;
	Create_Manager cm;
	cm.create_manager("manager.txt", m);
	std::string c_deposit, s_deposit, manager_id, manager_pwd;
	int answr;

	std::cout << "Manager ID: " << std::endl;
	std::cin >> manager_id;
	std::cout << "This" << m.get_ID() <<std::endl;
	if (m.get_ID() != manager_id){
		std::cout << "Wrong ID or it does not exist\n" << std::endl;	
		open_acc(temp_vector, account, file_name);
	}
	std::cout << "password: " << std::endl;
	std::cin >> manager_pwd;
	if (m.get_password() !=  manager_pwd){
		std::cout << "Wrong password " <<std::endl;
		open_acc(temp_vector, account, file_name);

	}else{
		std::cout << "Correct password" << std::endl;
}
		std::cout << "Account Open" << std::endl;
		std::cout << "[1] chequing account\n[2] saving account \n[3] both" << std::endl;
		std::cin >> answr;
		if (answr == 1){
			if (account.get_account_name_C() == "chequing" ){
				std::cout << "you already have a chequing account." << std::endl;
			}
			
			else{
				std::cout << "How much do you want to deposit in your Chequing account?" << std::endl;
				std::cin >> c_deposit;
				if (atof(c_deposit.c_str()) <= 0) {
					std::cout << "it should be more than $0. Please try again!" << std::endl;
					open_acc(temp_vector, account, file_name);
				}
				account.set_account_name_C("chequing");
				account.set_chequing_balance(atof(c_deposit.c_str()));				
				temp_vector.insert(temp_vector.begin() + 2, c_deposit);
				temp_vector.insert(temp_vector.begin() + 5, "CS");
				
				std::ofstream output_file(file_name);
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end() -1, output_iterator);	
			}

		}else if (answr == 2){
			if (account.get_account_name_S()=="saving"){
				std::cout << "you already have a saving account." << std::endl;
			}else{
				std::cout << "How much do you want to deposit in youe Saving account?" << std::endl;
				std::cin >> s_deposit;
				if (atof(s_deposit.c_str()) <= 0) {
					std::cout << "it should be more than $0. Please try again!" << std::endl;
					open_acc(temp_vector, account, file_name);
				}
				account.set_saving_balance(atof(s_deposit.c_str()));
				account.set_account_name_S("saving");
				temp_vector.insert(temp_vector.begin() + 3, s_deposit);
				temp_vector.insert(temp_vector.begin() + 5, "CS");	
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
