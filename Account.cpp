#include "Account.hpp"

//Account has a constructor
//Account::Account(std::string ID, std::string chequing, std::string saving, std::string date) : ID(ID), chequing(chequing), saving(saving), date(date) {}
Account::Account(){}
Account::Account(Customer *customer, std::string account_name, double chequing_balance, double saving_balance): customer(customer), account_name(account_name), chequing_balance(chequing_balance), saving_balance(saving_balance){

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

void Account::set_account_name(std::string account_name){
	if(account_name == "chequing") account_name = this->chequing_balance;
	else if(account_name == "saving") account_name = this->saving_balance;
}


void Account::set_customer(Customer *customer){
	this->customer = customer;
}



