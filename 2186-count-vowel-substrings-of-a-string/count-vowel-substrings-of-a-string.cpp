class Solution {
public:
    int countVowelSubstrings(string s) {
        unordered_set<char> st = {'a','e','i','o','u'};
        int n = s.size();
        int start  =0 ;
        int end =0 ;
        int counter = 0;
        
        for(int i = 0 ; i<n ;i++){
            if(st.find(s[i])==st.end()){
                continue;
            }else{
                unordered_map<char,int> mp;
                for(int j = i; j<n;j++){
                    if(st.find(s[j])!=st.end()){
                        mp[s[j]]++;
                        if(mp.size()==5){
                            counter++;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        return counter;
    }
};