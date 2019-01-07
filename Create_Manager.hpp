#ifndef CREATE_MANAGER_H_
#define CREATE_MANAGER_H_
#include "Manager.hpp"


class Create_Manager{
	std::string file_name;
	Manager manager;
	public:
		Create_Manager();
		void create_manager(std::string file_name, Manager manager);
};

#endif
