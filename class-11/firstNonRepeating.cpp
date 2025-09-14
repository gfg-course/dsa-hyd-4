#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
string firstNonRepeating(string s) {
    int n = s.length();
    queue<char> q;
    vector<int> freq(26, 0);

    string result = "";

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        if (freq[s[i] - 'a'] == 1) {
            q.push(s[i]);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back('#');
        } else {
            result.push_back(q.front());
        }
    }

    return result;
}

int main() {
    cout << firstNonRepeating("aabc") << endl;
    cout << firstNonRepeating("abacdbd") << endl;
    cout << firstNonRepeating("aabcdcdde") << endl;
}