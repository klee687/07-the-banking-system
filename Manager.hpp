#ifndef MANAGER_H_
#define MANAGER_H_
#include "Account.hpp"

class Manager {

	// Anything that a manager would need will go in here. SO the manager is able to open/close accounts, so those should be in this class.

	//Declare private variables that you need. (Im adding some, but if add/remove them as you need. THis is just an example

	//These are all private by default. 
	std::string ID;
	std::vector<std::string> temp_vector;
	std::string file_name;
	public:		
		//Declare constructor
		Manager(std::string ID);

		void add_account(Account account);
		void open_acc(std::vector<std::string> temp_vector, Account account, std::string file_name);
};	


#endif
