class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), counter =0;
        for(int i=2; i<n ;i++){
            if(nums[i-2]==0){
                counter++;
                nums[i-2]= nums[i-2]^1;
                nums[i-1] = nums[i-1]^1;
                nums[i] = nums[i]^1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum==n) return counter;
        else return -1;
    }
};