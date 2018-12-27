#include "Account.hpp"

//Account has a constructor
Account::Account(std::string name, std::string chequing, std::string saving, std::string date) : name(name), chequing(chequing), saving(saving), date(date) {}

std::string Account::getName(){
	return this->name;
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



void Account::setName(std::string name){
	this->name = name;
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
