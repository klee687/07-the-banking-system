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
	int a1;
	std::ofstream output_file(file_name);
label1:	std::cout << "\n[1] Deposit\n[2] Withdrawal\n[3] Move money from C -> S\n[4] Move money from S -> C" << std::endl;
	std::cin >> a1;
	if (a1 == 1) deposit(account, temp_vector, file_name);
	else if (a1 == 2) withdrawal(account, temp_vector, file_name);
}


void Transaction::deposit(Account account, std::vector<std::string> temp_vector, std::string file_name){
	int a2;
	double c_dep, s_dep;
	std::ofstream output_file(file_name);

	std::cout << "[1] Chequing deposit\n[2] Saving deposit" << std::endl;
	std::cin >> a2;
	if (a2 == 1){
		if (account.get_account_name_C() != "chequing"){
			std::cout << "You might not have a chequing account." <<std::endl;	
			transaction(account, temp_vector, file_name);
		}else{
			std::cout << "How much do you want to deposit in your chequing account?		: " <<std::endl;
			std::cin >> c_dep;
			account.set_chequing_balance(account.get_chequing_balance()+c_dep);
			std::cout << "Your chequing balance is now $" << account.get_chequing_balance() << std::endl;
			temp_vector[2] = std::to_string(account.get_chequing_balance());
			std::ostream_iterator<std::string> output_iterator(output_file, " ");
			std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);				
		}
/*a1*/	}else if (a2 == 2){
		if (account.get_account_name_S() != "saving"){
			std::cout << "You might not have set up your saving account. " << std::endl;
			transaction(account, temp_vector, file_name);
		}else{
			std::cout << "How much do you want to deposit in your saving account?	:" << std::endl;
			std::cin >> s_dep;
			account.set_saving_balance(account.get_saving_balance()+s_dep);
			std::cout << "your saving balance is now $" << account.get_saving_balance() << std::endl;
			if (temp_vector[3] == "S"){
				temp_vector[2] = std::to_string(account.get_saving_balance());
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);
			}else if (temp_vector[4] == "CS"){
				temp_vector[3] = std::to_string(account.get_saving_balance());
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);				
			}	
		}
	}
} //deposit



void Transaction::withdrawal(Account account, std::vector<std::string> temp_vector, std::string file_name){

	int a3,a4;
	double c_wit, s_wit;
	std::ofstream output_file(file_name);

	std::cout << "[1] Chequing withdrawal\n[2] Saving withdrawal" << std::endl;
	std::cin >> a3;

	if (a3 == 1){
		if (account.get_account_name_C() != "chequing"){
			std::cout << "You might not have a chequing account." <<std::endl;	
			withdrawal(account, temp_vector, file_name);

		}else{
			
			std::cout << "How much do you want to withdraw from your chequing account?		: " <<std::endl;
			std::cin >> c_wit;

			if (account.get_chequing_balance() - c_wit <= 0){
				std::cout << "your balance cannot be 0 or below.\n" << std::endl;
				withdrawal(account, temp_vector, file_name);	
			}


			else if (account.get_chequing_balance() >=1000 && (account.get_chequing_balance()-c_wit) < 1000 ){
				std::cout << "Your chequing balance is $1000 or above and if it goes below $1000 after this transaction(withdrawal), $5 will be charged as a penalty." << std::endl;
				std::cout << "Will you still proceed?\n[1] Yes\n[2] Nah" <<std::endl;
				std::cin >> a4;
				
				if (a4 == 1){
					sub_wit(account, temp_vector,c_wit+5, file_name, 1);
					
				}else if(a4 == 2){
					withdrawal(account, temp_vector, file_name);
				}			
			}else {
				sub_wit(account, temp_vector,c_wit,file_name, 1);
			}
		}

	}else if (a3 == 2){
		if (account.get_account_name_S() != "saving"){
			std::cout << "You might not have set up your saving account. " << std::endl;
			withdrawal(account, temp_vector, file_name);
		}else{
			std::cout << "How much do you want to withdraw from your saving account?		: " <<std::endl;
			std::cin >> s_wit;

			if (account.get_saving_balance() - s_wit <= 0){
				std::cout << "your balance cannot be 0 or below.\n" << std::endl;
				withdrawal(account, temp_vector, file_name);	
			}


			else if (account.get_saving_balance() >=1000 && (account.get_saving_balance()-s_wit) < 1000 ){
				std::cout << "Your saving balance is $1000 or above and if it goes below $1000 after this transaction(withdrawal), $5 will be charged as a penalty." << std::endl;
				std::cout << "Will you still proceed?\n[1] Yes\n[2] Nah" <<std::endl;
				std::cin >> a4;

				if (a4 == 1){
					sub_wit(account, temp_vector,s_wit+5,file_name, 2);
					
				}else if(a4 == 2){
					withdrawal(account, temp_vector, file_name);
				}			
			}else {
				sub_wit(account, temp_vector,s_wit,file_name, 2);
			}
		}
	}	

}//withdraw

void Transaction::sub_wit(Account account, std::vector<std::string> temp_vector, double in, std::string file_name, int i){
	std::ofstream output_file(file_name);
	if (i == 1){
		account.set_chequing_balance(account.get_chequing_balance()-in);
		std::cout << "Your chequing balance is now $" << account.get_chequing_balance() << std::endl;
		temp_vector[2] = std::to_string(account.get_chequing_balance());
		std::ostream_iterator<std::string> output_iterator(output_file, " ");
		std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);
	}

	else if (i == 2){
		account.set_saving_balance(account.get_saving_balance()-in);
		std::cout << "Your saving balance is now $" << account.get_saving_balance() << std::endl;

		if (temp_vector[3] == "S"){				
			temp_vector[2] = std::to_string(account.get_saving_balance());
			std::ostream_iterator<std::string> output_iterator(output_file, " ");
			std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);
		}else if (temp_vector[4] == "CS"){
			temp_vector[3] = std::to_string(account.get_saving_balance());
			std::ostream_iterator<std::string> output_iterator(output_file, " ");
			std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);
		}
	}
}



