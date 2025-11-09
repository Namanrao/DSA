class Solution {
public:

    int function(vector<int> &arr){
        int n = arr.size() ;
        int ans = INT_MAX;
        for(int i =0 ; i+2<n ; i++){
            int minimum = arr[i];
            int maximum = arr[i+2];
            ans = min(ans , 2*(maximum - minimum));
        }
        return ans;
    }

    int minimumDistance(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int, vector<int>> mp;
        for(int i =0; i<n ; i++){
           mp[nums[i]].push_back(i);
        }
        // now go across the entire map and pull up the sliding window for it 
        int ans  = INT_MAX;
        for(auto &p :mp){
            auto& arr = p.second;
            if(arr.size()>=3){
                ans = min(ans , function(arr));
            }   
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};