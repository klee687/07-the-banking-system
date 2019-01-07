#ifndef MANAGER_H_
#define MANAGER_H_
#include "Account.hpp"

class Manager {

	std::string ID;
	std::string password;	
	std::vector<Manager> managers;
	public:		
		//Declare constructor
		Manager();
		Manager(std::string ID, std::string password);
		void add_manager(Manager manager);
		std::string get_password();
		std::string get_ID();
		void set_password(std::string password);
		void set_ID(std::string ID);
};	


#endif
