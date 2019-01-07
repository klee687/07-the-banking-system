#include "Inf_manager.hpp"
#include <vector>

Inf_manager::Inf_manager(std::string first_name, std::string pwd): first_name(first_name),pwd(pwd){}

std::string Inf_manager::get_firstname(){
  return this->first_name;
}

std::string Inf_manager::get_pwd(){
  return this->pwd;
}

void Inf_manager::set_firstname(std::string first_name){
  this->first_name = first_name;
}

void Inf_manager::set_pwd(std::string pwd){
  this->pwd = pwd;
}
