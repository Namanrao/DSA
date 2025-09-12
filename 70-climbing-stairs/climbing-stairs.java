class Solution {
    public int solve(int n , int stairs, int [] dp){
        if(stairs == n){
            return 1;
        }
        if(stairs > n ){
            return 0;
        }
        if(dp[stairs]!=-1){
            return dp[stairs];
        }

        return dp[stairs] = solve(n, stairs+1, dp ) + solve(n, stairs+2 , dp);

    }

    public int climbStairs(int n) {
        // simple recursive method - > TLE 
        int stairs = 0 ;
        int dp []  = new int [n+1];
        Arrays.fill(dp , -1);
        return solve(n , stairs , dp);

    }
}