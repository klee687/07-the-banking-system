#include <iostream>
#include "Maintenance.hpp"
#include "Manager.hpp"
#include "Customer.hpp"


int main(){

//Most of what you have here should probably be in the "Main.cpp" file. THis file should do all the processing

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
*/
} 
