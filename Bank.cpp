#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank(){}

Account :: Bank::openFile(){
	string line;
	vector<string> inf;
	ifstream myfile ("text.txt");
	if (!myfile){
		cout << "file error\n";						
		return 0;
	}
	
	//add strings in vector
	while (myfile>>line){
		//inf.push_back(line);
		

	}
}





