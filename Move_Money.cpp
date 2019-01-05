#include "Move_Money.hpp"
#include <iterator>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Move_Money::Move_Money(){}

void Move_Money::c_to_s(Account account, std::vector<std::string> temp_vector, std::string file_name){
	Transaction t;
	double cs;
	std::ofstream output_file(file_name);
	std::cout << "How much money do you want to move from Chequing to Saving?" << std::endl;
	std::cin >> cs;
	if (cs >= account.get_chequing_balance()){
		std::cout << "Too much money to move. Try again" << std::endl;
		c_to_s(account, temp_vector, file_name);
	}

	else{
		if (account.get_account_name_C() != "chequing" || account.get_account_name_S() != "saving"){
			std::cout << "you dont have either chequing or saving account. Too bad :/" << std::endl;
			t.transaction(account, temp_vector, file_name);
		}

		sub_move(account, temp_vector, file_name, cs, 1);
	} //else
}

void Move_Money::s_to_c(Account account, std::vector<std::string> temp_vector, std::string file_name){
	Transaction t;
	double cs;
//	std::ofstream output_file(file_name);
	std::cout << "How much money do you want to move from Saving to Chequing?" << std::endl;
	std::cin >> cs;
	if (cs >= account.get_saving_balance()){
		std::cout << "Too much money to move. Try again" << std::endl;
		s_to_c(account, temp_vector, file_name);
	}

	else{
		if (account.get_account_name_C() != "chequing" || account.get_account_name_S() != "saving"){
			std::cout << "you dont have either chequing or saving account. Too bad :/" << std::endl;
			t.transaction(account, temp_vector, file_name);
		}
		sub_move(account, temp_vector, file_name, cs, 2);
	} //else
}


void Move_Money::sub_move (Account account, std::vector<std::string> temp_vector, std::string file_name, double cs, int i){
	std::ofstream output_file(file_name);
	if (i == 1){ // C to S
		account.set_chequing_balance( account.get_chequing_balance() - cs );
		account.set_saving_balance( account.get_saving_balance() + cs) ; 
		std::cout << "Chequing Balance : " << account.get_chequing_balance() << "\n" << "Saving Balance : " << account.get_saving_balance() << std::endl;
	}



	else if (i == 2){ // S to C 
		account.set_chequing_balance( account.get_chequing_balance() + cs );
		account.set_saving_balance( account.get_saving_balance() - cs) ; 
		std::cout << "Chequing Balance : " << account.get_chequing_balance() << "\n" << "Saving Balance : " << account.get_saving_balance() << std::endl;
	}

	temp_vector[2] = std::to_string(account.get_chequing_balance());
	temp_vector[3] = std::to_string(account.get_saving_balance());
	std::ostream_iterator<std::string> output_iterator(output_file, " ");
	std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);

}
