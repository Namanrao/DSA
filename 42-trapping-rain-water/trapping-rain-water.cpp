class Solution {
public:
    vector<int> prefix(vector<int> &nums){
        int n= nums.size();
        vector<int> left(n,0);
        //first element is the same;
        left[0] = nums[0];
        for(int i =1; i<n ;i++){
            left[i] = max(left[i-1],nums[i]);
        }
        return left;
    }
    vector<int> suffix(vector<int> &nums){
        int n = nums.size();
        vector<int> right(n,0);
        //last element is the same; 
        right[n-1] = nums[n-1];
        for(int i = n-2 ;i>=0;i--){
            right[i] = max(right[i+1], nums[i]);
        }
        return right;
    }
    int trap(vector<int>& nums) {
     vector<int> left = prefix(nums);
     vector<int> right = suffix(nums);
     int total = 0;
     int n = nums.size();
     for(int i = 0 ; i<n ;i++){
        total = total + (min(left[i],right[i])-nums[i]);
     }
     return total;
    }
};