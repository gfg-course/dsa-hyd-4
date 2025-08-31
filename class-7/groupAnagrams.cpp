#include<bits/stdc++.h>
using namespace std;

string getHashKey(string s) {
    string key = "";
    vector<int> freq(26, 0);

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        key += to_string(freq[i]);
        key += "#";
    }

    return key;
}

// TC: O(n*m)
// AS: O(n)
vector<vector<string>> groupAnagramsTogether(vector<string> arr) {
    int n = arr.size();

    vector<vector<string>> result;
    unordered_map<string, int> hashKeyToIndexInTheOutput;

    for (int i = 0; i < n; i++) {
        string hashKey = getHashKey(arr[i]);
        if (hashKeyToIndexInTheOutput.find(hashKey) == hashKeyToIndexInTheOutput.end()) {
            hashKeyToIndexInTheOutput[hashKey] = result.size();
            result.push_back({});
        }
        
        int indexInTheOutput = hashKeyToIndexInTheOutput[hashKey];
        result[indexInTheOutput].push_back(arr[i]); 
    }

    return result;
}
 
int main() {
}