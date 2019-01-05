#include "Manager.hpp"
#include "Transaction.hpp"
#include <iterator>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


Transaction::Transaction(){}

void Transaction::transaction(Account account, std::vector<std::string> temp_vector, std::string file_name){
	int a1, a2, a3, a4; // a1, a2, 
	double c_dep, s_dep;
	std::ofstream output_file(file_name);
label1:	std::cout << "\n[1] Deposit\n[2] Withdrawal\n[3] Move money from C -> S\n[4] Move money from S -> C" << std::endl;
	std::cin >> a1;
	if (a1 == 1){
		std::cout << "[1] Chequing deposit\n[2] Saving deposit" << std::endl;
		std::cin >> a2;
		if (a2 == 1){
			if (account.get_account_name_C() != "chequing"){
				std::cout << "You might not have a chequing account." <<std::endl;	
				goto label1;
			}else{
				std::cout << "How much do you want to deposit in your chequing account?		: " <<std::endl;
				std::cin >> c_dep;
				account.set_chequing_balance(account.get_chequing_balance()+c_dep);
				std::cout << "Your chequing balance is now $" << account.get_chequing_balance() << std::endl;
				temp_vector[2] = std::to_string(account.get_saving_balance());
	std::ostream_iterator<std::string> output_iterator(output_file, " ");
	std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);				
			}
	/*a1*/	}else if (a2 == 2){
			if (account.get_account_name_S() != "saving"){
				std::cout << "You might not have set up your saving account. " << std::endl;
				goto label1;
			}else{
				std::cout << "How much do you want to deposit in your saving account?	:" << std::endl;
				std::cin >> s_dep;
				account.set_saving_balance(account.get_saving_balance()+s_dep);
				std::cout << "your saving balance is now $" << account.get_saving_balance() << std::endl;
				if (temp_vector[3] == "S"){
					temp_vector[2] = std::to_string(account.get_saving_balance());
	std::ostream_iterator<std::string> output_iterator(output_file, " ");
	std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);
				}	
			}
	} // a1
}//transaction 

}

