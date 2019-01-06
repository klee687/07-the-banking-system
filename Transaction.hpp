#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include "Customer.hpp"
#include "Account.hpp"

class Transaction{
	Account account;
	std::string file_name;
	public:
		Transaction();
		void transaction(Account account, std::vector<std::string> temp_vector, std::string file_name);
		void deposit(Account account, std::vector<std::string> temp_vector, std::string file_name);
		void withdrawal(Account account, std::vector<std::string> temp_vector, std::string file_name);
		void sub_wit (Account account, std::vector<std::string> temp_vector, double c_wit, std::string file_name, int i);
		void closing(std::vector<std::string> temp_vector, std::string file_name);
};
#endif 
