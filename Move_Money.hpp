#ifndef MOVE_MONEY_H_
#define MOVE_MONEY_H_

#include "Transaction.hpp"
#include "Customer.hpp"
#include "Account.hpp"

class Move_Money{
	public:
		Move_Money();
		void c_to_s(Account account, std::vector<std::string> temp_vector, std::string file_name);
		void s_to_c(Account account, std::vector<std::string> temp_vector, std::string file_name);
		void sub_move (Account account, std::vector<std::string> temp_vector, std::string file_name, double cs, int i);
};
#endif
