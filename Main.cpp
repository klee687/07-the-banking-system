//#include "Maintenance.hpp"
#include "Create_Customer.hpp"
#include "Customer.hpp"
#include "Account.hpp"
#include "Manager.hpp"
#include "Bank.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
			


void transaction(Account account, std::vector<std::string> temp_vector, std::string file_name){
	int a1, a2, a3, a4;
	double c_dep;
label1:	std::cout << "\n[1] Deposit\n[2] Withdrawal\n[3] Move money from C -> S\n[4] Move money from S -> C" << std::endl;
	std::cin >> a1;
	if (a1 == 1){
		std::cout << "[1] Chequing deposit\n[2] Saving deposit" << std::endl;
		std::cin >> a2;
		if (a2 == 1){
			if (account.get_account_name() != "chequing"){
				std::cout << "You might not have a chequing account." <<std::endl;	
				goto label1;
			}else{
				std::cout << "How much do you want to deposit in your chequing account?		: " <<std::endl;
				std::cin >> c_dep;
				account.set_chequing_balance(account.get_chequing_balance()+c_dep);
				std::cout << "Your chequing balance is now $" << account.get_chequing_balance() << std::endl;
				temp_vector[2] = std::to_string(account.get_chequing_balance());
				std::ofstream output_file(file_name);
				std::ostream_iterator<std::string> output_iterator(output_file, " ");
				std::copy(temp_vector.begin(), temp_vector.end(), output_iterator);				
			}	
		}
	}
}		

int main(){
	/**
		So the structure of all customers text files should be the same.
		In your case, you've chosen, name checking saving date, but you might want to add an ID also. Generate an ID randomly and then make your text file have:
		ID name checking saving date

		Secondly, now before we read, we know we need Customer objects, and Account objects. Now that I think of it, the 'date' attribute might be useless in your text file. Perhaps
		Keep it in your logs instead.

		So i guess your new text file will also need a password/pin (eventually). So your new text file might look something like this

		ID name pin checking saving

		For now, i gave you an id of 78982 and named the text file 78982.txt. So that later on, when a customer logs in, you can open the file by the ID that they provided as the file name. (pretty convenient i'd say)

			We can also make certain assumptions to aid us. If they only want 1 account, then it;'s always gonna be a checking account by default. 

			If they add 2, then they have a checking AND a saving. So we can use the size of the vector to our advantage. Right now, our temp_vector will have ID name checking saving, which means the vector will be of size 4. But if the user says "fuck it" i dont want a saving, then the text file would have ID name checking, making our vector size 3.

		Now we know we want to create Customers,  but the constructor of a Customer takes name, and ID
	*/	
			Create_Customer CC;
			Customer customer;
			Account account;
			CC.create_customer("78982.txt");

			//Bank bank(customer.get_ID());
			//bank.summary(customer, account, vector_size);

			//Manager manager(customer.get_ID());
			
			//std::cout << "S" <<  std::to_string(account.get_saving_balance()) << std::endl;
			//std::cout << "C" << std::to_string(account.get_chequing_balance()) << std::endl;
			//manager.open_acc(temp_vector, account, file_name);			
			//transaction(account, temp_vector,file_name);
} // main closing

void input(){
	std::string id;
	std::cout << "User's ID : \n" << std::endl;
	std::cin >> id;
	std::ifstream ifile(id+".txt");
	if (ifile) {
		std::cout << "This ID exist \n" << std::endl;
	}
	else{
		std::cout << "There is an issue with the file name, or the customer does not exist" << std::endl; //cute error message   ->>>>>>>>>>>> CUZ IM SYO FUCKING KAWAII! :3
	}
} //input closing 
