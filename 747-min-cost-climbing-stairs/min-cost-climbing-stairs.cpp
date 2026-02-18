class Solution {
public:


    int solve(int index ,vector<int> &cost, int n, vector<int> &dp){
        if(index >= n) return 0;

        if(dp[index] != -1) return dp[index];

        int one_step = solve(index +1, cost , n, dp);
        int two_step = solve(index +2 ,cost , n, dp);

        return dp[index] =  min(one_step, two_step) + cost[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(1001, -1);
        int startfromzero = solve(0 , cost , n, dp);
        int startfromone = solve(1,cost , n, dp);

        return min(startfromzero , startfromone);
    }
};