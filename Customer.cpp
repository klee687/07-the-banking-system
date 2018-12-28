#include "Customer.hpp"
Customer::Customer(std::string name, std::string ID) : name(name), ID(ID){

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

	//add functionality
}


//Also has a get balance


double Customer::get_balance(){

	//do as u wish
}
