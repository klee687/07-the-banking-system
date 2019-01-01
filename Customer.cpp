#include "Customer.hpp"

Customer::Customer(){}
Customer::Customer(std::string name, std::string ID, std::string password) : name(name), ID(ID), password(password){

	/**
		You're probably wondering what i'm doing with " :name(name), ID(id) {}

		This is the exact same thing as doing 
		
		this->name = name; // This is the same as name(name)
		this->ID = ID; //this is the same as ID(ID)

		However, the way I've done is much cleaner and it is the C++ way to do it. It's called "member initializer lists" 		

	**/
}



//Customer also has a print_summary function that was in the Customer.hpp, so we shall add that here too
void Customer::print_summary(){
	std::cout << customer->name << 	
}



void Customer::add_account(Account account){

	this->accounts.push_back(account);
}

void Customer::set_name(std::string name){
	this->name = name;
}

void Customer::set_ID(std::string ID){

	this->ID = ID;
}

std::string Customer::set_pwd(std::string password){
	this -> password = password;
}

