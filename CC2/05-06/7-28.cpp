// Exercise 7.28: ex_07_28.cpp

#include <iostream>
#include <string>

using namespace std;

bool esPalindromo(string);

int main() {string oracion = "¿somos o no somos?";
   cout << oracion << endl;

   if (esPalindromo(oracion))
      cout << "\nEs palindromo!" << endl;

   return 0;
}

bool esPalindromo(string s) {

   if ( s.size() < 2 )
      return true;

   size_t e{ s.size() - 1 };

   if (s[0] < 97 || s[0] > 122)
      return esPalindromo(s.substr(1, e));
   if (s[e] < 97 || s[e] > 122)
      return esPalindromo(s.substr(0, e));

   if (s[0] == s[e])
      return esPalindromo(s.substr(1, e - 1));

   return false;
}

