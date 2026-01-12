// ===== CADE SUMMARY =====
//
// C – Clarify
// - Order of characters does not matter.
// - All strings contain lowercase letters.
// - We need to group, not just check equality.
//
// A – Approach
// - Two approaches exist:
//   1. Sort each string and use it as a key (slower).
//   2. Use character frequency as a key (chosen).
// - Frequency avoids sorting and gives O(n * k) time.
//
// D – Dry Run
// - "eat" → [1,0,0,1…]
// - "tea" → [1,0,0,1…]
// - Same key → same group.
//
// E – Execute
// - Use a hashmap where key = frequency signature.
// - Append strings to the corresponding group.

class Solution{
public:
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
}


