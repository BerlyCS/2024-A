#include <cctype>
#include <iostream>
using namespace std;

bool isEqual(const char s1,const char s2,int &i) {

}

bool isPalindrome(const string &text1, const string &text2) {
    string ptext1, ptext2;
    int index=0;
    for (int i=0; i<text1.size(); i++) {
        if (isalpha(text1[i])) {
            ptext1.push_back(tolower(text1[i]));
        }
    }

    for (int i=0; i<text2.size(); i++) {
        if (isalpha(text2[i])) {
            ptext1.push_back(tolower(text2[i]));
        }
    }

    if (text1.size() != text2.size()) {
        return false;
    }



}

int main() {
    
}
