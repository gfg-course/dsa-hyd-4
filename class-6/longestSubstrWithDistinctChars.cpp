#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1) 
int getLongestSubstrWithDistinctChars(string s) {
    int n = s.length();
    vector<bool> isPresent(26);

    int result = 0;
    int left = 0, right = 0;
    while (right < n) {
        if (!isPresent[s[right] - 'a']) {
            isPresent[s[right] - 'a'] = true;
            result = max(result, right - left + 1);
        } else {
            while (s[left] != s[right]) {
                isPresent[s[left] - 'a'] = false;
                left++;
            }
            left++;
        }
        right++;
    }

    return result;
}
 
int main() {
    cout << getLongestSubstrWithDistinctChars("geeksforgeeks") << endl;
    cout << getLongestSubstrWithDistinctChars("aaa") << endl;
    cout << getLongestSubstrWithDistinctChars("abcdefabcbb") << endl;
}