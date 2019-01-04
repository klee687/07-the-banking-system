#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include "Account.hpp"

class Account; // Need this. Please read about cyclic redundancies
class Customer{


	//Customer probably has a name too??
	std::string name;
	//maybe he has an ID too? i dont remember fully
	std::string ID;
	//The customer almost certainly has an ARRAY of accounts. 

	std::string password;

	std::vector<Account> accounts;
	


public:
	Customer(); //need it 
	Customer(std::string name, std::string ID, std::string password);
	
	//Everything the customer is able to do should be here. So thing of when you go to an ATM and the stuff you are abkle to do.

	//you can probably check your account summary

	std::string set_pwd(std::string password);
	void set_ID(std::string ID);
	void set_name(std::string name);
	std::string get_ID();
	std::string get_name();
	//we want a method that adds to our std::vector<Account> accounuts; array
	//Tip: for the parameters, u dont *need* the variable name. that;s why i have just Account. But this only works in method declarations. U *must* have it in your method *definitions* in your cpp file, jsut like i have done in Customer.cpp
	void add_account(Account);
};



#endif
