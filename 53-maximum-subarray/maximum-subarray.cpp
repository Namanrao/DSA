class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kandane's algorithm 
        int sum = 0;
        int best = INT_MIN;
        for(int i =0 ; i < nums.size() ; i++){
            sum = sum + nums[i];
            best = max(best , sum);
            if(sum < 0){
                sum =0 ;
            }
        }
        return best;
    }
};