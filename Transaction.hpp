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
};
#endif 
