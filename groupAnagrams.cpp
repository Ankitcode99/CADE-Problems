#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (const string& s : strs) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        // build a unique key from frequency array
        string key;
        for (int count : freq) {
            key += "_" + to_string(count);
        }
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& entry : mp) {
        result.push_back(entry.second);
    }
    return result;
}


