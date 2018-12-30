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
	std::string chequing; //don't need.
	std::string saving; //dont need
	//std::string date; //add late if necessary
		

	double balance_chequing;
	double balance_saving;

	
public:
	//Account(std::string ID, std::string chequing, std::string saving, std::string date);
	Account (); //need default constructor
	Account(Customer *customer, std::string chequing, std::string saving); 
	//std::string getID();
	std::string getChequing();
	std::string getSaving();
	//std::string getDate();

	double get_chequing_balance();
	double get_saving_balance();	
	void set_account_name(std::string account_name);
	void set_customer(Customer *customer);
	
	void set_chequing_balance(double balance_chequing);
	void set_saving_balance(double balance_saving);

	//void setID(std::string ID); //don;t need for above reasons (obv)
	//void setChequing(std::string chequing); //unnecessary
	//void setSaving(std::string saving); // ^^
	//void setDate(std::string date); //maybe later
};
#endif
