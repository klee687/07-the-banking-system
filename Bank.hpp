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


//Need libraries 
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class Bank{
	std::string ID; 
	int v_size;
	

public:
	Bank(std::string ID); //add as u need
	void summary(Customer customer, Account account, int v_size);
};


#endif 
