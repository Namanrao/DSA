class Solution {
public:
void solve(vector<int> &candidates , vector<int> &arr, int index , int target, vector<vector<int>> &result){
      if(target<0){
            return;
        }

    if(target == 0){
        result.push_back(arr);
        return ;
    }
 
    for(int i = index ; i<candidates.size() ; i++){

        if(index <i && candidates[i-1] == candidates[i]){
            continue;
        }
        // DO
        arr.push_back(candidates[i]);
        solve(candidates, arr, i+1,target-candidates[i], result); //UNDO
        arr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, arr, 0,target, result);
        return result;
    }
};