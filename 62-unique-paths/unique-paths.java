class Solution {
        // recursive + memoization
    public int solve(int i , int j , int [][] dp){
        if(i == 0 && j == 0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1 ){
            return dp[i][j];
        }

        int row = solve(i-1, j ,dp);
        int column = solve(i,j-1,dp);

        return dp[i][j]  =  row+ column;
    }

    public int uniquePaths(int m, int n) {
        int dp [][] = new int[n+1][m+1];
        for(int i =0 ;i<=n ;i++){
            Arrays.fill(dp[i],-1);
        }
        int result =solve(n-1 ,m-1,dp);
        return result;
    }
}