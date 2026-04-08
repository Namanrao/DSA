class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // brute force / normal simulation 
    for(int i =0 ;i<queries.size() ; i++){
        vector<int>query = queries[i];
            int idx = query[0];
            while(idx<=query[1]){
                nums[idx] = (int)((1L * nums[idx] * query[3]) % 1000000007);
                idx += query[2];
            }
    }

        // calculate xor of every element in nums;
        int result =0;
        for(int i : nums){
            result = result^i;
        }
        return result;
    }
};