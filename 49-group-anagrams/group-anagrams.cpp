class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string ,vector<string>> mp;
        for(int i =0 ; i<n ;i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto it = mp.begin() ; it!=mp.end() ;it++){
            result.push_back(it->second);
        }
        return result;
    }
};