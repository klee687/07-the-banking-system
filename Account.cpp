#include "Account.hpp"

//Account has a constructor
//Account::Account(std::string ID, std::string chequing, std::string saving, std::string date) : ID(ID), chequing(chequing), saving(saving), date(date) {}
Account::Account(){}
Account::Account(Customer *customer, std::string account_name_C, std::string name, std::string ID, std::string account_name_S, double chequing_balance, double saving_balance): name(name), ID(ID),  customer(customer), account_name_C(account_name_C), account_name_S(account_name_S), chequing_balance(chequing_balance), saving_balance(saving_balance){

}

double Account::get_saving_balance(){
	return saving_balance;
}

double Account::set_saving_balance(double saving_balance){
	this->saving_balance = saving_balance;
}

double Account::get_chequing_balance(){
	return chequing_balance;
}

double Account::set_chequing_balance(double chequing_balance){
	this->chequing_balance = chequing_balance;	
}

void Account::set_account_name_C(std::string account_name_C){
	this->account_name_C= account_name_C;
}

void Account::set_account_name_S(std::string account_name_S){
	this-> account_name_S= account_name_S;	
}

std::string Account::get_account_name_C(){
	return account_name_C;
}

std::string Account::get_account_name_S(){
	return account_name_S;
}

std::string Account::get_name(){
	return name;
}

std::string Account::get_ID(){
	return ID;
}


void Account::set_customer(Customer *customer){
	this->customer = customer;
}



