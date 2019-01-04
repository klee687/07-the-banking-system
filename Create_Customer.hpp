#ifndef CREATE_CUSTOMER_H_
#define CREATE_CUSTOMER_H_
#include <string>

#include "Customer.hpp"
#include "Account.hpp"

class Customer;

class Create_Customer{
	
		
	Account account;
	Customer customer;
	std::string file_name;
	public:
		Create_Customer();
		void create_customer(std::string file_name);
};
#endif
