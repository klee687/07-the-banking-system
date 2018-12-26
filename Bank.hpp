//int main(void);


// Think of each entity as an Object. so Customer, Manager, etc should be classes



/**
void manager(int id);
void customer(int id);
void maintenance(int id);

**/

#ifndef BANK_H_
#define BANK_H_

#include "Manager.hpp"
#include "Account.hpp"
#include "Customer.hpp"
// This is basically your biggest class. You'll probably have data structures for Account, Customer, and Manager and whatever else. Think about it like a real world Bank.



class Bank{



	std::vector<Account> all_accounts;
	std::vector<Manager> all_managers;
	std::vector<Customer> all_customers;




public:
	Bank(); //add as u need



};


#endif 
