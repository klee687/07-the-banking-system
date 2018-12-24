#include <stdio.h>
#include <iostream>
#include <fstream>
#include "a.h"
//using namespace std;
using std::cout;
using std::cin;

void manager(int id){
	int min, an;
	cout << "What would you like to proceed?\n";
	cout << "1. Open a new account for a customer\n";
	cout << "2. Close an account for a customer \n";
	cout << "3. See a customer's information\n";
	cout << "4. See all the customers' information\n";
	cout << ">>  ";
	cin >> min;
	if (0 < min && min < 5) {
		if (min == 1){
			cout << "1. New Account for a new customer\n2. New Account for a current customer\n>>  ";
			cin >> an;
			if (an == 1){
			
			}
		}
	}else{
		printf ("Wrong input. Please try again. \n");
		return;
	}
}

void customer(int id){
	return ;	
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
	
	cout << "ID :: ";
	cin >> id;
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
}// main
