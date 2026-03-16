class Solution {
public:

    // simple recursion solution .

    int solve(int currentIndex , int endIndex,vector<int> &nums , vector<int> &dp){    
        if(currentIndex>endIndex) return 0;

        if(dp[currentIndex]!=-1) return dp[currentIndex];

        int pick  = solve(currentIndex+2 , endIndex , nums , dp) + nums[currentIndex];
        int notPick = solve(currentIndex+1 , endIndex , nums , dp);

        return dp[currentIndex] =  max(pick , notPick);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n+1 , -1);
        vector<int> dp2(n+1 , -1);
        int first_included = solve(0 , n-2 ,nums, dp1);
         int first_excluded = solve(1, n-1,nums , dp2);

        return max(first_included, first_excluded);
    }
};