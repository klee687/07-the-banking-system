//#include "Maintenance.hpp"
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
	
			std::ifstream file;
			std::string file_name = "text.txt";
			std::vector<std::string> temp_vector;
			std::string token;
					
			int vector_size;
			file.open(file_name.c_str());
			while(file >> token){
				temp_vector.push_back(token);
			}

			vector_size = temp_vector.size(); 

			//Check if size is 3 or 4. If it's 3, then they only made a checking account, if it's 4, then they made a saving accouunt too
			/*
				Thankfully we have structure in our text file, so we know index 0: ID, index 1:name, index 2:checking, index 3: saving (optional)
			*/


			//Create Customer object

			Customer customer;
			Account account;

			if(vector_size == 5){

				customer.set_ID(temp_vector[0]);
				customer.set_name(temp_vector[1]);

				account.set_account_name("chequing"); // look at how ive implemented set_account_name in the Account class, so u dont get confused by this
				account.set_chequing_balance(atof(temp_vector[2].c_str())); //THe value of the text file is 100, but it;'s a string. So we need to convert it to a double
				account.set_account_name("saving");
				account.set_saving_balance(atof(temp_vector[3].c_str()));
				account.set_customer(&customer);
				customer.add_account(account);	//Now lets add the account to customer's Account vector !	
			}
			else if(vector_size == 4){
				customer.set_ID(temp_vector[0]);
				customer.set_name(temp_vector[1]);

				if (temp_vector[3] == "C"){
					account.set_account_name("chequing");
					account.set_chequing_balance(atof(temp_vector[2].c_str()));
					account.set_customer(&customer); 
					customer.add_account(account);				
				}else if(temp_vector[3] == "S"){
					account.set_account_name("saving");
					account.set_saving_balance(atof(temp_vector[2].c_str()));
					account.set_customer(&customer); 
					customer.add_account(account);
				}
				
			}
			else std::cout << "invalid. vector size overflow\n" << std::endl;
				




			Bank bank(customer.get_ID());
			bank.summary(customer, account, vector_size);

			Manager manager(customer.get_ID());
			std::cout << vector_size << std::endl;
			std::cout << "S" <<  std::to_string(account.get_saving_balance()) << std::endl;
			std::cout << "C" << std::to_string(account.get_chequing_balance()) << std::endl;
			//manager.open_acc(temp_vector, account, file_name);			
			transaction(account, temp_vector,file_name);
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
