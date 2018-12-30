#include "Account.hpp"

//Account has a constructor
Account::Account(std::string ID, std::string chequing, std::string saving, std::string date) : ID(ID), chequing(chequing), saving(saving), date(date) {}

std::string Account::getID(){
	return this->ID;
}

std::string Account::getChequing(){
	return this->chequing;
}

std::string Account::getSaving(){
	return this->saving;
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
