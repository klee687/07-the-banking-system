#include "Account.hpp"

//Account has a constructor
//Account::Account(std::string ID, std::string chequing, std::string saving, std::string date) : ID(ID), chequing(chequing), saving(saving), date(date) {}
Account::Account(){}
Account::Account(Customer *customer, std::string account_name, std::string password, int ID, std::string balance_chequing, std::string balance_saving): customer(customer), account_name(account_name), password(password), ID(ID), balance_chequing(balance_chequing), balance_saving(balance_saving){

}

std::string Account::get_saving_balance(){
	return balance_saving;
}

std::string Account::set_saving_balance(double balance_saving){
	this->balance_saving = balance_saving;
}

std::string Account::get_chequing_balance(){
	return balance_chequing;
}

std::string Account::set_chequing_balance(double balance_chequing){
	this->balance_chequing = balance_chequing;	
}

void Account::set_account_name(std::string account_name){
	if(account_name == "chequing") this->balance_chequing = account_name;
	else if(account_name == "saving") this->balance_saving = account_name;
}

void Account::set_id(int ID){
	this->ID = ID;
}

void Account::set_password(std::string password){
	this->password = password;
}

void Account::set_customer(Customer *customer){
	this->customer = customer;
}



