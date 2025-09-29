#include "src/strcmp.hpp"
#include <iostream>



int main() {
  std::cout<<hello()<<std::endl;

  //testing some cases -- detailed testing in test file
  std::cout<<strcmp_case_insensitive("Hello World", "hello world")<<std::endl;
  std::cout<<strcmp_case_insensitive("Hello World", "hello wor ld", true)<<std::endl;
  std::cout<<strcmp_case_insensitive("Hello World", "helli wor ld", true, 3)<<std::endl;
  std::cout<<strcmp_case_insensitive("", "")<<std::endl;
  std::cout<<strcmp_case_insensitive("20 Hello World", "1 helli wor ld", true, 3)<<std::endl;
  std::cout<<strcmp_case_insensitive(" Hello World", "helli wor ld", false, 3)<<std::endl;

  std::cout<<"\n\n"<<std::endl;

  //user prompting program
  std::string str1 = "", str2 = "";
  bool spc = false;
  bool maxFlag = false;
  int max = -1;

  std::cout<<"Input the first string:"<<std::endl;
  std::getline(std::cin, str1);
  //std::cin.ignore(INT_MAX,'\n');

  std::cout<<"Input the second string"<<std::endl;
  std::getline(std::cin, str2);
  //std::cin.ignore(INT_MAX,'\n');

  std::cout<<"Do you want to skip spaces? (1/0)"<<std::endl;
  std::cin>>spc;
  std::cin.ignore(INT_MAX,'\n');

  std::cout<<"Do you want to cap comparison length? (1/0)"<<std::endl;
  std::cin>>maxFlag;
  std::cin.ignore(INT_MAX,'\n');

  if (maxFlag) {
    std::cout<<"Input the number of characters for comparison:"<<std::endl;
    std::cin>>max;
    std::cin.ignore(INT_MAX,'\n');
  }

  //std::cout<<str1<<str2<<spc<<max<<std::endl;
  std::cout<<strcmp_case_insensitive(str1, str2, spc, max)<<std::endl;

  return 0;
}
