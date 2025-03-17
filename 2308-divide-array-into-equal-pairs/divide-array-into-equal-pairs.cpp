class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n%2!=0) return false;

        map<int , int> mp ;
        for(int i : nums){
            mp[i]++;
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second%2!=0) return false;
        }
        return true;
    }
};