class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); 
        int count = 0;

        for(int i =0 ; i<n ; i++){
            if(i+1<n){
                if(nums[i+1]<nums[i]){
                    count ++;
                }
            }
        }
        if(count ==0) return true;

        if(count == 1 && nums[n-1] <=nums[0]) return true;

        return false;
    }
};