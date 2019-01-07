#ifndef INF_MANAGER
#define INF_MANAGER

#include <string>

class Inf_manager {

  std::string first_name;
  std::string pwd;

public:
  Inf_manager(std::string first_name, std::string pwd);
  std::string get_firstname();
  std::string get_pwd();
  void set_firstname(std::string first_name);
  void set_pwd(std::string pwd);
};

#endif
