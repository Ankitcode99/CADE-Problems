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
