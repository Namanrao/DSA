class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int max_ele = *max_element(nums.begin() , nums.end());
        int min_ele = *min_element(nums.begin() , nums.end());

        unordered_map<int , int> mp;
        for(int i :nums){
            mp[i]++;
        }

        vector<int> result;
         for(int i = min_ele ; i<=max_ele ; i++){
            if(mp.find(i)!=mp.end()){
                while(mp[i]--){
                    result.push_back(i); 
                }
            }
         }
         return result;
    }
};