//#include <iostream>
//#include "Maintenance.hpp"
//#include "Manager.hpp"
#include "Customer.hpp"
#include <stdlib.h> //We need this to convert string to double
#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <vector>

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
	**/
	

		/**
			We can also make certain assumptions to aid us. If they only want 1 account, then it;'s always gonna be a checking account by default. 

			If they add 2, then they have a checking AND a saving. So we can use the size of the vector to our advantage. Right now, our temp_vector will have ID name checking saving, which means the vector will be of size 4. But if the user says "fuck it" i dont want a saving, then the text file would have ID name checking, making our vector size 3.
		**/

		//Now we know we want to create Customers,  but the constructor of a Customer takes name, and ID
	
			
			std::ifstream file;
			std::string file_name = "78982.txt";
			
			std::vector<std::string> temp_vector;
			std::string token;
			
			file.open(file_name.c_str());

			while(file >> token){
				temp_vector.push_back(token);
			}
		

			//Check if size is 3 or 4. If it's 3, then they only made a checking account, if it's 4, then they made a saving accouunt too
			/**
				Thankfully we have structure in our text file, so we know index 0: ID, index 1:name, index 2:checking, index 3: saving (optional)
			**/


			//Create Customer object

			Customer customer;
			Account account;

			if(temp_vector.size() == 4){

				customer.set_ID(temp_vector[0]);
				customer.set_name(temp_vector[1]);

				account.set_account_name("checking"); // look at how ive implemented set_account_name in the Account class, so u dont get confused by this
				account.set_account_name("saving");
				//
				account.set_chequing_balance(atof(temp_vector[2].c_str())); //THe value of the text file is 100, but it;'s a string. So we need to convert it to a double
				account.set_saving_balance(atof(temp_vector[3].c_str()));

				account.set_customer(&customer);
	
				//Now lets add the account to customer's Account vector !
				customer.add_account(account);
				
		
			}

			else if(temp_vector.size() == 3){
				customer.set_ID(temp_vector[0]);
				customer.set_name(temp_vector[1]);

				account.set_account_name("checking");
				account.set_chequing_balance(atof(temp_vector[2].c_str()));
				//Now lets add the account to customer's Account vector !
				account.set_customer(&customer); //remember, the set_customer takes a pointer, and it HAS to take a pointer. So we pass in the address of the customer object
				customer.add_account(account);
			}

	
			std::cout << temp_vector[1] << std::endl;
		


  			// The file exists, and is open for input
			//std::ifstream ifile;
			//find the informaiton of a customer


		/**
	Don't need this either because you already have the ID in the above Customer object.
			std::string id;
			std::cout << "User's ID : \n" << std::endl;
			std::cin >> id;
			Customer user;
	**/
			

		//Go to your Customer class and implement a get_ID method, so that then you can do std::string ID = customer.get_id();

			/////////////////////LOOK HERE??????//////////////////////////////
			//Account acc;  ///You're creating a new Account object. But above you already createda  Customer AND an Account object. It's the above Account object that has all the information saved. not this one. So you can use the above Account object.


			//Yeah, no, u can't just make up your own language :p 
			//acc = saving.Account::get_saving_balance; ///////////// < these two things will be under if statement below. im just tryina get saving balance! :/ i know its a mess right now!
			
			double saving = account.get_saving_balance();
			/**
			You actually don;'t need this since you already got the file information from above ^
			std::ifstream ifile(id+".txt");
			if (ifile) {
			//	std::cout << std::to_string(acc.get_saving_balance) << std::endl;
				}
			else{
				std::cout << "There is an issue with the file name, or the customer does not exist" << std::endl; //cute error message
			}

		**/
}


/**

void manager(int id){
	int min, an, customerID;
	std::cout << "What would you like to proceed?\n";
	std::cout << "1. Open a new account for a customer\n";
	std::cout << "2. Close an account for a customer \n";
	std::cout << "3. See a customer's information\n";
	std::cout << "4. See all the customers' information\n";
	std::cout << ">>  ";
	std::cin >> min;
	if (0 < min && min < 5) {
		if (min == 1){
			std::cout << "1. New Account for a new customer\n2. New Account for a current customer\n>>  ";
			std::cin >> an;
			if (an == 1){
				std::ofstream outFile;
				outFile.open("text.txt");
				std::cout << "customer ID: ";
				std::cin >> customerID;
				//if (customerID != 
				outFile << customerID << std::endl;
				outFile.close();
			}
		}
	}else{
		printf ("Wrong input. Please try again. \n");
		return;
	}
}

void customer(int id){
		
}

void maintenance(int id){
}

int main(void){

	int id = 0;
	int password = 0;
	printf ("----------- Bank -----------\n");
	printf ("------ maintenance ----- [1]\n");
	printf ("--------- manager ------ [2]\n");
	printf ("---------customer ------ [3]\n");
	printf ("Remember, in orer to create a new account, you need to set up an appoinment with a manager. \n");
	
	std::cout << "ID :: ";
	std::cin >> id;
	// if ID -> manager's iD, then switch to manager's function
	// if ID -> clients, then go to client
	// if ID -> maintenance, then go to maintenance 


	if (id == 1){
		maintenance(id);
	}
	else if (id == 2){
		manager(id);
	}
	else{
		customer(id);
	}	

} 
*/
