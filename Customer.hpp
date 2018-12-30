#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include "Account.hpp"


class Customer{


	//Customer probably has a name too??
	std::string name;
	//maybe he has an ID too? i dont remember fully
	std::string ID;
	//The customer almost certainly has an ARRAY of accounts. 

	std::vector<Account> accounts;
	


public:

	Customer(std::string name, std::string ID);
	
	//Everything the customer is able to do should be here. So thing of when you go to an ATM and the stuff you are abkle to do.

	//you can probably check your account summary

	void print_summary();

	double get_balance(); //add/remove/change as you wish
};



#endif
