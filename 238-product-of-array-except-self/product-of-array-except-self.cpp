class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[n-1] = 1;
        // I will store right side product
        for(int i = n-2 ; i>=0 ; i--){
            result[i] = result[i+1]*nums[i+1];
        }
        // Now we will calculate the right side product
        int fp = 1;
        for(int i = 1 ;i< n ;i++){
            fp = fp*nums[i-1];
            result[i] = result[i]*fp;
        }
        return result;
    }
};