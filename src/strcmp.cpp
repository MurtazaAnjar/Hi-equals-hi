#include <string>

std::string hello() {
   return "Hello World!";
}

int strcmp(std::string str1, std::string str2) {
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

int strcmp_case_insensitive(std::string str1, std::string str2) {
   int l=0;
   if (str1.length()<str2.length()) {
      l=str1.length();
   }else {
      l=str2.length();
   }
   for (int i=0;i<l;i++) {
      if (tolower(str1[i])!=tolower(str2[i])) {
         return((str1[i]-str2[i]) > 0)? 1:-1;
      }
   }
   return 0;
}
