class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> copy(nums);  // Initialize copy with nums directly
        
        sort(copy.begin(), copy.end());
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            // Only set the index for the first occurrence to handle duplicates correctly
            if(mp.find(copy[i]) == mp.end()) {
                mp[copy[i]] = i;
            }
        }
        
        vector<int> result(n);  // Pre-allocate space
        
        for(int i = 0; i < n; i++){
            result[i] = mp[nums[i]];
        }
        
        return result;
    }
};
