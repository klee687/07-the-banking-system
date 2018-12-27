/*
	

ifndef, define are called #include guards.

Once the header is included, it checks if a unique value (in this case ACCOUNT_H) is defined. Then if it's not defined, it defines it and continues to the rest of the page.

When the code is included again, the first ifndef fails, resulting in a blank file.

That prevents double declaration of any identifiers such as types, enums and static variables.

*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>


class Account{
	std::string name;
	std::string chequing;
	std::string saving;
	std::string date;

public:
	Account(std::string name, std::string chequing, std::string saving, std::string date);
	std::string getName();
	std::string getChequing();
	std::string getSaving();
	std::string getDate();
	
	void setName(std::string name);
	void setChequing(std::string chequing);
	void setSaving(std::string saving);
	void setDate(std::string date);
};
#endif
