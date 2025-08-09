class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1; 
        unordered_map<char,int> mp2;

        for(char c:ransomNote){
            mp1[c]++;
        }

        for(char c: magazine){
            mp2[c]++;
        }

        for(char c: ransomNote){
            if(mp2[c]<mp1[c]){
                return false;
            }
        }
        return true;
    }
};