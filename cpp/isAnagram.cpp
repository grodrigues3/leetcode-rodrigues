class Solution {
public:
    bool isAnagram(string s, string t) {
        int char_counter[26] = {0};
        if(s.size() != t.size())
            return false;
        for(int i= 0; i< s.size(); i++){
            char_counter[s[i]-'a']++;
            char_counter[t[i]-'a']--;
        }
        
        for(int j =0; j<26; j++)
            if(char_counter[j] != 0)
                return false;
        return true;
        
    }
};