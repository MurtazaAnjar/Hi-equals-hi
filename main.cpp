#include <iostream>
#include "src/strcmp.hpp"


int main() {
  std::cout<<hello()<<std::endl;
  std::cout<<tolower('A')<<std::endl;
  std::cout<< strcmp("String one","String one") << std::endl;
  std::cout<< strcmp("String one","String two") << std::endl;
  std::cout<< strcmp("String two","String one") << std::endl;
  std::cout<< strcmp_case_insensitive("String one","string one") << std::endl;
  std::cout<< strcmp_case_insensitive("String one","string two") << std::endl;
  std::cout<< strcmp_case_insensitive("String two","string one") << std::endl;

  return 0;
}
