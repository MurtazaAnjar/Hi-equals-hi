#include "strcmp.hpp"

#include <iostream>
#include <ostream>
#include <string>

std::string hello() {
   return "Hello World!";
}

void removeSpace(std::string &str) {
   for (int i=0; i<str.length(); i++) {
      if (str[i] == ' ') {
         str.erase(i, 1);
         i--;
      }
   }
}

int strcmp(std::string str1, std::string str2) {//normal string comparison to help with testing
   int l=0;
   if (str1.length()<str2.length()) {
      l=str1.length();
   }else {
      l=str2.length();
   }
   for (int i=0;i<l;i++) {
      if (str1[i]!=str2[i]) {
         return((str1[i]-str2[i]) > 0)? 1:-1;
      }
   }
   return 0;
}

//parameter max only counts spaces if parameter spc is false
int strcmp_case_insensitive(std::string str1, std::string str2, bool spc, int max) {
   //space removal
   if (spc) {
      removeSpace(str1);
      removeSpace(str2);
   }

   //length of string to be compared
   int l=0;
   (str1.length()<str2.length())? l=str1.length():l=str2.length();
   if (max>0 && max<l) {//if max is negative, max parameter is essentially ignored
      l = max;
   }else if (max==0) {
      return 0;//If no characters are to be compared, returns 0 (substrings are equal)
   }

   //case insensitive comparison
   for (int i=0;i<l;i++) {
      if (i==0 && isdigit(str1[i]) && isdigit(str2[i])) {
         int num1=0, num2=0, j=0;
         while (isdigit(str1[j]) && j<str1.length()) {
            num1 = num1*10+static_cast<int>(str1[j])-'0';
            j++;
         }
         j=0;//reset for second string
         while (isdigit(str2[j]) && j<str2.length()) {
            num2 = num2*10+static_cast<int>(str2[j])-'0';
            j++;
         }
         if (num1 != num2) {
            return (num1>num2)?  1:-1;
         }
      }

      if (tolower(str1[i])!=tolower(str2[i])) {
         return((str1[i]-str2[i]) > 0)? 1:-1;
      }
   }
   return 0;
}
