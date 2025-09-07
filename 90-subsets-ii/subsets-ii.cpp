class Solution {
public:
void solve(vector<int> &nums, int index, vector<int> &arr, vector<vector<int>> &result){
    result.push_back(arr);
    for(int i = index ; i< nums.size() ;i++){

        if(i>index && nums[i] == nums[i-1]){
            continue;
        }
        
        // Do
        arr.push_back(nums[i]);
        solve(nums,i+1 , arr, result);
        // Undo
        arr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // NO dupilcates means we have to go via loop method. 
        vector<vector<int>> result;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        solve(nums , 0 , arr, result);
        return result;
    }
};