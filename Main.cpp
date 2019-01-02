//#include <iostream>
//#include "Maintenance.hpp"
//#include "Manager.hpp"
#include "Customer.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <vector>

void summary(Customer customer, Account account, int v_size){
	customer.print_summary();
	if (account.get_chequing_balance() !=0){
	std::cout << "chequing: " << account.get_chequing_balance() << std::endl;
	}if (account.get_saving_balance() !=0){
	std::cout << "saving: " <<account.get_saving_balance() << std::endl;
	}
	
} //summary closing


void open_acc(std::vector<std::string> temp_vector, Account account, std::string file_name){	
	std::string c_deposit;
	std::string s_deposit;
	int answr;
	std::cout << "Account Open" << std::endl;
		std::cout << "[1] chequing account\n[2] saving account \n[3] both" << std::endl;
		std::cin >> answr;
		if (answr == 1){
			if (account.get_chequing_balance() != 0){
				std::cout << "you already have a chequing account." << std::endl;
			}else{
				std::cout << "How much do you want to deposit in youe Chequing account?" << std::endl;
				std::cin >> c_deposit;
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
				std::cout << "How much do you want to deposit in youe Saving account?" << std::endl;
				std::cin >> s_deposit;
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
			std::string file_name = "78982.txt";
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
				account.set_account_name("saving");
				//
				account.set_chequing_balance(atof(temp_vector[2].c_str())); //THe value of the text file is 100, but it;'s a string. So we need to convert it to a double
				account.set_saving_balance(atof(temp_vector[3].c_str()));
				account.set_customer(&customer);
	
				//Now lets add the account to customer's Account vector !
				customer.add_account(account);		
			}
			else if(vector_size == 4){
				customer.set_ID(temp_vector[0]);
				customer.set_name(temp_vector[1]);
				if (temp_vector[3] == "C"){
					account.set_account_name("chequing");
					account.set_chequing_balance(atof(temp_vector[2].c_str()));
				}else if (temp_vector[3] == "S"){
					account.set_account_name("saving");
					account.set_saving_balance(atof(temp_vector[2].c_str()));				
				}//Now lets add the account to customer's Account vector !
				account.set_customer(&customer); //remember, the set_customer takes a pointer, and it HAS to take a pointer. So we pass in the address of the customer object
				customer.add_account(account);
			}else{
				std::cout << "invalid\n" << std::endl;
			}
			summary(customer, account, vector_size);

			
			//Create Customer by manager
			open_acc(temp_vector, account, file_name);			

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
