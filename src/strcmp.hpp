#ifndef STRCMP_H
#define STRCMP_H
#include <string>

std::string hello();
std::string removeSpace(std::string str);
int strcmp(std::string str1, std::string str2);
int strcmp_case_insensitive(const std::string &str1, const std::string &str2, bool spc = false, int max = -1);
#endif