#include<bits/stdc++.h>
using namespace std;

vector<string> keypad = {
    "",
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz"
};

void possibleWordsUtil(int index, vector<int> &arr, string &curr, vector<string> &result) {
    if (index == arr.size()) {
        result.push_back(curr);
        return;
    }

    string wordFromKeypad = keypad[arr[index]];
    for (char ch : wordFromKeypad) {
        curr.push_back(ch);
        possibleWordsUtil(index + 1, arr, curr, result);
        curr.pop_back();
    }
}

// TC: O(4^n)
// AS: O(n)
vector<string> possibleWords(vector<int> arr) {
    string curr = "";
    vector<string> result;

    possibleWordsUtil(0, arr, curr, result);
    return result;
}

int main() {

    
}