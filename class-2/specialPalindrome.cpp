#include<bits/stdc++.h>
using namespace std;

bool isAlphaNumeric(char ch) {
    // bool isUpperCase = ch >= 'A' && ch <= 'Z';
    // bool isLowerCase = ch >= 'a' && ch <= 'z';
    // bool isNumeric = ch >= '0' && ch <= '9';

    // return isUpperCase || isLowerCase || isNumeric;

    return 
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9');
}

bool isSame(char ch1, char ch2) {
    return 
        (ch1 == ch2) ||
        (ch1 - 'A' + 'a') == ch2 ||
        (ch1 - 'a' + 'A') == ch2;
}


// TC: O(n)
// AS: O(1)
bool isSpecialPalindrome(string s) {

    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (!isAlphaNumeric(s[i])) {
            i++;
            continue;
        }
        if (!isAlphaNumeric(s[j])) {
            j--;
            continue;
        }

        if (!isSame(s[i], s[j])) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}


int main() {

    cout << isSpecialPalindrome("level") << endl;
    cout << isSpecialPalindrome("levels") << endl;
    cout << isSpecialPalindrome("race a car") << endl;
    cout << isSpecialPalindrome("A man: Nama") << endl;
    cout << isSpecialPalindrome("||level") << endl;
    cout << isSpecialPalindrome("||") << endl;
}