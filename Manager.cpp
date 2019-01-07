#include "Customer.hpp"
#include "Account.hpp"
#include "Manager.hpp"
#include <iterator>
#include <stdlib.h> //We need this to convert string to double
#include <iostream>
#include <vector>
#include <fstream>


Manager::Manager(){}
Manager::Manager(std::string ID, std::string password) : ID(ID), password(password) {}


void Manager::set_ID(std::string ID){
	this->ID = ID;
}


std::string Manager::get_password(){
	return password;
}


std::string Manager::get_ID(){
	return ID;
}

void Manager::set_password(std::string password){
	this -> password = password;
}

