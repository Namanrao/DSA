class Solution {
public:

    // with memoization
    int solve(int n, vector<int> &dp){
        //base case ; 
        if(n<0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        if(n ==0) return 1;

        int one_step = solve(n-1, dp);
        int two_step = solve(n-2, dp);

        return dp[n] = one_step + two_step;
    }

    int climbStairs(int n) {
        // memoization
        vector<int> dp(46,-1);
        return solve(n , dp);
    }
};