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
        bool isValidAnagram(string s, string t){
            if (s.length()!=t.length) return false;
            
            int freq[26] = {0};
            
            for(int i=0; i < s.length(); i++){
                freq[s[i]-'a']++;
                freq[t[i]-'a']--;
            }
            
            for(int charFreq: freq) {
                if(charFreq !=0) 
                    return false;
            }
            return true;
        }
    }
}