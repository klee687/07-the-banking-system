/*
	

ifndef, define are called #include guards.

Once the header is included, it checks if a unique value (in this case ACCOUNT_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.

When the code is included again, the first ifndef fails, resulting in a blank file.

That prevents double declaration of any identifiers such as types, enums and static variables.

*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include "Customer.hpp"

/**
 	Remember the point of this class isn't to just return name of accounts. But to actually return it's balances n shit. THink of it like a real world Account always

**/

class Customer; //Please read about cylic redundanceies !!
class Account{
	//std::string ID; //maybe you don't need this because can associate an Account with a Customer object instead of an ID .
	
	Customer * customer;
	std::string account_name;
	double chequing_balance;
	double saving_balance;

	
public:
	//Account(std::string ID, std::string chequing, std::string saving, std::string date);
	Account (); //need default constructor
	Account(Customer *customer, std::string account_name, double chequing_balance, double saving_balance); 
	double get_chequing_balance();
	double get_saving_balance();	
	void set_account_name(std::string account_name);
	void set_customer(Customer *customer);
	double set_chequing_balance(double chequing_balance);
	double set_saving_balance(double saving_balance);

};
#endif
