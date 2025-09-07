class Solution {
public:
    void solve(vector<int> &candidates , int index ,vector<int> &arr , int target ,             vector<vector<int>>&result){
        if(target == 0){
            result.push_back(arr);
            return ;
        }
        if(index >= candidates.size() || target<0){
            return ;
        }

        arr.push_back(candidates[index]);
        solve(candidates , index , arr, target-candidates[index] ,result);

        arr.pop_back();
        solve(candidates, index+1, arr, target, result);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;

        solve(candidates , 0, arr, target, result);
        return result;
    }
};