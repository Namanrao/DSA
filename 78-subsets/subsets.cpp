class Solution {
public:
    void allSubsequences(int index , vector<int> & nums , vector<int> &arr  ,vector<vector<int>> &result, int n ){
        // base case;
        if(index>=n){
            result.push_back(arr);
            return ;
        }
    // add the element 
    arr.push_back(nums[index]);
    allSubsequences(index+1 ,nums, arr, result , n);

    // Not adding the elemenet
    arr.pop_back();
    allSubsequences(index+1 , nums, arr, result , n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // backtracking approach 
        vector<vector<int>> result;
        int index =0 ;
        int n = nums.size();
        vector<int> arr;
    allSubsequences(index, nums, arr, result ,n);
    return result;
    }
};