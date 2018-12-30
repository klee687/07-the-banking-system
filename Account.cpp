#include "Account.hpp"

//Account has a constructor
//Account::Account(std::string ID, std::string chequing, std::string saving, std::string date) : ID(ID), chequing(chequing), saving(saving), date(date) {}
Account::Account(){}
Account::Account(Customer *customer, std::string chequing, std::string saving): customer(customer), chequing(chequing), saving(saving){


}

double Account::get_saving_balance(){

	return balance_saving;
}

double Account::get_chequing_balance(){


		return balance_chequing;

}

void Account::set_customer(Customer *customer){

	this->customer = customer;
	
}


void Account::set_account_name(std::string account_name){

	if(account_name == "chequing") this->chequing = account_name;

	else if(account_name == "saving") this->saving = account_name;
}


void Account::set_chequing_balance(double balance_chequing){

	this->balance_chequing = balance_chequing;
	
}

void Account::set_saving_balance(double balance_saving){

	this->balance_saving = balance_saving;
		
}


std::string Account::getChequing(){
	return this->chequing;
}


std::string Account::getSaving(){
	return this->saving;
}




/**
std::string Account::getID(){
	return this->ID;
}



std::string Account::getDate(){
	return this->date;
}



void Account::setID(std::string ID){
	this->ID = ID;
}

void Account::setChequing(std::string chequing){
	this->chequing = chequing;
}

void Account::setSaving(std::string saving){
	this->saving = saving;
}

void Account::setDate(std::string date){
	this->date = date;
}


**/
